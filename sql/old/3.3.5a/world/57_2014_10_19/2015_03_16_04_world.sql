-- Spirit of Koosu SAI
SET @ENTRY := 29034;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,21971,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spirit of Koosu - Combat CMC - Cast 'Poison Bolt'");

-- Anub'ar Necromancer SAI
SET @ENTRY := 29064;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,4000,6000,11,53333,64,0,0,0,0,2,0,0,0,0,0,0,0,"Anub'ar Necromancer - Combat CMC - Cast 'Shadow Bolt' (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,6,14000,17000,23000,27000,11,53334,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Necromancer - Combat - Cast 'Animate Bones' (Dungeon)");

-- Anub'ar Necromancer SAI
SET @ENTRY := 29098;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,4000,6000,11,53333,64,0,0,0,0,2,0,0,0,0,0,0,0,"Anub'ar Necromancer - Combat CMC - Cast 'Shadow Bolt' (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,6,14000,17000,23000,27000,11,53334,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Necromancer - Combat - Cast 'Animate Bones' (Dungeon)");


-- Anub'ar Prime Guard SAI
SET @ENTRY := 29128;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,10000,13000,11,54309,64,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Combat CMC - Cast 'Mark of Darkness' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,10000,13000,11,59352,64,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Combat CMC - Cast 'Mark of Darkness' (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,7,0,5,0,0,11,54314,33,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - 0-5 Range - Cast 'Drain Power' (No Repeat) (Dungeon)");


-- Lost Drakkari Spirit SAI
SET @ENTRY := 29129;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,23,0,100,0,17327,0,2000,2000,11,17327,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Drakkari Spirit - On Has Aura 'Spirit Particles' - Cast 'Spirit Particles'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,1500,1500,11,37361,65,0,0,0,0,2,0,0,0,0,0,0,0,"Lost Drakkari Spirit - Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,10000,16000,15000,18000,11,24050,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lost Drakkari Spirit - In Combat - Cast 'Spirit Burst'");

-- Onslaught Harbor Guard SAI
SET @ENTRY := 29330;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Harbor Guard - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,12000,14000,11,50750,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Harbor Guard - Combat - Cast 'Raven Heal'");

-- Sifreldar Runekeeper SAI
SET @ENTRY := 29331;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,15000,22000,11,52714,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - 0-30% Health - Cast 'Revitalizing Rune' (No Repeat)");

-- Onslaught Raven Bishop SAI
SET @ENTRY := 29338;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,50740,64,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Raven Bishop - Combat CMC - Cast 'Raven Flock'"),
(@ENTRY,0,1,0,2,0,100,1,10,50,2000,8000,11,50750,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Raven Bishop - 10-50% Health - Cast 'Raven Heal'  (No Repeat)");

-- Savage Hill Scavenger SAI
SET @ENTRY := 29404;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,5000,8000,11,50403,64,0,0,0,0,5,0,0,0,0,0,0,0,"Savage Hill Scavenger - Combat CMC - Cast 'Bone Toss'");

-- Savage Hill Mystic SAI
SET @ENTRY := 29622;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,4400,5800,11,50273,64,0,0,0,0,2,0,0,0,0,0,0,0,"Savage Hill Mystic - Combat CMC - Cast 'Arcane Barrage'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - 0-15% Health - Flee For Assist");

-- Stormforged Tracker SAI
SET @ENTRY := 29652;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Tracker - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,9000,12000,11,46982,1,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Tracker - Combat - Cast 'Lightning Gun Shot'");

-- Spitting Cobra SAI
SET @ENTRY := 29774;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,12000,15000,11,32860,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,12000,15000,11,38378,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,5000,10000,17000,20000,11,55703,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - Combat CMC - Cast 'Cobra Strike' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,5000,10000,17000,20000,11,59020,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - Combat CMC - Cast 'Cobra Strike' (Heroic Dungeon)");

-- Drakkari God Hunter SAI
SET @ENTRY := 29820;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,5000,11,35946,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,5000,11,59146,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,10000,12000,15000,11,55624,1,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat - Cast 'Arcane Shot' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,7000,10000,12000,15000,11,58973,1,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat - Cast 'Arcane Shot' (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,3000,5000,33000,37000,11,55798,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat - Cast 'Flare' (Dungeon)"),
(@ENTRY,0,5,0,0,0,100,6,18000,21000,19000,23000,11,55625,0,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari God Hunter - Combat - Cast 'Tranquillizing Shot' (Dungeon)"),
(@ENTRY,0,6,0,2,0,100,6,0,30,12000,15000,11,31567,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - 0-30% Health - Cast 'Deterrence' (Dungeon)");

-- Drakkari Fire Weaver SAI
SET @ENTRY := 29822;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,8000,9000,11,55659,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Fire Weaver - Combat CMC - Cast 'Lava Burst' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,8000,9000,11,58972,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Fire Weaver - Combat CMC - Cast 'Lava Burst' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,12000,15000,11,55613,65,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari Fire Weaver - Combat CMC - Cast 'Flame Shock' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,4000,7000,10000,14000,11,58971,65,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari Fire Weaver - Combat CMC - Cast 'Flame Shock' (Heroic Dungeon)"),
(@ENTRY,0,4,0,9,0,100,6,0,5,10000,16000,11,61362,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - 0-5 Range - Cast 'Blast Wave' (Dungeon)");

-- Drakkari Battle Rider SAI
SET @ENTRY := 29836;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,5000,7000,11,55348,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Battle Rider - Combat CMC - Cast 'Throw' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,5000,7000,11,58966,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Battle Rider - Combat CMC - Cast 'Throw' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,12000,15000,16000,22000,11,55521,33,0,0,0,0,6,0,0,0,0,0,0,0,"Drakkari Battle Rider - Combat - Cast 'Poisoned Spear' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,12000,15000,16000,22000,11,58967,33,0,0,0,0,6,0,0,0,0,0,0,0,"Drakkari Battle Rider - Combat - Cast 'Poisoned Spear' (Heroic Dungeon)");

-- Mildred the Cruel SAI
SET @ENTRY := 29885;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,30,3400,4800,11,15587,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mildred the Cruel - Combat CMC - Cast 'Mind Blast'"),
(@ENTRY,0,1,0,0,0,100,0,7000,11000,12000,15000,11,14032,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mildred the Cruel - Combat - Cast 'Shadow Word: Pain'"),
(@ENTRY,0,2,0,2,0,100,0,0,15,10000,15000,11,47697,1,0,0,0,0,5,0,0,0,0,0,0,0,"Mildred the Cruel - 0-15% Health - Cast 'Shadow Word: Death'");

-- K3 Bruiser SAI
SET @ENTRY := 29910;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,20,11000,16000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"K3 Bruiser - Within 0-20 Range - Cast 'Net' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"K3 Bruiser - Combat CMC - Cast 'Shoot'");

-- Earthen Stoneguard SAI
SET @ENTRY := 29960;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,20,11000,16000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Stoneguard - Within 0-20 Range - Cast 'Net' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Stoneguard - Combat CMC - Cast 'Shoot'");

-- Iron Dwarf Magus SAI
SET @ENTRY := 29979;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,30,3400,4800,11,12058,64,0,0,0,0,2,0,0,0,0,0,0,0,"Iron Dwarf Magus - Combat CMC - Cast 'Chain Lightning'");
