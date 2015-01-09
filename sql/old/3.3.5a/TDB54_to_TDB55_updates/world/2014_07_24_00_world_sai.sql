-- Bael'dun Rifleman SAI
SET @ENTRY := 3377;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'dun Rifleman - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Barak Kodobane SAI
SET @ENTRY := 3394;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Barak Kodobane - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,12000,15000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Barak Kodobane - In Combat - Cast 'Net'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Nak SAI
SET @ENTRY := 3434;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nak - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,0,0,100,17500,22500,11,8004,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - Between 0-100% Health - Cast 'Lesser Healing Wave'"),
(@ENTRY,0,2,0,0,0,100,1,6000,12000,0,0,11,8154,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - In Combat - Cast 'Stoneskin Totem' (No Repeat)");

-- Kuz SAI
SET @ENTRY := 3436;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kuz - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,9000,12000,11,20795,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kuz - In Combat - Cast 'Fire Blast'"),
(@ENTRY,0,2,0,0,0,100,0,8000,12000,12000,16000,11,11831,1,0,0,0,0,2,0,0,0,0,0,0,0,"Kuz - In Combat - Cast 'Frost Nova'");

-- Tonga Runetotem SAI
SET @ENTRY := 3448;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,880,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Tonga Runetotem - On Quest 'Altered Beings' Finished - Say Line 0"),
(@ENTRY,0,1,2,61,0,100,0,880,0,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Tonga Runetotem - On Quest 'Altered Beings' Finished - Say Line 1"),
(@ENTRY,0,2,3,61,0,100,0,880,0,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Tonga Runetotem - On Quest 'Altered Beings' Finished - Say Line 2"),
(@ENTRY,0,3,0,61,0,100,0,880,0,0,0,1,3,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Tonga Runetotem - On Quest 'Altered Beings' Finished - Say Line 3");

-- Razormane Pathfinder SAI
SET @ENTRY := 3456;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Pathfinder - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,5000,7000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Pathfinder - In Combat - Cast 'Thrash'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Delmanis the Hated SAI
SET @ENTRY := 3662;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Delmanis the Hated - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,6000,10000,12000,16000,11,7101,1,0,0,0,0,2,0,0,0,0,0,0,0,"Delmanis the Hated - In Combat - Cast 'Flame Blast'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delmanis the Hated - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Ilkrud Magthrull SAI
SET @ENTRY := 3664;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,8722,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Out of Combat - Cast 'Summon Succubus' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ilkrud Magthrull - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,66500,76300,11,6487,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Between 0-50% Health - Cast 'Ilkrud's Guardians'");

-- Boahn SAI
SET @ENTRY := 3672;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Boahn - In Combat CMC - Cast 'Lightning Bolt'0"),
(@ENTRY,0,1,0,2,0,100,0,0,40,30000,40000,11,5187,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Between 0-40% Health - Cast 'Healing Touch'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Raene Wolfrunner SAI
SET @ENTRY := 3691;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Raene Wolfrunner - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,9000,13000,11,21390,0,0,0,0,0,5,0,0,0,0,0,0,0,"Raene Wolfrunner - Within 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,12000,16000,11,15495,0,0,0,0,0,5,0,0,0,0,0,0,0,"Raene Wolfrunner - Within 5-30 Range - Cast 'Explosive Shot'"),
(@ENTRY,0,3,0,0,0,100,0,18000,25000,60000,70000,11,22908,1,0,0,0,0,5,0,0,0,0,0,0,0,"Raene Wolfrunner - In Combat - Cast 'Volley'"),
(@ENTRY,0,4,0,9,0,100,0,0,20,11000,13000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Raene Wolfrunner - Within 0-20 Range - Cast 'Net'"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Ran Bloodtooth SAI
SET @ENTRY := 3696;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ran Bloodtooth - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,9000,14000,11,14443,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ran Bloodtooth - Within 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Out of Combat - Flee For Assist (No Repeat)");

-- Wrathtail Sea Witch SAI
SET @ENTRY := 3715;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,5000,11,8598,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Sea Witch - In Combat CMC - Cast 'Lightning Blast'"),
(@ENTRY,0,1,0,9,0,100,0,0,10,20900,33500,11,2691,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Within 0-10 Range - Cast 'Mana Burn'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Wrathtail Sorceress SAI
SET @ENTRY := 3717;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Sorceress - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,4500,15700,14100,32600,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - In Combat - Cast 'Frost Nova'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dark Strand Cultist SAI
SET @ENTRY := 3725;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Cultist - Out of Combat - Cast 'Summon Imp' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3900,5900,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Strand Cultist - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,3700,4600,10900,11300,11,6222,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Strand Cultist - In Combat - Cast 'Corruption'");

-- Dark Strand Adept SAI
SET @ENTRY := 3728;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Out of Combat - Cast 'Summon Voidwalker' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,5800,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Strand Adept - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Apothecary Falthis SAI
SET @ENTRY := 3735;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Apothecary Falthis - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Saltspittle Muckdweller SAI
SET @ENTRY := 3740;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Saltspittle Muckdweller - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Foulweald Pathfinder SAI
SET @ENTRY := 3745;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,1000,1000,0,0,11,6820,32,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Out of Combat - Cast 'Corrupted Agility Passive' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Foulweald Pathfinder - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Xavian Hellcaller SAI
SET @ENTRY := 3757;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Out of Combat - Cast 'Gift of the Xavian' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,4700,5800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Xavian Hellcaller - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Severed Druid SAI
SET @ENTRY := 3799;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Severed Druid - In Combat CMC - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,0,0,75,20600,80800,11,1430,1,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - Between 0-75% Health - Cast 'Rejuvenation'");

-- Forsaken Dark Stalker SAI
SET @ENTRY := 3808;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,8218,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - On Reset - Cast 'Sneak'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Forsaken Dark Stalker - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Druid of the Fang SAI
SET @ENTRY := 3840;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - On Aggro - Set Event Phase 1 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,1,100,2,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Druid of the Fang - In Combat CMC - Cast 'Lightning Bolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,2,0,0,1,100,2,8000,11000,10000,20000,11,8040,33,0,0,0,0,6,0,0,0,0,0,0,0,"Druid of the Fang - In Combat - Cast 'Druid's Slumber' (Normal Dungeon)"),
(@ENTRY,0,3,0,74,1,100,2,0,40,12000,18000,11,5187,1,0,0,0,0,9,0,0,0,0,0,0,0,"Druid of the Fang - On Friendly Between 0-40% Health - Cast 'Healing Touch' (Normal Dungeon)"),
(@ENTRY,0,4,5,2,0,100,3,0,50,20000,25000,11,8041,1,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - Between 0-50% Health - Cast 'Serpent Form' (Normal Dungeon)"),
(@ENTRY,0,5,6,61,0,100,2,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - Between 0-50% Health - Enable Combat Movement"),
(@ENTRY,0,6,0,61,0,100,2,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - Between 0-50% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,7,0,23,0,100,2,8041,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - On has aura 'Serpent Form' stack 0 - Set Event Phase 1 (Normal Dungeon)");

-- Thistlefur Pathfinder SAI
SET @ENTRY := 3926;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,11,6813,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - On Reset - Cast 'Coat of Thistlefur' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,2800,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Thistlefur Pathfinder - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodfury Storm Witch SAI
SET @ENTRY := 4027;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfury Storm Witch - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,6000,10000,40000,45000,11,6535,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfury Storm Witch - In Combat - Cast 'Lightning Cloud'");

-- Daughter of Cenarius SAI
SET @ENTRY := 4053;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Daughter of Cenarius - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,10000,12000,11,527,1,0,0,0,0,2,0,0,0,0,0,0,0,"Daughter of Cenarius - In Combat - Cast 'Dispel Magic'"),
(@ENTRY,0,2,0,0,0,100,0,4500,4500,6000,10000,11,527,1,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - In Combat - Cast 'Dispel Magic'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Archmage Koreln SAI
SET @ENTRY := 37582;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,51779,64,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Koreln - In Combat CMC - Cast 'Frostfire Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4800,11,70616,64,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Koreln - In Combat CMC - Cast 'Frostfire Bolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,6,0,8,10000,14000,11,22645,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - Within 0-8 Range - Cast 'Frost Nova' (Dungeon)"),
(@ENTRY,0,3,0,0,0,100,6,8000,12000,13000,16000,11,22746,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - In Combat - Cast 'Cone of Cold' (Dungeon)");

-- Dark Ranger Kalira SAI
SET @ENTRY := 37583;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,31942,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Ranger Kalira - In Combat CMC - Cast 'Multi-Shot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,31942,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Ranger Kalira - In Combat CMC - Cast 'Multi-Shot' (Heroic Dungeon)");

-- Archmage Elandra SAI
SET @ENTRY := 37774;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,51779,64,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Elandra - In Combat CMC - Cast 'Frostfire Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4800,11,70616,64,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Elandra - In Combat CMC - Cast 'Frostfire Bolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,8000,12000,13000,16000,11,22746,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - In Combat - Cast 'Cone of Cold' (Dungeon)");

-- Dark Ranger Loralen SAI
SET @ENTRY := 37779;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,31942,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Ranger Loralen - In Combat CMC - Cast 'Multi-Shot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,70513,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Ranger Loralen - In Combat CMC - Cast 'Multi-Shot' (Heroic Dungeon)");
