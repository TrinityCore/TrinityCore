-- Knucklerot SAI
SET @ENTRY := 16246;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,8000,13000,11,3396,32,0,0,0,0,5,0,0,0,0,0,0,0,"Knucklerot - In Combat - Cast Corrosive Poison"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,9000,11,8014,1,0,0,0,0,5,0,0,0,0,0,0,0,"Knucklerot - At 0 - 5 Range - Cast Tetanus");

-- Borgoth the Bloodletter SAI
SET @ENTRY := 16247;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,18000,23000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Borgoth the Bloodletter - In Combat - Cast Rend"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,9000,11,3148,1,0,0,0,0,5,0,0,0,0,0,0,0,"Borgoth the Bloodletter - At 0 - 5 Range - Cast Head Crack");

-- Jurion the Deceiver SAI
SET @ENTRY := 16248;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,11000,21000,28000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jurion the Deceiver - In Combat - Cast Shadow Word: Pain");

-- Magister Idonis SAI
SET @ENTRY := 16204;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Idonis - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Idonis - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magister Idonis - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Idonis - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magister Idonis - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Idonis - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Idonis - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Idonis - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Idonis - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Idonis - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Idonis - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Idonis - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Idonis - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Magister Idonis - At 15% HP - Flee For Assist");

-- Luzran SAI
SET @ENTRY := 16245;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,11000,11,13444,0,0,0,0,0,2,0,0,0,0,0,0,0,"Luzran - At 0 - 5 Range - Cast Sunder Armor"),
(@ENTRY,0,1,0,0,0,100,0,12000,15000,13000,17000,11,40504,1,0,0,0,0,2,0,0,0,0,0,0,0,"Luzran - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,15000,21000,11,31389,1,0,0,0,0,2,0,0,0,0,0,0,0,"Luzran - In Combat - Cast Knock Away");

-- Masophet the Black SAI
SET @ENTRY := 16249;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masophet the Black - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masophet the Black - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Masophet the Black - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masophet the Black - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Masophet the Black - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masophet the Black - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masophet the Black - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masophet the Black - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masophet the Black - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masophet the Black - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,25,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Masophet the Black - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,12000,15000,9000,13000,11,16568,1,0,0,0,0,2,0,0,0,0,0,0,0,"Masophet the Black - In Combat - Cast Mind Flay"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masophet the Black - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masophet the Black - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Masophet the Black - At 15% HP - Flee For Assist");

-- Mirdoran the Fallen SAI
SET @ENTRY := 16250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,11000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mirdoran the Fallen - At 0 - 5 Range - Cast Sunder Armor"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,15000,19000,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mirdoran the Fallen - In Combat - Cast Shield Bash");

-- Aquantion SAI
SET @ENTRY := 16292;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,4000,6000,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aquantion - At 0 - 40 Range - Cast Frostbolt");

-- Risen Creeper SAI
SET @ENTRY := 16300;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,11000,11,6951,32,0,0,0,0,5,0,0,0,0,0,0,0,"Risen Creeper - At 0 - 5 Range - Cast Decayed Strength");

-- Risen Hungerer SAI
SET @ENTRY := 16301;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,75,5000,9000,11,6958,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Hungerer - At 75% HP - Cast Blood Leech");

-- Risen Stalker SAI
SET @ENTRY := 16302;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,5000,11000,11,8282,32,0,0,0,0,5,0,0,0,0,0,0,0,"Risen Stalker - At 0 - 20 Range - Cast Curse of Blood");

-- Dreadbone Skeleton SAI
SET @ENTRY := 16303;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,6000,10000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadbone Skeleton - At 0 - 5 Range - Cast Strike");

-- Arcane Devourer SAI
SET @ENTRY := 16304;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,10000,8000,15000,11,29054,0,0,0,0,0,5,0,0,0,0,0,0,0,"Arcane Devourer - In Combat - Cast Devour Mana");

-- Dreadbone Sentinel SAI
SET @ENTRY := 16305;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,11000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadbone Sentinel - At 0 - 5 Range - Cast Sunder Armor"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,15000,19000,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadbone Sentinel - In Combat - Cast Shield Bash");

-- Deathcage Scryer SAI
SET @ENTRY := 16307;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Scryer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Scryer - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathcage Scryer - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Scryer - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathcage Scryer - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Scryer - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Scryer - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Scryer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Scryer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Scryer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,25,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Scryer - At 100% Mana - Increment Phase");

-- Deathcage Sorcerer SAI
SET @ENTRY := 16308;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Sorcerer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Sorcerer - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathcage Sorcerer - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Sorcerer - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathcage Sorcerer - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Sorcerer - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Sorcerer - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Sorcerer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Sorcerer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Sorcerer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,25,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Sorcerer - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,9,0,100,0,0,8,11000,16000,11,12748,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathcage Sorcerer - At 0 - 8 Range - Cast Frost Nova");

-- Gangled Cannibal SAI
SET @ENTRY := 16309;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,120000,120000,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gangled Cannibal - At 30% HP - Cast Enrage");

-- Mana Shifter SAI
SET @ENTRY := 16310;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,8000,11000,11,29058,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mana Shifter - At 0 - 20 Range - Cast Drain Mana"),
(@ENTRY,0,1,0,3,0,100,1,99,100,0,0,11,29106,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mana Shifter - At 100% Mana - Cast Arcane Explosion");

-- Phantasmal Watcher SAI
SET @ENTRY := 16311;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Watcher - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Watcher - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phantasmal Watcher - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Watcher - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phantasmal Watcher - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Watcher - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Watcher - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Watcher - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Watcher - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Watcher - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,25,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Watcher - At 100% Mana - Increment Phase");

-- Nerubis Guard SAI
SET @ENTRY := 16313;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,11000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nerubis Guard - At 0 - 5 Range - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,0,9000,15000,18000,21000,11,744,33,0,0,0,0,2,0,0,0,0,0,0,0,"Nerubis Guard - In Combat - Cast Poison"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,16000,11,28887,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nerubis Guard - In Combat - Cast Wither Strike");

-- Fallen Ranger SAI
SET @ENTRY := 16314;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Ranger - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Ranger - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,28993,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fallen Ranger - On Aggro - Cast Banshee Wail"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Ranger - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,28993,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fallen Ranger - At 0 - 40 Range - Cast Banshee Wail"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Ranger - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Ranger - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Ranger - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Ranger - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Ranger - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,25,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Ranger - At 100% Mana - Increment Phase");

-- Deatholme Acolyte SAI
SET @ENTRY := 16315;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,20798,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Acolyte - Out Of Combat - Cast Demon Skin"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,21000,25000,11,11639,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deatholme Acolyte - In Combat - Cast Shadow Word: Pain");

-- Stonewing Tracker SAI
SET @ENTRY := 16316;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,11000,13000,16000,11,5810,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonewing Tracker - In Combat - Cast Stone Skin");

-- Deatholme Necromancer SAI
SET @ENTRY := 16317;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,0,1,0,100,0,1000,1000,300000,300000,11,29066,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - Out Of Combat - Cast Summon Dreadbone Skeleton"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deatholme Necromancer - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,0,0,40,3400,4800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deatholme Necromancer - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,6,7,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - At 7% Mana - Increment Phase"),
(@ENTRY,0,8,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,2,0,100,0,0,20,8000,12000,11,29067,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - At 20% HP - Cast Slave Drain"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - At 15% HP - Set Phase 3"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Deatholme Necromancer - At 15% HP - Flee For Assist");

-- Deatholme Darkmage SAI
SET @ENTRY := 16318;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Darkmage - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Darkmage - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deatholme Darkmage - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Darkmage - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deatholme Darkmage - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Darkmage - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Darkmage - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Darkmage - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Darkmage - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Darkmage - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Darkmage - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,7000,11000,32000,36000,11,18267,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deatholme Darkmage - In Combat - Cast Curse of Weakness"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Darkmage - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Darkmage - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Deatholme Darkmage - At 15% HP - Flee For Assist");

-- Nerubis Centurion SAI
SET @ENTRY := 16319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,120000,120000,11,21787,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nerubis Centurion - At 0 - 10 Range - Cast Deadly Poison");

-- Eye of Dar'Khan SAI
SET @ENTRY := 16320;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,32000,36000,11,14868,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Dar'Khan - In Combat - Cast Curse of Agony"),
(@ENTRY,0,1,0,0,0,100,0,12000,15000,18000,21000,11,8140,1,0,0,0,0,5,0,0,0,0,0,0,0,"Eye of Dar'Khan - In Combat - Cast Befuddlement");

-- Wailer SAI
SET @ENTRY := 16321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,9000,14000,11,7713,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailer - In Combat - Cast Wailing Dead");

-- Gangled Flesheater SAI
SET @ENTRY := 16322;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,9000,14000,11,8016,32,0,0,0,0,5,0,0,0,0,0,0,0,"Gangled Flesheater - In Combat - Cast Spirit Decay");

-- Phantasmal Seeker SAI
SET @ENTRY := 16323;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,8000,12000,11,13860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phantasmal Seeker - In Combat - Cast Mind Blast"),
(@ENTRY,0,1,0,0,0,100,0,12000,15000,18000,21000,11,30900,33,0,0,0,0,5,0,0,0,0,0,0,0,"Phantasmal Seeker - In Combat - Cast Curse of Impotence");

-- Stonewing Slayer SAI
SET @ENTRY := 16324;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,15000,19000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonewing Slayer - In Combat - Cast Rend Flesh");

-- Quel'dorei Ghost SAI
SET @ENTRY := 16325;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,50,0,0,11,31379,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'dorei Ghost - At 50% HP - Cast Evasion"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'dorei Ghost - At 50% HP - Say Line 0");

-- Quel'dorei Wraith SAI
SET @ENTRY := 16326;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,50,0,0,11,31379,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'dorei Wraith - At 50% HP - Cast Evasion"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'dorei Wraith - At 50% HP - Say Line 0");

-- Texts for Quel'dorei Ghost
DELETE FROM `creature_text` WHERE `entry`= 16325;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16325,0,0, "%s shimmers and becomes intangible.",16,0,100,0,0,0, "Quel\'dorei Ghost");

-- Texts for Quel'dorei Wraith
DELETE FROM `creature_text` WHERE `entry`= 16326;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16326,0,0, "%s shimmers and becomes intangible.",16,0,100,0,0,0, "Quel\'dorei Wraith");

-- Ravening Apparition SAI
SET @ENTRY := 16327;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,25000,28000,11,7140,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravening Apparition - At 0 - 5 Range - Cast Expose Weakness");

-- Vengeful Apparition SAI
SET @ENTRY := 16328;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,120000,120000,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vengeful Apparition - At 30% HP - Cast Enrage");

-- Dar'Khan Drathir SAI
SET @ENTRY := 16329;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dar'Khan Drathir - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dar'Khan Drathir - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dar'Khan Drathir - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dar'Khan Drathir - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dar'Khan Drathir - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dar'Khan Drathir - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dar'Khan Drathir - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dar'Khan Drathir - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dar'Khan Drathir - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dar'Khan Drathir - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dar'Khan Drathir - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,9000,12000,27000,31000,11,21068,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dar'Khan Drathir - In Combat - Cast Corruption"),
(@ENTRY,0,12,0,0,0,100,0,19000,24000,21000,25000,11,38660,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dar'Khan Drathir - In Combat - Cast Fear"),
(@ENTRY,0,13,0,6,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dar'Khan Drathir - On Death - Say Line 0");

-- Texts for Dar'Khan Drathir
DELETE FROM `creature_text` WHERE `entry`= 16329;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16329,0,0, "Insolence!",14,0,100,0,0,0, "Dar\'Khan Drathir");

-- Sentinel Spy SAI
SET @ENTRY := 16330;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,9000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Spy - At 0 - 5 Range - Cast Sinister Strike"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,7000,11000,11,7159,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Spy - In Combat - Cast Backstab"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sentinel Spy - At 15% HP - Flee For Assist");

-- Darnassian Druid SAI
SET @ENTRY := 16331;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,30000,35000,11,25602,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darnassian Druid - In Combat - Cast Faerie Fire"),
(@ENTRY,0,1,0,14,0,100,0,0,40,15000,25000,11,11431,1,0,0,0,0,7,0,0,0,0,0,0,0,"Darnassian Druid - On Friendly Unit At 0 - 40% Health - Cast Healing Touch");

-- Darnassian Huntress SAI
SET @ENTRY := 16332;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darnassian Huntress - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darnassian Huntress - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,9,0,100,0,0,5,5000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darnassian Huntress - At 0 - 5 Range - Cast Strike"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - At 15% HP - Increment Phase"),
(@ENTRY,0,15,16,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Darnassian Huntress - At 15% HP - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Huntress - On Evade - Display melee weapon");

-- Sentinel Infiltrator SAI
SET @ENTRY := 16333;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,15000,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Infiltrator - At 0 - 5 Range - Cast Gouge"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,7000,11000,11,7159,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Infiltrator - In Combat - Cast Backstab"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sentinel Infiltrator - At 15% HP - Flee For Assist");

-- Blackpaw Gnoll SAI
SET @ENTRY := 16334;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackpaw Gnoll - At 15% HP - Flee For Assist");

-- Blackpaw Scavenger SAI
SET @ENTRY := 16335;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,45000,45000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackpaw Scavenger - At 0 - 5 Range - Cast Pierce Armor"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackpaw Scavenger - At 15% HP - Flee For Assist");

-- Blackpaw Shaman SAI
SET @ENTRY := 16337;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20802,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackpaw Shaman - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20802,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackpaw Shaman - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,30,15000,25000,11,28902,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - At 30% HP - Cast Bloodlust"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackpaw Shaman - At 15% HP - Flee For Assist");

-- Arcane Reaver SAI
SET @ENTRY := 16339;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,11000,18000,11,31390,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Reaver - At 0 - 5 Range - Cast Knockdown");

-- Shadowpine Ripper SAI
SET @ENTRY := 16340;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,10000,14000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowpine Ripper - At 0 - 5 Range - Cast Pummel");

-- Shadowpine Witch SAI
SET @ENTRY := 16341;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,20000,40000,11,12550,32,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Witch - In Combat - Cast Lightning Shield");

-- Mummified Headhunter SAI
SET @ENTRY := 16342;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,29047,7,0,0,0,0,1,0,0,0,0,0,0,0,"Mummified Headhunter - On Death - Cast Cloud of Disease");

-- Shadowpine Oracle SAI
SET @ENTRY := 16343;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,0,10,20000,30000,11,7154,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowpine Oracle - On Friendly Unit At 0 - 10% Health - Cast Dark Offering"),
(@ENTRY,0,1,0,2,0,100,1,0,25,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowpine Oracle - At 25% HP - Flee For Assist");

-- Shadowpine Headhunter SAI
SET @ENTRY := 16344;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowpine Headhunter - On Aggro - Cast Throw"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 15% HP - Increment Phase"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowpine Headhunter - At 15% HP - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Headhunter - On Evade - Display melee weapon");

-- Shadowpine Catlord SAI
SET @ENTRY := 16345;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,16,0,100,0,28902,30,20000,40000,11,28902,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowpine Catlord - On Friendly Buff Missing - Cast Bloodlust");

-- Shadowpine Hexxer SAI
SET @ENTRY := 16346;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,6000,9000,11,17201,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Hexxer - In Combat - Cast Dispel Magic"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,12000,18000,11,29044,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowpine Hexxer - In Combat - Cast Hex"),
(@ENTRY,0,2,0,2,0,100,1,0,25,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowpine Hexxer - At 25% HP - Flee For Assist");

-- Ghostclaw Ravager SAI
SET @ENTRY := 16349;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,10000,12000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghostclaw Ravager - At 0 - 5 Range - Cast Exploit Weakness");

-- Spindleweb Spider SAI
SET @ENTRY := 16350;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,4000,9000,11,11918,32,0,0,0,0,2,0,0,0,0,0,0,0,"Spindleweb Spider - At 0 - 5 Range - Cast Poison");

-- Spindleweb Lurker SAI
SET @ENTRY := 16351;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,4000,9000,11,11918,32,0,0,0,0,2,0,0,0,0,0,0,0,"Spindleweb Lurker - At 0 - 5 Range - Cast Poison");

-- Greater Spindleweb SAI
SET @ENTRY := 16352;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,4000,9000,11,11918,32,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Spindleweb - At 0 - 5 Range - Cast Poison");

-- Anok'suten SAI
SET @ENTRY := 16357;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,4000,9000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Anok'suten - At 0 - 5 Range - Cast Poison"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,13000,11,13584,1,0,0,0,0,2,0,0,0,0,0,0,0,"Anok'suten - At 0 - 5 Range - Cast Strike"),
(@ENTRY,0,2,0,0,0,100,0,8000,12000,11000,15000,11,28887,1,0,0,0,0,2,0,0,0,0,0,0,0,"Anok'suten - In Combat - Cast Wither Strike"),
(@ENTRY,0,3,4,2,0,100,0,0,30,0,0,39,40,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anok'suten - At 30% HP - Call For Help"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anok'suten - At 30% HP - Say Line 0");

-- Texts for Anok'suten
DELETE FROM `creature_text` WHERE `entry`= 16357;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16357,0,0, "%s calls for help!",16,0,100,0,0,0, "Anok\'suten");

-- Kel'gash the Wicked SAI
SET @ENTRY := 16358;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'gash the Wicked - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'gash the Wicked - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20802,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kel'gash the Wicked - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'gash the Wicked - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20802,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kel'gash the Wicked - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'gash the Wicked - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'gash the Wicked - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'gash the Wicked - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'gash the Wicked - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'gash the Wicked - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'gash the Wicked - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,9,0,100,0,0,30,9000,13000,11,28900,1,0,0,0,0,5,0,0,0,0,0,0,0,"Kel'gash the Wicked - At 0 - 30 Range - Cast Chain Lightning"),
(@ENTRY,0,12,0,0,0,100,0,7000,10000,15000,22000,11,7289,32,0,0,0,0,5,0,0,0,0,0,0,0,"Kel'gash the Wicked - In Combat - Cast Shrink");

-- Zombified Grimscale SAI
SET @ENTRY := 16402;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Zombified Grimscale - At 15% HP - Flee For Assist");

-- Withered Grimscale SAI
SET @ENTRY := 16403;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Grimscale - On Aggro - Cast Throw"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Grimscale - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,9,0,100,0,0,5,16000,28000,11,7901,32,0,0,0,0,5,0,0,0,0,0,0,0,"Withered Grimscale - At 0 - 5 Range - Cast Decayed Agility"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - At 15% HP - Increment Phase"),
(@ENTRY,0,15,16,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Withered Grimscale - At 15% HP - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Grimscale - On Evade - Display melee weapon");

-- Shadowpine Shadowcaster SAI
SET @ENTRY := 16469;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,11000,15000,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowpine Shadowcaster - At 0 - 20 Range - Cast Mind Flay"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,9000,13000,11,31394,33,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowpine Shadowcaster - In Combat - Cast Mark of Shadow");

-- Sentinel Leader SAI
SET @ENTRY := 17210;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,9000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Leader - At 0 - 5 Range - Cast Sinister Strike"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,7000,11000,11,7159,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Leader - In Combat - Cast Backstab"),
(@ENTRY,0,2,3,2,0,100,0,0,15,0,0,39,40,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Leader - At 15% HP - Call For Help"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Leader - At 15% HP - Say Line 0");

-- Texts for Sentinel Leader
DELETE FROM `creature_text` WHERE `entry`= 17210;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17210,0,0, "%s calls for help!",16,0,100,0,0,0, "Sentinel Leader");

-- Sangrias Stillblade SAI
SET @ENTRY := 17716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,30,0,0,11,22120,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sangrias Stillblade - At 0 - 30 Range - Cast Charge");

-- Dr. Whitherlimb SAI
SET @ENTRY := 22062;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,4000,7000,11,21067,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dr. Whitherlimb - At 0 - 30 Range - Cast Poison Bolt"),
(@ENTRY,0,1,0,0,0,100,0,8000,15000,15000,30000,11,38864,33,0,0,0,0,5,0,0,0,0,0,0,0,"Dr. Whitherlimb - In Combat - Cast Withering Poison"),
(@ENTRY,0,2,0,2,0,100,0,0,50,35000,45000,11,38871,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dr. Whitherlimb - At 50% HP - Cast Monstrous Elixir");

-- Budd's Bodyguard SAI
SET @ENTRY := 25145;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,23337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Budd's Bodyguard - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,0,45,2300,3900,11,23337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Budd's Bodyguard - At 0 - 45 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - At 0 - 45 Range - Display ranged weapon"),
(@ENTRY,0,6,0,9,0,100,0,0,20,8000,13000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Budd's Bodyguard - At 0 - 20 Range - Cast Net"),
(@ENTRY,0,7,8,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,9,10,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,11,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,14,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Budd's Bodyguard - On Evade - Display melee weapon");

-- High Executor Darthalia SAI
SET @ENTRY := 2215;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,15000,20000,11,23511,1,0,0,0,0,1,0,0,0,0,0,0,0,"High Executor Darthalia - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,15000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"High Executor Darthalia - At 0 - 5 Range - Cast Hamstring"),
(@ENTRY,0,2,0,9,0,100,0,0,5,9000,12000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Executor Darthalia - At 0 - 5 Range - Cast Cleave"),
(@ENTRY,0,3,0,0,0,100,0,20000,30000,30000,45000,11,19134,1,0,0,0,0,1,0,0,0,0,0,0,0,"High Executor Darthalia - In Combat - Cast Frightening Shout");

-- Syndicate Shadow Mage SAI
SET @ENTRY := 2244;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Shadow Mage - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Shadow Mage - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Shadow Mage - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,2400,4200,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Shadow Mage - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Shadow Mage - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Shadow Mage - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Shadow Mage - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Shadow Mage - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Shadow Mage - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Shadow Mage - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Shadow Mage - At 15% HP - Set Phase 3"),
(@ENTRY,0,11,12,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Shadow Mage - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Syndicate Shadow Mage - At 15% HP - Flee For Assist");

-- Ferocious Yeti SAI
SET @ENTRY := 2249;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,20,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ferocious Yeti - At 20% HP - Cast Enrage"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ferocious Yeti - At 20% HP - Say Line 0");

-- Texts for Ferocious Yeti
DELETE FROM `creature_text` WHERE `entry`= 2249;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2249,0,0, "%s goes into a frenzy!",16,0,100,0,0,0, "Ferocious Yeti");

-- Syndicate Rogue SAI
SET @ENTRY := 2260;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,8000,12000,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Rogue - At 0 - 5 Range - Cast Backstab");

-- Hillsbrad Tailor SAI
SET @ENTRY := 2264;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,9000,11,2590,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hillsbrad Tailor - At 0 - 5 Range - Cast Backstab"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,11000,11,101,1,0,0,0,0,2,0,0,0,0,0,0,0,"Hillsbrad Tailor - At 0 - 5 Range - Cast Trip"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hillsbrad Tailor - At 30% HP - Flee For Assist");

-- Hillsbrad Apprentice Blacksmith SAI
SET @ENTRY := 2265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,25000,30000,11,3148,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hillsbrad Apprentice Blacksmith - At 0 - 5 Range - Cast Head Crack"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hillsbrad Apprentice Blacksmith - At 30% HP - Flee For Assist");

-- Hillsbrad Farmer SAI
SET @ENTRY := 2266;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,13000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hillsbrad Farmer - At 0 - 5 Range - Cast Disarm"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hillsbrad Farmer - At 30% HP - Flee For Assist");

-- Hillsbrad Peasant SAI
SET @ENTRY := 2267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,45000,45000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hillsbrad Peasant - At 0 - 5 Range - Cast Pierce Armor"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hillsbrad Peasant - At 30% HP - Flee For Assist");

-- Hillsbrad Footman SAI
SET @ENTRY := 2268;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,180000,180000,11,7164,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Footman - In Combat - Cast Defensive Stance"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,15000,11,1671,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hillsbrad Footman - At 0 - 5 Range - Cast Shield Bash"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hillsbrad Footman - At 30% HP - Flee For Assist");

-- Hillsbrad Miner SAI
SET @ENTRY := 2269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,180000,180000,11,7164,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Miner - In Combat - Cast Defensive Stance"),
(@ENTRY,0,1,0,9,0,100,0,0,5,6000,11000,11,7405,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hillsbrad Miner - At 0 - 5 Range - Cast Sunder Armor"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hillsbrad Miner - At 30% HP - Flee For Assist");

-- Hillsbrad Sentry SAI
SET @ENTRY := 2270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hillsbrad Sentry - At 30% HP - Flee For Assist");

-- Magistrate Henry Maleb SAI
SET @ENTRY := 2276;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,3,0,0,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - In Combat - Say Line 0"),
(@ENTRY,0,4,5,4,0,100,0,0,0,0,0,11,12737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magistrate Henry Maleb - On Aggro - Cast Frostbolt"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - On Aggro - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,0,0,40,3400,4800,11,12737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magistrate Henry Maleb - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,7,8,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - At 7% Mana - Increment Phase"),
(@ENTRY,0,9,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - At 100% Mana - Increment Phase"),
(@ENTRY,0,13,0,9,0,100,0,0,8,12000,15000,11,15531,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - At 0 - 8 Range - Cast Frost Nova"),
(@ENTRY,0,14,0,16,0,100,0,12544,1,10000,20000,11,12544,33,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - On Friendly Buff Missing - Cast Frost Armor"),
(@ENTRY,0,15,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - At 15% HP - Set Phase 3"),
(@ENTRY,0,16,17,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Magistrate Henry Maleb - At 15% HP - Flee For Assist");

-- Captain Ironhill SAI
SET @ENTRY := 2304;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,23000,30000,11,7020,1,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Ironhill - In Combat - Cast Stoneform"),
(@ENTRY,0,1,0,9,0,100,0,0,5,10000,14000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Ironhill - At 0 - 5 Range - Cast Pummel"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Captain Ironhill - At 30% HP - Flee For Assist");

-- Foreman Bonds SAI
SET @ENTRY := 2305;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,643,1,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Bonds - On Respawn - Cast Devotion Aura"),
(@ENTRY,0,1,0,9,0,100,0,0,5,60000,60000,11,5588,1,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Bonds - At 0 - 5 Range - Cast Hammer of Justice"),
(@ENTRY,0,2,3,2,0,100,0,0,30,0,0,12,7360,1,300000,0,0,0,2,0,0,0,0,0,0,0,"Foreman Bonds - At 30% HP - Summon Creature Dun Garok Soldier"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,12,7360,1,300000,0,0,0,2,0,0,0,0,0,0,0,"Foreman Bonds - At 30% HP - Summon Creature Dun Garok Soldier");

-- Magistrate Burnside SAI
SET @ENTRY := 2335;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magistrate Burnside - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magistrate Burnside - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,9,0,100,0,0,8,12000,15000,11,11969,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - At 0 - 8 Range - Cast Fire Nova"),
(@ENTRY,0,12,0,0,0,100,0,5000,7000,16000,20000,11,7739,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - In Combat - Cast Inferno Shell"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - At 15% HP - Set Phase 3"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Magistrate Burnside - At 15% HP - Flee For Assist");

-- Dun Garok Mountaineer SAI
SET @ENTRY := 2344;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,643,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Mountaineer - On Respawn - Cast Devotion Aura"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,15000,11,13953,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dun Garok Mountaineer - At 0 - 5 Range - Cast Holy Strike"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dun Garok Mountaineer - At 30% HP - Flee For Assist");

-- Dun Garok Rifleman SAI
SET @ENTRY := 2345;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dun Garok Rifleman - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,0,0,100,0,12000,18000,30000,30000,11,6685,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dun Garok Rifleman - In Combat - Cast Piercing Shot"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - In Combat - Display ranged weapon"),
(@ENTRY,0,8,9,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,10,11,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,12,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,13,14,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,15,0,2,0,100,1,0,30,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 30% HP - Increment Phase"),
(@ENTRY,0,16,17,2,0,100,0,0,30,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 30% HP - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dun Garok Rifleman - At 30% HP - Flee For Assist"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - On Evade - Display melee weapon");

-- Dun Garok Priest SAI
SET @ENTRY := 2346;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9734,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dun Garok Priest - On Aggro - Cast Holy Smite"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,9734,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dun Garok Priest - At 0 - 40 Range - Cast Holy Smite"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,14,0,100,0,0,40,15000,21000,11,11642,1,0,0,0,0,7,0,0,0,0,0,0,0,"Dun Garok Priest - On Friendly Unit At 0 - 40% Health - Cast Heal"),
(@ENTRY,0,12,0,2,0,100,1,0,30,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - At 30% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,30,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - At 30% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dun Garok Priest - At 30% HP - Flee For Assist");

-- Elder Moss Creeper SAI
SET @ENTRY := 2348;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5500,31000,36000,11,3396,32,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Moss Creeper - In Combat - Cast Corrosive Poison");

-- Hillsbrad Farmhand SAI
SET @ENTRY := 2360;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hillsbrad Farmhand - At 30% HP - Flee For Assist");

-- Daggerspine Shorestalker SAI
SET @ENTRY := 2368;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,180000,180000,11,7164,1,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorestalker - In Combat - Cast Defensive Stance"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,13000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Daggerspine Shorestalker - At 0 - 5 Range - Cast Pummel");

-- Daggerspine Shorehunter SAI
SET @ENTRY := 2369;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Daggerspine Shorehunter - On Aggro - Cast Throw"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2200,3800,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Daggerspine Shorehunter - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,0,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,8,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,8,9,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,10,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - At 15% HP - Increment Phase"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Daggerspine Shorehunter - At 15% HP - Flee For Assist"),
(@ENTRY,0,15,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - On Evade - Display melee weapon");

-- Daggerspine Screamer SAI
SET @ENTRY := 2370;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,12000,16000,11,3589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Daggerspine Screamer - In Combat - Cast Deafening Screech");

-- Daggerspine Siren SAI
SET @ENTRY := 2371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Siren - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Daggerspine Siren - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Siren - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3400,4800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Daggerspine Siren - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Siren - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Siren - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Siren - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Siren - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Siren - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Siren - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,6000,8000,22000,27000,11,992,1,0,0,0,0,5,0,0,0,0,0,0,0,"Daggerspine Siren - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,11,0,0,0,100,0,11000,15000,17000,21000,11,6728,0,0,0,0,0,6,0,0,0,0,0,0,0,"Daggerspine Siren - In Combat - Cast Enveloping Winds"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Siren - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Siren - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Daggerspine Siren - At 15% HP - Flee For Assist");

-- Mudsnout Gnoll SAI
SET @ENTRY := 2372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,30000,30000,11,3650,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mudsnout Gnoll - At 0 - 5 Range - Cast Sling Mud");

-- Mudsnout Shaman SAI
SET @ENTRY := 2373;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20805,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mudsnout Shaman - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20805,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mudsnout Shaman - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,14,0,100,0,0,40,14000,19000,11,939,1,0,0,0,0,7,0,0,0,0,0,0,0,"Mudsnout Shaman - On Friendly Unit At 0 - 40% Health - Cast Healing Wave"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mudsnout Shaman - At 15% HP - Flee For Assist");

-- Torn Fin Muckdweller SAI
SET @ENTRY := 2374;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,8000,12000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Torn Fin Muckdweller - At 0 - 5 Range - Cast Infected Wound"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Torn Fin Muckdweller - At 15% HP - Flee For Assist");

-- Torn Fin Coastrunner SAI
SET @ENTRY := 2375;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Torn Fin Coastrunner - On Aggro - Cast Throw"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 15% HP - Increment Phase"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Torn Fin Coastrunner - At 15% HP - Flee For Assist"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - On Evade - Display melee weapon");

-- Torn Fin Oracle SAI
SET @ENTRY := 2376;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Torn Fin Oracle - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Torn Fin Oracle - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,0,0,25,25000,35000,11,939,1,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - At 25% HP - Cast Healing Wave"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Torn Fin Oracle - At 15% HP - Flee For Assist");

-- Torn Fin Tidehunter SAI
SET @ENTRY := 2377;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,15000,11,865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Tidehunter - At 0 - 5 Range - Cast Frost Nova"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Torn Fin Tidehunter - At 15% HP - Flee For Assist");

-- Kundric Zanden SAI
SET @ENTRY := 2378;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kundric Zanden - At 15% HP - Flee For Assist");

-- Caretaker Smithers SAI
SET @ENTRY := 2379;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Caretaker Smithers - At 15% HP - Flee For Assist");

-- Nandar Branson SAI
SET @ENTRY := 2380;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Nandar Branson - At 15% HP - Flee For Assist");

-- Micha Yance SAI
SET @ENTRY := 2381;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Micha Yance - At 15% HP - Flee For Assist");

-- Darren Malvew SAI
SET @ENTRY := 2382;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Darren Malvew - At 15% HP - Flee For Assist");

-- Lindea Rabonne SAI
SET @ENTRY := 2383;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lindea Rabonne - At 15% HP - Flee For Assist");

-- Starving Mountain Lion SAI
SET @ENTRY := 2384;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,24450,0,0,0,0,0,1,0,0,0,0,0,0,0,"Starving Mountain Lion - On Respawn - Cast Prowl");

-- Southshore Guard SAI
SET @ENTRY := 2386;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Southshore Guard - At 15% HP - Flee For Assist");

-- Texts for Magistrate Henry Maleb
DELETE FROM `creature_text` WHERE `entry`= 2276;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2276,0,0, "More agents of the Syndicate I'll wager! You'll never take back Alterac... Or Southshore!",12,7,100,0,0,0, "Magistrate Henry Maleb");

-- Hillsbrad Councilman SAI
SET @ENTRY := 2387;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,20806,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hillsbrad Councilman - On Aggro - Cast Frostbolt"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,0,0,40,3400,4800,11,20806,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hillsbrad Councilman - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,6,7,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - At 7% Mana - Increment Phase"),
(@ENTRY,0,8,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,9,0,100,0,0,5,25000,25000,11,122,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - At 0 - 5 Range - Cast Frost Nova"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - At 15% HP - Set Phase 3"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hillsbrad Councilman - At 15% HP - Flee For Assist");

-- Hans Zandin SAI
SET @ENTRY := 2396;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,300000,30000,450000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hans Zandin - Out Of Combat - Say Line 0");

-- Texts for Hans Zandin
DELETE FROM `creature_text` WHERE `entry`= 2396;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2396,0,0, "I spent my whole life caring for these trees. Pruning and nurturing them... only fitting that they have joined me in death.",12,1,100,0,0,0, "Hans Zandin"),
(2396,0,1, "This orchard is now as barren and lifeless as my rotting shell. Once these trees bloomed with fruit but now there is only rot.",12,1,100,0,0,0, "Hans Zandin");

-- Farmer Getz SAI
SET @ENTRY := 2403;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Farmer Getz - At 15% HP - Flee For Assist");

-- Blacksmith Verringtan SAI
SET @ENTRY := 2404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blacksmith Verringtan - At 15% HP - Flee For Assist");

-- Tarren Mill Deathguard SAI
SET @ENTRY := 2405;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Deathguard - On Aggro - Say Line 0");

-- Texts for Tarren Mill Deathguard
DELETE FROM `creature_text` WHERE `entry`= 2405;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2405,0,0, "Intruders! Attack the intruders!",12,33,100,0,0,0, "Tarren Mill Deathguard");

-- Mountain Lion SAI
SET @ENTRY := 2406;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,24450,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mountain Lion - On Respawn - Cast Prowl");

-- Jailor Eston SAI
SET @ENTRY := 2427;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,11000,21000,25000,11,3442,0,0,0,0,0,6,0,0,0,0,0,0,0,"Jailor Eston - In Combat - Cast Enslave");

-- Jailor Marlgen SAI
SET @ENTRY := 2428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jailor Marlgen - On Aggro - Cast Shoot"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - On Aggro - Increment Phase"),
(@ENTRY,0,5,6,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jailor Marlgen - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,7,8,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,9,10,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,11,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,14,0,9,0,100,0,0,20,7000,11000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Jailor Marlgen - At 0 - 20 Range - Cast Net"),
(@ENTRY,0,15,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - At 15% HP - Increment Phase"),
(@ENTRY,0,16,17,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Jailor Marlgen - At 15% HP - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - On Evade - Display melee weapon");

-- Helcular's Remains SAI
SET @ENTRY := 2433;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Helcular's Remains - On Respawn - Say Line 0"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Helcular's Remains - On Aggro - Say Line 1"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,4950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Helcular's Remains - On Aggro - Cast Summon Helcular's Puppets");

-- Texts for Jailor Marlgen
DELETE FROM `creature_text` WHERE `entry`= 2428;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2428,0,0, "Never cross a Dark Iron, $C.",12,0,100,0,0,0, "Jailor Marlgen"),
(2428,0,1, "Time to die, $C!",12,0,100,0,0,0, "Jailor Marlgen"),
(2428,0,2, "Feel the power of the Dark Iron Dwarves!",12,0,100,0,0,0, "Jailor Marlgen");

-- Texts for Helcular's Remains
DELETE FROM `creature_text` WHERE `entry`= 2433;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2433,0,0, "Revenge shall be mine at last!",14,0,100,1,0,0, "Helcular\'s Remains"),
(2433,0,1, "I have risen!",14,0,100,1,0,0, "Helcular\'s Remains"),
(2433,0,2, "Southshore shall pay in blood!",14,0,100,1,0,0, "Helcular\'s Remains"),
(2433,1,0, "The undead shall feast on your soul, $N.",14,0,100,1,0,0, "Helcular\'s Remains");

-- Shadowy Assassin SAI
SET @ENTRY := 2434;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,1786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Assassin - On Respawn - Cast Stealth");

-- Southshore Crier SAI
SET @ENTRY := 2435;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southshore Crier - On Respawn - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,1,120000,120000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southshore Crier - Out Of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,1,126000,126000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southshore Crier - Out Of Combat - Say Line 2"),
(@ENTRY,0,3,0,1,0,100,1,130000,130000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southshore Crier - Out Of Combat - Say Line 3");

-- Texts for Southshore Crier
DELETE FROM `creature_text` WHERE `entry`= 2435;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2435,0,0, "Help me! Help! Assassins in the hills! To arms! To arms!",14,0,100,22,0,0, "Southshore Crier"),
(2435,1,0, "Guards to your posts! They must be after the Magistrate again. He must be protected! They could come from any direction!",12,0,100,1,0,0, "Southshore Crier"),
(2435,2,0, "%s grabs the back of his neck and his eyes go wide.",16,0,100,0,0,0, "Southshore Crier"),
(2435,3,0, "Assassins... save... th... Magistraaa...",12,0,100,65,0,0, "Southshore Crier");

-- Bartolo Ginsetti SAI
SET @ENTRY := 2438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,20000,45000,45000,60000,10,4,15,23,0,0,0,1,0,0,0,0,0,0,0,"Bartolo Ginsetti - Out Of Combat - Random Emote");

-- Clerk Horrace Whitesteed SAI
SET @ENTRY := 2448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Clerk Horrace Whitesteed - At 15% HP - Flee For Assist");

-- Citizen Wilkes SAI
SET @ENTRY := 2449;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Citizen Wilkes - At 15% HP - Flee For Assist");

-- Miner Hackett SAI
SET @ENTRY := 2450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Miner Hackett - At 15% HP - Flee For Assist");

-- Farmer Kalaba SAI
SET @ENTRY := 2451;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Farmer Kalaba - At 15% HP - Flee For Assist");

-- Hillsbrad Foreman SAI
SET @ENTRY := 2503;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,11000,15000,11,5115,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Foreman - In Combat - Cast Battle Command"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hillsbrad Foreman - At 15% HP - Flee For Assist");

-- Brewmeister Bilger SAI
SET @ENTRY := 2705;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Brewmeister Bilger - At 15% HP - Flee For Assist");

-- Phin Odelic SAI
SET @ENTRY := 2711;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Phin Odelic - At 15% HP - Flee For Assist");

-- Hal McAllister SAI
SET @ENTRY := 3540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hal McAllister - At 15% HP - Flee For Assist");

-- Sarah Raycroft SAI
SET @ENTRY := 3541;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sarah Raycroft - At 15% HP - Flee For Assist");

-- Jaysin Lanyda SAI
SET @ENTRY := 3542;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Jaysin Lanyda - At 15% HP - Flee For Assist");

-- Robert Aebischer SAI
SET @ENTRY := 3543;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Robert Aebischer - At 15% HP - Flee For Assist");

-- Raleigh the Devout SAI
SET @ENTRY := 3980;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Raleigh the Devout - At 15% HP - Flee For Assist");

-- Condemned Acolyte SAI
SET @ENTRY := 7068;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,21000,25000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Condemned Acolyte - At 0 - 5 Range - Cast Shadow Word: Pain"),
(@ENTRY,0,1,0,14,0,100,0,0,40,18000,25000,11,25058,1,0,0,0,0,7,0,0,0,0,0,0,0,"Condemned Acolyte - On Friendly Unit At 0 - 40% Health - Cast Renew");

-- Condemned Monk SAI
SET @ENTRY := 7069;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,21000,11,15614,0,0,0,0,0,2,0,0,0,0,0,0,0,"Condemned Monk - At 0 - 5 Range - Cast Kick"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,13000,11,12555,1,0,0,0,0,2,0,0,0,0,0,0,0,"Condemned Monk - At 0 - 5 Range - Cast Pummel");

-- Condemned Cleric SAI
SET @ENTRY := 7070;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Condemned Cleric - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Condemned Cleric - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,25054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Condemned Cleric - On Aggro - Cast Holy Smite"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Condemned Cleric - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,25054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Condemned Cleric - At 0 - 40 Range - Cast Holy Smite"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Condemned Cleric - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Condemned Cleric - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Condemned Cleric - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Condemned Cleric - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Condemned Cleric - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Condemned Cleric - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,14,0,100,0,0,40,18000,21000,11,15586,1,0,0,0,0,7,0,0,0,0,0,0,0,"Condemned Cleric - On Friendly Unit At 0 - 40% Health - Cast Heal");

-- Cursed Paladin SAI
SET @ENTRY := 7071;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,14000,18000,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Paladin - At 0 - 8 Range - Cast Hammer of Justice");

-- Cursed Justicar SAI
SET @ENTRY := 7072;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,8000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Justicar - At 0 - 5 Range - Cast Strike");

-- Writhing Mage SAI
SET @ENTRY := 7075;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Writhing Mage - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Writhing Mage - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Writhing Mage - At 15% HP - Flee For Assist");

-- Dun Garok Soldier SAI
SET @ENTRY := 7360;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,180000,180000,11,7164,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Soldier - In Combat - Cast Defensive Stance"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,15000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dun Garok Soldier - At 0 - 5 Range - Cast Shield Bash");

-- Wesley SAI
SET @ENTRY := 9978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Wesley - At 15% HP - Flee For Assist");

-- Milton Beats SAI
SET @ENTRY := 13082;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,12000,16000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,"Milton Beats - In Combat - Cast Incapacitating Shout"),
(@ENTRY,0,1,0,9,0,100,0,0,5,8000,12000,11,6754,1,0,0,0,0,2,0,0,0,0,0,0,0,"Milton Beats - At 0 - 5 Range - Cast Slap!");

-- Sergeant Hartman SAI
SET @ENTRY := 15199;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sergeant Hartman - At 15% HP - Flee For Assist");

-- Shattered Sun Marksman SAI
SET @ENTRY := 24938;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Marksman - On Respawn - Allow Combat Movement"),
(@ENTRY,0,1,0,10,0,100,1,0,70,4500,8000,11,42580,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shattered Sun Marksman - On LOS Out Of Combat - Cast Shoot");

-- Wretched Devourer SAI
SET @ENTRY := 24960;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,12000,25000,30000,11,33483,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Devourer - In Combat - Cast Mana Tap"),
(@ENTRY,0,1,0,0,0,100,0,15000,20000,25000,30000,11,35334,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Devourer - In Combat - Cast Nether Shock"),
(@ENTRY,0,2,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Devourer - On Aggro - Say Line 0");

-- Wretched Fiend SAI
SET @ENTRY := 24966;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,20000,60000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Fiend - In Combat - Cast Sunder Armor"),
(@ENTRY,0,1,0,0,0,100,0,15000,20000,15000,20000,11,29098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Fiend - In Combat - Cast Bitter Withdrawal"),
(@ENTRY,0,2,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Fiend - On Aggro - Say Line 0");

-- Texts for Wretched Devourer
DELETE FROM `creature_text` WHERE `entry`= 24960;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(24960,0,0, "Mine! You shall not take this place!",12,0,100,0,0,0, "Wretched Devourer");

-- Texts for Wretched Fiend
DELETE FROM `creature_text` WHERE `entry`= 24966;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(24966,0,0, "Get away, this place is ours!",12,0,100,0,0,0, "Wretched Fiend");

-- Dawnblade Blood Knight SAI
SET @ENTRY := 24976;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,1,40,15000,25000,11,13952,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dawnblade Blood Knight - At 40% HP - Cast Holy Light"),
(@ENTRY,0,1,0,14,0,100,0,0,250,5000,12000,11,13952,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dawnblade Blood Knight - On Friendly Unit At 0 - 250% Health - Cast Holy Light"),
(@ENTRY,0,2,0,0,0,100,0,8000,18000,25000,36000,11,45337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dawnblade Blood Knight - In Combat - Cast Judgement of Wrath"),
(@ENTRY,0,3,0,0,0,100,0,3000,17000,14000,48750,11,45095,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dawnblade Blood Knight - In Combat - Cast Seal of Wrath");

-- Dawnblade Summoner SAI
SET @ENTRY := 24978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,75,1,0,0,0,0,11,44977,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dawnblade Summoner - On Respawn - Cast Fel Armor"),
(@ENTRY,0,1,0,1,0,100,0,8000,30000,120000,500000,11,44977,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dawnblade Summoner - Out Of Combat - Cast Fel Armor"),
(@ENTRY,0,2,0,1,0,100,1,5000,10000,5000,10000,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dawnblade Summoner - Out Of Combat - Cast Summon Imp"),
(@ENTRY,0,3,0,0,0,100,0,2000,4000,8000,12000,11,32707,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dawnblade Summoner - In Combat - Cast Incinerate"),
(@ENTRY,0,4,0,0,0,100,0,15000,18000,25000,30000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dawnblade Summoner - In Combat - Cast Immolate");

-- Dawnblade Marksman SAI
SET @ENTRY := 24979;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,0,70,7000,13000,11,45101,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dawnblade Marksman - On LOS Out Of Combat - Cast Flaming Arrow");

-- Irespeaker SAI
SET @ENTRY := 24999;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,3000,10000,15000,11,35913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irespeaker - In Combat - Cast Fel Fireball"),
(@ENTRY,0,1,0,0,0,100,0,13000,16000,20000,35000,11,18267,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irespeaker - In Combat - Cast Curse of Weakness"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,33,25068,0,0,0,0,0,7,0,0,0,0,0,0,0,"Irespeaker - On Death - Quest Credit");

-- Abyssal Flamewalker SAI
SET @ENTRY := 25001;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,4000,6000,11,12744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Abyssal Flamewalker - In Combat - Cast Immolation"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,33,25068,0,0,0,0,0,7,0,0,0,0,0,0,0,"Abyssal Flamewalker - On Death - Quest Credit");

-- Unleashed Hellion SAI
SET @ENTRY := 25002;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,33,25068,0,0,0,0,0,7,0,0,0,0,0,0,0,"Unleashed Hellion - On Death - Quest Credit"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,18000,35000,11,11876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unleashed Hellion - In Combat - Cast War Stomp"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,12600,16000,11,20754,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unleashed Hellion - In Combat - Cast Rain of Fire");

-- Emissary of Hate SAI
SET @ENTRY := 25003;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,15000,20000,11,25003,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emissary of Hate - In Combat - Cast Mortar"),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,15000,20000,11,38611,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emissary of Hate - In Combat - Cast Flame Wave");

-- Pit Overlord SAI
SET @ENTRY := 25031;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,10000,8000,15000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pit Overlord - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,0,7500,13000,15000,20000,11,19630,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pit Overlord - In Combat - Cast Cone of Fire"),
(@ENTRY,0,2,0,0,0,65,0,2000,4000,20000,30000,11,32709,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pit Overlord - In Combat - Cast Death Coil");

-- Eredar Sorcerer SAI
SET @ENTRY := 25033;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,45046,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eredar Sorcerer - In Combat - Cast Flames of Doom");

-- Darkspine Myrmidon SAI
SET @ENTRY := 25060;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5500,10000,17000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspine Myrmidon - In Combat - Cast Sunder Armor"),
(@ENTRY,0,1,0,0,0,100,0,4000,12000,35000,45000,11,13730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspine Myrmidon - In Combat - Cast Demoralizing Shout");

-- Dawnblade Hawkrider SAI
SET @ENTRY := 25063;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,0,70,3000,6500,11,45189,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dawnblade Hawkrider - On LOS Out Of Combat - Cast Dawnblade Attack");

-- Darkspine Siren SAI
SET @ENTRY := 25073;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspine Siren - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,5400,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspine Siren - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,20000,50000,80000,120000,11,3589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspine Siren - In Combat - Cast Deafening Screech"),
(@ENTRY,0,12,0,0,0,100,0,13000,18000,5000,25000,11,38033,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspine Siren - In Combat - Cast Frost Nova"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - At 15% HP - Set Phase 3"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspine Siren - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Darkspine Siren - At 15% HP - Flee For Assist");

-- Dawnblade Reservist SAI
SET @ENTRY := 25087;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,79,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dawnblade Reservist - On Respawn - Set Ranged Movement"),
(@ENTRY,0,1,0,0,0,100,0,2500,6000,6000,10000,11,34120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dawnblade Reservist - In Combat - Cast Steady Shot"),
(@ENTRY,0,2,0,9,0,100,0,1,25,1000,4000,11,32915,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dawnblade Reservist - At 1 - 25 Range - Cast Raptor Strike");

-- Sunblade Lookout SAI
SET @ENTRY := 25132;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,10,0,25000,120000,50000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Lookout - Out Of Combat - Say Line 0");

-- Texts for Sunblade Lookout
DELETE FROM `creature_text` WHERE `entry`= 25132;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(25132,0,0, "Shattered Sun scum! Fire at will!",14,0,100,0,0,0, "Sunblade Lookout");

-- Shattered Sun Bombardier SAI
SET @ENTRY := 25144;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,15,0,30000,40000,45000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Bombardier - Out Of Combat - Say Line 0");

-- Texts for Shattered Sun Bombardier
DELETE FROM `creature_text` WHERE `entry`= 25144;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(25144,0,0, "Dragonhawk incoming from the west! Shoot that druid down!",12,0,100,0,0,0, "Shattered Sun Bombardier"),
(25144,0,1, "Keep your eye on the demons. We're not concerned with killing Scourge today.",14,0,100,0,0,0, "Shattered Sun Bombardier");

-- Drill Sergeant Bahduum SAI
SET @ENTRY := 25162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,60000,14400000,14400000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,63000,63000,14403000,14403000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,0,68000,68000,14408000,14408000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 2"),
(@ENTRY,0,3,0,1,0,100,0,76000,76000,14416000,14416000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 3"),
(@ENTRY,0,4,0,1,0,100,0,84000,84000,14424000,14424000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 4"),
(@ENTRY,0,5,0,1,0,100,0,92000,92000,14432000,14432000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 5"),
(@ENTRY,0,6,0,1,0,100,0,100000,100000,14440000,14440000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 6"),
(@ENTRY,0,7,0,1,0,100,0,180000,180000,900000,900000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 0"),
(@ENTRY,0,8,0,1,0,100,0,183000,183000,903000,903000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 8"),
(@ENTRY,0,9,0,1,0,100,0,188000,188000,908000,908000,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 9"),
(@ENTRY,0,10,0,1,0,100,0,194000,194000,914000,914000,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 10"),
(@ENTRY,0,11,0,1,0,100,0,202000,202000,922000,922000,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 11"),
(@ENTRY,0,12,0,1,0,100,0,210000,210000,930000,930000,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 12"),
(@ENTRY,0,13,0,1,0,100,0,218000,218000,938000,938000,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 13"),
(@ENTRY,0,14,0,1,0,100,0,4500000,4500000,13500000,13500000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 0"),
(@ENTRY,0,15,0,1,0,100,0,4503000,4503000,13503000,13503000,1,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 15"),
(@ENTRY,0,16,0,1,0,100,0,4511000,4511000,13511000,13511000,1,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 16"),
(@ENTRY,0,17,0,1,0,100,0,4519000,4519000,13519000,13519000,1,17,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 17"),
(@ENTRY,0,18,0,1,0,100,0,4527000,4527000,13527000,13527000,1,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 18"),
(@ENTRY,0,19,0,1,0,100,0,4535000,4535000,13535000,13535000,1,19,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 19"),
(@ENTRY,0,20,0,1,0,100,0,4543000,4543000,13543000,13543000,1,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drill Sergeant Bahduum - Out Of Combat - Say Line 20");

-- Texts for Drill Sergeant Bahduum
DELETE FROM `creature_text` WHERE `entry`= 25162;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(25162,0,0, "ATTENTION!",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,1,0, "Alright, quiet down. We have a lot of work to do and very little time to do it in, people.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,2,0, "I've stood with some of you draenei before at Skettis, and others in Shadowmoon Valley. But now we're on Azeroth, and the situation looks grim.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,3,0, "First though, you sin'dorei listen up. I run a tight ship... this isn't going to be like what you're used to with the Scryers. Pull your weight, or get back on the boat!",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,4,0, "Now that that's out of the way, welcome to the Isle of Quel'Danas. The Sunwell's on the plateau to the south, and Prince Kael'thas is holed up in the Magisters' Terrace to the east.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,5,0, "We're here as support for the so-called 'adventurers' that the brass called in. We'll help them hold the key points on the island, and keep the heat off so that they can do their jobs.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,6,0, "If none of you ladies have any questions, you can get further instruction and assignments from your squad leaders. That's it. Good luck!",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,7,0, "ATTENTION!",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,8,0, "Welcome to the Sunwell. Despite the mild temperatures and scenic vistas, you're not on vacation, ladies and gentlemen!",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,9,0, "The current situation looks like this: we're holding what we can while those with more experience and better equipment are moving against Prince Kael'thas.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,10,0, "I know, we thought he was dead too, but that's not the case. He's trying to use the Sunwell to bring the master of the Burning Legion, Kil'jaeden, into this world.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,11,0, "Let me assure you people that if he's successful, this world will suffer far worse than Outland ever did! So let's make sure that doesn't come to pass.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,12,0, "Warriors will be deployed to hold key positions, while you marksmen will be assigned to keep the enemy fliers at bay.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,13,0, "I'm awaiting orders on your specific assignments. In the meantime, stay here and be ready to move at a moment's notice!",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,14,0, "ATTENTION!",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,15,0, "Hello to you new recruits. I'm Drill Sergeant Bahduum. For the next few days, you're going to receive orientation.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,16,0, "The Isle of Quel'Danas has been overrun by the forces of Prince Kael'thas Sunstrider. Intel had him pegged as deceased. Intel was wrong.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,17,0, "Up on the plateau, he and his demon friends are trying to reignite the Sunwell and open a rift to bring their head-honcho, Kil'Jaeden back into the world.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,18,0, "Our job is to clear out as much of the fodder as we can, while supporting the specialists that the powers-that-be are having brought in.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,19,0, "Needless to say, a lot of us won't be going home. But if you remember your training and keep your wits about you, you'll greatly increase your chances.",12,0,100,0,0,0, "Drill Sergeant Bahduum"),
(25162,20,0, "That's all I have to say for now. Stay focused, boys and girls.",12,0,100,0,0,0, "Drill Sergeant Bahduum");

-- Stonesplinter Trogg SAI
SET @ENTRY := 1161;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Trogg - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonesplinter Trogg - At 15% HP - Flee For Assist");

-- Texts for Stonesplinter Trogg
DELETE FROM `creature_text` WHERE `entry`= 1161;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1161,0,0, "Destroy!",12,0,100,0,0,0, "Stonesplinter Trogg"),
(1161,0,1, "Kill!",12,0,100,0,0,0, "Stonesplinter Trogg"),
(1161,0,2, "Crush!",12,0,100,0,0,0, "Stonesplinter Trogg");

-- Texts for Stonesplinter Scout
DELETE FROM `creature_text` WHERE `entry`= 1162;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1162,0,0, "Destroy!",12,0,100,0,0,0, "Stonesplinter Scout"),
(1162,0,1, "Kill!",12,0,100,0,0,0, "Stonesplinter Scout"),
(1162,0,2, "Crush!",12,0,100,0,0,0, "Stonesplinter Scout");

-- Texts for Stonesplinter Skullthumper
DELETE FROM `creature_text` WHERE `entry`= 1163;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1163,0,0, "Destroy!",12,0,100,0,0,0, "Stonesplinter Skullthumper"),
(1163,0,1, "Kill!",12,0,100,0,0,0, "Stonesplinter Skullthumper"),
(1163,0,2, "Crush!",12,0,100,0,0,0, "Stonesplinter Skullthumper");

-- Texts for Stonesplinter Geomancer
DELETE FROM `creature_text` WHERE `entry`= 1165;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1165,0,0, "Destroy!",12,0,100,0,0,0, "Stonesplinter Geomancer"),
(1165,0,1, "Kill!",12,0,100,0,0,0, "Stonesplinter Geomancer"),
(1165,0,2, "Crush!",12,0,100,0,0,0, "Stonesplinter Geomancer");

-- Texts for Stonesplinter Seer
DELETE FROM `creature_text` WHERE `entry`= 1166;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1166,0,0, "Destroy!",12,0,100,0,0,0, "Stonesplinter Seer"),
(1166,0,1, "Kill!",12,0,100,0,0,0, "Stonesplinter Seer"),
(1166,0,2, "Crush!",12,0,100,0,0,0, "Stonesplinter Seer");

-- Texts for Stonesplinter Digger
DELETE FROM `creature_text` WHERE `entry`= 1167;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1167,0,0, "Destroy!",12,0,100,0,0,0, "Stonesplinter Digger"),
(1167,0,1, "Kill!",12,0,100,0,0,0, "Stonesplinter Digger"),
(1167,0,2, "Crush!",12,0,100,0,0,0, "Stonesplinter Digger");

-- Stonesplinter Scout SAI
SET @ENTRY := 1162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Scout - On Aggro - Cast Throw"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - On Aggro - Increment Phase"),
(@ENTRY,0,5,6,9,0,100,0,5,30,2800,4800,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Scout - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,7,8,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,9,10,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,11,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - At 15% HP - Increment Phase"),
(@ENTRY,0,15,16,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonesplinter Scout - At 15% HP - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - On Evade - Display melee weapon");

-- Stonesplinter Skullthumper SAI
SET @ENTRY := 1163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Skullthumper - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,75,0,1900,3700,10800,14800,11,1776,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Skullthumper - In Combat - Cast Gouge"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonesplinter Skullthumper - At 15% HP - Flee For Assist");

-- Stonesplinter Bonesnapper SAI
SET @ENTRY := 1164;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,2000,6000,12100,22000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Bonesnapper - In Combat - Cast Strike"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonesplinter Bonesnapper - At 15% HP - Flee For Assist");

-- Stonesplinter Geomancer SAI
SET @ENTRY := 1165;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Geomancer - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,15000,15000,11,4979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Geomancer - In Combat - Cast Quick Flame Ward"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonesplinter Geomancer - At 15% HP - Flee For Assist");

-- Stonesplinter Seer SAI
SET @ENTRY := 1166;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Seer - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,1200,2400,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Seer - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonesplinter Seer - At 15% HP - Flee For Assist");

-- Stonesplinter Digger SAI
SET @ENTRY := 1167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Digger - In Combat - Say Line 0"),
(@ENTRY,0,1,0,0,0,85,1,0,0,700,700,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Digger - In Combat - Cast Defensive Stance"),
(@ENTRY,0,2,0,0,0,100,0,4700,7800,9800,16700,11,7386,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Digger - In Combat - Cast Sunder Armor"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonesplinter Digger - At 15% HP - Flee For Assist");

-- Dark Iron Insurgent SAI
SET @ENTRY := 1169;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Insurgent - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,1,0,80,0,0,11,7020,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Insurgent - At 80% HP - Cast Stoneform"),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,7020,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Insurgent - At 40% HP - Cast Stoneform"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Insurgent - At 15% HP - Flee For Assist");

-- Tunnel Rat Vermin SAI
SET @ENTRY := 1172;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Vermin - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tunnel Rat Vermin - At 15% HP - Flee For Assist");

-- Texts for Dark Iron Insurgent
DELETE FROM `creature_text` WHERE `entry`= 1169;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1169,0,0, "Time to die, $C!",12,0,100,0,0,0, "Dark Iron Insurgent"),
(1169,0,1, "Feel the power of the Dark Iron Dwarves!",12,0,100,0,0,0, "Dark Iron Insurgent");

-- Texts for Tunnel Rat Vermin
DELETE FROM `creature_text` WHERE `entry`= 1172;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1172,0,0, "Yip! Me kill!",12,0,100,0,0,0, "Tunnel Rat Vermin"),
(1172,0,1, "Me no run from $C like you!",12,0,100,0,0,0, "Tunnel Rat Vermin");

-- Tunnel Rat Scout SAI
SET @ENTRY := 1173;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tunnel Rat Scout - On Aggro - Cast Shoot"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - On Aggro - Increment Phase"),
(@ENTRY,0,5,6,9,0,100,0,5,30,2300,2700,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tunnel Rat Scout - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,7,0,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - At 15% HP - Increment Phase"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tunnel Rat Scout - At 15% HP - Flee For Assist"),
(@ENTRY,0,15,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - On Evade - Display melee weapon");

-- Tunnel Rat Geomancer SAI
SET @ENTRY := 1174;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Geomancer - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,1,500,1500,8800,8800,11,4979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Geomancer - In Combat - Cast Quick Flame Ward"),
(@ENTRY,0,2,0,0,0,100,0,500,1000,61500,62700,11,134,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Geomancer - In Combat - Cast Fire Shield"),
(@ENTRY,0,3,0,0,0,100,0,1000,3800,9800,14800,11,2136,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tunnel Rat Geomancer - In Combat - Cast Fire Blast"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tunnel Rat Geomancer - At 15% HP - Flee For Assist");

-- Tunnel Rat Digger SAI
SET @ENTRY := 1175;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Digger - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,184100,184100,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Digger - In Combat - Cast Defensive Stance"),
(@ENTRY,0,2,0,0,0,100,0,1200,6900,12100,24300,11,7386,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tunnel Rat Digger - In Combat - Cast Sunder Armor"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tunnel Rat Digger - At 15% HP - Flee For Assist");

-- Tunnel Rat Forager SAI
SET @ENTRY := 1176;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3600,5600,49000,60000,11,7365,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tunnel Rat Forager - In Combat - Cast Bottle of Poison"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tunnel Rat Forager - At 15% HP - Flee For Assist");

-- Tunnel Rat Surveyor SAI
SET @ENTRY := 1177;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Surveyor - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tunnel Rat Surveyor - At 15% HP - Flee For Assist");

-- Texts for Tunnel Rat Scout
DELETE FROM `creature_text` WHERE `entry`= 1173;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1173,0,0, "Yip! Me kill!",12,0,100,0,0,0, "Tunnel Rat Scout"),
(1173,0,1, "Me no run from $C like you!",12,0,100,0,0,0, "Tunnel Rat Scout");

-- Texts for Tunnel Rat Geomancer
DELETE FROM `creature_text` WHERE `entry`= 1174;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1174,0,0, "Yip! Me kill!",12,0,100,0,0,0, "Tunnel Rat Geomancer"),
(1174,0,1, "Me no run from $C like you!",12,0,100,0,0,0, "Tunnel Rat Geomancer");

-- Texts for Tunnel Rat Digger
DELETE FROM `creature_text` WHERE `entry`= 1175;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1175,0,0, "Yip! Me kill!",12,0,100,0,0,0, "Tunnel Rat Digger"),
(1175,0,1, "Me no run from $C like you!",12,0,100,0,0,0, "Tunnel Rat Digger");

-- Texts for Tunnel Rat Surveyor
DELETE FROM `creature_text` WHERE `entry`= 1177;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1177,0,0, "Yip! Me kill!",12,0,100,0,0,0, "Tunnel Rat Surveyor"),
(1177,0,1, "Me no run from $C like you!",12,0,100,0,0,0, "Tunnel Rat Surveyor");

-- Mo'grosh Ogre SAI
SET @ENTRY := 1178;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Ogre - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,85,0,500,6800,20900,25300,11,5164,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mo'grosh Ogre - In Combat - Cast Knockdown");

-- Mo'grosh Enforcer SAI
SET @ENTRY := 1179;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Enforcer - In Combat - Say Line 0"),
(@ENTRY,0,1,2,0,0,100,0,7400,14500,46600,53700,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Enforcer - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Enforcer - In Combat - Play Emote 15");

-- Mo'grosh Brute SAI
SET @ENTRY := 1180;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Brute - In Combat - Say Line 0");

-- Mo'grosh Shaman SAI
SET @ENTRY := 1181;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mo'grosh Shaman - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,5400,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mo'grosh Shaman - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,60,1,1000,2000,0,0,11,3229,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - In Combat - Cast Quick Bloodlust");

-- Mo'grosh Mystic SAI
SET @ENTRY := 1183;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Mystic - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Mystic - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mo'grosh Mystic - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Mystic - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,5400,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mo'grosh Mystic - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Mystic - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Mystic - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Mystic - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Mystic - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Mystic - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Mystic - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,14,0,100,1,0,40,0,0,11,547,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mo'grosh Mystic - On Friendly Unit At 0 - 40% Health - Cast Healing Wave");

-- Texts for Mo'grosh Ogre
DELETE FROM `creature_text` WHERE `entry`= 1178;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1178,0,0, "Me smash! You die!",12,0,100,0,0,0, "Mo\'grosh Ogre"),
(1178,0,1, "I'll crush you!",12,0,100,0,0,0, "Mo\'grosh Ogre");

-- Texts for Mo'grosh Enforcer
DELETE FROM `creature_text` WHERE `entry`= 1179;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1179,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Mo\'grosh Enforcer"),
(1179,0,1, "Me smash! You die!",12,0,100,0,0,0, "Mo\'grosh Enforcer"),
(1179,0,2, "I'll crush you!",12,0,100,0,0,0, "Mo\'grosh Enforcer");

-- Texts for Mo'grosh Brute
DELETE FROM `creature_text` WHERE `entry`= 1180;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1180,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Mo\'grosh Brute"),
(1180,0,1, "Me smash! You die!",12,0,100,0,0,0, "Mo\'grosh Brute"),
(1180,0,2, "I'll crush you!",12,0,100,0,0,0, "Mo\'grosh Brute");

-- Texts for Mo'grosh Shaman
DELETE FROM `creature_text` WHERE `entry`= 1181;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1181,0,0, "Me smash! You die!",12,0,100,0,0,0, "Mo\'grosh Shaman"),
(1181,0,1, "I'll crush you!",12,0,100,0,0,0, "Mo\'grosh Shaman");

-- Texts for Mo'grosh Mystic
DELETE FROM `creature_text` WHERE `entry`= 1183;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1183,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Mo\'grosh Mystic"),
(1183,0,1, "Me smash! You die!",12,0,100,0,0,0, "Mo\'grosh Mystic"),
(1183,0,2, "I'll crush you!",12,0,100,0,0,0, "Mo\'grosh Mystic");

-- Cliff Lurker SAI
SET @ENTRY := 1184;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,17100,23000,39000,43300,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Cliff Lurker - In Combat - Cast Poison");

-- Wood Lurker SAI
SET @ENTRY := 1185;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,20500,25300,48600,53800,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Wood Lurker - In Combat - Cast Poison");

-- Mountain Boar SAI
SET @ENTRY := 1190;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mountain Boar - On Aggro - Cast Rushing Charge");

-- Mangy Mountain Boar SAI
SET @ENTRY := 1191;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mangy Mountain Boar - On Aggro - Cast Rushing Charge");

-- Elder Mountain Boar SAI
SET @ENTRY := 1192;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Mountain Boar - On Aggro - Cast Rushing Charge");

-- Mountain Buzzard SAI
SET @ENTRY := 1194;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,7000,14400,35000,42000,11,8014,32,0,0,0,0,2,0,0,0,0,0,0,0,"Mountain Buzzard - In Combat - Cast Tetanus");

-- Forest Lurker SAI
SET @ENTRY := 1195;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,21300,25300,48600,53800,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Forest Lurker - In Combat - Cast Poison");

-- Stonesplinter Shaman SAI
SET @ENTRY := 1197;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Shaman - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,14,0,100,0,0,20,17600,35700,11,547,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stonesplinter Shaman - On Friendly Unit At 0 - 20% Health - Cast Healing Wave"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonesplinter Shaman - At 15% HP - Flee For Assist");

-- Texts for Stonesplinter Shaman
DELETE FROM `creature_text` WHERE `entry`= 1197;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1197,0,0, "Destroy!",12,0,100,0,0,0, "Stonesplinter Shaman"),
(1197,0,1, "Kill!",12,0,100,0,0,0, "Stonesplinter Shaman"),
(1197,0,2, "Crush!",12,0,100,0,0,0, "Stonesplinter Shaman");

-- Tunnel Rat Kobold SAI
SET @ENTRY := 1202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Kobold - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,6700,12100,25300,34400,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Kobold - In Combat - Cast Thrash"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tunnel Rat Kobold - At 15% HP - Flee For Assist"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Kobold - On Aggro - Say Line 2");

-- Texts for Tunnel Rat Kobold
DELETE FROM `creature_text` WHERE `entry`= 1202;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1202,0,0, "Yip! Me kill!",12,0,100,0,0,0, "Tunnel Rat Kobold"),
(1202,0,1, "Me no run from $C like you!",12,0,100,0,0,0, "Tunnel Rat Kobold"),
(1202,2,0, "Weak $C! You are no match for the Stonesplinter Tribe!",12,0,100,0,0,0, "Tunnel Rat Kobold"),
(1202,2,1, "The only good $R is a dead $R!",12,0,100,0,0,0, "Tunnel Rat Kobold");

-- Grawmug SAI
SET @ENTRY := 1205;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3600,5500,8800,12400,11,3229,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grawmug - In Combat - Cast Quick Bloodlust"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Grawmug - At 15% HP - Flee For Assist");

-- Gnasher SAI
SET @ENTRY := 1206;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,0,0,8800,8800,11,3393,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gnasher - In Combat - Cast Consume Flesh"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gnasher - At 15% HP - Flee For Assist");

-- Brawler SAI
SET @ENTRY := 1207;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,700,3600,6500,10800,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brawler - In Combat - Cast Backhand"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Brawler - At 15% HP - Flee For Assist");

-- Chok'sul SAI
SET @ENTRY := 1210;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chok'sul - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,4300,13200,10300,23000,11,18072,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chok'sul - In Combat - Cast Uppercut");

-- Texts for Chok'sul
DELETE FROM `creature_text` WHERE `entry`= 1210;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1210,0,0, "Bash it!",12,0,100,0,0,0, "Chok\'sul"),
(1210,0,1, "Dat $R look gud to eat!",12,0,100,0,0,0, "Chok\'sul"),
(1210,0,2, "Huh? What dat?",12,0,100,0,0,0, "Chok\'sul");

-- Berserk Trogg SAI
SET @ENTRY := 1393;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Berserk Trogg - On Aggro - Say Line 0"),
(@ENTRY,0,1,2,2,0,100,0,0,40,0,0,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Berserk Trogg - At 40% HP - Cast Frenzy"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Berserk Trogg - At 40% HP - Say Line 1");

-- Boss Galgosh SAI
SET @ENTRY := 1398;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boss Galgosh - On Aggro - Say Line 0"),
(@ENTRY,0,1,2,0,0,100,0,5600,15500,18400,33800,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boss Galgosh - In Combat - Cast Frenzy"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boss Galgosh - In Combat - Say Line 1"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Boss Galgosh - At 15% HP - Flee For Assist");

-- Texts for Berserk Trogg
DELETE FROM `creature_text` WHERE `entry`= 1393;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1393,0,0, "Destroy!",12,0,100,0,0,0, "Berserk Trogg"),
(1393,0,1, "Kill!",12,0,100,0,0,0, "Berserk Trogg"),
(1393,0,2, "Crush!",12,0,100,0,0,0, "Berserk Trogg"),
(1393,1,0, "%s becomes enraged!",16,0,100,0,0,0, "Berserk Trogg");

-- Texts for Boss Galgosh
DELETE FROM `creature_text` WHERE `entry`= 1398;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1398,0,0, "A $C called $N? You'll make a fine breakfast!",12,0,100,0,0,0, "Boss Galgosh"),
(1398,0,1, "Weak $C! You are no match for the Stonesplinter Tribe!",12,0,100,0,0,0, "Boss Galgosh"),
(1398,0,2, "The only good $R is a dead $R!",12,0,100,0,0,0, "Boss Galgosh"),
(1398,1,0, "%s becomes enraged!",16,0,100,0,0,0, "Boss Galgosh");

-- Magosh SAI
SET @ENTRY := 1399;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magosh - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magosh - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magosh - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magosh - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,1200,3400,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magosh - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magosh - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magosh - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magosh - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magosh - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magosh - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magosh - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,14,0,100,0,0,40,26700,26700,11,913,1,0,0,0,0,7,0,0,0,0,0,0,0,"Magosh - On Friendly Unit At 0 - 40% Health - Cast Healing Wave"),
(@ENTRY,0,12,0,0,0,100,0,1000,3200,20300,35000,11,2606,1,0,0,0,0,2,0,0,0,0,0,0,0,"Magosh - In Combat - Cast Shock");

-- Texts for Magosh
DELETE FROM `creature_text` WHERE `entry`= 1399;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1399,0,0, "The Loch belongs to the Stonesplinter Tribe now, $N! Now die!",12,0,100,0,0,0, "Magosh"),
(1399,0,1, "Die $R! These lands belong to the Stonesplinter Tribe!",12,0,100,0,0,0, "Magosh"),
(1399,0,2, "Weak $C! You are no match for the Stonesplinter Tribe!",12,0,100,0,0,0, "Magosh");

-- Grizlak SAI
SET @ENTRY := 1425;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,0,40,20100,28100,11,6074,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grizlak - On Friendly Unit At 0 - 40% Health - Cast Renew"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Grizlak - At 15% HP - Flee For Assist");

-- Ram SAI
SET @ENTRY := 2098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,99,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ram - At 99% HP - Flee For Assist");

-- Dark Iron Raider SAI
SET @ENTRY := 2149;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Raider - On Aggro - Say Line 0");

-- Texts for Dark Iron Raider
DELETE FROM `creature_text` WHERE `entry`= 2149;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2149,0,0, "[Dwarvish] Dum mos",12,0,100,0,0,0, "Dark Iron Raider");

-- Large Loch Crocolisk SAI
SET @ENTRY := 2476;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,1,4100,13900,32200,46200,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Large Loch Crocolisk - In Combat - Cast Infected Wound");

-- Emogg the Crusher SAI
SET @ENTRY := 14267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,80,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emogg the Crusher - On Aggro - Say Line 0");

-- Texts for Emogg the Crusher
DELETE FROM `creature_text` WHERE `entry`= 14267;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(14267,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Emogg the Crusher"),
(14267,0,1, "Me smash! You die!",12,0,100,0,0,0, "Emogg the Crusher"),
(14267,0,2, "I'll crush you!",12,0,100,0,0,0, "Emogg the Crusher");

-- Gath'Ilzogg SAI
SET @ENTRY := 334;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1300,6500,194300,194300,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gath'Ilzogg - In Combat - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,0,2000,12900,32100,39400,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Gath'Ilzogg - In Combat - Cast Infected Wound"),
(@ENTRY,0,2,0,0,0,100,0,2500,2500,5200,12100,11,11792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gath'Ilzogg - In Combat - Cast Opening Cage");

-- Singe SAI
SET @ENTRY := 335;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Singe - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Singe - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Singe - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3500,5200,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Singe - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Singe - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Singe - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Singe - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Singe - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Singe - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Singe - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,4100,9200,19700,21300,11,12468,0,0,0,0,0,2,0,0,0,0,0,0,0,"Singe - In Combat - Cast Flamestrike");

-- Bellygrub SAI
SET @ENTRY := 345;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3200,11900,11500,16100,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bellygrub - In Combat - Cast Trample"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bellygrub - On Aggro - Cast Rushing Charge");

-- Morganth SAI
SET @ENTRY := 397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - Out Of Combat - Cast Demon Armor"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morganth - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,1700,3800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morganth - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,50,0,0,11,3611,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - At 50% HP - Cast Minion of Morganth");

-- Murloc Flesheater SAI
SET @ENTRY := 422;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,12000,25700,30700,11,3393,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Flesheater - In Combat - Cast Consume Flesh"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murloc Flesheater - At 15% HP - Flee For Assist");

-- Dire Condor SAI
SET @ENTRY := 428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1900,12100,7900,16100,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dire Condor - In Combat - Cast Swoop");

-- Shadowhide Slayer SAI
SET @ENTRY := 431;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,12,0,100,1,0,20,0,0,11,7160,1,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowhide Slayer - On Target At 0 - 20% HP - Cast Execute"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowhide Slayer - At 15% HP - Flee For Assist");

-- Blackrock Champion SAI
SET @ENTRY := 435;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Champion - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,1,1400,5900,0,0,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Champion - In Combat - Cast Devotion Aura"),
(@ENTRY,0,2,3,0,0,100,0,5800,10100,15400,18700,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Champion - In Combat - Cast Frenzy"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Champion - In Combat - Say Line 1"),
(@ENTRY,0,4,5,0,0,100,0,4700,13800,30500,30500,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Champion - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Champion - In Combat - Say Line 1"),
(@ENTRY,0,6,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackrock Champion - At 15% HP - Flee For Assist");

-- Blackrock Shadowcaster SAI
SET @ENTRY := 436;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - Out Of Combat - Cast Demon Armor"),
(@ENTRY,0,2,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Shadowcaster - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,0,0,40,500,3200,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Shadowcaster - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,6,7,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - At 15% Mana - Increment Phase"),
(@ENTRY,0,8,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,0,0,100,0,3700,4500,8400,28100,11,11639,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blackrock Shadowcaster - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,13,14,0,0,100,0,11600,18600,37600,47300,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - In Combat - Cast Frenzy"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - In Combat - Say Line 1"),
(@ENTRY,0,15,0,0,0,75,0,24100,24100,44500,44500,11,8994,0,0,0,0,0,6,0,0,0,0,0,0,0,"Blackrock Shadowcaster - In Combat - Cast Banish"),
(@ENTRY,0,16,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - At 15% HP - Set Phase 3"),
(@ENTRY,0,17,18,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackrock Shadowcaster - At 15% HP - Flee For Assist");

-- Blackrock Renegade SAI
SET @ENTRY := 437;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Renegade - On Aggro - Say Line 0"),
(@ENTRY,0,1,2,0,0,100,0,9600,11100,18100,37600,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Renegade - In Combat - Cast Frenzy"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Renegade - In Combat - Say Line 1"),
(@ENTRY,0,3,0,0,0,100,0,6500,10000,20900,30300,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Renegade - In Combat - Cast Shield Slam"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackrock Renegade - At 15% HP - Flee For Assist");

-- Blackrock Grunt SAI
SET @ENTRY := 440;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Grunt - On Aggro - Say Line 0"),
(@ENTRY,0,1,2,0,0,100,0,9600,14000,18100,37600,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Grunt - In Combat - Cast Frenzy"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Grunt - In Combat - Say Line 1"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackrock Grunt - At 15% HP - Flee For Assist");

-- Texts for Blackrock Champion
DELETE FROM `creature_text` WHERE `entry`= 435;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(435,0,0, "[Orcish] Tago mog regas gi mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Champion"),
(435,0,1, "[Orcish] Ogg kaz ko zugas kil mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Champion"),
(435,1,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Champion"),
(435,2,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Champion");

-- Texts for Blackrock Shadowcaster
DELETE FROM `creature_text` WHERE `entry`= 436;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(436,0,0, "[Orcish] Tago mog regas gi mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Shadowcaster"),
(436,0,1, "[Orcish] Ogg kaz ko zugas kil mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Shadowcaster"),
(436,1,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Shadowcaster");

-- Texts for Blackrock Renegade
DELETE FROM `creature_text` WHERE `entry`= 437;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(437,0,0, "[Orcish] Tago mog regas gi mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Renegade"),
(437,0,1, "[Orcish] Ogg kaz ko zugas kil mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Renegade"),
(437,1,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Renegade");

-- Texts for Blackrock Grunt
DELETE FROM `creature_text` WHERE `entry`= 440;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(440,0,0, "[Orcish] Tago mog regas gi mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Grunt"),
(440,0,1, "[Orcish] Ogg kaz ko zugas kil mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Grunt"),
(440,1,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Grunt");

-- Black Dragon Whelp SAI
SET @ENTRY := 441;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Dragon Whelp - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Dragon Whelp - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Dragon Whelp - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,600,3200,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Dragon Whelp - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Dragon Whelp - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Dragon Whelp - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Dragon Whelp - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Dragon Whelp - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Dragon Whelp - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Black Dragon Whelp - At 100% Mana - Increment Phase");

-- Tarantula SAI
SET @ENTRY := 442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2200,7400,30200,34100,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Tarantula - In Combat - Cast Poison");

-- Blackrock Outrunner SAI
SET @ENTRY := 485;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Outrunner - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,8000,18000,20800,40500,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Outrunner - In Combat - Cast Net"),
(@ENTRY,0,2,3,0,0,100,0,9800,9800,23100,35800,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Outrunner - In Combat - Cast Frenzy"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Outrunner - In Combat - Say Line 1"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackrock Outrunner - At 15% HP - Flee For Assist");

-- Tharil'zun SAI
SET @ENTRY := 486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,16300,250000,255000,11,3631,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tharil'zun - In Combat - Cast Battle Fury"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,24600,46600,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tharil'zun - In Combat - Cast Net"),
(@ENTRY,0,2,3,0,0,100,0,5000,14600,16100,32300,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tharil'zun - In Combat - Cast Frenzy"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tharil'zun - In Combat - Say Line 0"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tharil'zun - At 15% HP - Flee For Assist");

-- Texts for Blackrock Outrunner
DELETE FROM `creature_text` WHERE `entry`= 485;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(485,0,0, "[Orcish] Tago mog regas gi mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Outrunner"),
(485,0,1, "[Orcish] Ogg kaz ko zugas kil mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Outrunner"),
(485,1,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Outrunner");

-- Texts for Tharil'zun
DELETE FROM `creature_text` WHERE `entry`= 486;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(486,0,0, "%s becomes enraged!",16,0,100,0,0,0, "Tharil\'zun");

-- Greater Tarantula SAI
SET @ENTRY := 505;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,13500,10000,18100,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Tarantula - In Combat - Cast Poison");

-- Yowler SAI
SET @ENTRY := 518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Yowler - At 15% HP - Flee For Assist");

-- Murloc Nightcrawler SAI
SET @ENTRY := 544;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8500,8500,44600,47800,11,7992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Nightcrawler - In Combat - Cast Slowing Poison");

-- Murloc Tidecaller SAI
SET @ENTRY := 545;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6200,12600,25000,30000,11,122,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Tidecaller - In Combat - Cast Frost Nova"),
(@ENTRY,0,1,0,14,0,100,0,0,40,24100,25500,11,913,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murloc Tidecaller - On Friendly Unit At 0 - 40% Health - Cast Healing Wave"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murloc Tidecaller - At 15% HP - Flee For Assist");

-- Great Goretusk SAI
SET @ENTRY := 547;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,80,1,0,0,0,0,11,6268,1,0,0,0,0,1,0,0,0,0,0,0,0,"Great Goretusk - On Aggro - Cast Rushing Charge");

-- Murloc Minor Tidecaller SAI
SET @ENTRY := 548;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - On Aggro - Cast Frostbolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3500,6400,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,14,0,100,0,0,40,31800,82800,11,547,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - On Friendly Unit At 0 - 40% Health - Cast Healing Wave"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - At 15% HP - Flee For Assist");

-- Murloc Scout SAI
SET @ENTRY := 578;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Scout - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2600,3700,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Scout - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,0,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,8,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,8,9,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,10,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - At 15% HP - Increment Phase"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murloc Scout - At 15% HP - Flee For Assist"),
(@ENTRY,0,14,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - On Evade - Display melee weapon");

-- Shadowhide Assassin SAI
SET @ENTRY := 579;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Assassin - Out Of Combat - Cast Stealth"),
(@ENTRY,0,1,0,0,0,100,0,3700,3700,3600,12400,11,2590,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowhide Assassin - In Combat - Cast Backstab"),
(@ENTRY,0,2,0,0,0,100,0,16900,29700,31300,34500,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowhide Assassin - In Combat - Cast Poison"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowhide Assassin - At 15% HP - Flee For Assist");

-- Kazon SAI
SET @ENTRY := 584;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,3500,11900,27500,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kazon - In Combat - Cast Backhand"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kazon - At 15% HP - Flee For Assist");

-- Blackrock Tracker SAI
SET @ENTRY := 615;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Tracker - On Aggro - Say Line 0"),
(@ENTRY,0,1,2,0,0,100,0,7300,17300,16300,29300,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Tracker - In Combat - Cast Frenzy"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Tracker - In Combat - Say Line 1"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackrock Tracker - At 15% HP - Flee For Assist");

-- Texts for Blackrock Tracker
DELETE FROM `creature_text` WHERE `entry`= 615;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(615,0,0, "[Orcish] Tago mog regas gi mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Tracker"),
(615,0,1, "[Orcish] Ogg kaz ko zugas kil mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Tracker"),
(615,1,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Tracker");

-- Chatter SAI
SET @ENTRY := 616;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2200,7400,30200,34100,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Chatter - In Combat - Cast Poison"),
(@ENTRY,0,1,0,0,0,100,0,8200,12500,16600,21900,11,3609,32,0,0,0,0,2,0,0,0,0,0,0,0,"Chatter - In Combat - Cast Paralyzing Poison");

-- Lieutenant Fangore SAI
SET @ENTRY := 703;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lieutenant Fangore - At 15% HP - Flee For Assist");

-- Redridge Thrasher SAI
SET @ENTRY := 712;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Redridge Thrasher - At 15% HP - Flee For Assist");

-- Servant of Ilgalar SAI
SET @ENTRY := 819;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,600,8800,27300,37300,11,8129,0,0,0,0,0,5,0,0,0,0,0,0,0,"Servant of Ilgalar - In Combat - Cast Mana Burn");

-- Rohh the Silent SAI
SET @ENTRY := 947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rohh the Silent - Out Of Combat - Cast Stealth"),
(@ENTRY,0,1,0,0,0,100,0,2200,7400,30200,34100,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Rohh the Silent - In Combat - Cast Poison");

-- Murloc Shorestriker SAI
SET @ENTRY := 1083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Shorestriker - On Aggro - Cast Rushing Charge"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murloc Shorestriker - At 15% HP - Flee For Assist");

-- Blackrock Scout SAI
SET @ENTRY := 4064;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Scout - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Scout - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,14,0,0,100,0,1400,4300,16900,25300,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - In Combat - Cast Frenzy"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - In Combat - Say Line 0"),
(@ENTRY,0,15,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - At 15% HP - Increment Phase"),
(@ENTRY,0,16,17,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackrock Scout - At 15% HP - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - On Evade - Display melee weapon");

-- Blackrock Sentry SAI
SET @ENTRY := 4065;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Sentry - On Aggro - Say Line 0"),
(@ENTRY,0,1,2,0,0,100,0,4400,14800,15900,23400,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Sentry - In Combat - Cast Frenzy"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Sentry - In Combat - Say Line 1"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackrock Sentry - At 15% HP - Flee For Assist");

-- Texts for Blackrock Scout
DELETE FROM `creature_text` WHERE `entry`= 4064;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(4064,0,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Scout");

-- Texts for Blackrock Sentry
DELETE FROM `creature_text` WHERE `entry`= 4065;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(4065,0,0, "[Orcish] Tago mog regas gi mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Sentry"),
(4065,0,1, "[Orcish] Ogg kaz ko zugas kil mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Sentry"),
(4065,1,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Sentry");

-- Blackrock Hunter SAI
SET @ENTRY := 4462;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Hunter - On Aggro - Cast Throw"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - On Aggro - Increment Phase"),
(@ENTRY,0,5,6,9,0,100,0,5,30,2200,3800,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Hunter - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,7,8,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,9,10,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,11,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,14,15,0,0,100,0,6400,31400,19700,34400,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - In Combat - Cast Frenzy"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - In Combat - Say Line 1"),
(@ENTRY,0,16,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - At 15% HP - Increment Phase"),
(@ENTRY,0,17,18,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackrock Hunter - At 15% HP - Flee For Assist"),
(@ENTRY,0,19,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Hunter - On Evade - Display melee weapon");

-- Blackrock Summoner SAI
SET @ENTRY := 4463;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - Out Of Combat - Cast Summon Imp"),
(@ENTRY,0,2,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Summoner - On Aggro - Cast Fireball"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,0,0,40,3400,6000,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Summoner - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,6,7,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - At 15% Mana - Increment Phase"),
(@ENTRY,0,8,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,0,0,100,0,300,6400,18100,38800,11,184,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - In Combat - Cast Fire Shield II"),
(@ENTRY,0,13,14,0,0,100,0,6400,31400,39100,68100,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - In Combat - Cast Frenzy"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - In Combat - Say Line 1"),
(@ENTRY,0,15,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - At 15% HP - Set Phase 3"),
(@ENTRY,0,16,17,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Summoner - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackrock Summoner - At 15% HP - Flee For Assist");

-- Blackrock Gladiator SAI
SET @ENTRY := 4464;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Gladiator - On Aggro - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,122000,130000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Gladiator - In Combat - Cast Battle Shout"),
(@ENTRY,0,2,0,0,0,100,1,3700,6400,18100,22800,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Gladiator - In Combat - Cast Disarm"),
(@ENTRY,0,3,4,0,0,100,0,4400,14800,15900,23400,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Gladiator - In Combat - Cast Frenzy"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Gladiator - In Combat - Say Line 0"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackrock Gladiator - At 15% HP - Flee For Assist");

-- Texts for Blackrock Hunter
DELETE FROM `creature_text` WHERE `entry`= 4462;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(4462,0,0, "[Orcish] Tago mog regas gi mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Hunter"),
(4462,0,1, "[Orcish] Ogg kaz ko zugas kil mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Hunter"),
(4462,1,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Hunter");

-- Texts for Blackrock Summoner
DELETE FROM `creature_text` WHERE `entry`= 4463;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(4463,0,0, "[Orcish] Tago mog regas gi mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Summoner"),
(4463,0,1, "[Orcish] Ogg kaz ko zugas kil mog Tov'nokaz Kagg",12,0,100,0,0,0, "Blackrock Summoner"),
(4463,1,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Summoner");

-- Texts for Blackrock Gladiator
DELETE FROM `creature_text` WHERE `entry`= 4464;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(4464,0,0, "%s becomes enraged!",16,0,100,0,0,0, "Blackrock Gladiator");

-- Squiddic SAI
SET @ENTRY := 14270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Squiddic - At 15% HP - Flee For Assist");

-- Ribchaser SAI
SET @ENTRY := 14271;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ribchaser - At 15% HP - Flee For Assist");

-- Dark Iron Geologist SAI
SET @ENTRY := 5839;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Geologist - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Geologist - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Geologist - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,2800,3600,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Geologist - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Geologist - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Geologist - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Geologist - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Geologist - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Geologist - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Geologist - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,0,5,30,5000,12000,11,8858,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Geologist - At 5 - 30 Range - Cast Bomb"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Geologist - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Geologist - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Geologist - At 15% HP - Flee For Assist");

-- Dark Iron Steamsmith SAI
SET @ENTRY := 5840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,7000,12000,15000,11,11983,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Steamsmith - In Combat - Cast Steam Jet");

-- Dark Iron Slaver SAI
SET @ENTRY := 5844;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,8000,14000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Slaver - In Combat - Cast Net"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,15000,20000,11,11977,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Slaver - In Combat - Cast Rend");

-- Dark Iron Taskmaster SAI
SET @ENTRY := 5846;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,10000,15000,11,5115,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Taskmaster - In Combat - Cast Battle Command"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,12613,3,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Taskmaster - On Death - Cast Dark Iron Taskmaster Death");

-- Dark Iron Lookout SAI
SET @ENTRY := 8566;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Lookout - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,1200,2400,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Lookout - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - At 15% HP - Increment Phase"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Lookout - At 15% HP - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - On Evade - Display melee weapon");

-- Dark Iron Watchman SAI
SET @ENTRY := 8637;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,5000,6000,11,11976,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Watchman - In Combat - Cast Strike");

-- Overmaster Pyron SAI
SET @ENTRY := 9026;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,10000,10000,15000,11,12470,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overmaster Pyron - In Combat - Cast Fire Nova"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,8000,12000,11,13341,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overmaster Pyron - In Combat - Cast Fire Blast");

-- Vile Fin Shredder SAI
SET @ENTRY := 1767;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,2500,2500,30000,35000,11,3252,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Shredder - In Combat - Cast Shred");

-- Vile Fin Tidehunter SAI
SET @ENTRY := 1768;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,2500,2500,5000,7500,11,12748,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidehunter - In Combat - Cast Frost Nova"),
(@ENTRY,0,1,0,1,0,85,1,0,0,1000,1000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidehunter - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,2,0,14,0,85,0,0,80,14000,14000,11,4980,1,0,0,0,0,7,0,0,0,0,0,0,0,"Vile Fin Tidehunter - On Friendly Unit At 0 - 80% Health - Cast Quick Frost Ward");

-- Rot Hide Gladerunner SAI
SET @ENTRY := 1772;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,1,0,0,2500,2500,11,3237,0,0,0,0,0,5,0,0,0,0,0,0,0,"Rot Hide Gladerunner - In Combat - Cast Curse of Thule");

-- Rot Hide Mystic SAI
SET @ENTRY := 1773;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,85,0,0,80,5000,5000,11,332,0,0,0,0,0,7,0,0,0,0,0,0,0,"Rot Hide Mystic - On Friendly Unit At 0 - 80% Health - Cast Healing Wave"),
(@ENTRY,0,1,0,0,0,40,1,0,0,2500,2500,11,3237,1,0,0,0,0,5,0,0,0,0,0,0,0,"Rot Hide Mystic - In Combat - Cast Curse of Thule");

-- Mist Creeper SAI
SET @ENTRY := 1781;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,13000,30000,35000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Mist Creeper - In Combat - Cast Poison");

-- Ravenclaw Raider SAI
SET @ENTRY := 1865;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,1,0,0,2000,2000,11,5271,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravenclaw Raider - In Combat - Cast Cursed Blade");

-- Ravenclaw Slave SAI
SET @ENTRY := 1866;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,3000,3000,6000,9000,11,7761,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ravenclaw Slave - In Combat - Cast Shared Bondage");

-- Dalaran Apprentice SAI
SET @ENTRY := 1867;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,13322,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Apprentice - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,2400,3800,11,13322,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Apprentice - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dalaran Apprentice - At 15% HP - Flee For Assist");

-- Ravenclaw Servant SAI
SET @ENTRY := 1868;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,85,0,0,65,22000,22000,11,7290,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ravenclaw Servant - At 65% HP - Cast Soul Siphon"),
(@ENTRY,0,1,0,0,0,85,0,4000,4000,24000,28000,11,980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravenclaw Servant - In Combat - Cast Curse of Agony"),
(@ENTRY,0,2,0,9,0,100,0,4,30,1,1,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravenclaw Servant - At 4 - 30 Range - Set Ranged Movement"),
(@ENTRY,0,3,0,9,0,100,0,0,4,1,1,79,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravenclaw Servant - At 0 - 4 Range - Set Ranged Movement"),
(@ENTRY,0,4,0,11,0,100,1,0,0,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravenclaw Servant - On Respawn - Set Ranged Movement");

-- Hand of Ravenclaw SAI
SET @ENTRY := 1870;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,2500,2500,10000,12500,11,3263,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hand of Ravenclaw - In Combat - Cast Touch of Ravenclaw");

-- Dalaran Watcher SAI
SET @ENTRY := 1888;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,1000,1000,0,0,11,134,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Watcher - In Combat - Cast Fire Shield"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,5000,9000,11,11829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Watcher - In Combat - Cast Flamestrike");

-- Dalaran Wizard SAI
SET @ENTRY := 1889;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Wizard - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,5400,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Wizard - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,6000,9000,9000,14000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - In Combat - Cast Frost Nova"),
(@ENTRY,0,12,0,0,0,100,1,3000,5000,14000,20000,11,4980,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - In Combat - Cast Quick Frost Ward"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - At 15% HP - Set Phase 3"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dalaran Wizard - At 15% HP - Flee For Assist");

-- Vile Fin Oracle SAI
SET @ENTRY := 1908;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,1000,1000,6000,9000,11,2606,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Oracle - In Combat - Cast Shock"),
(@ENTRY,0,1,0,9,0,100,0,2,20,1,1,19,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Oracle - At 2 - 20 Range - Remove unit_flag 15"),
(@ENTRY,0,2,0,9,0,100,0,0,2,1,1,19,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Oracle - At 0 - 2 Range - Remove unit_flag 0"),
(@ENTRY,0,3,0,11,0,100,1,0,0,0,0,19,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Oracle - On Respawn - Remove unit_flag 15");

-- Vile Fin Lakestalker SAI
SET @ENTRY := 1909;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,2500,2500,30000,40000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Lakestalker - In Combat - Cast Healing Ward"),
(@ENTRY,0,1,0,1,0,85,1,0,0,5000,5000,11,5605,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Lakestalker - Out Of Combat - Cast Healing Ward");

-- Dalaran Protector SAI
SET @ENTRY := 1912;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,0,0,3000,3000,11,3615,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Protector - In Combat - Cast Summon Dalaran Serpent");

-- Dalaran Warder SAI
SET @ENTRY := 1913;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,1000,1000,0,0,11,3615,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Warder - In Combat - Cast Summon Dalaran Serpent");

-- Dalaran Mage SAI
SET @ENTRY := 1914;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Mage - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,2400,3800,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Mage - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,1,8000,14000,0,0,11,134,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - In Combat - Cast Fire Shield"),
(@ENTRY,0,11,0,0,0,100,1,4000,7000,20000,30000,11,4979,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - In Combat - Cast Quick Flame Ward"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dalaran Mage - At 15% HP - Flee For Assist");

-- Dalaran Conjuror SAI
SET @ENTRY := 1915;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,20798,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - Out Of Combat - Cast Demon Skin"),
(@ENTRY,0,2,0,1,0,100,1,2000,2000,0,0,11,25112,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - Out Of Combat - Cast Summon Voidwalker"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Conjuror - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,0,0,40,2400,3800,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Conjuror - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,6,7,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - At 15% Mana - Increment Phase"),
(@ENTRY,0,8,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dalaran Conjuror - At 15% HP - Flee For Assist");

-- Dalaran Spellscribe SAI
SET @ENTRY := 1920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Spellscribe - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,2800,3600,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Spellscribe - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dalaran Spellscribe - At 15% HP - Flee For Assist");

-- Rot Hide Brute SAI
SET @ENTRY := 1939;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,3000,3000,6000,9000,11,11971,0,0,0,0,0,5,0,0,0,0,0,0,0,"Rot Hide Brute - In Combat - Cast Sunder Armor"),
(@ENTRY,0,1,0,0,0,40,1,0,0,2500,2500,11,3237,1,0,0,0,0,5,0,0,0,0,0,0,0,"Rot Hide Brute - In Combat - Cast Curse of Thule");

-- Rot Hide Plague Weaver SAI
SET @ENTRY := 1940;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,5000,5000,20000,40000,11,3256,32,0,0,0,0,5,0,0,0,0,0,0,0,"Rot Hide Plague Weaver - In Combat - Cast Plague Cloud"),
(@ENTRY,0,1,0,0,0,40,1,0,0,2500,2500,11,3237,0,0,0,0,0,5,0,0,0,0,0,0,0,"Rot Hide Plague Weaver - In Combat - Cast Curse of Thule"),
(@ENTRY,0,2,0,9,0,100,0,4,30,1,1,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Plague Weaver - At 4 - 30 Range - Set Ranged Movement"),
(@ENTRY,0,3,0,9,0,100,0,0,4,1,1,79,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Plague Weaver - At 0 - 4 Range - Set Ranged Movement"),
(@ENTRY,0,4,0,11,0,100,1,0,0,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Plague Weaver - On Respawn - Set Ranged Movement");

-- Rot Hide Savage SAI
SET @ENTRY := 1942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,2000,2000,4000,6000,11,3258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Savage - In Combat - Cast Savage Rage"),
(@ENTRY,0,1,0,0,0,40,1,0,0,2500,2500,11,3237,1,0,0,0,0,5,0,0,0,0,0,0,0,"Rot Hide Savage - In Combat - Cast Curse of Thule");

-- Raging Rot Hide SAI
SET @ENTRY := 1943;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,1,0,0,2500,2500,11,3237,0,0,0,0,0,5,0,0,0,0,0,0,0,"Raging Rot Hide - In Combat - Cast Curse of Thule");

-- Rot Hide Bruiser SAI
SET @ENTRY := 1944;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Rot Hide Bruiser - At 15% HP - Flee For Assist");

-- Thule Ravenclaw SAI
SET @ENTRY := 1947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,5000,5000,20000,30000,11,7655,1,0,0,0,0,5,0,0,0,0,0,0,0,"Thule Ravenclaw - In Combat - Cast Hex of Ravenclaw"),
(@ENTRY,0,1,0,0,0,85,0,1000,1000,7000,12000,11,20800,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thule Ravenclaw - In Combat - Cast Immolate"),
(@ENTRY,0,2,0,1,0,100,1,0,0,1000,1000,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thule Ravenclaw - Out Of Combat - Cast Summon Imp"),
(@ENTRY,0,3,0,4,0,85,1,0,0,0,0,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thule Ravenclaw - On Aggro - Cast Demon Armor"),
(@ENTRY,0,4,0,9,0,100,0,4,30,1,1,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thule Ravenclaw - At 4 - 30 Range - Set Ranged Movement"),
(@ENTRY,0,5,0,9,0,100,0,0,4,1,1,79,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thule Ravenclaw - At 0 - 4 Range - Set Ranged Movement"),
(@ENTRY,0,6,0,11,0,100,1,0,0,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thule Ravenclaw - On Respawn - Set Ranged Movement");

-- Snarlmane SAI
SET @ENTRY := 1948;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,2500,2500,60000,60000,11,3387,0,0,0,0,0,5,0,0,0,0,0,0,0,"Snarlmane - In Combat - Cast Rage of Thule");

-- Lake Skulker SAI
SET @ENTRY := 1953;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,1,0,0,5000,5000,11,6866,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lake Skulker - In Combat - Cast Moss Covered Hands");

-- Elder Lake Skulker SAI
SET @ENTRY := 1954;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,1,0,0,5000,5000,11,6866,1,0,0,0,0,5,0,0,0,0,0,0,0,"Elder Lake Skulker - In Combat - Cast Moss Covered Hands"),
(@ENTRY,0,1,0,2,0,85,0,0,65,22000,22000,11,9616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Lake Skulker - At 65% HP - Cast Wild Regeneration");

-- Lake Creeper SAI
SET @ENTRY := 1955;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,1,0,0,5000,5000,11,6870,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lake Creeper - In Combat - Cast Moss Covered Feet");

-- Elder Lake Creeper SAI
SET @ENTRY := 1956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,1,0,0,5000,5000,11,6870,1,0,0,0,0,5,0,0,0,0,0,0,0,"Elder Lake Creeper - In Combat - Cast Moss Covered Feet"),
(@ENTRY,0,1,0,0,0,85,0,2500,2500,15000,17500,11,11922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Lake Creeper - In Combat - Cast Entangling Roots");

-- Vile Fin Shorecreeper SAI
SET @ENTRY := 1957;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,2500,2500,10000,12500,11,1776,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Shorecreeper - In Combat - Cast Gouge"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,6000,12000,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Shorecreeper - In Combat - Cast Backstab");

-- Vile Fin Tidecaller SAI
SET @ENTRY := 1958;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,2500,2500,5000,7500,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidecaller - In Combat - Cast Frost Nova");

-- Ravenclaw Guardian SAI
SET @ENTRY := 1973;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,3000,3000,6000,9000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravenclaw Guardian - In Combat - Cast Improved Blocking");

-- Ravenclaw Drudger SAI
SET @ENTRY := 1974;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,85,1,0,40,0,0,11,3269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravenclaw Drudger - At 40% HP - Cast Blessing of Thule");

-- Nightlash SAI
SET @ENTRY := 1983;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,9000,21000,25000,11,3485,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightlash - In Combat - Cast Wail of Nightlash"),
(@ENTRY,0,1,0,14,0,100,1,0,30,0,0,11,3477,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nightlash - On Friendly Unit At 0 - 30% Health - Cast Spirit Steal");

-- Archmage Ataeric SAI
SET @ENTRY := 2120;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ataeric - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Ataeric - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ataeric - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,1500,3000,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Ataeric - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ataeric - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ataeric - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ataeric - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ataeric - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ataeric - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ataeric - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,11000,16000,28000,38000,11,512,0,0,0,0,0,5,0,0,0,0,0,0,0,"Archmage Ataeric - In Combat - Cast Chains of Ice"),
(@ENTRY,0,11,0,0,0,100,0,4000,9000,35000,45000,11,118,1,0,0,0,0,6,0,0,0,0,0,0,0,"Archmage Ataeric - In Combat - Cast Polymorph"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ataeric - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ataeric - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Archmage Ataeric - At 15% HP - Flee For Assist");

-- Ravenclaw Regent SAI
SET @ENTRY := 2283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,3000,3000,9000,12000,11,970,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ravenclaw Regent - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,1,0,0,0,85,0,6000,6000,12000,18000,11,7645,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ravenclaw Regent - In Combat - Cast Dominate Mind"),
(@ENTRY,0,2,0,9,0,100,0,4,30,1,1,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravenclaw Regent - At 4 - 30 Range - Set Ranged Movement"),
(@ENTRY,0,3,0,9,0,100,0,0,4,1,1,79,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravenclaw Regent - At 0 - 4 Range - Set Ranged Movement"),
(@ENTRY,0,4,0,11,0,100,1,0,0,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravenclaw Regent - On Respawn - Set Ranged Movement");

-- Dalaran Brewmaster SAI
SET @ENTRY := 3577;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,6000,8000,11,7638,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Brewmaster - In Combat - Cast Potion Toss");

-- Dalin Forgewright SAI
SET @ENTRY := 5682;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,80,20000,20000,11,6075,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalin Forgewright - At 80% HP - Cast Renew"),
(@ENTRY,0,1,0,2,0,100,0,0,30,10000,10000,11,2054,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalin Forgewright - At 30% HP - Cast Heal");

-- Fenwick Thatros SAI
SET @ENTRY := 6570;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,2000,2000,4000,6000,11,18072,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fenwick Thatros - In Combat - Cast Uppercut");

-- General Marcus Jonathan SAI
SET @ENTRY := 466;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,100,0,78,1000,1000,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Marcus Jonathan - Received Emote - Play Emote 66"),
(@ENTRY,0,1,0,22,0,100,0,101,1000,1000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Marcus Jonathan - Received Emote - Say Line 0");

-- Ol' Beasley SAI
SET @ENTRY := 1395;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ol' Beasley - Out Of Combat - Say Line 0");

-- Topper McNabb SAI
SET @ENTRY := 1402;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Topper McNabb - Out Of Combat - Say Line 0");

-- Morris Lawry SAI
SET @ENTRY := 1405;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morris Lawry - Out Of Combat - Say Line 0");

-- Warden Thelwater SAI
SET @ENTRY := 1719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,6000,43000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Thelwater - Out Of Combat - Say Line 0");

-- Gil SAI
SET @ENTRY := 3504;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gil - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,60000,60000,180000,180000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gil - Out Of Combat - Say Line 1");

-- Thomas Miller SAI
SET @ENTRY := 3518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thomas Miller - Out Of Combat - Say Line 0");

-- Ol' Emma SAI
SET @ENTRY := 3520;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ol' Emma - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,60000,60000,180000,180000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ol' Emma - Out Of Combat - Say Line 1");

-- Nurse Lillian SAI
SET @ENTRY := 5042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,87000,89000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Lillian - Out Of Combat - Say Line 0");

-- Miles Sidney SAI
SET @ENTRY := 28347;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,5000,60000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miles Sidney - Out Of Combat - Say Line 0");

-- Wright Williams SAI
SET @ENTRY := 28355;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,60000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wright Williams - Out Of Combat - Say Line 0");

-- Captain Paul Carver SAI
SET @ENTRY := 29287;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,9000,7000,15000,10,1,273,6,0,0,0,1,0,0,0,0,0,0,0,"Captain Paul Carver - Out Of Combat - Random Emote");

-- First Mate Edgar Flores SAI
SET @ENTRY := 29289;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,9000,7000,15000,10,1,6,274,0,0,0,1,0,0,0,0,0,0,0,"First Mate Edgar Flores - Out Of Combat - Random Emote");

-- Navigator Rian Trost SAI
SET @ENTRY := 29290;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,9000,7000,15000,10,1,273,6,0,0,0,1,0,0,0,0,0,0,0,"Navigator Rian Trost - Out Of Combat - Random Emote");

-- Galley Chief Paul Kubit SAI
SET @ENTRY := 29291;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,9000,7000,15000,10,1,6,274,0,0,0,1,0,0,0,0,0,0,0,"Galley Chief Paul Kubit - Out Of Combat - Random Emote");

-- Serban Oprescu SAI
SET @ENTRY := 29299;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,9000,7000,15000,10,1,273,6,0,0,0,1,0,0,0,0,0,0,0,"Serban Oprescu - Out Of Combat - Random Emote");

-- Bloodscalp Warrior SAI
SET @ENTRY := 587;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,26900,35400,20000,32200,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Warrior - In Combat - Cast Disarm"),
(@ENTRY,0,1,0,13,0,100,0,15000,20000,0,0,11,11972,1,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodscalp Warrior - On Target Casting - Cast Shield Bash"),
(@ENTRY,0,2,3,2,0,100,0,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Warrior - At 30% HP - Cast Enrage"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Warrior - At 30% HP - Say Line 0");

-- Texts for General Marcus Jonathan
DELETE FROM `creature_text` WHERE `entry`= 466;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(466,0,0, "Greetings citizen.",12,7,100,0,0,0, "General Marcus Jonathan");

-- Texts for Ol' Beasley
DELETE FROM `creature_text` WHERE `entry`= 1395;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1395,0,0, "It's all their fault, stupid Alliance army. Just had to build their towers right behind my farm.",12,0,100,0,0,0, "Ol\' Beasley"),
(1395,0,1, "Spare some change for a poor blind man?...What do you mean im not blind?...I'M NOT BLIND! I CAN SEE! ITS A MIRACLE!",12,0,100,0,0,0, "Ol\' Beasley"),
(1395,0,2, "I will gladly pay you Tuesday for a hamburger today.",12,0,100,0,0,0, "Ol\' Beasley");

-- Texts for Topper McNabb
DELETE FROM `creature_text` WHERE `entry`= 1402;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1402,0,0, "Some coin?",12,0,100,0,0,0, "Topper McNabb"),
(1402,0,1, "Help a poor bloke out?",12,0,100,0,0,0, "Topper McNabb"),
(1402,0,2, "Shine yer armor for a copper?",12,0,100,0,0,0, "Topper McNabb");

-- Texts for Morris Lawry
DELETE FROM `creature_text` WHERE `entry`= 1405;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1405,0,0, "Some coin?",12,0,100,0,0,0, "Morris Lawry"),
(1405,0,1, "Help a poor bloke out?",12,0,100,0,0,0, "Morris Lawry"),
(1405,0,2, "Shine yer armor for a copper?",12,0,100,0,0,0, "Morris Lawry");

-- Texts for Warden Thelwater
DELETE FROM `creature_text` WHERE `entry`= 1719;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1719,0,0, "All of a sudden they were everywhere.",12,0,100,0,0,0, "Warden Thelwater"),
(1719,0,1, "They must have had someone helping them.",12,0,100,0,0,0, "Warden Thelwater"),
(1719,0,2, "If the Captain finds out, it'll be the end of me.",12,0,100,0,0,0, "Warden Thelwater");

-- Texts for Gil
DELETE FROM `creature_text` WHERE `entry`= 3504;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(3504,0,0, "Is it true? Are there crocolisks in the canal?",12,0,100,0,0,0, "Gil"),
(3504,0,1, "My feet hurt.",12,0,100,0,0,0, "Gil"),
(3504,0,2, "Are we there yet?",12,0,100,0,0,0, "Gil"),
(3504,1,0, "I wanna see the Mage Tower.",12,0,100,0,0,0, "Gil"),
(3504,1,1, "Where we goin'?",12,0,100,0,0,0, "Gil"),
(3504,1,2, "Why do we always go the same way?",12,0,100,0,0,0, "Gil");

-- Texts for Thomas Miller
DELETE FROM `creature_text` WHERE `entry`= 3518;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(3518,0,0, "Freshly baked bread for sale!",12,0,100,0,0,0, "Thomas Miller"),
(3518,0,1, "Fresh bread for sale!",12,0,100,0,0,0, "Thomas Miller");

-- Texts for Ol' Emma
DELETE FROM `creature_text` WHERE `entry`= 3520;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(3520,0,0, "Seems like a hundred times a day I walk all the way to get more water. No respect for their elders I tell ya.",12,0,100,0,0,0, "Ol\' Emma"),
(3520,0,1, "Jack and Jill my wrinkled patoot! I do all the water luggin' 'round here.",12,0,100,0,0,0, "Ol\' Emma"),
(3520,0,2, "Think I'm starting to wear a rut in the paving stones.",12,0,100,0,0,0, "Ol\' Emma"),
(3520,1,0, "O'ourse I'm talking to myself. Only way to get a decent conversation in this city.",12,0,100,0,0,0, "Ol\' Emma"),
(3520,1,1, "As if I don't have better things to do in my old age than carry buckets of water.",12,0,100,0,0,0, "Ol\' Emma"),
(3520,1,2, "Where's the water Emma? Get the water Emma? If'n it weren't fer me that lot wouldn't know what water looks like.",12,0,100,0,0,0, "Ol\' Emma");

-- Texts for Nurse Lillian
DELETE FROM `creature_text` WHERE `entry`= 5042;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(5042,0,0, "You're going to be just fine.",12,0,100,0,0,0, "Nurse Lillian"),
(5042,0,1, "Drink this, it will help.",12,0,100,0,0,0, "Nurse Lillian"),
(5042,0,2, "Let me help you with those.",12,0,100,0,0,0, "Nurse Lillian");

-- Texts for Miles Sidney
DELETE FROM `creature_text` WHERE `entry`= 28347;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28347,0,0, "Remember, kid: You're always more wrong than you think you are. Double It!",12,0,100,0,0,0, "Miles Sidney"),
(28347,0,1, "Only put half as much in next time.",12,0,100,0,0,0, "Miles Sidney"),
(28347,0,2, "Then put twice as much in next time!",12,0,100,0,0,0, "Miles Sidney");

-- Texts for Wright Williams
DELETE FROM `creature_text` WHERE `entry`= 28355;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28355,0,0, "Sir, I think we were close with the Lethargy Root in that last poison recipie.",12,0,100,0,0,0, "Wright Williams"),
(28355,0,1, "Sir, our customers are complaining that there's too much Deathweed in our Anesthetics.",12,0,100,0,0,0, "Wright Williams"),
(28355,0,2, "Sir, our customers are complaining that there's not enough Maiden's Anguish in our Deadly Poisons.",12,0,100,0,0,0, "Wright Williams");

-- Texts for Bloodscalp Warrior
DELETE FROM `creature_text` WHERE `entry`= 587;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(587,0,0, "%s becomes enraged!",16,0,100,0,0,0, "Bloodscalp Warrior");

-- Bloodscalp Berserker SAI
SET @ENTRY := 597;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Berserker - At 30% HP - Cast Enrage"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Berserker - At 30% HP - Say Line 0"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bloodscalp Berserker - At 15% HP - Flee For Assist");

-- Lashtail Raptor SAI
SET @ENTRY := 686;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1200,8800,19700,24100,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lashtail Raptor - In Combat - Cast Lash");

-- Stone Maw Basilisk SAI
SET @ENTRY := 688;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,12000,12000,15000,15000,11,3635,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stone Maw Basilisk - In Combat - Cast Crystal Gaze");

-- Crystal Spine Basilisk SAI
SET @ENTRY := 689;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,5000,5000,16000,16000,11,3635,0,0,0,0,0,5,0,0,0,0,0,0,0,"Crystal Spine Basilisk - In Combat - Cast Crystal Gaze");

-- Cold Eye Basilisk SAI
SET @ENTRY := 690;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,8000,8000,30000,30000,11,3636,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cold Eye Basilisk - In Combat - Cast Crystalline Slumber");

-- Texts for Bloodscalp Berserker
DELETE FROM `creature_text` WHERE `entry`= 597;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(597,0,0, "%s becomes enraged!",16,0,100,0,0,0, "Bloodscalp Berserker");

-- Bhag'thera SAI
SET @ENTRY := 728;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,0,9000,9000,28000,28000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bhag'thera - In Combat - Cast Rend Flesh"),
(@ENTRY,0,1,0,0,0,100,0,2000,2000,32000,32000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bhag'thera - In Combat - Cast Pierce Armor");

-- King Bangalash SAI
SET @ENTRY := 731;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,8816,1,0,0,0,0,1,0,0,0,0,0,0,0,"King Bangalash - At 50% HP - Cast Summon Panthers");

-- Skullsplitter Berserker SAI
SET @ENTRY := 783;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,23000,26000,11,3148,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Berserker - In Combat - Cast Head Crack"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skullsplitter Berserker - At 15% HP - Flee For Assist");

-- Sergeant Malthus SAI
SET @ENTRY := 814;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,500,10900,18600,11,7068,32,0,0,0,0,2,0,0,0,0,0,0,0,"Sergeant Malthus - In Combat - Cast Veil of Shadow"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sergeant Malthus - At 15% HP - Flee For Assist");

-- Venture Co. Lumberjack SAI
SET @ENTRY := 921;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5200,7500,5900,9800,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Lumberjack - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Venture Co. Lumberjack - At 15% HP - Flee For Assist");

-- Kurzen Jungle Fighter SAI
SET @ENTRY := 937;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kurzen Jungle Fighter - At 15% HP - Flee For Assist");

-- Kurzen Commando SAI
SET @ENTRY := 938;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Commando - Out Of Combat - Cast Stealth"),
(@ENTRY,0,1,0,0,0,100,0,2400,4100,2400,4100,11,2591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kurzen Commando - In Combat - Cast Backstab"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,11,7964,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Commando - At 15% HP - Cast Smoke Bomb");

-- Kurzen Elite SAI
SET @ENTRY := 939;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7700,11000,8100,26200,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kurzen Elite - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,11900,24600,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Elite - In Combat - Cast Whirlwind"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kurzen Elite - At 15% HP - Flee For Assist");

-- Kurzen Medicine Man SAI
SET @ENTRY := 940;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,0,30,19900,28900,11,6077,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kurzen Medicine Man - On Friendly Unit At 0 - 30% Health - Cast Renew"),
(@ENTRY,0,1,0,14,0,100,0,0,30,34300,39100,11,6064,1,0,0,0,0,7,0,0,0,0,0,0,0,"Kurzen Medicine Man - On Friendly Unit At 0 - 30% Health - Cast Heal"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,588,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Medicine Man - At 30% HP - Cast Inner Fire"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kurzen Medicine Man - At 15% HP - Flee For Assist");

-- Kurzen Witch Doctor SAI
SET @ENTRY := 942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,40000,45000,11,6364,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Witch Doctor - In Combat - Cast Searing Totem"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,15000,20000,11,370,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kurzen Witch Doctor - In Combat - Cast Purge"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kurzen Witch Doctor - At 15% HP - Flee For Assist");

-- Kurzen Wrangler SAI
SET @ENTRY := 943;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1700,10700,18400,29800,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kurzen Wrangler - In Combat - Cast Net"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kurzen Wrangler - At 15% HP - Flee For Assist");

-- Elder Stranglethorn Tiger SAI
SET @ENTRY := 1085;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8600,8600,31300,31300,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Stranglethorn Tiger - In Combat - Cast Rend");

-- Venture Co. Workboss SAI
SET @ENTRY := 1095;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3600,241000,246000,11,3631,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Workboss - In Combat - Cast Battle Fury"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Venture Co. Workboss - At 15% HP - Flee For Assist");

-- River Crocolisk SAI
SET @ENTRY := 1150;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8200,12900,24100,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"River Crocolisk - In Combat - Cast Tendon Rip");

-- Saltwater Crocolisk SAI
SET @ENTRY := 1151;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8200,24100,32300,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saltwater Crocolisk - In Combat - Cast Tendon Rip");

-- Snapjaw Crocolisk SAI
SET @ENTRY := 1152;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,11200,12000,11200,12000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snapjaw Crocolisk - In Combat - Cast Tendon Rip");

-- Thrashtail Basilisk SAI
SET @ENTRY := 1550;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,5000,5000,18000,18000,11,6607,0,0,0,0,0,5,0,0,0,0,0,0,0,"Thrashtail Basilisk - In Combat - Cast Lash");

-- Ironjaw Basilisk SAI
SET @ENTRY := 1551;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,8000,8000,30000,30000,11,5106,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironjaw Basilisk - In Combat - Cast Crystal Flash");

-- Scale Belly SAI
SET @ENTRY := 1552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,15000,15000,26000,26000,11,5106,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scale Belly - In Combat - Cast Crystal Flash");

-- King Mukla SAI
SET @ENTRY := 1559;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2600,3800,6000,10200,11,5568,0,0,0,0,0,2,0,0,0,0,0,0,0,"King Mukla - In Combat - Cast Trample");

-- Bloodsail Raider SAI
SET @ENTRY := 1561;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,29651,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Raider - On Aggro - Cast Dual Wield"),
(@ENTRY,0,1,0,0,0,100,0,9800,11300,18500,31400,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Raider - In Combat - Cast Net"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bloodsail Raider - At 15% HP - Flee For Assist");
