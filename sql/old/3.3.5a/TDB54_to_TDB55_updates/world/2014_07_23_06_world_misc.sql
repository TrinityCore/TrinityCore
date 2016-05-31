-- Dragonflayer Seer SAI
SET @ENTRY := 26554;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,7000,11000,11,48698,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Seer - In Combat CMC - Cast 'Lightning Bolt' (Dungeon) Heroic 59081"),
(@ENTRY,0,1,0,0,0,100,6,4000,7000,12000,15000,11,48699,64,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Seer - In Combat CMC - Cast 'Chain Lightning' (Dungeon) Heroic 59082"),
(@ENTRY,0,2,0,74,0,100,6,0,30,18000,21000,11,48700,0,0,0,0,0,9,0,0,0,0,0,0,0,"Dragonflayer Seer - On Friendly Between 0-30% Health - Cast 'Healing Wave' (Dungeon) Heroic 59083");

-- Blackrock Shadowcaster SAI
SET @ENTRY := 436;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Shadowcaster - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,3700,4500,8400,28100,11,11639,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blackrock Shadowcaster - In Combat - Cast 'Shadow Word: Pain'"),
(@ENTRY,0,3,4,0,0,100,0,11600,18600,37600,47300,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - In Combat - Cast 'Frenzy'"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Shadowcaster - In Combat - Say Line 1"),
(@ENTRY,0,5,0,0,0,75,0,24100,24100,44500,44500,11,8994,0,0,0,0,0,6,0,0,0,0,0,0,0,"Blackrock Shadowcaster - In Combat - Cast 'Banish'"),
(@ENTRY,0,6,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blackrock Shadowcaster - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Stonesplinter Scout SAI
SET @ENTRY := 1162;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2800,4800,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Scout - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Stonesplinter Seer SAI
SET @ENTRY := 1166;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,1200,2400,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Seer - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Seer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Tunnel Rat Scout SAI
SET @ENTRY := 1173;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,2700,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Tunnel Rat Scout - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mo'grosh Shaman SAI
SET @ENTRY := 1181;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,40,3400,5400,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mo'grosh Shaman - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,0,0,60,1,1000,2000,0,0,11,3229,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Shaman - In Combat - Cast 'Quick Bloodlust'");

-- Mo'grosh Mystic SAI
SET @ENTRY := 1183;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Mystic - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,5400,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mo'grosh Mystic - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,74,0,100,1,0,40,0,0,11,547,0,0,0,0,0,9,0,0,0,0,0,0,0,"Mo'grosh Mystic - On Friendly Between 0-40% Health - Cast 'Healing Wave'");

-- Frostmane Seer SAI
SET @ENTRY := 1397;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Seer - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,5400,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmane Seer - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Seer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Magosh SAI
SET @ENTRY := 1399;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magosh - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,40,1200,3400,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Magosh - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,74,0,100,0,0,40,26700,26700,11,913,1,0,0,0,0,9,0,0,0,0,0,0,0,"Magosh - On Friendly Between 0-40% Health - Cast 'Healing Wave'"),
(@ENTRY,0,3,0,0,0,100,0,1000,3200,20300,35000,11,2606,1,0,0,0,0,2,0,0,0,0,0,0,0,"Magosh - In Combat - Cast 'Shock'");

-- Bluegill Raider SAI
SET @ENTRY := 1418;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2700,4900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bluegill Raider - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,0,0,100,0,11000,14300,16500,33300,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bluegill Raider - In Combat - Cast 'Net'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Splinter Fist Enslaver SAI
SET @ENTRY := 1487;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,5100,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Enslaver - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,0,0,100,0,0,3200,21100,42100,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Enslaver - In Combat - Cast 'Net'");

-- Darkeye Bonecaster SAI
SET @ENTRY := 1522;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,4000,5000,11,13322,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkeye Bonecaster - In Combat CMC - Cast 'Frostbolt'");

-- Scarlet Neophyte SAI
SET @ENTRY := 1539;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,13322,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Neophyte - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodsail Mage SAI
SET @ENTRY := 1562;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3600,5900,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Mage - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,1200,4700,34200,36800,11,2601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - In Combat - Cast 'Fire Shield III'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodsail Warlock SAI
SET @ENTRY := 1564;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Out of Combat - Set Phase Random Between 1-2 (No Repeat)"), -- Condition no pet?
(@ENTRY,0,1,0,1,1,100,1,0,1000,0,0,11,8722,3,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Out of Combat - Cast 'Summon Succubus' (No Repeat)"),
(@ENTRY,0,2,0,1,2,100,1,0,1000,0,0,11,11939,3,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Out of Combat - Cast 'Summon Imp' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,0,0,2400,3800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Warlock - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,4,0,0,0,100,0,6900,20900,15900,15900,11,11980,32,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Warlock - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodsail Elder Magus SAI
SET @ENTRY := 1653;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Elder Magus - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,14900,14900,43000,43000,11,11969,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - In Combat - Cast 'Fire Nova'"),
(@ENTRY,0,2,0,0,0,100,0,28700,28700,45200,45200,11,20827,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Elder Magus - In Combat - Cast 'Flamestrike'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Defias Watchman SAI
SET @ENTRY := 1725;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2200,3800,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Watchman - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 0-15% Health - Flee For Assist (Normal Dungeon) (No Repeat)");

-- Defias Magician SAI
SET @ENTRY := 1726;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - Out of Combat - Cast 'Frost Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,4000,6600,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Magician - In Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,0,0,23200,38500,11,5110,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - In Combat - Cast 'Summon Living Flame' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 0-15% Health - Flee For Assist (Normal Dungeon) (No Repeat)");

-- Skeletal Sorcerer SAI
SET @ENTRY := 1784;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Sorcerer - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,12000,20000,11,11969,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Sorcerer - In Combat - Cast 'Fire Nova'");

-- Skeletal Acolyte SAI
SET @ENTRY := 1789;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,1500,2800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Acolyte - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,11000,15000,11,14887,0,0,0,0,0,5,0,0,0,0,0,0,0,"Skeletal Acolyte - In Combat - Cast 'Shadow Bolt Volley'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,16588,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Acolyte - Between 0-30% Health - Cast 'Dark Mending' (No Repeat)");

-- Scarlet Mage SAI
SET @ENTRY := 1826;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Mage - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,9000,12000,11,20822,1,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Mage - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Hunter SAI
SET @ENTRY := 1831;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Hunter - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Magus SAI
SET @ENTRY := 1832;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Magus - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,10000,12000,18000,25000,11,15744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Magus - In Combat - Cast 'Blast Wave'"),
(@ENTRY,0,2,0,0,0,100,0,5000,10000,14000,19000,11,17203,1,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Magus - In Combat - Cast 'Fireball Volley'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magus - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Araj the Summoner SAI
SET @ENTRY := 1852;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,15497,64,0,0,0,0,2,0,0,0,0,0,0,0,"Araj the Summoner - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,14000,20000,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - In Combat - Cast 'Frost Nova'"),
(@ENTRY,0,2,0,0,0,100,0,18000,24000,50000,65000,11,17231,1,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - In Combat - Cast 'Summon Illusory Wraith'"),
(@ENTRY,0,3,0,6,0,100,1,0,0,0,0,11,18661,7,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - On Just Died - Cast 'Araj's Phylactery' (No Repeat)");

-- Dalaran Apprentice SAI
SET @ENTRY := 1867;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,13322,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Apprentice - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Apprentice - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Ravenclaw Servant SAI
SET @ENTRY := 1868;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,85,1,0,65,22000,22000,11,7290,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ravenclaw Servant - Between 0-65% Health - Cast 'Soul Siphon' (No Repeat)"),
(@ENTRY,0,1,0,0,0,85,0,4000,4000,24000,28000,11,980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravenclaw Servant - In Combat - Cast 'Curse of Agony'");

-- Dalaran Wizard SAI
SET @ENTRY := 1889;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,5400,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Wizard - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,9000,14000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - In Combat - Cast 'Frost Nova'"),
(@ENTRY,0,3,0,0,0,100,1,3000,5000,14000,20000,11,4980,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - In Combat - Cast 'Quick Frost Ward'"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Wizard - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Deeb SAI
SET @ENTRY := 1911;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deeb - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,2000,6000,6000,10000,11,2607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deeb - In Combat - Cast 'Shock'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeb - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dalaran Mage SAI
SET @ENTRY := 1914;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Mage - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,1,8000,14000,0,0,11,134,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - In Combat - Cast 'Fire Shield'"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,20000,30000,11,4979,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - In Combat - Cast 'Quick Flame Ward'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Mage - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dalaran Conjuror SAI
SET @ENTRY := 1915;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,20798,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - Out of Combat - Cast 'Demon Skin'"),
(@ENTRY,0,1,0,1,0,100,1,2000,2000,0,0,11,25112,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - Out of Combat - Cast 'Summon Voidwalker' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,0,0,2400,3800,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Conjuror - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Conjuror - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dalaran Spellscribe SAI
SET @ENTRY := 1920;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2800,3600,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Spellscribe - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Spellscribe - Between 0-15% Health - Flee For Assist (No Repeat)");
