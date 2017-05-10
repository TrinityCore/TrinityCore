-- DB/SAI: Update Winterspring
-- Anguished Highborne SAI
SET @ENTRY := 7524;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,17000,24000,11,13860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anguished Highborne - In Combat - Cast 'Mind Blast'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anguished Highborne - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,90798,3,0,0,0,0,1,0,0,0,0,0,0,0,"Anguished Highborne - On Just Died - Cast 'Released Highborne' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 7524;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(7524, 0, 0, 'It was all her fault! She told us to steal it!', 12, 0, 100, 0, 0, 0, 48852, 0, 'Anguished Highborne'),
(7524, 0, 1, 'It\'s our fault... the destruction is all our fault...', 12, 0, 100, 0, 0, 0, 48855, 0, 'Anguished Highborne'),
(7524, 0, 2, 'My children... what have I done?', 12, 0, 100, 0, 0, 0, 48853, 0, 'Anguished Highborne'),
(7524, 0, 3, 'No... I was to live forever... I will still...', 12, 0, 100, 0, 0, 0, 48854, 0, 'Anguished Highborne'),
(7524, 0, 4, 'So tired... just want to rest...', 12, 0, 100, 0, 0, 0, 48857, 0, 'Anguished Highborne'),
(7524, 0, 5, 'The crystal can still be found... if we can just find it again...', 12, 0, 100, 0, 0, 0, 48856, 0, 'Anguished Highborne'),
(7524, 0, 6, 'The crystal will save us! We can be saved!', 12, 0, 100, 0, 0, 0, 48858, 0, 'Anguished Highborne');

-- Released Highborne Spirit SAI
SET @ENTRY := 48727;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Released Highborne Spirit - On Just Summoned - Run Script (No Repeat)");
-- Actionlist SAI
SET @ENTRY := 4872700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Released Highborne Spirit - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,1500,1500,0,0,11,90793,2,0,0,0,0,1,0,0,0,0,0,0,0,"Released Highborne Spirit - On Script - Cast 'Transform: Wisp'"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,6540.52,-4113.04,710.365,1.95536,"Released Highborne Spirit - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Released Highborne Spirit - On Script - Despawn Instant");

-- NPC talk text insert
SET @ENTRY := 48727;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(48727, 0, 0, 'Leave now... you do not deserve to suffer the crystal\'s wrath...', 12, 0, 100, 0, 0, 0, 48898, 0, 'Released Highborne Spirit'),
(48727, 0, 1, 'Relief at last...', 12, 0, 100, 0, 0, 0, 48896, 0, 'Released Highborne Spirit'),
(48727, 0, 2, 'Thank you...', 12, 0, 100, 0, 0, 0, 48897, 0, 'Released Highborne Spirit'),
(48727, 0, 3, 'The crystal has returned. You must leave...', 12, 0, 100, 0, 0, 0, 48900, 0, 'Released Highborne Spirit');

-- Arcane Mana-Cluster SAI
SET @ENTRY := 50322;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,15000,17000,11,13901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Mana-Cluster - In Combat - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,19000,27000,11,21073,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Mana-Cluster - In Combat - Cast 'Arcane Explosion'");

-- Archmage Maenius SAI
SET @ENTRY := 48740;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Maenius - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,18000,11,79868,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Maenius - In Combat - Cast 'Arcane Blast'"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,22000,25000,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Maenius - In Combat - Cast 'Arcane Explosion'"),
(@ENTRY,0,3,0,0,0,50,0,4000,9000,17000,22000,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Maenius - In Combat - Cast 'Arcane Missiles'"),
(@ENTRY,0,4,0,0,0,50,0,4000,9000,17000,22000,11,79880,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Maenius - In Combat - Cast 'Slow'"),
(@ENTRY,0,5,0,2,0,100,0,0,60,14000,21000,11,21655,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Maenius - Between 0-60% Health - Cast 'Blink'"),
(@ENTRY,0,6,0,6,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Maenius - On Just Died - Say Line 1 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 48740;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'You don\'t understand! I had to study it! I HAD TO!',12,0,100,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'Forgive... me...',12,0,100,0,0,0, 'on Death Text');

-- Azurous SAI
SET @ENTRY := 10202;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,15000,18000,11,16099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azurous - In Combat - Cast 'Frost Breath'");
-- Berserk Owlbeast SAI
SET @ENTRY := 7454;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,5915,0,0,0,0,0,1,0,0,0,0,0,0,0,"Berserk Owlbeast - Between 0-30% Health - Cast 'Crazed' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Berserk Owlbeast - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 7454;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s grows increasingly crazed!',16,0,100,0,0,0, 'combat Crazed',30727);
-- Ironjaw SAI
SET @ENTRY := 18670;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ironjaw - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,17000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironjaw - Within 0-5 Range - Cast 'Cleave'");
-- Boiling Springbubble SAI
SET @ENTRY := 48768;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,9000,14000,11,93655,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boiling Springbubble - In Combat - Cast 'Steam Blast'");
-- Brumeran SAI
SET @ENTRY := 10807;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,9000,25000,35000,11,15797,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brumeran - In Combat - Cast 'Lightning Breath'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,14000,17000,11,16552,0,0,0,0,0,2,32,0,0,0,0,0,0,"Brumeran - Within 0-30 Range - Cast 'Venom Spit'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brumeran - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brumeran - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 10807;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Chillwind Chimaera SAI
SET @ENTRY := 7448;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,10000,24000,34000,11,15797,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chillwind Chimaera - In Combat - Cast 'Lightning Breath'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,17000,21000,11,15850,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chillwind Chimaera - In Combat - Cast 'Chilled'");
-- Coldlurk Burrower SAI
SET @ENTRY := 49347;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,15000,17500,11,21059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldlurk Burrower - In Combat - Cast 'Acid Spit'");
-- Coldlurk Creeper SAI
SET @ENTRY := 49346;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3500,21000,24000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Coldlurk Creeper - In Combat - Cast 'Poison'");
-- Crazed Owlbeast SAI
SET @ENTRY := 7452;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Owlbeast - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Owlbeast - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 7452;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Dimensional Ooze SAI
SET @ENTRY := 50319;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,9000,15000,11,93661,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dimensional Ooze - In Combat - Cast 'Arcane Barrage'");
-- Displaced Warp Stalker SAI
SET @ENTRY := 50313;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,300000,300000,11,32939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Displaced Warp Stalker - Out of Combat - Cast 'Phase Burst'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,20000,11,39449,0,0,0,0,0,2,0,0,0,0,0,0,0,"Displaced Warp Stalker - In Combat - Cast 'Pounce'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,19000,26000,11,32920,0,0,0,0,0,2,0,0,0,0,0,0,0,"Displaced Warp Stalker - In Combat - Cast 'Warp'");
-- Everlook Bruiser SAI
SET @ENTRY := 11190;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Everlook Bruiser - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,9000,11000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Everlook Bruiser - Within 0-20 Range - Cast 'Net'");
-- Frostilicus SAI
SET @ENTRY := 50251;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79858,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frostilicus - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,27000,11,79860,1,0,0,0,0,4,0,0,0,0,0,0,0,"Frostilicus - In Combat - Cast 'Blizzard'"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostilicus - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,3,0,9,0,100,0,0,8,13600,14500,11,79850,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostilicus - Within 0-8 Range - Cast 'Frost Nova'"),
(@ENTRY,0,4,0,0,0,100,0,11000,12000,24000,27000,11,79859,1,0,0,0,0,2,0,0,0,0,0,0,0,"Frostilicus - In Combat - Cast 'Ice Lance'");
-- Frostleaf Treant SAI
SET @ENTRY := 48952;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,16000,24500,11,15089,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostleaf Treant - In Combat - Cast 'Frost Shock'");
-- Frostmaul Giant SAI
SET @ENTRY := 7428;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,9000,24000,31000,11,22643,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmaul Giant - In Combat - Cast 'Frostbolt Volley'"),
(@ENTRY,0,1,0,0,0,100,0,12000,17000,33000,37000,11,18670,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmaul Giant - In Combat - Cast 'Knock Away'"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,15000,22000,11,18368,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmaul Giant - In Combat - Cast 'Strike'"),
(@ENTRY,0,3,0,9,0,100,0,0,30,22000,23500,11,6136,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmaul Giant - Within 0-30 Range - Cast 'Chilled'");
-- Frostmaul Preserver SAI
SET @ENTRY := 7429;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,19000,26000,11,9616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmaul Preserver - Between 0-40% Health - Cast 'Wild Regeneration'");
-- Frostsaber SAI
SET @ENTRY := 7431;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,15000,18000,11,24331,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostsaber - In Combat - Cast 'Rake'");
-- Frostsaber Huntress SAI
SET @ENTRY := 7433;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostsaber Huntress - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostsaber Huntress - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,5000,26000,27000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostsaber Huntress - In Combat - Cast 'Rend'");
-- NPC talk text insert
SET @ENTRY := 7433;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Frostsaber Pride Watcher SAI
SET @ENTRY := 7434;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,82828,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostsaber Pride Watcher - On Aggro - Cast 'Feral Leap' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostsaber Pride Watcher - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostsaber Pride Watcher - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,6000,7000,22000,25000,11,36590,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostsaber Pride Watcher - In Combat - Cast 'Rip'");
-- NPC talk text insert
SET @ENTRY := 7434;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Frostsaber Stalker SAI
SET @ENTRY := 7432;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,82828,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostsaber Stalker - On Aggro - Cast 'Feral Leap' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostsaber Stalker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostsaber Stalker - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,6000,7000,22000,25000,11,36590,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostsaber Stalker - In Combat - Cast 'Rip'");
-- NPC talk text insert
SET @ENTRY := 7432;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Frostshard Rumbler SAI
SET @ENTRY := 48960;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,36645,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostshard Rumbler - On Aggro - Cast 'Throw Rock' (No Repeat)");
-- General Colbatann SAI
SET @ENTRY := 10196;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Colbatann - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,35000,44000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Colbatann - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,15000,19000,11,11971,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Colbatann - In Combat - Cast 'Sunder Armor'");
-- Grizzle Snowpaw SAI
SET @ENTRY := 10199;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,17000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grizzle Snowpaw - Within 0-5 Range - Cast 'Maul'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grizzle Snowpaw - Within 0-20 Range - Cast 'Frost Shock'"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,24000,25000,11,8364,0,0,0,0,0,4,0,0,0,0,0,0,0,"Grizzle Snowpaw - In Combat - Cast 'Blizzard'");
-- Grolnar the Berserk SAI
SET @ENTRY := 49178;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grolnar the Berserk - On Respawn - Cast 'Coat of Thistlefur' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,0,0,50,32000,35000,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grolnar the Berserk - Between 0-50% Health - Cast 'Bloodlust'"),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,22000,24000,11,39591,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grolnar the Berserk - In Combat - Cast 'Searing Totem'"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grolnar the Berserk - On Aggro - Say Line 0 (No Repeat)");
-- Hell-Hoot SAI
SET @ENTRY := 50044;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,24000,25000,11,31298,1,0,0,0,0,2,0,0,0,0,0,0,0,"Hell-Hoot - In Combat - Cast 'Sleep'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,17000,28000,11,79846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hell-Hoot - In Combat - Cast 'Flamestrike'"),
(@ENTRY,0,2,0,0,0,100,0,11000,12000,33000,34000,11,81119,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hell-Hoot - In Combat - Cast 'Howling Screech'"),
(@ENTRY,0,3,0,9,0,100,0,0,5,12000,16000,11,49865,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hell-Hoot - Within 0-5 Range - Cast 'Eye Peck'");
-- High Chief Winterfall SAI
SET @ENTRY := 10738;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,17000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Chief Winterfall - Within 0-5 Range - Cast 'Maul'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Chief Winterfall - Within 0-20 Range - Cast 'Frost Shock'"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,24000,25000,11,8364,0,0,0,0,0,4,0,0,0,0,0,0,0,"High Chief Winterfall - In Combat - Cast 'Blizzard'");
-- Ice Avatar SAI
SET @ENTRY := 50250;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,12000,15000,11,81161,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Avatar - Within 0-30 Range - Cast 'Baker Team Broadcast Master'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,12000,15000,11,83669,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Avatar - In Combat - Cast 'Water Bolt'");

-- Ice Thistle Matriarch SAI
SET @ENTRY := 7459;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,18000,21000,11,15878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Thistle Matriarch - In Combat - Cast 'Ice Blast'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ice Thistle Matriarch - On Aggro - Cast 'Rushing Charge' (No Repeat)");
-- Ice Thistle Patriarch SAI
SET @ENTRY := 7460;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,18000,21000,11,15878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Thistle Patriarch - In Combat - Cast 'Ice Blast'"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,24000,25000,11,3131,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Thistle Patriarch - In Combat - Cast 'Frost Breath'");
-- Ice Thistle Yeti SAI
SET @ENTRY := 7458;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,18000,21000,11,15878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Thistle Yeti - In Combat - Cast 'Ice Blast'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,19000,26000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Thistle Yeti - In Combat - Cast 'Tendon Rip'");
-- Icewhomp SAI
SET @ENTRY := 49235;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,19000,22000,11,22643,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icewhomp - In Combat - Cast 'Frostbolt Volley'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,17000,26000,11,18670,0,0,0,0,0,2,0,0,0,0,0,0,0,"Icewhomp - In Combat - Cast 'Knock Away'");
-- K'areshi Trader SAI
SET @ENTRY := 50316;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,13000,11,13901,0,0,0,0,0,2,0,0,0,0,0,0,0,"K'areshi Trader - In Combat - Cast 'Arcane Bolt'");
-- Kashoch the Reaver SAI
SET @ENTRY := 10198;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,14000,16000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kashoch the Reaver - In Combat - Cast 'Cleave'");
-- Lost Ravager SAI
SET @ENTRY := 50320;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,11000,15000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lost Ravager - Within 0-5 Range - Cast 'Strike'");
-- Mana Thirster SAI
SET @ENTRY := 50317;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,13000,11,93711,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Thirster - In Combat - Cast 'Arcane Bolt'");
-- Mana-Compelled Shade SAI
SET @ENTRY := 50312;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,13000,11,13901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana-Compelled Shade - In Combat - Cast 'Arcane Bolt'");
-- Mezzir the Howler SAI
SET @ENTRY := 10197;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,31000,35000,11,15971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mezzir the Howler - Within 0-5 Range - Cast 'Demoralizing Roar'"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,15000,21000,11,3131,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mezzir the Howler - In Combat - Cast 'Frost Breath'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,18000,24000,11,14100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mezzir the Howler - Between 0-40% Health - Cast 'Terrifying Roar'");
-- Moontouched Owlbeast SAI
SET @ENTRY := 7453;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,55,18000,22500,11,12160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moontouched Owlbeast - Between 0-55% Health - Cast 'Rejuvenation'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4500,14000,16000,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moontouched Owlbeast - In Combat - Cast 'Moonfire'");
-- Rabid Shardtooth SAI
SET @ENTRY := 7446;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,17000,22000,11,3150,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Shardtooth - In Combat - Cast 'Rabies'");
-- Ragged Owlbeast SAI
SET @ENTRY := 7450;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,120000,120000,11,15848,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragged Owlbeast - In Combat - Cast 'Festering Rash'");
-- Raging Owlbeast SAI
SET @ENTRY := 7451;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,25000,28000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Owlbeast - Within 0-5 Range - Cast 'Rend'");
-- Rak'shiri SAI
SET @ENTRY := 10200;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,35,25000,26000,11,7399,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rak'shiri - Between 0-35% Health - Cast 'Terrify'");
-- Rimepelt SAI
SET @ENTRY := 48765;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,87187,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rimepelt - On Aggro - Cast 'Feral Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,25000,27000,11,15727,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rimepelt - In Combat - Cast 'Demoralizing Roar'");
-- Scalding Springsurge SAI
SET @ENTRY := 48767;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,5500,14000,16000,11,17276,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalding Springsurge - In Combat - Cast 'Scald'");
-- Shade of the Spiritspeaker SAI
SET @ENTRY := 48678;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,12000,13000,11,85424,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shade of the Spiritspeaker - In Combat - Cast 'Spirit Burst'");
-- Shardtooth Bear SAI
SET @ENTRY := 7444;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,25000,25000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shardtooth Bear - In Combat - Cast 'Tendon Rip'");
-- Shardtooth Mauler SAI
SET @ENTRY := 7443;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,12000,12000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shardtooth Mauler - In Combat - Cast 'Maul'");
-- Shy-Rotam SAI
SET @ENTRY := 10737;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,35,25000,26000,11,14100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shy-Rotam - Between 0-35% Health - Cast 'Terrifying Roar'"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,17000,22000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shy-Rotam - In Combat - Cast 'Tendon Rip'"),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,25000,29000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shy-Rotam - In Combat - Cast 'Rend'");
-- Sian-Rotam SAI
SET @ENTRY := 10741;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,35,25000,26000,11,14100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sian-Rotam - Between 0-35% Health - Cast 'Terrifying Roar'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,17000,19000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sian-Rotam - In Combat - Cast 'Tendon Rip'"),
(@ENTRY,0,2,0,0,0,100,0,6500,8000,25000,27000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sian-Rotam - In Combat - Cast 'Rend'");
-- Snowfrolic Fox SAI
SET @ENTRY := 49565;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,18000,21000,11,75529,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfrolic Fox - In Combat - Cast 'Agile Focus'");
-- Suffering Highborne SAI
SET @ENTRY := 7523;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,17000,24000,11,13860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Suffering Highborne - In Combat - Cast 'Mind Blast'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Suffering Highborne - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,90798,3,0,0,0,0,1,0,0,0,0,0,0,0,"Suffering Highborne - On Just Died - Cast 'Released Highborne' (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 7523;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(7523, 0, 0, 'It was all her fault! She told us to steal it!', 12, 0, 100, 0, 0, 0, 48852, 0, 'Highborne'),
(7523, 0, 1, 'It\'s our fault... the destruction is all our fault...', 12, 0, 100, 0, 0, 0, 48855, 0, 'Highborne'),
(7523, 0, 2, 'My children... what have I done?', 12, 0, 100, 0, 0, 0, 48853, 0, 'Highborne'),
(7523, 0, 3, 'No... I was to live forever... I will still...', 12, 0, 100, 0, 0, 0, 48854, 0, 'Highborne'),
(7523, 0, 4, 'So tired... just want to rest...', 12, 0, 100, 0, 0, 0, 48857, 0, 'Highborne'),
(7523, 0, 5, 'The crystal can still be found... if we can just find it again...', 12, 0, 100, 0, 0, 0, 48856, 0, 'Highborne'),
(7523, 0, 6, 'The crystal will save us! We can be saved!', 12, 0, 100, 0, 0, 0, 48858, 0, 'Highborne');

-- Ursius SAI
SET @ENTRY := 10806;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,17000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ursius - Within 0-5 Range - Cast 'Maul'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,33000,35000,11,15971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ursius - In Combat - Cast 'Demoralizing Roar'");
-- Winterfall Den Watcher SAI
SET @ENTRY := 7440;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Den Watcher - Out of Combat - Cast 'Winterfall Firewater'");
-- Winterfall Pathfinder SAI
SET @ENTRY := 7442;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Winterfall Pathfinder - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Pathfinder - Out of Combat - Cast 'Winterfall Firewater'"),
(@ENTRY,0,2,0,0,0,100,0,6000,8000,22000,25000,11,16498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Winterfall Pathfinder - In Combat - Cast 'Faerie Fire'");
-- Winterfall Runner SAI
SET @ENTRY := 10916;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Runner - Out of Combat - Cast 'Winterfall Firewater'");
-- Winterfall Shaman SAI
SET @ENTRY := 7439;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Winterfall Shaman - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Shaman - Out of Combat - Cast 'Winterfall Firewater'"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,13585,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Shaman - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,3,0,16,0,100,0,13585,1,15000,30000,11,13585,1,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Shaman - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'"),
(@ENTRY,0,4,0,2,0,100,0,0,40,14000,21000,11,11431,1,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Shaman - Between 0-40% Health - Cast 'Healing Touch'"),
(@ENTRY,0,5,0,14,0,100,0,800,40,15000,18000,11,11431,1,0,0,0,0,7,0,0,0,0,0,0,0,"Winterfall Shaman - Friendly At 800 Health - Cast 'Healing Touch'");
-- Winterfall Totemic SAI
SET @ENTRY := 7441;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Totemic - Out of Combat - Cast 'Winterfall Firewater'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,45000,50000,11,15786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Totemic - In Combat - Cast 'Earthbind Totem'"),
(@ENTRY,0,2,0,0,0,100,0,6500,8500,22000,25000,11,15787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Totemic - In Combat - Cast 'Moonflare Totem'");
-- Winterfall Ursa SAI
SET @ENTRY := 7438;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Ursa - Out of Combat - Cast 'Winterfall Firewater'");
-- Regurgitated Bones SAI
SET @ENTRY := 48718;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Regurgitated Bones - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,15000,22000,11,81087,0,0,0,0,0,2,0,0,0,0,0,0,0,"Regurgitated Bones - In Combat - Cast 'Puncture Wound'");
-- Winterspring Owl SAI
SET @ENTRY := 7455;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,15000,20000,11,81119,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterspring Owl - In Combat - Cast 'Howling Screech'"),
(@ENTRY,0,1,0,0,0,100,0,2000,9000,12000,24000,11,16576,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterspring Owl - In Combat - Cast 'Piercing Screech'");
-- Winterspring Screecher SAI
SET @ENTRY := 7456;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,14000,18000,11,3589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterspring Screecher - In Combat - Cast 'Deafening Screech'");
-- Wintervine Lasher SAI
SET @ENTRY := 49217;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,40,0,0,11,36604,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wintervine Lasher - Between 0-40% Health - Cast 'Flanking Growth' (No Repeat)");
-- Wretched Spectre SAI
SET @ENTRY := 48665;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,11000,14000,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Spectre - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,6000,7000,22000,23000,11,11980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Spectre - In Combat - Cast 'Curse of Weakness'");
-- Wretched Spirit SAI
SET @ENTRY := 48664;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,55,15000,16000,11,29098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Spirit - Between 0-55% Health - Cast 'Bitter Withdrawal'");
-- Xandivious SAI
SET @ENTRY := 15623;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,10000,20000,11,16046,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xandivious - In Combat - Cast 'Blast Wave'"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,25818,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xandivious - On Respawn - Cast 'Aura of Rot' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,22000,23000,11,11980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Xandivious - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,3,0,0,0,100,0,4000,11000,26000,28000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Xandivious - In Combat - Cast 'Shadow Word: Pain'"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xandivious - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,5,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xandivious - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 15623;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Xorothian Eredar SAI
SET @ENTRY := 50315;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,39083,64,0,0,0,0,2,0,0,0,0,0,0,0,"Xorothian Eredar - In Combat - Cast 'Incinerate'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,21000,22000,11,11443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Xorothian Eredar - In Combat - Cast 'Cripple'");
-- Xorothian Imp SAI
SET @ENTRY := 50321;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20801,64,0,0,0,0,2,0,0,0,0,0,0,0,"Xorothian Imp - In Combat - Cast 'Firebolt'");
