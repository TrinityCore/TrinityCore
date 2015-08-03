-- Skeletal Guardian SAI
SET @ENTRY := 10390;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - Out of Combat - Cast 'Demon Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,4,0,100,2,0,0,0,0,11,16799,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Guardian - On Aggro - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,2400,3800,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Guardian - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,85,2,9000,12000,9000,12000,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Guardian - In Combat Range - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,85,2,6000,7000,9000,12000,11,37361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Guardian - In Combat - Cast 'Arcane Bolt' (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,85,2,14000,18000,14000,18000,11,11975,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - In Combat - Cast 'Arcane Explosion' (Normal Dungeon)");

-- Skul SAI
SET @ENTRY := 10393;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - Out of Combat - Cast 'Frost Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,16799,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skul - In Combat - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,50,2,6000,8000,16000,20000,11,15499,1,0,0,0,0,5,0,0,0,0,0,0,0,"Skul - In Combat - Cast 'Frost Shock' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,40,2,9000,11000,9000,11000,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skul - In Combat - Cast 'Arcane Bolt' (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skul - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Thuzadin Shadowcaster SAI
SET @ENTRY := 10398;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,4000,6000,20000,25000,11,11443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - In Combat - Cast 'Cripple' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,12000,15000,20000,11,16429,33,0,0,0,0,5,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - In Combat - Cast 'Piercing Shadow' (Normal Dungeon)");

-- Crimson Conjuror SAI
SET @ENTRY := 10419;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,40,2400,3800,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Conjuror - In Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,85,2,7000,7000,10000,10000,11,17195,1,0,0,0,0,5,0,0,0,0,0,0,0,"Crimson Conjuror - In Combat - Cast 'Scorch' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10000,10000,15000,15000,11,12674,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - In Combat - Cast 'Frost Nova' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,5000,5000,35000,45000,11,17162,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - In Combat - Cast 'Summon Water Elemental' (Normal Dungeon)");

-- Crimson Sorcerer SAI
SET @ENTRY := 10422;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - Out of Combat - Cast 'Frost Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,3000,3000,1800000,1800000,11,17150,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - Out of Combat - Cast 'Arcane Might' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,0,0,2400,3800,11,15230,64,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Sorcerer - In Combat CMC - Cast 'Arcane Bolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,7000,14000,21000,26000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Crimson Sorcerer - In Combat - Cast 'Polymorph' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,5000,6000,8500,10000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Sorcerer - In Combat - Cast 'Fire Blast' (Normal Dungeon)");

-- Chromatic Whelp SAI
SET @ENTRY := 10442;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,2,0,0,0,0,11,16249,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Whelp - On Aggro - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,2400,3800,2400,3800,11,12167,64,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Whelp - In Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,16200,26500,7000,27900,11,16249,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Whelp - In Combat - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,10800,19600,15700,20400,11,16250,1,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Whelp - In Combat - Cast 'Fireball Volley' (Normal Dungeon)");

-- Scholomance Adept SAI
SET @ENTRY := 10469;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3200,4800,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Adept - In Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7300,17300,9400,14300,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - In Combat - Cast 'Cone of Cold' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7600,19700,12200,24700,11,15499,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Adept - In Combat - Cast 'Frost Shock' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scholomance Adept - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Scholomance Neophyte SAI
SET @ENTRY := 10470;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Neophyte - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,2,8600,26300,18400,36000,11,17165,1,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Neophyte - In Combat - Cast 'Mind Flay'");

-- Scholomance Necrolyte SAI
SET @ENTRY := 10476;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Necrolyte - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,1400,6200,7400,22000,11,17234,1,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Necrolyte - In Combat - Cast 'Shadow Shock' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,1400,22000,22000,33200,11,17151,32,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Necrolyte - In Combat - Cast 'Shadow Barrier' (Normal Dungeon)");

-- Hearthsinger Forresten SAI
SET @ENTRY := 10558;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5,30,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hearthsinger Forresten - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,5000,12000,19000,11,16244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - In Combat - Cast 'Demoralizing Shout' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,9000,20000,25000,11,16798,1,0,0,0,0,6,0,0,0,0,0,0,0,"Hearthsinger Forresten - In Combat - Cast 'Enchanting Lullaby' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Lady Vespia SAI
SET @ENTRY := 10559;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5400,7100,14300,19600,11,8398,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Vespia - In Combat - Cast 'Frostbolt Volley' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,0,15300,19100,9500,22100,11,13586,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Vespia - In Combat - Cast 'Aqua Jet' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Vespia - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Urok Ogre Magus SAI
SET @ENTRY := 10602;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15979,64,0,0,0,0,2,0,0,0,0,0,0,0,"Urok Ogre Magus - In Combat CMC - Cast 'Arcane Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8000,11000,17000,24000,11,13747,1,0,0,0,0,5,0,0,0,0,0,0,0,"Urok Ogre Magus - In Combat - Cast 'Slow' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,30,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - Between 0-30% Health - Cast 'Bloodlust' (No Repeat) (Normal Dungeon)");
