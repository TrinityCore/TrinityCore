-- Arcane Annihilator SAI
SET @ENTRY := 18856;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6300,6300,19500,22400,11,35892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Annihilator - In Combat - Cast 35892"),
(@ENTRY,0,1,0,0,0,100,0,14500,17700,21400,23600,11,33860,1,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Annihilator - In Combat - Cast 33860");

-- Sunfury Warp-Master SAI
SET @ENTRY := 18857;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,2900,5800,0,0,11,35919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Warp-Master - In Combat - Cast 35919");

-- Wrath Priestess SAI
SET @ENTRY := 18859;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,36226,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Priestess - On Respawn - Cast 36226"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,14000,17000,11,34017,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrath Priestess - In Combat - Cast 34017");

-- Daughter of Destiny SAI
SET @ENTRY := 18860;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,7000,10000,11,36225,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Destiny - In Combat - Cast 36225");

-- Mana Wraith SAI
SET @ENTRY := 18864;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,9000,13000,11,29054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Wraith - Between 0-30 Range - Cast 29054");

-- Mageslayer SAI
SET @ENTRY := 18866;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,16000,20000,11,36096,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mageslayer - In Combat - Cast 36096"),
(@ENTRY,0,1,0,0,0,100,1,8000,12000,15000,21000,11,36097,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mageslayer - In Combat - Cast 36097");

-- Mana Seeker SAI
SET @ENTRY := 18867;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,6000,9000,11,11981,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Seeker - In Combat - Cast 11981"),
(@ENTRY,0,1,0,9,0,100,0,0,25,16000,20000,11,36843,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Seeker - Between 0-25 Range - Cast 36843");

-- Unstable Voidwraith SAI
SET @ENTRY := 18869;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34302,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unstable Voidwraith - On Respawn - Cast 34302"),
(@ENTRY,0,1,2,2,0,8,1,0,15,0,0,11,36463,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unstable Voidwraith - Between 0-15% Health - Cast 36463"),
(@ENTRY,0,2,0,61,0,8,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unstable Voidwraith - Between 0-15% Health - Forced Despawn");

-- Disembodied Vindicator SAI
SET @ENTRY := 18872;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Disembodied Vindicator - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,15000,11,36002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Disembodied Vindicator - Between 0-5 Range - Cast 36002"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,36003,7,0,0,0,0,1,0,0,0,0,0,0,0,"Disembodied Vindicator - On Death - Cast 36003");

-- Disembodied Protector SAI
SET @ENTRY := 18873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Disembodied Protector - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,9,0,100,0,0,5,3000,5000,11,36647,0,0,0,0,0,2,0,0,0,0,0,0,0,"Disembodied Protector - Between 0-5 Range - Cast 36647"),
(@ENTRY,0,2,0,0,0,100,0,7000,11000,9000,12000,11,9734,1,0,0,0,0,2,0,0,0,0,0,0,0,"Disembodied Protector - In Combat - Cast 9734");

-- Zaxxis Raider SAI
SET @ENTRY := 18875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,12000,17000,11,35922,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zaxxis Raider - Between 0-8 Range - Cast 35922");

-- Nether Drake SAI
SET @ENTRY := 18877;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,14000,18000,11,36513,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nether Drake - Between 0-30 Range - Cast 36513");

-- Nether Ray SAI
SET @ENTRY := 18880;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,7000,11000,11,35334,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nether Ray - Between 0-20 Range - Cast 35334"),
(@ENTRY,0,1,0,9,0,100,0,0,15,6000,9000,11,36659,33,0,0,0,0,5,0,0,0,0,0,0,0,"Nether Ray - Between 0-15 Range - Cast 36659"),
(@ENTRY,0,2,0,9,0,100,0,0,10,11000,15000,11,17008,1,0,0,0,0,5,0,0,0,0,0,0,0,"Nether Ray - Between 0-10 Range - Cast 17008");

-- Sundered Thunderer SAI
SET @ENTRY := 18882;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,16000,19000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sundered Thunderer - Between 0-8 Range - Cast 8078"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,35007,7,0,0,0,0,1,0,0,0,0,0,0,0,"Sundered Thunderer - On Death - Cast 35007");

-- Mana Snapper SAI
SET @ENTRY := 18883;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,12000,15000,11,37176,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Snapper - Between 0-10 Range - Cast 37176"),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,14000,17000,11,36574,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mana Snapper - In Combat - Cast 36574"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,34814,7,0,0,0,0,1,0,0,0,0,0,0,0,"Mana Snapper - On Death - Cast 34814");

-- Spymistress Mehlisah Highcrown SAI
SET @ENTRY := 18893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,25000,5000,15000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spymistress Mehlisah Highcrown - Out Of Combat - Emote Talk");

-- Bonechewer Scavenger SAI
SET @ENTRY := 18952;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Scavenger - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,7000,9000,11,34113,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Scavenger - In Combat - Cast 34113"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,9000,11000,11,13398,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Scavenger - In Combat - Cast 13398"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bonechewer Scavenger - Between 0-15% Health - Flee For Assist");

-- Texts for Bonechewer Scavenger
SET @ENTRY := 18952;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Death to the interlopers!",12,0,100,0,0,0,"Bonechewer Scavenger");

-- Doomwhisperer SAI
SET @ENTRY := 18981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,10000,10000,11,33969,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doomwhisperer - In Combat - Cast 33969");

-- Blackfang Tarantula SAI
SET @ENTRY := 18983;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1400,3000,29800,30200,11,34366,32,0,0,0,0,5,0,0,0,0,0,0,0,"Blackfang Tarantula - In Combat - Cast 34366 (Dungeon Only)");

-- Infinite Executioner SAI
SET @ENTRY := 18994;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,30,1,1,2,0,0,0,1,0,0,0,0,0,0,0,"Infinite Executioner - On Aggro - Set Random Phase (Dungeon Only)"),
(@ENTRY,0,1,0,0,2,100,2,7300,14000,7300,14000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 15496 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,2,0,0,2,100,4,2000,11700,6000,11700,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 15496 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,3,0,0,2,100,4,600,10200,10800,15800,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 9080 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,4,0,0,0,100,2,7200,7200,9700,20300,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 15580 (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,4,2000,3900,9700,13700,11,34920,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Executioner - In Combat - Cast 34920 (Heroic Dungeon)");

-- Skettis Outcast SAI
SET @ENTRY := 19075;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,25000,5000,15000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Outcast - Out Of Combat - Emote Talk");

-- Anchorite Attendant SAI
SET @ENTRY := 19138;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,25,0,269500,269500,269500,269500,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Attendant - Out Of Combat - Say Line 0");

-- Texts for Anchorite Attendant
SET @ENTRY := 19138;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"May it be so.",12,0,100,0,0,0,"Anchorite Attendant");

-- Nagrand Target Dummy SAI
SET @ENTRY := 19139;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10350,10350,2350,2350,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nagrand Target Dummy - Out Of Combat - Emote Wounded"),
(@ENTRY,0,1,0,1,0,100,0,28350,28350,15350,15350,5,34,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nagrand Target Dummy - Out Of Combat - Emote Wounded Critical");

-- Mag'har Pitfighter SAI
SET @ENTRY := 19140;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,10000,2000,2000,11,33423,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Pitfighter - Out Of Combat - Cast 33423"),
(@ENTRY,0,1,0,1,0,100,0,28000,28000,15000,15000,5,60,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Pitfighter - Out Of Combat - Emote Kick"),
(@ENTRY,0,2,0,1,0,100,0,28000,28000,15000,15000,11,33425,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Pitfighter - Out Of Combat - Cast 33425");

-- Kurenai Pitfighter SAI
SET @ENTRY := 19141;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,10000,2000,2000,11,33423,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurenai Pitfighter - Out Of Combat - Cast 33423"),
(@ENTRY,0,1,0,1,0,100,0,28000,28000,15000,15000,5,60,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurenai Pitfighter - Out Of Combat - Emote Kick"),
(@ENTRY,0,2,0,1,0,100,0,28000,28000,15000,15000,11,33425,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurenai Pitfighter - Out Of Combat - Cast 33425");

-- Mag'har Refugee SAI
SET @ENTRY := 19144;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,15000,25000,10000,20000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Refugee - Out Of Combat - Emote Talk");

-- Orc Refugee SAI
SET @ENTRY := 19150;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,15000,25000,10000,20000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orc Refugee - Out Of Combat - Emote Talk");

-- Peasant Refugee SAI
SET @ENTRY := 19170;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,15000,25000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Peasant Refugee - Out Of Combat - Emote Talk");

-- Chieftain Mummaki SAI
SET @ENTRY := 19174;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,35205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chieftain Mummaki - Between 0-50% Health - Cast 35205");

-- Raging Colossus SAI
SET @ENTRY := 19188;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,50,0,6000,6000,10000,10000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Colossus - In Combat - Cast 11428"),
(@ENTRY,0,1,0,0,0,50,0,6000,6000,10000,10000,11,33688,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Colossus - In Combat - Cast 33688"),
(@ENTRY,0,2,3,2,0,100,1,0,20,0,0,11,18501,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Colossus - Between 0-20% Health - Cast 18501"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Colossus - Between 0-20% Health - Say Line 0");

-- Texts for Raging Colossus
SET @ENTRY := 19188;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Raging Colossus");

-- Quillfang Skitterer SAI
SET @ENTRY := 19189;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,33781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quillfang Skitterer - In Combat - Cast 33781");

-- Fel Handler SAI
SET @ENTRY := 19190;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,5000,5000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Handler - In Combat - Cast 32736");

-- Arazzius the Cruel SAI
SET @ENTRY := 19191;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,15000,15000,11,33975,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arazzius the Cruel - In Combat - Cast 33975"),
(@ENTRY,0,1,0,0,0,100,0,7000,7000,15000,15000,11,34089,0,0,0,0,0,5,0,0,0,0,0,0,0,"Arazzius the Cruel - In Combat - Cast 34089"),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,15000,15000,11,15245,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arazzius the Cruel - In Combat - Cast 15245"),
(@ENTRY,0,3,0,2,0,100,1,0,50,0,0,11,34249,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arazzius the Cruel - Between 0-50% Health - Cast 34249");

-- Mistress of Doom SAI
SET @ENTRY := 19192;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,5000,5000,10000,10000,11,34017,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistress of Doom - In Combat - Cast 34017"),
(@ENTRY,0,1,0,2,0,100,1,0,80,0,0,11,34237,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistress of Doom - Between 0-80% Health - Cast 34237");

-- Cro Threadstrong SAI
SET @ENTRY := 19196;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,900000,900000,900000,960000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cro Threadstrong - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,660000,660000,660000,780000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cro Threadstrong - Out Of Combat - Say Line 1");

-- Texts for Cro Threadstrong
SET @ENTRY := 19196;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I feel that war is fast approaching. The fruit vendor has enlisted to help an ogre. I shall have to enlist help as well.",12,0,100,0,0,0,"Cro Threadstrong"),
(@ENTRY,1,0,"FRUIT VENDOR!!! Your cart is still in our way! We will give you one more hour to move it from our area. Do not test our patience anymore!",14,0,100,0,0,0,"Cro Threadstrong");

-- Summoned Cabal Acolyte SAI
SET @ENTRY := 19208;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,3600000,3600000,11,33482,1,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - Out Of Combat - Cast 33482 (Dungeon Only)"),
(@ENTRY,0,1,0,14,0,100,2,9000,20,5000,9000,11,12039,0,0,0,0,0,7,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - On Friendly Unit At 9000 Health Within 20 Range - Cast 12039 (Normal Dungeon)"),
(@ENTRY,0,2,0,14,0,100,4,15000,20,5000,9000,11,38209,0,0,0,0,0,7,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - On Friendly Unit At 15000 Health Within 20 Range - Cast 38209 (Heroic Dungeon)"),
(@ENTRY,0,3,0,14,0,100,2,4000,20,12000,15000,11,25058,0,0,0,0,0,7,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - On Friendly Unit At 4000 Health Within 20 Range - Cast 25058 (Normal Dungeon)"),
(@ENTRY,0,4,0,14,0,100,4,7000,20,12000,15000,11,38210,0,0,0,0,0,7,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - On Friendly Unit At 7000 Health Within 20 Range - Cast 38210 (Heroic Dungeon)"),
(@ENTRY,0,5,0,7,0,100,7,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - On Evade - Forced Despawn (Dungeon Only)"),
(@ENTRY,0,6,0,7,0,100,7,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - On Evade - Set Not Selectable Flag (Dungeon Only)");

-- Summoned Cabal Deathsworn SAI
SET @ENTRY := 19209;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,10000,12000,15000,11,33480,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - In Combat - Cast 33480 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,8000,10000,12000,15000,11,38226,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - In Combat - Cast 38226 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,3000,7000,10000,12000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - In Combat - Cast 11428 (Dungeon Only)"),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - Between 0-30% Health - Cast 8599 (Dungeon Only)"),
(@ENTRY,0,4,0,7,0,100,7,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - On Evade - Forced Despawn (Dungeon Only)"),
(@ENTRY,0,5,0,7,0,100,7,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - On Evade - Set Not Selectable Flag (Dungeon Only)");

-- Granny Smith SAI
SET @ENTRY := 19223;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,210000,210000,210000,210000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Granny Smith - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,600000,600000,600000,600000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Granny Smith - Out Of Combat - Say Line 1");

-- Texts for Granny Smith
SET @ENTRY := 19223;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I could have sworn I had more apples. Grok!",12,0,100,0,0,0,"Granny Smith"),
(@ENTRY,1,0,"What is that poor orc yelling about? Someone should see what is going on.",12,0,100,0,0,0,"Granny Smith");

-- Griftah SAI
SET @ENTRY := 19227;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,75,0,1,30,120000,120000,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Griftah - On LOS Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,10,0,20,0,1,30,500000,500000,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Griftah - On LOS Out Of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,0,600000,600000,300000,500000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Griftah - Out Of Combat - Say Line 2");

-- Texts for Griftah
SET @ENTRY := 19227;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Hey! Hey, $r! I be havin' just the thing for ya. Ya ever see a Tikbalang? Frightenin' creatures. Prone to stealin' ya away. What ya need is my tikbaland wards. Guaranteed to ward away all tikbalangs!",12,0,100,0,0,0,"Griftah"),
(@ENTRY,0,1,"Look over here, $c! I got somethin' for ya. Just what ya need. It's soap, right... and it's on a rope! No offense, man, but yer a little ripe, you know what I'm sayin'? ",12,0,100,0,0,0,"Griftah"),
(@ENTRY,0,2,"C'mere, $r. Ya don't want to be riskin' yerself in a dungeon, do ya? Filthy work, and for what? Some worthless trinket? Nah, what ya need be one of my amulets. Guarenteed to work! ",12,0,100,0,0,0,"Griftah"),
(@ENTRY,1,0,"Ya look tired, $c. I be havin' somethin' for ya. These amulets, they can help ya leap obstacles and swim through the rivers like ya be born to it. They energize the food ya be eatin'. Makin' yer wounds close before yer eyes!",12,0,100,0,0,0,"Griftah"),
(@ENTRY,1,1,"Hey! Hey, $r! I be havin' just the thing for ya. Ya ever see a Tikbalang? Frightenin' creatures. Prone to stealin' ya away. What ya need is my tikbaland wards. Guaranteed to ward away all tikbalangs!",12,0,100,0,0,0,"Griftah"),
(@ENTRY,1,2,"Look over here, $c! I got somethin' for ya. Just what ya need. It's soap, right... and it's on a rope! No offense, man, but yer a little ripe, you know what I'm sayin'? ",12,0,100,0,0,0,"Griftah"),
(@ENTRY,2,0,"Ya look lovesick. Special someone be gettin' ya down, eh? No worries, no worries. Ya get this medallion from me, ya wear it when ya see 'em and they be all over ya, sweetheart!",12,0,100,0,0,0,"Griftah"),
(@ENTRY,2,1,"Amazing Amulets! Incredible curios! The newfangled jewelcrafters be havin' nothin' on the tried and true mystical methods of ol' %s! Improve yerself through these magical talismans for a bargain price!",12,0,100,0,0,0,"Griftah"),
(@ENTRY,2,2,"Dangerous out there, innit? Know what ya need? Protection. I can help ya defy death itself! Ya wear this madstone 'round yer neck, see, and then ya be able to come back if ya find yerself in the spirit world! Just a quick jaunt to yer corpse and up ya com",12,0,100,0,0,0,"Griftah");

-- Vagrant SAI
SET @ENTRY := 19283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,30000,45000,45000,10,12,13,64,0,0,0,1,0,0,0,0,0,0,0,"Vagrant - Out Of Combat - Random Emote"),
(@ENTRY,0,1,0,1,0,100,0,30000,60000,45000,90000,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vagrant - Out Of Combat - Emote State Stand"),
(@ENTRY,0,2,0,1,0,100,0,15000,40000,20000,40000,10,18,20,1,0,0,0,1,0,0,0,0,0,0,0,"Vagrant - Out Of Combat - Random Emote"),
(@ENTRY,0,3,0,1,0,100,0,30000,300000,240000,520000,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Vagrant - Out Of Combat - Say Line 0");

-- Texts for Vagrant
SET @ENTRY := 19283;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Please don't ignore us...",12,0,100,1,0,0,"Vagrant"),
(@ENTRY,0,1,"Spare a copper, madame?",12,0,100,1,0,0,"Vagrant"),
(@ENTRY,0,2,"Hey, $G man:lady;? Got some money?  I got five kids to feed!",12,0,100,1,0,0,"Vagrant");

-- Vagabond SAI
SET @ENTRY := 19289;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,50,1,0,0,0,0,10,12,65,68,0,0,0,1,0,0,0,0,0,0,0,"Vagabond - On Respawn - Random Emote");

-- Shattered Hand Grenadier SAI
SET @ENTRY := 19295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,13000,15000,11,7978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Grenadier - In Combat - Cast 7978");

-- Goliathon SAI
SET @ENTRY := 19305;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,50,0,6000,6000,10000,10000,11,32959,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goliathon - In Combat - Cast 32959"),
(@ENTRY,0,1,0,0,0,50,0,8000,8000,10000,10000,11,33688,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goliathon - In Combat - Cast 33688"),
(@ENTRY,0,2,0,0,0,50,0,9000,9000,10000,10000,11,5568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goliathon - In Combat - Cast 5568"),
(@ENTRY,0,3,0,2,0,100,1,0,90,0,0,11,33904,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goliathon - Between 0-90% Health - Cast 33904"),
(@ENTRY,0,4,0,2,0,100,1,0,60,0,0,11,33905,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goliathon - Between 0-60% Health - Cast 33905"),
(@ENTRY,0,5,0,2,0,100,1,0,30,0,0,11,33906,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goliathon - Between 0-30% Health - Cast 33906");

-- Mana Leech SAI
SET @ENTRY := 19306;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8200,13900,18700,18700,11,15785,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mana Leech - In Combat - Cast 15785 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,5800,16000,14600,18100,11,25602,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mana Leech - In Combat - Cast 25602 (Dungeon Only)"),
(@ENTRY,0,2,0,6,0,100,7,0,0,0,0,11,34933,7,0,0,0,0,1,0,0,0,0,0,0,0,"Mana Leech - On Death - Cast 34933 (Dungeon Only)");

-- Nexus Terror SAI
SET @ENTRY := 19307;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,1300,16500,32900,11,34922,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nexus Terror - In Combat - Cast 34922 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,8400,17100,15700,22500,11,38065,1,0,0,0,0,6,0,0,0,0,0,0,0,"Nexus Terror - In Combat - Cast 38065 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,12000,20000,18000,25000,11,34322,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Terror - In Combat - Cast 34322 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,6,7100,17100,60000,70000,11,34925,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nexus Terror - In Combat - Cast 34925 (Dungeon Only)");

-- Marshal Isildor SAI
SET @ENTRY := 19308;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,60000,120000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marshal Isildor - Out Of Combat - Say Line 0");

-- Texts for Marshal Isildor
SET @ENTRY := 19308;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"This war - and don't mistake this for anything but war - is not going to win itself. If we do not fight, scratch, claw, and kick for every speck of land on this shattered world, all will be lost.",12,0,100,5,0,0,"Marshal Isildor"),
(@ENTRY,0,1,"How many more soldiers need to die before we start paying attention out there?",12,0,100,5,0,0,"Marshal Isildor"),
(@ENTRY,0,2,"Do you think that demons will play fair? These beasts are more savage than the orcs, more cunning than the undead. Do not attempt to engage Legion by normal standards of war.",12,0,100,5,0,0,"Marshal Isildor");

-- Drillmaster Zurok SAI
SET @ENTRY := 19312;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8200,8200,19000,21600,11,33500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drillmaster Zurok - In Combat - Cast 33500"),
(@ENTRY,0,1,0,9,0,100,0,0,10,12600,13500,11,18813,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drillmaster Zurok - Between 0-10 Range - Cast 18813");

-- Harbinger Erothem SAI
SET @ENTRY := 19346;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,120000,120000,240000,240000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harbinger Erothem - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,124000,124000,244000,244000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harbinger Erothem - Out Of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,0,269000,269000,269000,269000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harbinger Erothem - Out Of Combat - Say Line 2");

-- Texts for Harbinger Erothem
SET @ENTRY := 19346;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Anchorite Nindumen, I have a request to make of you.",12,0,100,0,0,0,"Harbinger Erothem"),
(@ENTRY,1,0,"We've just sent another inexperienced squad into Nagrand. Might you offer a prayer for them?",12,0,100,0,0,0,"Harbinger Erothem"),
(@ENTRY,2,0,"May it be so.",12,0,100,0,0,0,"Harbinger Erothem");

-- Thornfang Ravager SAI
SET @ENTRY := 19349;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,33781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thornfang Ravager - In Combat - Cast 33781");

-- Thornfang Venomspitter SAI
SET @ENTRY := 19350;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,50,0,6000,6000,20000,20000,11,6917,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thornfang Venomspitter - In Combat - Cast 6917"),
(@ENTRY,0,1,0,0,0,50,0,6000,6000,10000,10000,11,33781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thornfang Venomspitter - In Combat - Cast 33781");

-- Kor'kron Defender SAI
SET @ENTRY := 19362;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,5,0,190000,190000,250000,550000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Defender - Out Of Combat - Say Line 0");

-- Texts for Kor'kron Defender
SET @ENTRY := 19362;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"If I see any lazy peons here, I'll load them into a catapult and launch them off to the Black Temple!",14,0,100,0,0,0,"Kor\'kron Defender"),
(@ENTRY,0,1,"Any time any of you peons want to take a break, the graveyard is right over there.",12,0,100,0,0,0,"Kor\'kron Defender");

-- Anchorite Nindumen SAI
SET @ENTRY := 19378;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,122000,122000,242000,242000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Nindumen - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,127000,127000,247000,247000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Nindumen - Out Of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,0,129000,129000,249000,249000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Nindumen - Out Of Combat - Say Line 2"),
(@ENTRY,0,3,0,1,0,100,0,134000,134000,254000,254000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Nindumen - Out Of Combat - Say Line 3"),
(@ENTRY,0,4,0,1,0,100,0,138000,138000,258000,258000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Nindumen - Out Of Combat - Say Line 4"),
(@ENTRY,0,5,0,1,0,100,0,140000,140000,260000,260000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Nindumen - Out Of Combat - Say Line 5"),
(@ENTRY,0,6,0,1,0,100,0,143000,143000,263000,263000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Nindumen - Out Of Combat - Say Line 6"),
(@ENTRY,0,7,0,1,0,100,0,146000,146000,266000,266000,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Nindumen - Out Of Combat - Say Line 7"),
(@ENTRY,0,8,0,1,0,100,0,148000,148000,268000,268000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Nindumen - Out Of Combat - Say Line 8");

-- Texts for Anchorite Nindumen
SET @ENTRY := 19378;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Of course, my friend. How can I be of service to you?",12,0,100,0,0,0,"Anchorite Nindumen"),
(@ENTRY,1,0,"A noble request. It would be an honor, Erothem.",12,0,100,0,0,0,"Anchorite Nindumen"),
(@ENTRY,2,0,"My friends, please join me in humble supplication the the Light.",12,0,100,0,0,0,"Anchorite Nindumen"),
(@ENTRY,3,0,"Light that we embrace, we beseech thee...",12,0,100,0,0,0,"Anchorite Nindumen"),
(@ENTRY,4,0,"Into our struggle against the darkness we have sent our children.",12,0,100,0,0,0,"Anchorite Nindumen"),
(@ENTRY,5,0,"Please bless and protect them, and grant them success over those who seek to do us harm...",12,0,100,0,0,0,"Anchorite Nindumen"),
(@ENTRY,6,0,"Continue to bless this, our ancient home, we beg.",12,0,100,0,0,0,"Anchorite Nindumen"),
(@ENTRY,7,0,"Bless us with tolerance for our elven visitors.",12,0,100,0,0,0,"Anchorite Nindumen"),
(@ENTRY,8,0,"By the Naaru, may it be so.",12,0,100,0,0,0,"Anchorite Nindumen");

-- Withered Bog Lord SAI
SET @ENTRY := 19402;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,35235,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Bog Lord - In Combat - Cast 35235"),
(@ENTRY,0,1,0,0,0,75,0,3000,3000,10000,10000,11,35238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Bog Lord - In Combat - Cast 35238");

-- Shattered Hand Neophyte SAI
SET @ENTRY := 19410;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6800,15100,45000,55000,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Neophyte - In Combat - Cast 6742"),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,11640,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Neophyte - Between 0-40% Health - Cast 11640"),
(@ENTRY,0,2,0,0,0,100,0,6500,9300,18700,18700,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Neophyte - In Combat - Cast 11639"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shattered Hand Neophyte - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,4,0,6,0,10,1,0,0,0,0,11,38879,7,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Neophyte - On Death - Cast 38879");

-- D'ore SAI
SET @ENTRY := 19412;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"D'ore - On Respawn - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,7765,0,0,0,0,0,1,0,0,0,0,0,0,0,"D'ore - On Respawn - Cast 7765 (Dungeon Only)");

-- Texts for D'ore
SET @ENTRY := 19412;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"A cool breeze caresses your face. Gentle, melodic humming resonates throughout the chamber.",16,0,100,0,0,0,"D\'ore");

-- Shattered Hand Guard SAI
SET @ENTRY := 19414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,3000,5000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Guard - In Combat - Cast 11976");

-- Shattered Hand Acolyte SAI
SET @ENTRY := 19415;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Acolyte - On Aggro - Cast 13864"),
(@ENTRY,0,1,0,0,0,80,0,3000,3000,5000,9000,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Acolyte - In Combat - Cast 16568"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,11642,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Acolyte - Between 0-50% Health - Cast 11642");

-- Raging Shardling SAI
SET @ENTRY := 19419;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Shardling - Between 0-20% Health - Cast 8599"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Shardling - Between 0-20% Health - Say Line 0");

-- Texts for Raging Shardling
SET @ENTRY := 19419;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Raging Shardling");

-- Netherstorm Crystal Target SAI
SET @ENTRY := 19421;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,500,5000,5000,11,34397,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherstorm Crystal Target - Out Of Combat - Cast 34397");

-- Bleeding Hollow Tormentor SAI
SET @ENTRY := 19424;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,10000,10000,11,33924,1,0,0,0,0,3,0,0,0,0,0,0,0,"Bleeding Hollow Tormentor - In Combat - Cast 33924"),
(@ENTRY,0,1,0,0,0,100,1,0,0,3000,3000,11,34368,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Tormentor - In Combat - Cast 34368"),
(@ENTRY,0,2,3,2,0,100,1,0,15,0,0,11,31553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Tormentor - Between 0-15% Health - Cast 31553"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bleeding Hollow Tormentor - Between 0-15% Health - Flee For Assist");

-- Avian Darkhawk SAI
SET @ENTRY := 19429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,8,25,5000,8000,11,38059,1,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Darkhawk - Between 8-25 Range - Cast 38059 (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,4,8,25,5000,8000,11,39197,1,0,0,0,0,6,0,0,0,0,0,0,0,"Avian Darkhawk - Between 8-25 Range - Cast 39197 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4000,5000,8000,10000,11,32901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Darkhawk - In Combat - Cast 32901 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,4000,5000,8000,10000,11,39198,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avian Darkhawk - In Combat - Cast 39198 (Heroic Dungeon)");

-- Eye of Grillok SAI
SET @ENTRY := 19440;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Grillok - In Combat - Forced Despawn"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Grillok - On Aggro - Say Line 0");

-- Texts for Eye of Grillok
SET @ENTRY := 19440;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"You are spotted by the eye of Grillok!",16,0,100,0,0,0,"Eye of Grillok");

-- Worg Master Kruush SAI
SET @ENTRY := 19442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,8000,8000,11,30478,1,0,0,0,0,2,0,0,0,0,0,0,0,"Worg Master Kruush - In Combat - Cast 30478"),
(@ENTRY,0,1,0,0,0,100,1,0,0,2500,2500,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Worg Master Kruush - In Combat - Say Line 0"),
(@ENTRY,0,2,3,2,0,100,1,0,25,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Worg Master Kruush - Between 0-25% Health - Cast 8599"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Worg Master Kruush - Between 0-25% Health - Say Line 1");

-- Texts for Worg Master Kruush
SET @ENTRY := 19442;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s calls for his worgs!",16,0,100,0,0,0,"Worg Master Kruush"),
(@ENTRY,1,0,"%s becomes enraged!",16,0,100,0,0,0,"Worg Master Kruush");

-- Sunfury Captain SAI
SET @ENTRY := 19453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,3700,3700,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Captain - In Combat - Cast 32064"),
(@ENTRY,0,1,0,0,0,100,1,3700,3700,0,0,11,35871,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Captain - In Combat - Cast 35871"),
(@ENTRY,0,2,3,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Captain - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Captain - Between 0-30% Health - Say Line 0");

-- Texts for Sunfury Captain
SET @ENTRY := 19453;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Sunfury Captain");

-- Grillok "Darkeye" SAI
SET @ENTRY := 19457;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,7000,11000,11000,11,32062,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grillok 'Darkeye' - In Combat - Cast 32062"),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,11000,13000,11,12058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Grillok 'Darkeye' - In Combat - Cast 12058"),
(@ENTRY,0,2,0,0,0,100,0,15000,15000,15000,15000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grillok 'Darkeye' - In Combat - Cast 12550"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,20000,20000,11,34079,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grillok 'Darkeye' - In Combat - Cast 34079"),
(@ENTRY,0,4,0,1,0,100,1,0,0,2500,2500,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grillok 'Darkeye' - Out Of Combat - Cast 12550"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Grillok 'Darkeye' - Between 0-15% Health - Flee For Assist");

-- Ripp SAI
SET @ENTRY := 19458;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,20,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ripp - Between 0-20% Health - Flee For Assist");

-- Feng SAI
SET @ENTRY := 19459;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,20,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Feng - Between 0-20% Health - Flee For Assist");

-- Harbinger Haronem SAI
SET @ENTRY := 19475;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,6000,6000,6000,6000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harbinger Haronem - Out Of Combat - Emote Talk"),
(@ENTRY,0,1,0,1,0,100,0,39000,39000,300000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harbinger Haronem - Out Of Combat - Say Line 0");

-- Texts for Harbinger Haronem
SET @ENTRY := 19475;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"It's coming along, Wafflefry. Haven't you got a product demonstration to do or something?",12,0,100,1,0,0,"Harbinger Haronem");

-- Ekkorash the Inquisitor SAI
SET @ENTRY := 19493;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,14000,20000,11,11980,32,0,0,0,0,2,0,0,0,0,0,0,0,"Ekkorash the Inquisitor - Between 0-30 Range - Cast 11980"),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,18000,23000,11,36040,1,0,0,0,0,5,0,0,0,0,0,0,0,"Ekkorash the Inquisitor - In Combat - Cast 36040");

-- Ar'kelos SAI
SET @ENTRY := 19494;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,12000,15000,11,11975,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ar'kelos - Between 0-8 Range - Cast 11975");

-- Starving Bog Lord SAI
SET @ENTRY := 19519;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,6000,6000,11,35244,0,0,0,0,0,2,0,0,0,0,0,0,0,"Starving Bog Lord - In Combat - Cast 35244"),
(@ENTRY,0,1,0,0,0,75,0,3000,3000,10000,10000,11,35238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Starving Bog Lord - In Combat - Cast 35238");

-- Stormspire Nexus-Guard SAI
SET @ENTRY := 19529;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,15000,11,9080,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormspire Nexus-Guard - Between 0-5 Range - Cast 9080"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,11000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormspire Nexus-Guard - Between 0-5 Range - Cast 16856"),
(@ENTRY,0,2,0,0,0,100,0,7000,9000,5000,7000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormspire Nexus-Guard - In Combat - Cast 15284");

-- Dealer Zijaad SAI
SET @ENTRY := 19535;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,60000,180000,240000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dealer Zijaad - Out Of Combat - Say Line 0");

-- Texts for Dealer Zijaad
SET @ENTRY := 19535;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Ahh, another powerful traveler. The nether can be dangerous; you'll want the most potent spells at your disposal. I carry the finest reagents, common and exotic. Come and buy - you won't be sorry!",12,0,100,0,0,0,"Dealer Zijaad");

-- Lykul Stinger SAI
SET @ENTRY := 19632;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,6,0,50,14000,18000,11,34392,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lykul Stinger - Between 0-50% Health - Cast 34392 (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lykul Stinger - Between 0-50% Health - Say Line 0 (Dungeon Only)");

-- Texts for Lykul Stinger
SET @ENTRY := 19632;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Lykul Stinger");

-- Captain Arathyn SAI
SET @ENTRY := 19635;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Arathyn - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,1,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Arathyn - Out Of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,1,10000,10000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Arathyn - Out Of Combat - Say Line 2"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,35882,1,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Arathyn - On Aggro - Cast 35882"),
(@ENTRY,0,4,0,9,0,100,0,0,5,7000,10000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Arathyn - Between 0-5 Range - Cast 17207");

-- Warp-Raider Nesaad SAI
SET @ENTRY := 19641;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,12000,17000,21000,11,35924,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp-Raider Nesaad - In Combat - Cast 35924");

-- Zaxxis Stalker SAI
SET @ENTRY := 19642;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,8000,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zaxxis Stalker - Between 0-5 Range - Cast 7159");

-- Muffin Man Moser SAI
SET @ENTRY := 19664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,480000,480000,480000,480000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muffin Man Moser - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,490000,490000,490000,490000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muffin Man Moser - Out Of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,0,345000,345000,345000,465000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muffin Man Moser - Out Of Combat - Say Line 2");

-- Texts for Muffin Man Moser
SET @ENTRY := 19664;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Nothing like a tankard full to wash down one of my magnificent muffins.",12,0,100,0,0,0,"Muffin Man Moser"),
(@ENTRY,1,0,"Yea, that hit the spot. Muffins for sale! Get your fresh muffins right here!",12,0,100,7,0,0,"Muffin Man Moser"),
(@ENTRY,2,0,"I've got muffins right over here. Come on over!",12,0,100,0,0,0,"Muffin Man Moser"),
(@ENTRY,2,1,"Yea, yea, I'm the muffin man. You know why? Because I sell muffins, that's why!",12,0,100,0,0,0,"Muffin Man Moser");

-- Shadow Lord Xiraxis SAI
SET @ENTRY := 19666;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Aggro - Say Line 0 (Dungeon Only)");

-- Texts for Shadow Lord Xiraxis
SET @ENTRY := 19666;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Never underestimate the other ethereal's greed.",12,0,100,0,0,0,"Shadow Lord Xiraxis");

-- Marshrock Threshalisk SAI
SET @ENTRY := 19706;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,35385,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marshrock Threshalisk - On Aggro - Cast 35385");

-- Ironspine Threshalisk SAI
SET @ENTRY := 19729;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,35385,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ironspine Threshalisk - On Aggro - Cast 35385");

-- Ironspine Gazer SAI
SET @ENTRY := 19730;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,5000,5000,16000,16000,11,35313,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ironspine Gazer - In Combat - Cast 35313"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,35385,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironspine Gazer - On Aggro - Cast 35385");

-- Daggerfen Servant SAI
SET @ENTRY := 19733;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,35207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerfen Servant - Between 0-50% Health - Cast 35207");

-- Doomclaw SAI
SET @ENTRY := 19738;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,14000,18000,11,36205,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doomclaw - Between 0-10 Range - Cast 36205"),
(@ENTRY,0,1,0,9,0,100,0,0,10,14000,18000,11,36996,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doomclaw - Between 0-10 Range - Cast 36996"),
(@ENTRY,0,2,0,9,0,100,0,0,5,8000,11000,11,34261,33,0,0,0,0,5,0,0,0,0,0,0,0,"Doomclaw - Between 0-5 Range - Cast 34261");

-- Deathforge Tinkerer SAI
SET @ENTRY := 19754;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,15000,30000,11,38107,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Tinkerer - Out Of Combat - Cast 38107"),
(@ENTRY,0,1,0,0,0,100,0,15000,15000,15000,30000,11,38107,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Tinkerer - In Combat - Cast 38107"),
(@ENTRY,0,2,0,0,0,100,0,1000,1000,10000,15000,11,38753,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Tinkerer - In Combat - Cast 38753");

-- Deathforge Smith SAI
SET @ENTRY := 19756;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,10000,15000,11,37580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Smith - In Combat - Cast 37580"),
(@ENTRY,0,1,0,0,0,100,0,12000,12000,12000,16000,11,36225,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Smith - In Combat - Cast 36225");

-- Eclipsion Centurion SAI
SET @ENTRY := 19792;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,7000,15000,30000,11,35871,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eclipsion Centurion - In Combat - Cast 35871"),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,36476,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Centurion - Between 0-20% Health - Cast 36476");

-- Eclipsion Archmage SAI
SET @ENTRY := 19796;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,27500,27500,27500,55000,11,37986,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eclipsion Archmage - In Combat - Cast 37986"),
(@ENTRY,0,1,0,0,0,100,0,7500,7500,21500,43000,11,13878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eclipsion Archmage - In Combat - Cast 13878"),
(@ENTRY,0,2,0,0,0,100,0,15000,15000,35000,70000,11,11829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eclipsion Archmage - In Combat - Cast 11829");

-- Eclipsion Bloodwarder SAI
SET @ENTRY := 19806;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,38311,3,0,0,0,0,2,0,0,0,0,0,0,0,"Eclipsion Bloodwarder - On Death - Cast 38311"),
(@ENTRY,0,1,0,2,0,100,1,0,35,0,0,11,37838,0,0,0,0,0,5,0,0,0,0,0,0,0,"Eclipsion Bloodwarder - Between 0-35% Health - Cast 37838");

-- Dark Conclave Talonite SAI
SET @ENTRY := 19825;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Talonite - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,12000,14000,11,39229,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Conclave Talonite - In Combat - Cast 39229"),
(@ENTRY,0,2,0,0,0,100,0,11000,11000,10000,14000,11,39230,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Conclave Talonite - In Combat - Cast 39230");

-- Dark Conclave Ravenguard SAI
SET @ENTRY := 19827;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Ravenguard - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,8000,14000,11,23600,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Ravenguard - In Combat - Cast 23600"),
(@ENTRY,0,2,3,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Ravenguard - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Ravenguard - Between 0-30% Health - Say Line 0");

-- Texts for Dark Conclave Ravenguard
SET @ENTRY := 19827;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Dark Conclave Ravenguard");

-- Levixus SAI
SET @ENTRY := 19847;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,24313,0,0,0,0,0,1,0,0,0,0,0,0,0,"Levixus - On Respawn - Cast 24313"),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,13000,17000,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Levixus - In Combat - Cast 11443"),
(@ENTRY,0,2,0,0,0,100,0,9000,14000,13000,17000,11,7645,1,0,0,0,0,6,0,0,0,0,0,0,0,"Levixus - In Combat - Cast 7645"),
(@ENTRY,0,3,0,0,0,100,0,10000,13000,18000,22000,11,38939,1,0,0,0,0,2,0,0,0,0,0,0,0,"Levixus - In Combat - Cast 38939");

-- Artifact Seeker SAI
SET @ENTRY := 19852;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,12000,15000,11,11981,0,0,0,0,0,5,0,0,0,0,0,0,0,"Artifact Seeker - In Combat - Cast 11981"),
(@ENTRY,0,1,0,0,0,100,0,11000,15000,20000,30000,11,30849,0,0,0,0,0,5,0,0,0,0,0,0,0,"Artifact Seeker - In Combat - Cast 30849");

-- Felblade Doomguard SAI
SET @ENTRY := 19853;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,13000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felblade Doomguard - Between 0-5 Range - Cast 32736"),
(@ENTRY,0,1,0,0,0,100,0,7000,12000,15000,18000,11,35238,1,0,0,0,0,2,0,0,0,0,0,0,0,"Felblade Doomguard - In Combat - Cast 35238");

-- Spellreaver Marathelle SAI
SET @ENTRY := 19926;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,35848,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spellreaver Marathelle - On Respawn - Cast 35848"),
(@ENTRY,0,1,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spellreaver Marathelle - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,9,0,100,0,0,8,12000,15000,11,35843,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spellreaver Marathelle - Between 0-8 Range - Cast 35843"),
(@ENTRY,0,3,0,9,0,100,0,0,15,35000,45000,11,35831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spellreaver Marathelle - Between 0-15 Range - Cast 35831");

-- Texts for Spellreaver Marathelle
SET @ENTRY := 19926;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Looks like today was the wrong day to quit mana tapping...",12,0,100,1,0,0,"Spellreaver Marathelle");

-- Apex SAI
SET @ENTRY := 19940;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,11900,11900,21200,21200,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apex - In Combat - Cast 8078"),
(@ENTRY,0,1,0,2,0,100,1,0,75,0,0,12,21328,1,600000,0,0,0,2,0,0,0,0,0,0,0,"Apex - Between 0-75% Health - Summon Creature Apex Crumbler"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,12,21328,1,600000,0,0,0,2,0,0,0,0,0,0,0,"Apex - Between 0-50% Health - Summon Creature Apex Crumbler"),
(@ENTRY,0,3,0,2,0,100,1,0,25,0,0,12,21328,1,600000,0,0,0,2,0,0,0,0,0,0,0,"Apex - Between 0-25% Health - Summon Creature Apex Crumbler");

-- Darkcrest Slaver SAI
SET @ENTRY := 19946;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,30000,35000,11,13730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkcrest Slaver - In Combat - Cast 13730");

-- Bloodmaul Skirmisher SAI
SET @ENTRY := 19948;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,8000,8000,20000,30000,11,34932,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Skirmisher - In Combat - Cast 34932"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,37786,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Skirmisher - Between 0-30% Health - Cast 37786"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Skirmisher - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,3,0,0,0,90,0,3000,3000,12000,14000,11,34802,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Skirmisher - In Combat - Cast 34802");

-- Texts for Bloodmaul Skirmisher
SET @ENTRY := 19948;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bloodmaul Skirmisher");

-- Bloodmaul Brewmaster SAI
SET @ENTRY := 19957;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,6000,6000,30000,35000,11,37591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Brewmaster - In Combat - Cast 37591");

-- Deathforge Over-Smith SAI
SET @ENTRY := 19978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,15000,11,36486,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Over-Smith - In Combat - Cast 36486"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,16000,19000,11,37615,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Over-Smith - In Combat - Cast 37615");

-- Deathforge Technician SAI
SET @ENTRY := 19979;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,15000,11,36250,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Technician - In Combat - Cast 36250"),
(@ENTRY,0,1,0,2,0,100,0,0,30,8000,8000,11,36825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Technician - Between 0-30% Health - Cast 36825");

-- Darkwater Crocolisk SAI
SET @ENTRY := 20075;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1900,9000,6800,18300,11,34370,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkwater Crocolisk - In Combat - Cast 34370 (Dungeon Only)");

-- Bloodscale Overseer SAI
SET @ENTRY := 20088;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,5000,5000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscale Overseer - In Combat - Cast 9080"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,10000,10000,11,34812,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscale Overseer - In Combat - Cast 34812");

-- Umbrafen Witchdoctor SAI
SET @ENTRY := 20115;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,10000,10000,11,7289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Umbrafen Witchdoctor - In Combat - Cast 7289"),
(@ENTRY,0,1,0,0,0,100,0,500,500,10000,10000,11,34871,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umbrafen Witchdoctor - In Combat - Cast 34871"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,35197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umbrafen Witchdoctor - Between 0-50% Health - Cast 35197");

-- Sunfury Researcher SAI
SET @ENTRY := 20136;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,35000,40000,11,35918,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunfury Researcher - Between 0-5 Range - Cast 35918");

-- Sunfury Centurion SAI
SET @ENTRY := 20140;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,6000,9000,11,35871,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Centurion - Between 0-5 Range - Cast 35871"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Centurion - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Centurion - Between 0-30% Health - Say Line 0");

-- Texts for Sunfury Centurion
SET @ENTRY := 20140;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Sunfury Centurion");

-- Hound of Culuthas SAI
SET @ENTRY := 20141;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,9000,12000,11,36406,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hound of Culuthas - In Combat - Cast 36406"),
(@ENTRY,0,1,0,0,0,100,0,0,8,14000,17000,11,36405,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hound of Culuthas - In Combat - Cast 36405");

-- Void Spawner - Quest - Warp Rifts SAI
SET @ENTRY := 20143;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,5000,15000,23000,11,34943,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Spawner - Quest - Warp Rifts - Out Of Combat - Cast 34943");

-- Unstable Voidwalker SAI
SET @ENTRY := 20145;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,10000,12000,11,33914,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unstable Voidwalker - In Combat - Cast 33914");

-- Bloodthirsty Marshfang SAI
SET @ENTRY := 20196;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,1000,1000,10000,10000,11,17008,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodthirsty Marshfang - In Combat - Cast 17008");

-- Bogflare Needler SAI
SET @ENTRY := 20197;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,15000,15000,11,35328,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bogflare Needler - In Combat - Cast 35328");

-- Fenglow Stinger SAI
SET @ENTRY := 20198;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,10000,10000,11,35325,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fenglow Stinger - In Combat - Cast 35325");

-- Ambassador's Honor Guard SAI
SET @ENTRY := 20199;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,8000,12000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ambassador's Honor Guard - Between 0-5 Range - Cast 15284");

-- Cragskaar SAI
SET @ENTRY := 20202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,12000,16000,11,32959,0,0,0,0,0,5,0,0,0,0,0,0,0,"Cragskaar - Between 0-8 Range - Cast 32959");

-- Shaleskin Flayer SAI
SET @ENTRY := 20210;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,36576,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shaleskin Flayer - On Aggro - Cast 36576");

-- Pentatharon SAI
SET @ENTRY := 20215;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8500,7400,12500,11,36039,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pentatharon - In Combat - Cast 36039");

-- Grulloc SAI
SET @ENTRY := 20216;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,20000,20000,20000,25000,11,38771,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grulloc - In Combat - Cast 38771"),
(@ENTRY,0,1,0,0,0,100,0,7000,7000,12000,16000,11,21055,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grulloc - In Combat - Cast 21055"),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,45000,45000,11,38772,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grulloc - In Combat - Cast 38772"),
(@ENTRY,0,3,0,6,0,100,1,0,0,0,0,11,39890,7,0,0,0,0,1,0,0,0,0,0,0,0,"Grulloc - On Death - Cast 39890");

-- Sunfury Flamekeeper SAI
SET @ENTRY := 20221;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,6000,9000,11,35857,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Flamekeeper - Between 0-5 Range - Cast 35857"),
(@ENTRY,0,1,0,9,0,100,0,0,5,13000,17000,11,33731,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Flamekeeper - Between 0-5 Range - Cast 33731"),
(@ENTRY,0,2,3,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Flamekeeper - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Flamekeeper - Between 0-30% Health - Say Line 0");

-- Texts for Sunfury Flamekeeper
SET @ENTRY := 20221;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Sunfury Flamekeeper");

-- Feralfen Druid SAI
SET @ENTRY := 20270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,35200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Druid - On Aggro - Cast 35200"),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,16561,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Druid - Between 0-50% Health - Cast 16561");

-- Ragestone Threshalisk SAI
SET @ENTRY := 20279;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,20,0,0,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragestone Threshalisk - Between 0-20% Health - Cast 3019"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragestone Threshalisk - Between 0-20% Health - Say Line 0");

-- Texts for Ragestone Threshalisk
SET @ENTRY := 20279;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Ragestone Threshalisk");

-- Ragestone Trampler SAI
SET @ENTRY := 20280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragestone Trampler - Between 0-30% Health - Cast 3019"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragestone Trampler - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,2,0,0,0,75,0,12000,12000,25000,25000,11,5568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragestone Trampler - In Combat - Cast 5568");

-- Texts for Ragestone Trampler
SET @ENTRY := 20280;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Ragestone Trampler");

-- Dr. Boom SAI
SET @ENTRY := 20284;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,15,7000,13000,11,35276,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dr. Boom - Between 0-15 Range - Cast 35276");

-- Gan'arg Warp-Tinker SAI
SET @ENTRY := 20285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,11000,15000,11,36208,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gan'arg Warp-Tinker - Between 0-5 Range - Cast 36208"),
(@ENTRY,0,1,0,0,0,100,0,6000,11000,9000,14000,11,36846,1,0,0,0,0,5,0,0,0,0,0,0,0,"Gan'arg Warp-Tinker - In Combat - Cast 36846");

-- Marsh Baron Brok SAI
SET @ENTRY := 20292;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,75,0,0,11,9616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marsh Baron Brok - Between 0-75% Health - Cast 9616");

-- Bogstrok Razorclaw SAI
SET @ENTRY := 20294;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,10000,10000,11,35321,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bogstrok Razorclaw - In Combat - Cast 35321");

-- Bogstrok Crusher SAI
SET @ENTRY := 20295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,6000,6000,11,21055,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bogstrok Crusher - In Combat - Cast 21055");

-- Parched Hydra SAI
SET @ENTRY := 20324;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,1000,1000,6000,6000,11,35236,0,0,0,0,0,2,0,0,0,0,0,0,0,"Parched Hydra - In Combat - Cast 35236");

-- Mo'arg Warp-Master SAI
SET @ENTRY := 20326;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,16000,20000,11,36486,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mo'arg Warp-Master - Between 0-5 Range - Cast 36486");

-- Nether Dragon SAI
SET @ENTRY := 20332;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,20000,24000,11,36513,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nether Dragon - Between 0-30 Range - Cast 36513"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,13000,11,36631,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nether Dragon - Between 0-5 Range - Cast 36631");
