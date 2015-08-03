-- Summoned Blackhand Veteran SAI
SET @ENTRY := 10681;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Veteran - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,3,8,25,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Blackhand Veteran - Between 8-25 Range - Cast 15749 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,5800,14000,7800,18200,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Blackhand Veteran - In Combat - Cast 14516 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,10000,15000,6000,18000,11,11972,0,0,0,0,0,6,0,0,0,0,0,0,0,"Summoned Blackhand Veteran - In Combat - Cast 11972 (Normal Dungeon)"),
(@ENTRY,0,4,0,1,0,100,2,10000,10000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Veteran - Out Of Combat - Die (Normal Dungeon)");

-- Texts for Summoned Blackhand Veteran
SET @ENTRY := 10681;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s summons a Blackhand Veteran to his aid!",16,0,100,0,0,0,"Summoned Blackhand Veteran");

-- Rookery Hatcher SAI
SET @ENTRY := 10683;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,12000,10000,15000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rookery Hatcher - In Combat - Cast 15572 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,7000,4000,6000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rookery Hatcher - In Combat - Cast 15580 (Normal Dungeon)");

-- Chromatic Elite Guard SAI
SET @ENTRY := 10814;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,12800,13000,13000,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Elite Guard - In Combat - Cast 15708 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5600,15400,11200,25700,11,16790,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Elite Guard - In Combat - Cast 16790 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,80,2,12000,20800,9000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Elite Guard - In Combat - Cast 15580 (Normal Dungeon)");

-- Goraluk Anvilcrack SAI
SET @ENTRY := 10899;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,4000,6000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goraluk Anvilcrack - In Combat - Cast 15580 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,10000,20000,20000,11,16172,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goraluk Anvilcrack - In Combat - Cast 16172 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10000,10000,10000,10000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goraluk Anvilcrack - In Combat - Cast 6253 (Normal Dungeon)");

-- Succubus Minion SAI
SET @ENTRY := 10928;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,4000,7000,11,32202,0,0,0,0,0,2,0,0,0,0,0,0,0,"Succubus Minion - In Combat - Cast 32202");

-- Fras Siabi SAI
SET @ENTRY := 11058;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fras Siabi - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,70,2,2000,2000,9000,9000,11,7964,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fras Siabi - In Combat - Cast 7964 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,70,2,15000,15000,30000,30000,11,17294,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fras Siabi - In Combat - Cast 17294 (Normal Dungeon)");

-- Texts for Fras Siabi
SET @ENTRY := 11058;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Looking for these???? You'll never have em!",12,0,66,0,0,0,"Fras Siabi"),
(@ENTRY,0,1,"I'm going to wear your skin as a smoking jacket! The stogies? You'll have to pry them from my cold dead... er... RAWR!!!!",12,0,33,0,0,0,"Fras Siabi");

-- Manifestation of Water SAI
SET @ENTRY := 11256;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,10000,10000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Manifestation of Water - Out Of Combat - Say Line 0");

-- Texts for Manifestation of Water
SET @ENTRY := 11256;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"NO!!!  It puts the tannin in the basket, or it gets the mallet again!",14,0,100,0,0,0,"Manifestation of Water");

-- Gordok Brute SAI
SET @ENTRY := 11441;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,3,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Brute - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,4000,8000,12000,15000,11,18072,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gordok Brute - In Combat - Cast 18072 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,3000,7000,10000,12000,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Brute - In Combat - Cast 15615 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,10000,18000,15000,18000,11,22572,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Brute - In Combat - Cast 22572 (Normal Dungeon)"),
(@ENTRY,0,4,5,2,0,100,3,0,30,0,0,11,15716,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Brute - Between 0-30% Health - Cast 15716 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Brute - Between 0-30% Health - Say Line 1 (Normal Dungeon)");

-- Texts for Gordok Brute
SET @ENTRY := 11441;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,"Gordok Brute"),
(@ENTRY,0,1,"Me smash! You die!",12,0,100,0,0,0,"Gordok Brute"),
(@ENTRY,0,2,"I'll crush you!",12,0,100,0,0,0,"Gordok Brute"),
(@ENTRY,1,0,"%s becomes enraged!",16,0,100,0,0,0,"Gordok Brute");

-- Gordok Mauler SAI
SET @ENTRY := 11442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,3,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Mauler - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,10000,8000,12000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Mauler - In Combat - Cast 3391 (Normal Dungeon)"),
(@ENTRY,0,2,3,2,0,100,3,0,30,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mauler - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mauler - Between 0-30% Health - Say Line 1 (Normal Dungeon)");

-- Texts for Gordok Mauler
SET @ENTRY := 11442;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,"Gordok Mauler"),
(@ENTRY,0,1,"Me smash! You die!",12,0,100,0,0,0,"Gordok Mauler"),
(@ENTRY,0,2,"I'll crush you!",12,0,100,0,0,0,"Gordok Mauler"),
(@ENTRY,1,0,"%s becomes enraged!",16,0,100,0,0,0,"Gordok Mauler");

-- Gordok Captain SAI
SET @ENTRY := 11445;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,7000,9000,11,22575,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Captain - In Combat - Cast 22575 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,10000,9000,12000,11,22574,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Captain - In Combat - Cast 22574 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,1000,3000,11000,18000,11,16244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Captain - In Combat - Cast 16244 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,9000,15000,16000,20000,11,12096,1,0,0,0,0,6,0,0,0,0,0,0,0,"Gordok Captain - In Combat - Cast 12096 (Normal Dungeon)");

-- Gordok Reaver SAI
SET @ENTRY := 11450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,7000,12000,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Reaver - In Combat - Cast 16145 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,11000,14000,9000,12000,11,15284,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Reaver - In Combat - Cast 15284 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,13000,11000,15000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Reaver - In Combat - Cast 13737 (Normal Dungeon)");

-- Wildspawn Trickster SAI
SET @ENTRY := 11453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,30000,45000,11,22371,32,0,0,0,0,5,0,0,0,0,0,0,0,"Wildspawn Trickster - In Combat - Cast 22371 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,10000,15000,30000,45000,11,12493,32,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Trickster - In Combat - Cast 12493 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,10000,16000,22000,11,3609,1,0,0,0,0,6,0,0,0,0,0,0,0,"Wildspawn Trickster - In Combat - Cast 3609 (Normal Dungeon)");

-- Petrified Treant SAI
SET @ENTRY := 11458;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,50,25400,42900,11,22693,0,0,0,0,0,1,0,0,0,0,0,0,0,"Petrified Treant - Between 0-50% Health - Cast 22693 (Normal Dungeon)");

-- Ironbark Protector SAI
SET @ENTRY := 11459;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,5000,9000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ironbark Protector - In Combat - Cast 5568 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,14000,18000,11,18670,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironbark Protector - In Combat - Cast 18670 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,19000,25000,11,28858,1,0,0,0,0,5,0,0,0,0,0,0,0,"Ironbark Protector - In Combat - Cast 28858 (Normal Dungeon)");

-- Warpwood Guardian SAI
SET @ENTRY := 11461;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,23000,27000,11,16172,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warpwood Guardian - In Combat - Cast 16172 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,10000,12000,15000,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warpwood Guardian - In Combat - Cast 15615 (Normal Dungeon)"),
(@ENTRY,0,2,0,14,0,100,2,3400,40,19000,34000,11,22373,1,0,0,0,0,7,0,0,0,0,0,0,0,"Warpwood Guardian - On Friendly Unit At 3400 Health Within 40 Range - Cast 22373 (Normal Dungeon)");

-- Warpwood Tangler SAI
SET @ENTRY := 11464;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,5000,7000,11,22414,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warpwood Tangler - In Combat - Cast 22414 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,18000,22000,11,22415,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warpwood Tangler - In Combat - Cast 22415 (Normal Dungeon)");

-- Warpwood Stomper SAI
SET @ENTRY := 11465;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,12000,11000,16000,11,22414,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warpwood Stomper - In Combat - Cast 22414 (Normal Dungeon)");

-- Tsu'zee SAI
SET @ENTRY := 11467;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,5000,7000,11,15581,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tsu'zee - In Combat - Cast 15581 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,6000,8000,9000,12000,11,12540,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tsu'zee - In Combat - Cast 12540 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,16000,21000,11,21060,1,0,0,0,0,6,0,0,0,0,0,0,0,"Tsu'zee - In Combat - Cast 21060 (Normal Dungeon)");

-- Eldreth Seether SAI
SET @ENTRY := 11469;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,25000,25000,50000,52500,11,16843,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Seether - In Combat - Cast 16843 (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,3,0,30,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Seether - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Seether - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Eldreth Seether
SET @ENTRY := 11469;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Eldreth Seether");

-- Eldreth Sorcerer SAI
SET @ENTRY := 11470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,4000,11000,13000,11,16006,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Sorcerer - In Combat - Cast 16006 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,30000,40000,11,22823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Sorcerer - In Combat - Cast 22823 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,15000,21000,41000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Eldreth Sorcerer - In Combat - Cast 13323 (Normal Dungeon)");

-- Eldreth Spirit SAI
SET @ENTRY := 11472;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,20000,30000,11,16838,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Spirit - In Combat - Cast 16838 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,15000,22000,11,22743,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Spirit - In Combat - Cast 22743 (Normal Dungeon)");

-- Eldreth Spectre SAI
SET @ENTRY := 11473;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,500,500,0,0,11,32811,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Spectre - Out Of Combat - Cast 32811 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,3,2000,2000,0,0,28,32811,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Spectre - In Combat - Remove Aura 32811 (Normal Dungeon)"),
(@ENTRY,0,2,0,14,0,100,3,2000,10,0,0,11,7154,0,0,0,0,0,7,0,0,0,0,0,0,0,"Eldreth Spectre - On Friendly Unit At 2000 Health Within 10 Range - Cast 7154 (Normal Dungeon)"),
(@ENTRY,0,3,0,14,0,100,3,4000,10,0,0,11,7154,0,0,0,0,0,7,0,0,0,0,0,0,0,"Eldreth Spectre - On Friendly Unit At 4000 Health Within 10 Range - Cast 7154 (Normal Dungeon)"),
(@ENTRY,0,4,0,14,0,100,3,6000,10,0,0,11,7154,0,0,0,0,0,7,0,0,0,0,0,0,0,"Eldreth Spectre - On Friendly Unit At 6000 Health Within 10 Range - Cast 7154 (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,2,9000,12000,22000,26000,11,17201,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Spectre - In Combat - Cast 17201 (Normal Dungeon)");

-- Eldreth Phantasm SAI
SET @ENTRY := 11475;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,7000,20000,35000,11,17831,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Phantasm - In Combat - Cast 17831 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,50,2,25000,25000,140000,141000,11,15802,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Phantasm - In Combat - Cast 15802 (Normal Dungeon)");

-- Skeletal Highborne SAI
SET @ENTRY := 11476;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,8000,12000,11,21081,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Highborne - In Combat - Cast 21081 (Normal Dungeon)");

-- Arcane Aberration SAI
SET @ENTRY := 11480;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,40,2400,3800,11,15979,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Aberration - Between 0-40 Range - Cast 15979 (Normal Dungeon)"),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,11,22936,7,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Aberration - On Death - Cast 22936 (Normal Dungeon)");

-- Mana Remnant SAI
SET @ENTRY := 11483;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,14514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mana Remnant - On Aggro - Cast 14514 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,8000,11000,11,15659,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Remnant - In Combat - Cast 15659 (Normal Dungeon)");

-- Residual Monstrosity SAI
SET @ENTRY := 11484;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,40,2400,3800,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Residual Monstrosity - Between 0-40 Range - Cast 15230 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,9000,14000,11,22940,1,0,0,0,0,5,0,0,0,0,0,0,0,"Residual Monstrosity - In Combat - Cast 22940 (Normal Dungeon)"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,11,22939,7,0,0,0,0,1,0,0,0,0,0,0,0,"Residual Monstrosity - On Death - Cast 22939 (Normal Dungeon)");

-- Prince Tortheldrin SAI
SET @ENTRY := 11486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Tortheldrin - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,6000,9000,11,15589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Tortheldrin - In Combat - Cast 15589 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,8000,12000,10000,12000,11,22920,1,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Tortheldrin - In Combat - Cast 22920 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,1000,3000,6000,9000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Tortheldrin - In Combat - Cast 3391 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,12000,15000,15000,20000,11,22995,1,0,0,0,0,6,0,0,0,0,0,0,0,"Prince Tortheldrin - In Combat - Cast 22995 (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,2,13000,16000,30000,40000,11,20537,1,0,0,0,0,5,0,0,0,0,0,0,0,"Prince Tortheldrin - In Combat - Cast 20537 (Normal Dungeon)");

-- Texts for Prince Tortheldrin
SET @ENTRY := 11486;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Who dares disrupt the sanctity of Eldre'Thalas? Face me, cowards!",14,0,100,0,0,0,"Prince Tortheldrin");

-- Magister Kalendris SAI
SET @ENTRY := 11487;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,6000,8000,11,17287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magister Kalendris - In Combat - Cast 17287 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,20000,24000,11,17146,1,0,0,0,0,2,0,0,0,0,0,0,0,"Magister Kalendris - In Combat - Cast 17146 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,10000,9000,12000,11,22919,0,0,0,0,0,5,0,0,0,0,0,0,0,"Magister Kalendris - In Combat - Cast 22919 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,8000,12000,15000,20000,11,7645,1,0,0,0,0,6,0,0,0,0,0,0,0,"Magister Kalendris - In Combat - Cast 7645 (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,60,0,0,11,22917,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Kalendris - Between 0-60% Health - Cast 22917 (Normal Dungeon)"),
(@ENTRY,0,5,0,2,0,100,3,0,30,0,0,28,22917,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Kalendris - Between 0-30% Health - Remove Aura 22917 (Normal Dungeon)");

-- Illyanna Ravenoak SAI
SET @ENTRY := 11488;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,12000,60000,65000,11,22908,1,0,0,0,0,2,0,0,0,0,0,0,0,"Illyanna Ravenoak - In Combat - Cast 22908 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,1000,3000,6000,9000,11,22940,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illyanna Ravenoak - In Combat - Cast 22940 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,5000,9000,12000,15000,11,22914,1,0,0,0,0,2,0,0,0,0,0,0,0,"Illyanna Ravenoak - In Combat - Cast 22914 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,3000,5000,25000,35000,11,22910,32,0,0,0,0,1,0,0,0,0,0,0,0,"Illyanna Ravenoak - In Combat - Cast 22910 (Normal Dungeon)");

-- Tendris Warpwood SAI
SET @ENTRY := 11489;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,9000,14000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tendris Warpwood - In Combat - Cast 5568 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,9000,12000,12000,15000,11,22916,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tendris Warpwood - In Combat - Cast 22916 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,2000,4000,17000,22000,11,22924,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tendris Warpwood - In Combat - Cast 22924 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,6000,12000,15000,20000,11,22994,32,0,0,0,0,6,0,0,0,0,0,0,0,"Tendris Warpwood - In Combat - Cast 22994 (Normal Dungeon)");

-- Zevrim Thornhoof SAI
SET @ENTRY := 11490;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,20000,26000,11,22478,0,0,0,0,0,5,0,0,0,0,0,0,0,"Zevrim Thornhoof - In Combat - Cast 22478 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,9000,12000,15000,18000,11,22651,1,0,0,0,0,5,0,0,0,0,0,0,0,"Zevrim Thornhoof - In Combat - Cast 22651 (Normal Dungeon)");

-- Immol'thar SAI
SET @ENTRY := 11496;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,9000,14000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Immol'thar - In Combat - Cast 5568 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,8000,12000,11,16128,33,0,0,0,0,2,0,0,0,0,0,0,0,"Immol'thar - In Combat - Cast 16128 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,12000,15000,22000,11,22899,1,0,0,0,0,1,0,0,0,0,0,0,0,"Immol'thar - In Combat - Cast 22899 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,10000,14000,17000,24000,11,22950,1,0,0,0,0,5,0,0,0,0,0,0,0,"Immol'thar - In Combat - Cast 22950 (Normal Dungeon)"),
(@ENTRY,0,4,5,2,0,100,3,0,30,180000,180000,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Immol'thar - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Immol'thar - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Immol'thar
SET @ENTRY := 11496;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Immol\'thar");

-- King Gordok SAI
SET @ENTRY := 11501;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,22886,0,0,0,0,0,2,0,0,0,0,0,0,0,"King Gordok - On Aggro - Cast 22886 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,7000,9000,14000,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,"King Gordok - In Combat - Cast 15708 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,3000,5000,7000,12000,11,15572,1,0,0,0,0,2,0,0,0,0,0,0,0,"King Gordok - In Combat - Cast 15572 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,12000,15000,17000,24000,11,16727,1,0,0,0,0,1,0,0,0,0,0,0,0,"King Gordok - In Combat - Cast 16727 (Normal Dungeon)");

-- Scholomance Dark Summoner SAI
SET @ENTRY := 11582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Dark Summoner - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,95,2,500,2800,1900,3700,11,17618,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Dark Summoner - In Combat - Cast 17618 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,0,500,38700,49300,11,12279,32,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Dark Summoner - In Combat - Cast 12279 (Normal Dungeon)");

-- Texts for Scholomance Dark Summoner
SET @ENTRY := 11582;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Now this is an example of what not to summon. Look, it's frail and brittle. One good whack from a mace will send bone shards flying.",12,0,100,0,0,0,"Scholomance Dark Summoner"),
(@ENTRY,0,1,"Hmmm, this one looks like something that would be better off as a windchime. Take notes class... This is NOT what you want to summon in the heat of battle.",12,0,100,0,0,0,"Scholomance Dark Summoner"),
(@ENTRY,0,2,"This one is slightly better than the last. However, it still suffers from the same flimsy bone structure as the others. When you summon one of these, you are on the right path.",12,0,100,0,0,0,"Scholomance Dark Summoner");

-- Taskmaster Snivvle SAI
SET @ENTRY := 11677;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Taskmaster Snivvle - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,6000,9000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Taskmaster Snivvle - In Combat - Cast 14516 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,6000,8000,7000,11000,11,3391,1,0,0,0,0,1,0,0,0,0,0,0,0,"Taskmaster Snivvle - In Combat - Cast 3391 (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,2,0,30,30000,35000,11,16170,1,0,0,0,0,1,0,0,0,0,0,0,0,"Taskmaster Snivvle - Between 0-30% Health - Cast 16170 (Normal Dungeon)");

-- Texts for Taskmaster Snivvle
SET @ENTRY := 11677;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Snivvle is here! Snivvle claims the Coldtooth Mine!",12,0,100,0,0,0,"Taskmaster Snivvle");

-- Desert Rager SAI
SET @ENTRY := 11747;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,18000,18000,5000,5000,11,13728,0,0,0,0,0,2,0,0,0,0,0,0,0,"Desert Rager - In Combat - Cast 13728"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Rager - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Rager - Between 0-30% Health - Say Line 0");

-- Texts for Desert Rager
SET @ENTRY := 11747;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Desert Rager");

-- Wildpaw Alpha SAI
SET @ENTRY := 11840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,9000,9000,13000,11,18072,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildpaw Alpha - In Combat - Cast 18072 (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,3,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Alpha - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Alpha - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Wildpaw Alpha
SET @ENTRY := 11840;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Wildpaw Alpha");

-- Gor'marok the Ravager SAI
SET @ENTRY := 12046;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,12000,6000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gor'marok the Ravager - In Combat - Cast 15496"),
(@ENTRY,0,1,0,0,0,100,0,5000,10000,9000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gor'marok the Ravager - In Combat - Cast 16856"),
(@ENTRY,0,2,3,2,0,100,1,0,50,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gor'marok the Ravager - Between 0-50% Health - Cast 8599"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gor'marok the Ravager - Between 0-50% Health - Say Line 0");

-- Texts for Gor'marok the Ravager
SET @ENTRY := 12046;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Gor\'marok the Ravager");

-- Drakan SAI
SET @ENTRY := 12121;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakan - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakan - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Drakan
SET @ENTRY := 12121;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Drakan");

-- Duros SAI
SET @ENTRY := 12122;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Duros - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duros - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Duros
SET @ENTRY := 12122;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Duros");

-- Lunaclaw SAI
SET @ENTRY := 12138;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,2500,4500,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lunaclaw - In Combat - Cast 3391"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,18986,7,0,0,0,0,1,0,0,0,0,0,0,0,"Lunaclaw - On Death - Cast 18986");

-- Burning Blade Toxicologist SAI
SET @ENTRY := 12319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,696,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Toxicologist - On Aggro - Cast 696"),
(@ENTRY,0,1,0,0,0,85,0,5000,5000,25000,25000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Toxicologist - In Combat - Cast 11962"),
(@ENTRY,0,2,0,0,0,85,0,9000,9000,32000,32000,11,980,0,0,0,0,0,5,0,0,0,0,0,0,0,"Burning Blade Toxicologist - In Combat - Cast 980"),
(@ENTRY,0,3,0,2,0,100,0,0,50,15000,15000,11,689,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Toxicologist - Between 0-50% Health - Cast 689");

-- Burning Blade Crusher SAI
SET @ENTRY := 12320;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,4133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Crusher - On Aggro - Cast 4133");

-- Bloodfury Ripper SAI
SET @ENTRY := 12579;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,5000,5000,23000,23000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfury Ripper - In Combat - Cast 13443"),
(@ENTRY,0,1,2,2,0,100,1,0,40,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Ripper - Between 0-40% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Ripper - Between 0-40% Health - Say Line 0");

-- Texts for Bloodfury Ripper
SET @ENTRY := 12579;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bloodfury Ripper");

-- Chief Murgut SAI
SET @ENTRY := 12918;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Murgut - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,20818,7,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Murgut - On Death - Cast 20818"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Murgut - On Death - Say Line 1");

-- Texts for Chief Murgut
SET @ENTRY := 12918;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"You are a little gnat to the Foulweald!  Die!",12,0,100,0,0,0,"Chief Murgut"),
(@ENTRY,1,0,"No!  You cannot be stronger than the Foulweald!  No!!",12,0,100,0,0,0,"Chief Murgut");

-- Enraged Foulweald SAI
SET @ENTRY := 12921;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6821,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Foulweald - On Respawn - Cast 6821"),
(@ENTRY,0,1,2,8,0,100,1,20746,0,0,0,11,20786,1,0,0,0,0,7,0,0,0,0,0,0,0,"Enraged Foulweald - On Spellhit By 20746 - Cast 20786"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Foulweald - On Spellhit By 20746 - Say Line 0");

-- Texts for Enraged Foulweald
SET @ENTRY := 12921;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s attacks Karang's Banner!",16,0,100,0,0,0,"Enraged Foulweald");

-- Gordok Mastiff SAI
SET @ENTRY := 13036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,15000,20000,11,13738,32,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Mastiff - In Combat - Cast 13738 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,1000,3000,5000,12000,11,3604,32,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Mastiff - In Combat - Cast 3604 (Normal Dungeon)");

-- Echo of Archimonde SAI
SET @ENTRY := 13083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,15000,15000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Echo of Archimonde - Out Of Combat - Say Line 0 (Normal Dungeon)");

-- Texts for Echo of Archimonde
SET @ENTRY := 13083;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"All of your efforts have been in vain, for the draining of the World Tree has already begun! Soon, the heart of your world shall beat no more!",14,0,100,0,0,10986,"Echo of Archimonde");

-- Carrion Swarmer SAI
SET @ENTRY := 13160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,14200,21700,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Carrion Swarmer - Between 0-5 Range - Cast 5416 (Normal Dungeon)");

-- Wildspawn Imp SAI
SET @ENTRY := 13276;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,6100,15700,11,13340,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Imp - Between 0-20 Range - Cast 13340 (Normal Dungeon)");

-- Hydrospawn SAI
SET @ENTRY := 13280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,6000,45000,65000,11,22420,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hydrospawn - In Combat - Cast 22420 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,12000,15000,22000,11,22421,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hydrospawn - In Combat - Cast 22421 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,12000,15000,12000,16000,11,22419,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hydrospawn - In Combat - Cast 22419 (Normal Dungeon)"),
(@ENTRY,0,3,0,6,0,100,3,0,0,0,0,11,22714,7,0,0,0,0,1,0,0,0,0,0,0,0,"Hydrospawn - On Death - Cast 22714 (Normal Dungeon)");

-- Death Lash SAI
SET @ENTRY := 13285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,25640,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death Lash - Out Of Combat - Cast 25640 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,7000,9000,11,3391,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death Lash - In Combat - Cast 3391 (Normal Dungeon)");

-- Stormpike Bowman SAI
SET @ENTRY := 13358;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpike Bowman - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpike Bowman - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,22121,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpike Bowman - On Aggro - Cast 22121 (Normal Dungeon)"),
(@ENTRY,0,3,4,9,1,100,2,0,80,2300,3900,11,22121,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpike Bowman - Between 0-80 Range - Cast 22121 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpike Bowman - Between 0-80 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,5,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpike Bowman - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Frostwolf Bowman SAI
SET @ENTRY := 13359;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostwolf Bowman - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostwolf Bowman - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,22121,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostwolf Bowman - On Aggro - Cast 22121 (Normal Dungeon)"),
(@ENTRY,0,3,4,9,0,100,2,0,80,2300,3900,11,22121,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostwolf Bowman - Between 0-80 Range - Cast 22121 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostwolf Bowman - Between 0-80 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,5,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostwolf Bowman - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Petrified Guardian SAI
SET @ENTRY := 14303;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,22696,0,0,0,0,0,1,0,0,0,0,0,0,0,"Petrified Guardian - Out Of Combat - Cast 22696 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,2,0,50,23000,26000,11,22695,1,0,0,0,0,1,0,0,0,0,0,0,0,"Petrified Guardian - Between 0-50% Health - Cast 22695 (Normal Dungeon)");

-- Ferra SAI
SET @ENTRY := 14308;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,22911,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ferra - On Aggro - Cast 22911 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,5000,8000,11,17156,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ferra - In Combat - Cast 17156 (Normal Dungeon)");

-- Guard Fengus SAI
SET @ENTRY := 14321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Fengus - On Aggro - Cast 15749 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,8000,12000,11,15580,1,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Fengus - In Combat - Cast 15580 (Normal Dungeon)"),
(@ENTRY,0,2,0,13,0,100,3,0,0,0,0,11,11972,1,0,0,0,0,7,0,0,0,0,0,0,0,"Guard Fengus - On Target Casting - Cast 11972 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,7000,12000,12000,15000,11,10101,1,0,0,0,0,5,0,0,0,0,0,0,0,"Guard Fengus - In Combat - Cast 10101 (Normal Dungeon)"),
(@ENTRY,0,4,5,2,0,100,2,0,30,120000,120000,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Fengus - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Fengus - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,6,0,6,0,100,3,0,0,0,0,11,22817,7,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Fengus - On Death - Cast 22817 (Normal Dungeon)");

-- Texts for Guard Fengus
SET @ENTRY := 14321;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Guard Fengus");

-- Stomper Kreeg SAI
SET @ENTRY := 14322;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,6000,7000,10000,11,15577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stomper Kreeg - In Combat - Cast 15577 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,12000,15000,22000,11,22833,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stomper Kreeg - In Combat - Cast 22833 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,12000,15000,12000,16000,11,16740,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stomper Kreeg - In Combat - Cast 16740 (Normal Dungeon)"),
(@ENTRY,0,3,4,2,0,100,3,0,30,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stomper Kreeg - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stomper Kreeg - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,5,0,2,0,100,3,0,15,0,0,11,22835,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stomper Kreeg - Between 0-15% Health - Cast 22835 (Normal Dungeon)");

-- Texts for Stomper Kreeg
SET @ENTRY := 14322;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Stomper Kreeg");

-- Guard Slip'kik SAI
SET @ENTRY := 14323;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Slip'kik - On Aggro - Cast 15749 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,8000,12000,11,15580,1,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Slip'kik - In Combat - Cast 15580 (Normal Dungeon)"),
(@ENTRY,0,2,0,13,0,100,3,0,0,0,0,11,11972,1,0,0,0,0,7,0,0,0,0,0,0,0,"Guard Slip'kik - On Target Casting - Cast 11972 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,7000,12000,12000,15000,11,10101,1,0,0,0,0,5,0,0,0,0,0,0,0,"Guard Slip'kik - In Combat - Cast 10101 (Normal Dungeon)"),
(@ENTRY,0,4,5,2,0,100,2,0,30,120000,120000,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Slip'kik - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Slip'kik - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,6,0,6,0,100,3,0,0,0,0,11,22820,7,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Slip'kik - On Death - Cast 22820 (Normal Dungeon)");

-- Texts for Guard Slip'kik
SET @ENTRY := 14323;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Guard Slip\'kik");

-- Captain Kromcrush SAI
SET @ENTRY := 14325;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kromcrush - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,11000,7000,11000,11,22859,0,0,0,0,0,5,0,0,0,0,0,0,0,"Captain Kromcrush - In Combat - Cast 22859 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,12000,21000,25000,35000,11,22857,1,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kromcrush - In Combat - Cast 22857 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,9000,18000,15000,19000,11,19134,1,0,0,0,0,6,0,0,0,0,0,0,0,"Captain Kromcrush - In Combat - Cast 19134 (Normal Dungeon)"),
(@ENTRY,0,4,5,2,0,100,3,0,75,0,0,11,22860,1,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kromcrush - Between 0-75% Health - Cast 22860 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kromcrush - Between 0-75% Health - Say Line 1 (Normal Dungeon)"),
(@ENTRY,0,6,7,2,0,100,3,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kromcrush - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kromcrush - Between 0-30% Health - Say Line 2 (Normal Dungeon)");

-- Texts for Captain Kromcrush
SET @ENTRY := 14325;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"No one get past me and threaten da king!  Ungh, take it!!",12,0,100,0,0,0,"Captain Kromcrush"),
(@ENTRY,1,0,"Help me crush these punys!",14,0,100,0,0,0,"Captain Kromcrush"),
(@ENTRY,2,0,"%s begins to retaliate all attacks against him!",16,0,100,0,0,0,"Captain Kromcrush");

-- Guard Mol'dar SAI
SET @ENTRY := 14326;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Mol'dar - On Aggro - Cast 15749 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,8000,12000,11,15580,1,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Mol'dar - In Combat - Cast 15580 (Normal Dungeon)"),
(@ENTRY,0,2,0,13,0,100,3,0,0,0,0,11,11972,1,0,0,0,0,7,0,0,0,0,0,0,0,"Guard Mol'dar - On Target Casting - Cast 11972 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,7000,12000,12000,15000,11,10101,1,0,0,0,0,5,0,0,0,0,0,0,0,"Guard Mol'dar - In Combat - Cast 10101 (Normal Dungeon)"),
(@ENTRY,0,4,5,2,0,100,2,0,30,120000,120000,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Mol'dar - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Mol'dar - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,6,0,6,0,100,3,0,0,0,0,11,22818,7,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Mol'dar - On Death - Cast 22818 (Normal Dungeon)");

-- Texts for Guard Mol'dar
SET @ENTRY := 14326;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Guard Mol\'dar");

-- Gordok Bushwacker SAI
SET @ENTRY := 14351;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,7000,12000,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Bushwacker - In Combat - Cast 16145 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,11000,14000,9000,12000,11,15284,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Bushwacker - In Combat - Cast 15284 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,13000,11000,15000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Bushwacker - In Combat - Cast 13737 (Normal Dungeon)");

-- Wandering Eye of Kilrogg SAI
SET @ENTRY := 14386;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,12000,20000,11,22876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wandering Eye of Kilrogg - In Combat - Cast 22876 (Normal Dungeon)");

-- Mirelow SAI
SET @ENTRY := 14424;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10800,16500,14300,28200,11,22127,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mirelow - In Combat - Cast 22127");

-- Gnawbone SAI
SET @ENTRY := 14425;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8400,8400,8300,26900,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gnawbone - In Combat - Cast 11977"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gnawbone - Between 0-15% Health - Flee For Assist");

-- Sludginn SAI
SET @ENTRY := 14433;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3600,3600,185900,189900,11,3335,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sludginn - In Combat - Cast 3335"),
(@ENTRY,0,1,0,0,0,100,0,10700,10700,16300,35300,11,3358,32,0,0,0,0,2,0,0,0,0,0,0,0,"Sludginn - In Combat - Cast 3358");

-- Vekniss Guardian SAI
SET @ENTRY := 15233;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vekniss Guardian - Between 0-20% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vekniss Guardian - Between 0-20% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,500,500,5000,5000,11,26025,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vekniss Guardian - In Combat - Cast 26025 (Normal Dungeon)");

-- Texts for Vekniss Guardian
SET @ENTRY := 15233;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Vekniss Guardian");

-- Qiraji Champion SAI
SET @ENTRY := 15252;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,500,500,4000,4000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Champion - In Combat - Cast 40504 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8000,8000,14000,14000,11,19134,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Champion - In Combat - Cast 19134 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4500,4500,12000,12000,11,11130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Champion - In Combat - Cast 11130 (Normal Dungeon)"),
(@ENTRY,0,3,4,2,0,100,2,1,25,30000,30000,11,25164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Qiraji Champion - Between 1-25% Health - Cast 25164 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Qiraji Champion - Between 1-25% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Qiraji Champion
SET @ENTRY := 15252;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Qiraji Champion");

-- Anubisath Warder SAI
SET @ENTRY := 15311;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,0,0,31,1,4,0,0,0,0,1,0,0,0,0,0,0,0,"Anubisath Warder - In Combat - Random Phase Range (1-4) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,2,100,2,5000,5000,20000,20000,11,26071,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anubisath Warder - In Combat - Cast 26071 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,2,0,0,4,100,2,5000,5000,20000,20000,11,26070,0,0,0,0,0,6,0,0,0,0,0,0,0,"Anubisath Warder - In Combat - Cast 26070 (Normal Dungeon) (Phase 4)"),
(@ENTRY,0,3,0,0,8,100,2,4000,4000,15000,15000,11,26072,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anubisath Warder - In Combat - Cast 26072 (Normal Dungeon) (Phase 8)"),
(@ENTRY,0,4,0,0,0,100,2,4000,4000,15000,15000,11,26069,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anubisath Warder - In Combat - Cast 26069 (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,2,750,750,3000,3000,11,26073,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anubisath Warder - In Combat - Cast 26073 (Normal Dungeon)");

-- Obsidian Nullifier SAI
SET @ENTRY := 15312;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,0,0,500,500,108,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Nullifier - Out Of Combat - Set Mana To 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,1500,1500,11,25671,0,0,0,0,0,5,0,0,0,0,0,0,0,"Obsidian Nullifier - In Combat - Cast 25671 (Normal Dungeon)"),
(@ENTRY,0,2,0,3,0,100,2,99,100,1000,1000,11,26552,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Nullifier - Between 99-100% Mana - Cast 26552 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,0,0,2500,2500,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Obsidian Nullifier - In Combat - Cast 40504 (Normal Dungeon)");

-- Anubisath Warrior SAI
SET @ENTRY := 15537;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anubisath Warrior - Between 0-20% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anubisath Warrior - Between 0-20% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,6000,6000,12000,12000,11,15550,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anubisath Warrior - In Combat - Cast 15550 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,0,0,12000,12000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anubisath Warrior - In Combat - Cast 10966 (Normal Dungeon)");

-- Texts for Anubisath Warrior
SET @ENTRY := 15537;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Anubisath Warrior");

-- Crypt Reaver SAI
SET @ENTRY := 15978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,5000,6000,9000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crypt Reaver - In Combat - Cast 40504 (Dungeon Only)"),
(@ENTRY,0,1,2,2,0,100,6,0,30,120000,120000,11,56625,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crypt Reaver - Between 0-30% Health - Cast 56625 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crypt Reaver - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Crypt Reaver
SET @ENTRY := 15978;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Crypt Reaver");

-- Lord Valthalak Trigger SAI
SET @ENTRY := 16048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,3,27202,0,0,0,12,16042,1,60000,0,0,0,2,0,0,0,0,0,0,0,"Lord Valthalak Trigger - On Spellhit By 27202 - Summon Creature Lord Valthalak (Normal Dungeon)"),
(@ENTRY,0,1,0,8,0,100,3,27202,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Valthalak Trigger - On Spellhit By 27202 - Forced Despawn (Normal Dungeon)");

-- Spectral Assassin SAI
SET @ENTRY := 16066;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,7000,9000,11,18663,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Assassin - In Combat - Cast 18663 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,3,10000,15000,0,0,11,27177,0,0,0,0,0,6,0,0,0,0,0,0,0,"Spectral Assassin - In Combat - Cast 27177 (Normal Dungeon)");

-- Empyrean SAI
SET @ENTRY := 16098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,8000,12000,11,17963,0,0,0,0,0,2,0,0,0,0,0,0,0,"Empyrean - In Combat - Cast 17963 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,12000,19000,24000,11,27638,0,0,0,0,0,2,0,0,0,0,0,0,0,"Empyrean - In Combat - Cast 27638 (Normal Dungeon)"),
(@ENTRY,0,2,3,2,0,100,2,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Empyrean - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empyrean - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Empyrean
SET @ENTRY := 16098;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Empyrean");

-- Plague Slime SAI
SET @ENTRY := 16243;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,7,0,0,0,0,31,1,4,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Slime - In Combat - Random Phase Range (1-4) (Dungeon Only)"),
(@ENTRY,0,1,0,0,2,100,7,1000,1000,0,0,11,28987,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Slime - In Combat - Cast 28987 (Dungeon Only) (Phase 2)"),
(@ENTRY,0,2,0,0,4,100,7,1000,1000,0,0,11,28988,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Slime - In Combat - Cast 28988 (Dungeon Only) (Phase 4)"),
(@ENTRY,0,3,0,0,8,100,7,1000,1000,0,0,11,28989,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Slime - In Combat - Cast 28989 (Dungeon Only) (Phase 8)"),
(@ENTRY,0,4,0,0,0,100,7,1000,1000,0,0,11,28990,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Slime - In Combat - Cast 28990 (Dungeon Only)");

-- Infectious Ghoul SAI
SET @ENTRY := 16244;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,9000,12000,11,29915,32,0,0,0,0,5,0,0,0,0,0,0,0,"Infectious Ghoul - In Combat - Cast 29915 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,3000,6000,9000,12000,11,54709,32,0,0,0,0,5,0,0,0,0,0,0,0,"Infectious Ghoul - In Combat - Cast 54709 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,8000,14000,19000,24000,11,54703,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infectious Ghoul - In Combat - Cast 54703 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,8000,14000,19000,24000,11,54708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infectious Ghoul - In Combat - Cast 54708 (Heroic Dungeon)"),
(@ENTRY,0,4,5,2,0,100,6,0,30,90000,90000,11,54701,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infectious Ghoul - Between 0-30% Health - Cast 54701 (Dungeon Only)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infectious Ghoul - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Infectious Ghoul
SET @ENTRY := 16244;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Infectious Ghoul");

-- Phantom Attendant SAI
SET @ENTRY := 16406;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantom Attendant - On Death - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,75,2,17000,17000,25000,25000,11,29587,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantom Attendant - In Combat - Cast 29587 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,80,2,7000,7000,30000,30000,11,29930,0,0,0,0,0,5,0,0,0,0,0,0,0,"Phantom Attendant - In Combat - Cast 29930 (Normal Dungeon)"),
(@ENTRY,0,3,0,13,0,80,2,30000,30000,0,0,11,29586,1,0,0,0,0,6,0,0,0,0,0,0,0,"Phantom Attendant - On Target Casting - Cast 29586 (Normal Dungeon)");

-- Texts for Phantom Attendant
SET @ENTRY := 16406;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"What is happening?",12,0,100,0,0,0,"Phantom Attendant"),
(@ENTRY,0,1,"Where am I? What...",12,0,100,0,0,0,"Phantom Attendant");

-- Phantom Valet SAI
SET @ENTRY := 16408;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,9000,9000,35000,35000,11,29584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phantom Valet - In Combat - Cast 29584 (Normal Dungeon)"),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantom Valet - On Death - Say Line 0 (Normal Dungeon)");

-- Texts for Phantom Valet
SET @ENTRY := 16408;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The fates have turned against me!",12,0,100,0,0,0,"Phantom Valet");

-- Phantom Guest SAI
SET @ENTRY := 16409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,17000,17000,17000,17000,11,29582,0,0,0,0,0,6,0,0,0,0,0,0,0,"Phantom Guest - In Combat - Cast 29582 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,70,2,20000,20000,20000,20000,11,29580,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantom Guest - In Combat - Cast 29580 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,70,2,13000,13000,13000,13000,11,29583,0,0,0,0,0,5,0,0,0,0,0,0,0,"Phantom Guest - In Combat - Cast 29583 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,70,2,22000,22000,22000,22000,11,29928,0,0,0,0,0,5,0,0,0,0,0,0,0,"Phantom Guest - In Combat - Cast 29928 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,70,2,30000,30000,30000,30000,11,29492,0,0,0,0,0,5,0,0,0,0,0,0,0,"Phantom Guest - In Combat - Cast 29492 (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,70,2,45000,45000,45000,45000,11,29930,0,0,0,0,0,5,0,0,0,0,0,0,0,"Phantom Guest - In Combat - Cast 29930 (Normal Dungeon)"),
(@ENTRY,0,6,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantom Guest - On Death - Say Line 0 (Normal Dungeon)");

-- Texts for Phantom Guest
SET @ENTRY := 16409;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Not... Fair...",12,0,100,0,0,0,"Phantom Guest");

-- Ghostly Steward SAI
SET @ENTRY := 16414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,8000,8000,15000,15000,11,29690,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghostly Steward - In Combat - Cast 29690 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,3,0,25,0,0,11,29691,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostly Steward - Between 0-25% Health - Cast 29691 (Not found in DBCs!) (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostly Steward - Between 0-25% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,3,0,6,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostly Steward - On Death - Say Line 1 (Normal Dungeon)");

-- Texts for Ghostly Steward
SET @ENTRY := 16414;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"That was a 200 year old Pupellyverbos Port!",12,0,100,0,0,0,"Ghostly Steward"),
(@ENTRY,0,1,"That was wasted on the likes of you!",12,0,100,0,0,0,"Ghostly Steward"),
(@ENTRY,0,2,"How dare you disturb the master's dinner!",14,0,100,0,0,0,"Ghostly Steward"),
(@ENTRY,1,0,"Wait... No! No!",12,0,100,0,0,0,"Ghostly Steward");
