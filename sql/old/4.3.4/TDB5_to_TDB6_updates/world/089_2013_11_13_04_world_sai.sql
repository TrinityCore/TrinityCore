-- Frenzyheart Ravager SAI
SET @ENTRY := 28078;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,5000,8000,11,49807,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Ravager - In Combat - Cast 49807"),
(@ENTRY,0,1,0,2,0,100,0,0,30,15000,18000,11,53361,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Ravager - Between 0-30% Health - Cast 53361"),
(@ENTRY,0,2,0,2,0,100,0,0,30,15000,18000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Ravager - Between 0-30% Health - Say Line 0");

-- Texts for Frenzyheart Ravager
SET @ENTRY := 28078;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Frenzyheart Ravager");

-- Sholazar Guardian SAI
SET @ENTRY := 28069;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,16000,22000,30000,11,52702,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sholazar Guardian - In Combat - Cast 52702");

-- Frenzyheart Berserker SAI
SET @ENTRY := 28076;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,50420,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Berserker - Between 0-30% Health - Cast 50420"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Berserker - Between 0-30% Health - Say Line 0");

-- Texts for Frenzyheart Berserker
SET @ENTRY := 28076;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Frenzyheart Berserker");

-- Argent Crusader SAI
SET @ENTRY := 28029;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,8000,11,14517,0,0,0,0,0,2,0,0,0,0,0,0,0,"Argent Crusader - Between 0-5 Range - Cast 14517"),
(@ENTRY,0,1,0,0,0,100,0,7000,11000,20000,24000,11,10326,1,0,0,0,0,6,0,0,0,0,0,0,0,"Argent Crusader - In Combat - Cast 10326"),
(@ENTRY,0,2,3,8,0,100,1,53031,0,0,0,11,53039,1,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusader - On Spellhit By 53031 - Cast 53039"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,33,29060,0,0,0,0,0,7,0,0,0,0,0,0,0,"Argent Crusader - On Spellhit By 53031 - Quest Credit");

-- Priest of Sseratus SAI
SET @ENTRY := 28035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,4000,10000,10000,11,54482,32,0,0,0,0,1,0,0,0,0,0,0,0,"Priest of Sseratus - In Combat - Cast 54482"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,20000,25000,11,13860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Priest of Sseratus - In Combat - Cast 13860"),
(@ENTRY,0,2,0,0,0,100,0,4000,10000,2000,10000,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Priest of Sseratus - In Combat - Cast 16568");

-- Champion of Sseratus SAI
SET @ENTRY := 28036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,4000,10000,10000,11,54482,32,0,0,0,0,1,0,0,0,0,0,0,0,"Champion of Sseratus - In Combat - Cast 54482"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,9000,16000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion of Sseratus - In Combat - Cast 15496");

-- Frozen Sphere SAI
SET @ENTRY := 28066;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,1200,3700,11,50578,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frozen Sphere - In Combat - Cast 50578");

-- Argent Shieldman SAI
SET @ENTRY := 28028;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,7000,11000,11,11977,32,0,0,0,0,2,0,0,0,0,0,0,0,"Argent Shieldman - In Combat - Cast 11977"),
(@ENTRY,0,1,0,0,0,100,1,2000,4000,8000,12000,11,32587,1,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Shieldman - In Combat - Cast 32587"),
(@ENTRY,0,2,3,8,0,100,1,53031,0,0,0,11,53039,1,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Shieldman - On Spellhit By 53031 - Cast 53039"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,33,29060,0,0,0,0,0,7,0,0,0,0,0,0,0,"Argent Shieldman - On Spellhit By 53031 - Quest Credit");

-- Rainspeaker Warrior SAI
SET @ENTRY := 28024;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,5000,8000,11,50533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rainspeaker Warrior - In Combat - Cast 50533");

-- Bittertide Hydra SAI
SET @ENTRY := 28003;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,120000,125000,11,52307,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bittertide Hydra - In Combat - Cast 52307");

-- Goretalon Roc SAI
SET @ENTRY := 28004;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,7000,10000,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goretalon Roc - In Combat - Cast 55079");

-- Drakkari Plague Spreader SAI
SET @ENTRY := 27941;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,11000,30000,35000,11,52230,32,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Plague Spreader - In Combat - Cast 52230");

-- Admiral Barean Westwind SAI
SET @ENTRY := 27951;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,50161,0,0,0,0,0,1,0,0,0,0,0,0,0,"Admiral Barean Westwind - On Respawn - Cast 50161");

-- Wyrmrest Protector SAI
SET @ENTRY := 27953;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,8000,13000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmrest Protector - Between 0-20 Range - Cast 6533"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,7000,12000,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmrest Protector - In Combat - Cast 16145"),
(@ENTRY,0,2,0,9,0,100,0,0,5,7000,10000,11,15496,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmrest Protector - Between 0-5 Range - Cast 15496"),
(@ENTRY,0,3,0,0,0,100,0,9000,12000,12000,15000,11,17547,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmrest Protector - In Combat - Cast 17547");

-- Flesheating Ghoul SAI
SET @ENTRY := 27871;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,9000,15000,25000,11,46202,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flesheating Ghoul - In Combat - Cast 46202 (Dungeon Only)"),
(@ENTRY,0,1,0,2,0,100,7,0,35,0,0,11,50933,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flesheating Ghoul - Between 0-35% Health - Cast 50933 (Dungeon Only)"),
(@ENTRY,0,2,0,2,0,100,7,0,35,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flesheating Ghoul - Between 0-35% Health - Say Line 0 (Dungeon Only)");

-- Texts for Flesheating Ghoul
SET @ENTRY := 27871;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Flesheating Ghoul");

-- Highlord Bolvar Fordragon SAI
SET @ENTRY := 27858;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,5000,35000,45000,11,49765,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highlord Bolvar Fordragon - In Combat - Cast 49765");

-- Luthion the Vile SAI
SET @ENTRY := 27860;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,50689,0,0,0,0,0,1,0,0,0,0,0,0,0,"Luthion the Vile - Out Of Combat - Cast 50689"),
(@ENTRY,0,1,0,0,0,100,0,8500,8500,21300,21300,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,"Luthion the Vile - In Combat - Cast 50688");

-- Venture Co. Evacuee SAI
SET @ENTRY := 27830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,9000,14000,11,50054,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Evacuee - In Combat - Cast 50054");

-- Wailing Soul SAI
SET @ENTRY := 27836;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,75,18000,21000,11,50027,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wailing Soul - Between 0-75% Health - Cast 50027");

-- Turgid the Vile SAI
SET @ENTRY := 27808;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,40,12000,18000,11,50335,0,0,0,0,0,2,0,0,0,0,0,0,0,"Turgid the Vile - Between 8-40 Range - Cast 50335"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,12000,15000,11,51356,1,0,0,0,0,2,0,0,0,0,0,0,0,"Turgid the Vile - In Combat - Cast 51356");

-- Naxxramas Dreadguard SAI
SET @ENTRY := 27823;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,12000,16000,11,51290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naxxramas Dreadguard - In Combat - Cast 51290");

-- Naxxramas Shade SAI
SET @ENTRY := 27824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,40,9000,14000,11,49961,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naxxramas Shade - Between 8-40 Range - Cast 49961"),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,9000,12000,11,38926,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naxxramas Shade - In Combat - Cast 38926");

-- Scout Captain Carter SAI
SET @ENTRY := 27783;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,10000,11,38621,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scout Captain Carter - Between 0-5 Range - Cast 38621");

-- Tattered Abomination SAI
SET @ENTRY := 27797;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,40,9000,14000,11,50335,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tattered Abomination - Between 8-40 Range - Cast 50335");

-- Scourge Technician SAI
SET @ENTRY := 27799;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,8000,11000,11,51316,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Technician - Between 0-5 Range - Cast 51316");

-- Leprous Servant SAI
SET @ENTRY := 27800;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,15000,11,51315,0,0,0,0,0,2,0,0,0,0,0,0,0,"Leprous Servant - Between 0-5 Range - Cast 51315");

-- Captain Drayzen SAI
SET @ENTRY := 27751;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,7000,10000,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Drayzen - In Combat - Cast 42724"),
(@ENTRY,0,1,0,0,0,100,0,11000,14000,11000,14000,11,38618,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Drayzen - In Combat - Cast 38618"),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,10000,14000,11,15708,1,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Drayzen - In Combat - Cast 15708");

-- Commander Howser SAI
SET @ENTRY := 27759;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,5,45,0,0,11,52460,1,0,0,0,0,2,0,0,0,0,0,0,0,"Commander Howser - Between 5-45 Range - Cast 52460"),
(@ENTRY,0,1,0,0,0,100,0,6000,10000,14000,17000,11,36132,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Howser - In Combat - Cast 36132");

-- Conquest Hold Defender SAI
SET @ENTRY := 27748;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,8000,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,"Conquest Hold Defender - Between 0-5 Range - Cast 29426");

-- Infinite Adversary SAI
SET @ENTRY := 27742;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,9000,13000,11,52633,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Adversary - Between 0-5 Range - Cast 52633 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,2,16000,21000,21000,29000,11,52634,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Adversary - In Combat - Cast 52634 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,16000,21000,21000,29000,11,58813,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Adversary - In Combat - Cast 58813 (Heroic Dungeon)");

-- Infinite Hunter SAI
SET @ENTRY := 27743;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,9000,15000,12000,18000,11,52636,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Hunter - In Combat - Cast 52636 (Dungeon Only)"),
(@ENTRY,0,1,0,8,0,100,2,0,127,0,0,11,52635,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Hunter - On Spellhit By 0 - Cast 52635 (Normal Dungeon)"),
(@ENTRY,0,2,0,8,0,100,4,0,127,0,0,11,58820,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Hunter - On Spellhit By 0 - Cast 58820 (Heroic Dungeon)");

-- Infinite Agent SAI
SET @ENTRY := 27744;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,12000,17000,11,52660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Agent - In Combat - Cast 52660 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,5000,9000,12000,17000,11,58817,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Agent - In Combat - Cast 58817 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,15000,21000,11,52657,1,0,0,0,0,5,0,0,0,0,0,0,0,"Infinite Agent - In Combat - Cast 52657 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,15000,21000,11,58816,1,0,0,0,0,5,0,0,0,0,0,0,0,"Infinite Agent - In Combat - Cast 58816 (Heroic Dungeon)");

-- Lordaeron Footman SAI
SET @ENTRY := 27745;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,5000,8000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lordaeron Footman - Between 0-5 Range - Cast 25710 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,7000,12000,9000,15000,11,52317,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Footman - In Combat - Cast 52317 (Dungeon Only)");

-- Crypt Fiend SAI
SET @ENTRY := 27734;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,5000,12000,16000,11,52496,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crypt Fiend - In Combat - Cast 52496 (Dungeon Only)"),
(@ENTRY,0,1,0,9,0,100,4,0,8,12000,15000,11,52491,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crypt Fiend - Between 0-8 Range - Cast 52491 (Heroic Dungeon)");

-- Patchwork Construct SAI
SET @ENTRY := 27736;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,58808,1,0,0,0,0,1,0,0,0,0,0,0,0,"Patchwork Construct - On Respawn - Cast 58808 (Normal Dungeon)"),
(@ENTRY,0,1,0,11,0,100,5,0,0,0,0,11,52525,1,0,0,0,0,1,0,0,0,0,0,0,0,"Patchwork Construct - On Respawn - Cast 52525 (Heroic Dungeon)");

-- Ruby Guardian SAI
SET @ENTRY := 27725;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,7000,10000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ruby Guardian - In Combat - Cast 40504");

-- Enraging Ghoul SAI
SET @ENTRY := 27729;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,9000,16000,24000,11,52461,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraging Ghoul - In Combat - Cast 52461 (Dungeon Only)");

-- Frenzied Gargoyle SAI
SET @ENTRY := 27691;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,8000,12000,11,31664,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzied Gargoyle - In Combat - Cast 31664");

-- General Gorlok SAI
SET @ENTRY := 27708;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,45,17000,20000,11,52460,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Gorlok - Between 5-45 Range - Cast 52460"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,9000,14000,11,16856,1,0,0,0,0,2,0,0,0,0,0,0,0,"General Gorlok - In Combat - Cast 16856");

-- Frigid Ghoul Attacker SAI
SET @ENTRY := 27685;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,14000,17000,11,50361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frigid Ghoul Attacker - In Combat - Cast 50361");

-- Silverbrook Defender SAI
SET @ENTRY := 27676;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,18000,21000,11,12054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silverbrook Defender - In Combat - Cast 12054"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,15000,11,52318,1,0,0,0,0,2,0,0,0,0,0,0,0,"Silverbrook Defender - Between 0-5 Range - Cast 52318");

-- Plague Eruptor SAI
SET @ENTRY := 27611;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,28000,38000,11,49350,0,0,0,0,0,5,0,0,0,0,0,0,0,"Plague Eruptor - In Combat - Cast 49350");

-- Angrathar Aberration SAI
SET @ENTRY := 27631;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,16000,21000,11,51922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Angrathar Aberration - In Combat - Cast 51922");

-- Goremaw SAI
SET @ENTRY := 27578;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,15000,19000,11,50729,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goremaw - In Combat - Cast 50729"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,18000,22000,11,53174,1,0,0,0,0,2,0,0,0,0,0,0,0,"Goremaw - In Combat - Cast 53174");

-- Varlam SAI
SET @ENTRY := 27579;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,8000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Varlam - In Combat - Cast 15496"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,12000,15000,11,32736,1,0,0,0,0,2,0,0,0,0,0,0,0,"Varlam - In Combat - Cast 32736");

-- Selas SAI
SET @ENTRY := 27580;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,9000,14000,11,53239,0,0,0,0,0,1,0,0,0,0,0,0,0,"Selas - In Combat - Cast 53239"),
(@ENTRY,0,1,0,2,0,100,0,0,50,9000,12000,11,52071,1,0,0,0,0,1,0,0,0,0,0,0,0,"Selas - Between 0-50% Health - Cast 52071");

-- Captain Iskandar SAI
SET @ENTRY := 27567;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,7000,11000,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Iskandar - In Combat - Cast 42724"),
(@ENTRY,0,1,0,9,0,100,0,0,5,11000,16000,11,15708,1,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Iskandar - Between 0-5 Range - Cast 15708"),
(@ENTRY,0,2,0,0,0,100,0,11000,14000,19000,22000,11,38618,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Iskandar - In Combat - Cast 38618");

-- Taunka Windfury SAI
SET @ENTRY := 27571;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,9000,14000,11,23380,32,0,0,0,0,5,0,0,0,0,0,0,0,"Taunka Windfury - In Combat - Cast 23380"),
(@ENTRY,0,1,0,14,0,100,0,2000,40,14000,20000,11,23381,1,0,0,0,0,7,0,0,0,0,0,0,0,"Taunka Windfury - On Friendly Unit At 2000 Health Within 40 Range - Cast 23381");

-- Reanimated Noble SAI
SET @ENTRY := 27552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,11000,17000,11,51285,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reanimated Noble - Between 0-50% Health - Cast 51285");

-- Drakkari Witch Doctor SAI
SET @ENTRY := 27555;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,9000,12000,11,52695,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Witch Doctor - In Combat - Cast 52695"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,30000,35000,11,32194,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Witch Doctor - In Combat - Cast 32194");

-- Enraged Apparition SAI
SET @ENTRY := 27551;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,0,1000,3000,300000,310000,11,50420,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Apparition - In Combat - Cast 50420"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Apparition - In Combat - Say Line 0");

-- Texts for Enraged Apparition
SET @ENTRY := 27551;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Enraged Apparition");

-- Ruby Watcher SAI
SET @ENTRY := 27542;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,12000,18000,11,49241,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ruby Watcher - Between 0-40 Range - Cast 49241");

-- Silverbrook Hunter SAI
SET @ENTRY := 27546;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,1,0,2,2,100,1,0,50,0,0,11,49561,1,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Hunter - Between 0-50% Health - Cast 49561 (Phase 2)"),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,7000,11000,11,47168,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silverbrook Hunter - In Combat - Cast 47168"),
(@ENTRY,0,3,0,7,0,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Hunter - On Evade - Set Event Phase 0");

-- Fordragon Gryphon Rider SAI
SET @ENTRY := 27521;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,14000,19000,11,49482,0,0,0,0,0,5,0,0,0,0,0,0,0,"Fordragon Gryphon Rider - In Combat - Cast 49482");

-- Grizzlesnout SAI
SET @ENTRY := 27523;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,50046,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grizzlesnout - In Combat - Cast 50046");

-- Frigid Abomination Attacker SAI
SET @ENTRY := 27531;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,7000,10000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frigid Abomination Attacker - In Combat - Cast 40504");

-- Frigid Ghoul SAI
SET @ENTRY := 27534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,45000,50000,11,50361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frigid Ghoul - In Combat - Cast 50361");

-- Fordragon Knight SAI
SET @ENTRY := 27535;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,12000,20000,11,31732,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Knight - In Combat - Cast 31732");

-- Conquest Hold Marauder SAI
SET @ENTRY := 27424;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,25,20000,25000,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Conquest Hold Marauder - Between 8-25 Range - Cast 27577"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,10000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Conquest Hold Marauder - Between 0-5 Range - Cast 25710"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,12000,18000,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Conquest Hold Marauder - In Combat - Cast 13730");

-- Conquest Hold Skirmisher SAI
SET @ENTRY := 27456;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,15000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Conquest Hold Skirmisher - Between 0-5 Range - Cast 9080"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,7000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Conquest Hold Skirmisher - In Combat - Cast 15496"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,12000,16000,11,32736,1,0,0,0,0,2,0,0,0,0,0,0,0,"Conquest Hold Skirmisher - In Combat - Cast 32736");

-- Conquest Hold Grunt SAI
SET @ENTRY := 27470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,25,20000,25000,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Conquest Hold Grunt - Between 8-25 Range - Cast 27577"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,10000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Conquest Hold Grunt - Between 0-5 Range - Cast 25710"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,12000,18000,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Conquest Hold Grunt - In Combat - Cast 13730");

-- Sergeant Bonesnap SAI
SET @ENTRY := 27493;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,25,20000,25000,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sergeant Bonesnap - Between 8-25 Range - Cast 27577"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,10000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sergeant Bonesnap - Between 0-5 Range - Cast 25710"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,12000,18000,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sergeant Bonesnap - In Combat - Cast 13730");

-- Risen Wintergarde Miner SAI
SET @ENTRY := 27401;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,12000,11,48374,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Wintergarde Miner - Between 0-5 Range - Cast 48374");

-- Duskhowl Prowler SAI
SET @ENTRY := 27408;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,17000,20000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Duskhowl Prowler - In Combat - Cast 32019");

-- Scourge Siegesmith SAI
SET @ENTRY := 27410;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,10000,11000,16000,11,22334,0,0,0,0,0,5,0,0,0,0,0,0,0,"Scourge Siegesmith - In Combat - Cast 22334");

-- Deathbringer Revenant SAI
SET @ENTRY := 27382;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,9000,14000,11,51131,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathbringer Revenant - In Combat - Cast 51131");

-- Smoldering Skeleton SAI
SET @ENTRY := 27360;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,51437,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smoldering Skeleton - On Aggro - Cast 51437");

-- Smoldering Construct SAI
SET @ENTRY := 27362;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,12000,16000,11,51439,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smoldering Construct - In Combat - Cast 51439");

-- Smoldering Geist SAI
SET @ENTRY := 27363;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,12000,16000,11,51500,0,0,0,0,0,5,0,0,0,0,0,0,0,"Smoldering Geist - In Combat - Cast 51500");

-- Onslaught Death Knight SAI
SET @ENTRY := 27367;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50689,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Death Knight - On Aggro - Cast 50689"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,15000,18000,11,50688,1,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Death Knight - In Combat - Cast 50688");

-- Burning Depths Necrolyte SAI
SET @ENTRY := 27356;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,12000,11,51430,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Depths Necrolyte - Between 0-5 Range - Cast 51430"),
(@ENTRY,0,1,0,2,0,100,0,0,30,25000,32000,11,48616,1,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Depths Necrolyte - Between 0-30% Health - Cast 48616");

-- Onslaught Scout SAI
SET @ENTRY := 27332;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,48594,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Scout - On Aggro - Cast 48594");

-- Onslaught Mason SAI
SET @ENTRY := 27333;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,6000,9000,11,50370,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Mason - In Combat - Cast 50370"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,30000,35000,11,50701,1,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Mason - In Combat - Cast 50701");

-- Onslaught Commander Iustus SAI
SET @ENTRY := 27334;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,7000,10000,11,48280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Commander Iustus - In Combat - Cast 48280"),
(@ENTRY,0,1,0,2,0,100,0,0,50,10000,14000,11,35949,1,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Commander Iustus - Between 0-50% Health - Cast 35949");

-- Bloodpaw Warrior SAI
SET @ENTRY := 27342;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,6000,9000,11,51875,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodpaw Warrior - In Combat - Cast 51875");

-- Bloodpaw Shaman SAI
SET @ENTRY := 27343;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,12000,15000,11,51876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodpaw Shaman - In Combat - Cast 51876"),
(@ENTRY,0,1,0,0,0,100,0,7000,10000,9000,13000,11,13281,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodpaw Shaman - In Combat - Cast 13281"),
(@ENTRY,0,2,0,2,0,100,0,0,30,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodpaw Shaman - Between 0-30% Health - Cast 6742");

-- Tundra Scavenger SAI
SET @ENTRY := 27294;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,4000,7000,11,51875,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tundra Scavenger - In Combat - Cast 51875");

-- Onslaught Bloodhound SAI
SET @ENTRY := 27329;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,4000,7000,11,51875,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Bloodhound - In Combat - Cast 51875");

-- Risen Wintergarde Defender SAI
SET @ENTRY := 27284;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,30000,35000,11,51307,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Wintergarde Defender - Between 0-30% Health - Cast 51307");

-- Reconstructed Frost Wyrm SAI
SET @ENTRY := 27285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,12000,15000,11,47425,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reconstructed Frost Wyrm - In Combat - Cast 47425");

-- Dreadbone Invader SAI
SET @ENTRY := 27286;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,10000,16000,11,51290,32,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadbone Invader - In Combat - Cast 51290");

-- Mindless Wight SAI
SET @ENTRY := 27287;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,11000,16000,11,51334,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mindless Wight - Between 0-5 Range - Cast 51334");

-- Death Knight Champion SAI
SET @ENTRY := 27288;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50689,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Champion - On Aggro - Cast 50689"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,15000,18000,11,50688,1,0,0,0,0,2,0,0,0,0,0,0,0,"Death Knight Champion - In Combat - Cast 50688");

-- Snowplain Shaman SAI
SET @ENTRY := 27279;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,25000,35000,11,39591,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowplain Shaman - In Combat - Cast 39591");

-- Devout Bodyguard SAI
SET @ENTRY := 27247;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,10000,15000,11,38256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Devout Bodyguard - In Combat - Cast 38256");

-- Alystros the Verdant Keeper SAI
SET @ENTRY := 27249;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,6000,9000,11,51937,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alystros the Verdant Keeper - In Combat - Cast 51937"),
(@ENTRY,0,1,0,9,0,100,0,0,5,16000,21000,11,51938,1,0,0,0,0,2,0,0,0,0,0,0,0,"Alystros the Verdant Keeper - Between 0-5 Range - Cast 51938"),
(@ENTRY,0,2,0,0,0,100,0,2500,4000,17000,21000,11,51922,0,0,0,0,0,6,0,0,0,0,0,0,0,"Alystros the Verdant Keeper - In Combat - Cast 51922");

-- Onslaught Executioner SAI
SET @ENTRY := 27211;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,13000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Executioner - Between 0-5 Range - Cast 9080"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,43673,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Executioner - In Combat - Cast 43673");

-- Captain Shely SAI
SET @ENTRY := 27232;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,22000,25000,11,50853,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Shely - In Combat - Cast 50853");

-- Onslaught Deckhand SAI
SET @ENTRY := 27233;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,7000,10000,11,50854,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Deckhand - In Combat - Cast 50854");

-- Foreman Kaleiki SAI
SET @ENTRY := 27238;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,14000,18000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Kaleiki - Between 0-5 Range - Cast 9080"),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,8000,11000,11,43673,1,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Kaleiki - In Combat - Cast 43673");

-- Emerald Skytalon SAI
SET @ENTRY := 27244;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,4000,7000,11,32909,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emerald Skytalon - Between 0-5 Range - Cast 32909"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,32909,7,0,0,0,0,1,0,0,0,0,0,0,0,"Emerald Skytalon - On Death - Cast 32909");

-- High General Abbendis SAI
SET @ENTRY := 27210;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50908,0,0,0,0,0,1,0,0,0,0,0,0,0,"High General Abbendis - On Aggro - Cast 50908"),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,19000,23000,11,50915,0,0,0,0,0,2,0,0,0,0,0,0,0,"High General Abbendis - In Combat - Cast 50915"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,20000,23000,11,50905,0,0,0,0,0,2,0,0,0,0,0,0,0,"High General Abbendis - In Combat - Cast 50905");

-- Onslaught Workman SAI
SET @ENTRY := 27207;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,12000,7000,12000,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Workman - In Combat - Cast 43410");

-- Camp Oneqwah Brave SAI
SET @ENTRY := 27126;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,10000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Camp Oneqwah Brave - Between 0-5 Range - Cast 40505"),
(@ENTRY,0,1,0,2,0,100,0,0,30,120000,130000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Camp Oneqwah Brave - Between 0-30% Health - Cast 8599");

-- 7th Legion Infantryman SAI
SET @ENTRY := 27160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,12000,18000,11,16244,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Infantryman - In Combat - Cast 16244"),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,13000,16000,11,32588,1,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Infantryman - In Combat - Cast 32588");

-- 7th Legion Cavalier SAI
SET @ENTRY := 27161;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,7000,9000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Cavalier - In Combat - Cast 19643"),
(@ENTRY,0,1,0,13,0,100,0,10000,14000,0,0,11,15618,0,0,0,0,0,7,0,0,0,0,0,0,0,"7th Legion Cavalier - On Target Casting - Cast 15618");

-- Conquest Hold Raider SAI
SET @ENTRY := 27118;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,25,20000,25000,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Conquest Hold Raider - Between 8-25 Range - Cast 27577"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,10000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Conquest Hold Raider - Between 0-5 Range - Cast 25710"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,12000,18000,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Conquest Hold Raider - In Combat - Cast 13730");

-- Bloodmoon Worgen SAI
SET @ENTRY := 27020;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,11000,18000,22000,11,53094,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmoon Worgen - In Combat - Cast 53094"),
(@ENTRY,0,1,0,2,0,100,0,0,30,10000,14000,11,32714,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmoon Worgen - Between 0-30% Health - Cast 32714");

-- Bloodmoon Cultist SAI
SET @ENTRY := 27024;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,8000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmoon Cultist - Between 0-5 Range - Cast 14873"),
(@ENTRY,0,1,0,0,0,100,0,5000,11000,18000,22000,11,53094,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmoon Cultist - In Combat - Cast 53094"),
(@ENTRY,0,2,0,2,0,100,0,0,30,10000,14000,11,32714,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmoon Cultist - Between 0-30% Health - Cast 32714");

-- Venomspite Deathguard SAI
SET @ENTRY := 27035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,12000,15000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venomspite Deathguard - In Combat - Cast 12170"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,9000,12000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venomspite Deathguard - In Combat - Cast 12169");

-- Kreug Oathbreaker SAI
SET @ENTRY := 27105;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,13000,15000,20000,11,53437,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kreug Oathbreaker - In Combat - Cast 53437"),
(@ENTRY,0,1,0,0,0,100,0,10000,15000,12000,18000,11,53438,0,0,0,0,0,6,0,0,0,0,0,0,0,"Kreug Oathbreaker - In Combat - Cast 53438"),
(@ENTRY,0,2,0,2,0,100,0,0,30,14000,18000,11,56310,1,0,0,0,0,1,0,0,0,0,0,0,0,"Kreug Oathbreaker - Between 0-30% Health - Cast 56310");

-- Chilltusk SAI
SET @ENTRY := 27005;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,11000,11,51878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chilltusk - Between 0-5 Range - Cast 51878"),
(@ENTRY,0,1,0,0,0,100,0,9000,14000,9000,14000,11,50410,1,0,0,0,0,2,0,0,0,0,0,0,0,"Chilltusk - In Combat - Cast 50410");

-- Iceshatter SAI
SET @ENTRY := 27007;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,45,13000,19000,11,52088,0,0,0,0,0,2,0,0,0,0,0,0,0,"Iceshatter - Between 5-45 Range - Cast 52088"),
(@ENTRY,0,1,0,0,0,100,0,7000,10000,7000,12000,11,52118,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iceshatter - In Combat - Cast 52118");

-- Bloodfeast SAI
SET @ENTRY := 27008;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,13000,13000,18000,11,52126,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeast - In Combat - Cast 52126");

-- Drakegore SAI
SET @ENTRY := 27009;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,5,45,0,0,11,52088,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakegore - Between 5-45 Range - Cast 52088"),
(@ENTRY,0,1,0,2,0,100,0,0,30,60000,70000,11,52101,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakegore - Between 0-30% Health - Cast 52101");

-- Reanimated Drakkari Tribesman SAI
SET @ENTRY := 26946;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,12000,16000,11,50642,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reanimated Drakkari Tribesman - In Combat - Cast 50642"),
(@ENTRY,0,1,0,2,0,100,0,0,30,30000,35000,11,3151,1,0,0,0,0,1,0,0,0,0,0,0,0,"Reanimated Drakkari Tribesman - Between 0-30% Health - Cast 3151");

-- Hulking Atrocity SAI
SET @ENTRY := 26948;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,6000,9000,11,49861,32,0,0,0,0,2,0,0,0,0,0,0,0,"Hulking Atrocity - In Combat - Cast 49861");

-- Tormented Drakkari SAI
SET @ENTRY := 26965;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,12000,16000,24000,11,50636,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tormented Drakkari - In Combat - Cast 50636"),
(@ENTRY,0,1,0,13,0,100,0,9000,12000,0,0,11,43518,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tormented Drakkari - On Target Casting - Cast 43518"),
(@ENTRY,0,2,0,2,0,100,0,0,50,12000,16000,11,50642,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tormented Drakkari - Between 0-50% Health - Cast 50642"),
(@ENTRY,0,3,0,2,0,100,0,0,30,30000,35000,11,3151,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tormented Drakkari - Between 0-30% Health - Cast 3151");

-- Icefist SAI
SET @ENTRY := 27004;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,11000,11,51878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Icefist - Between 0-5 Range - Cast 51878"),
(@ENTRY,0,1,0,0,0,100,0,9000,14000,9000,14000,11,50410,1,0,0,0,0,2,0,0,0,0,0,0,0,"Icefist - In Combat - Cast 50410");

-- Overseer Korgan SAI
SET @ENTRY := 26921;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,7000,9000,11,32018,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overseer Korgan - In Combat - Cast 32018"),
(@ENTRY,0,1,0,2,0,100,0,0,30,12000,16000,11,52714,1,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Korgan - Between 0-30% Health - Cast 52714");

-- Overseer Lochli SAI
SET @ENTRY := 26922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,12000,11000,15000,11,52717,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Lochli - In Combat - Cast 52717");

-- Wyrmrest Temple Drake SAI
SET @ENTRY := 26925;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,9000,14000,11,49113,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmrest Temple Drake - In Combat - Cast 49113");

-- Duke Vallenhal SAI
SET @ENTRY := 26926;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50689,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duke Vallenhal - On Aggro - Cast 50689"),
(@ENTRY,0,1,0,2,0,100,0,0,50,13000,19000,11,51673,1,0,0,0,0,2,0,0,0,0,0,0,0,"Duke Vallenhal - Between 0-50% Health - Cast 51673");

-- Wyrmrest Guardian SAI
SET @ENTRY := 26933;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,12000,18000,11,49110,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmrest Guardian - In Combat - Cast 49110");

-- Overseer Durval SAI
SET @ENTRY := 26920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,8000,11000,11,52715,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overseer Durval - In Combat - Cast 52715");

-- Conqueror Krenna SAI
SET @ENTRY := 26860;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,10000,7000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Conqueror Krenna - In Combat - Cast 15284");

-- Ancient Drakkari King SAI
SET @ENTRY := 26871;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,7000,11,52466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ancient Drakkari King - In Combat - Cast 52466");

-- The End of the Line Ley Line Focus Kill Credit Bunny SAI
SET @ENTRY := 26887;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,47634,0,0,0,11,47635,22,0,0,0,0,7,0,0,0,0,0,0,0,"The End of the Line Ley Line Focus Kill Credit Bunny - On Spellhit By 47634 - Cast 47635");

-- Undead Miner SAI
SET @ENTRY := 26891;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,8000,11000,11,48374,0,0,0,0,0,2,0,0,0,0,0,0,0,"Undead Miner - Between 0-5 Range - Cast 48374"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,6000,9000,11,52608,0,0,0,0,0,5,0,0,0,0,0,0,0,"Undead Miner - In Combat - Cast 52608");

-- Drak'aguul SAI
SET @ENTRY := 26919;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,52457,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drak'aguul - On Aggro - Cast 52457"),
(@ENTRY,0,1,0,9,0,100,0,5,45,17000,23000,11,52460,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drak'aguul - Between 5-45 Range - Cast 52460"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,39,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drak'aguul - Between 0-30% Health - Call For Help");

-- Gigantaur SAI
SET @ENTRY := 26836;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,6000,12000,11,9080,32,0,0,0,0,2,0,0,0,0,0,0,0,"Gigantaur - Between 0-5 Range - Cast 9080"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,12000,15000,11,52139,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gigantaur - In Combat - Cast 52139");

-- Conquest Hold Legionnaire SAI
SET @ENTRY := 26839;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,15000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Conquest Hold Legionnaire - Between 0-5 Range - Cast 9080"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,18000,11,61044,1,0,0,0,0,1,0,0,0,0,0,0,0,"Conquest Hold Legionnaire - In Combat - Cast 61044");
