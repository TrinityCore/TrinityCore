-- Skeletal Mage SAI
SET @ENTRY := 203;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Mage - Out of Combat - Cast Frost Armor"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3300,6100,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Mage - In Combat CMC - Cast Frostbolt");

-- Eliza SAI
SET @ENTRY := 314;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eliza - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,0,0,11,20819,64,0,0,0,0,5,0,0,0,0,0,0,0,"Eliza - In Combat CMC - Cast Frostbolt"),
(@ENTRY,0,2,0,0,0,100,0,2100,2900,12500,36300,11,11831,0,0,0,0,0,5,0,0,0,0,0,0,0,"Eliza - In Combat - Cast Frost Nova"),
(@ENTRY,0,3,0,0,0,100,0,4100,6400,72300,72300,11,3107,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eliza - In Combat - Cast Summon Eliza's Guard");

-- Singe SAI
SET @ENTRY := 335;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,5200,11,13375,64,0,0,0,0,2,0,0,0,0,0,0,0,"Singe - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,4100,9200,19700,21300,11,12468,0,0,0,0,0,2,0,0,0,0,0,0,0,"Singe - In Combat - Cast 'Flamestrike'");

-- Morganth SAI
SET @ENTRY := 397;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - Out of Combat - Cast 'Demon Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,1700,3800,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,"Morganth - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,3611,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morganth - hp@50 - Cast 'Minion of Morganth'");

-- Redridge Poacher SAI
SET @ENTRY := 424;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Poacher - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,3700,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Redridge Poacher - In Combat CMC - Cast 'Shoot'");

-- Shadowhide Darkweaver SAI
SET @ENTRY := 429;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,1400,1700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowhide Darkweaver - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Darkweaver - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Redridge Mystic SAI
SET @ENTRY := 430;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,600,1800,11,20802,64,0,0,0,0,2,0,0,0,0,0,0,0,"Redridge Mystic - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Mystic - Between 0-15% Health - Flee For Assist (No Repeat)");

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
(@ENTRY,0,6,0,2,0,100,1,0,0,15,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blackrock Shadowcaster - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Black Dragon Whelp SAI
SET @ENTRY := 441;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3200,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Black Dragon Whelp - In Combat CMC - Cast 'Fireball'");

-- Defias Renegade Mage SAI
SET @ENTRY := 450;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Renegade Mage - In Combat CMC - Cast 'Fireball' (Phase 1) (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,16400,18400,12300,17200,11,4979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - In Combat - Cast 'Quick Flame Ward'"),
(@ENTRY,0,2,0,0,0,100,0,19200,21200,63900,68200,11,134,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - In Combat - Cast 'Fire Shield'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Riverpaw Mystic SAI
SET @ENTRY := 453;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4400,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Mystic - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Murloc Minor Oracle SAI
SET @ENTRY := 456;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3600,5100,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Minor Oracle - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,14,0,100,0,130,40,30900,39000,11,332,1,0,0,0,0,7,0,0,0,0,0,0,0,"Murloc Minor Oracle - Friendly At 130 Health - Cast 'Healing Wave'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Murloc Hunter SAI
SET @ENTRY := 458;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,8656,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Out of Combat - Cast 'Summon Crawler' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2900,4800,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Hunter - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Riverpaw Scout SAI
SET @ENTRY := 500;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2200,4700,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Scout - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Nightbane Shadow Weaver SAI
SET @ENTRY := 533;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2800,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,21700,114300,76500,91800,11,992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - In Combat - Cast 'Shadow Word: Pain'");

-- Murloc Minor Tidecaller SAI
SET @ENTRY := 548;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,6400,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,74,0,100,0,0,40,31800,82800,11,547,0,0,0,0,0,9,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - On Friendly Between 0-40% Health - Cast 'Healing Wave'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Murloc Scout SAI
SET @ENTRY := 578;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2600,3700,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Scout - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Marisa du'Paige SAI
SET @ENTRY := 599;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,5400,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Marisa du'Paige - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,80,0,18000,25000,25000,35000,11,228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marisa du'Paige - In Combat - Cast 'Polymorph: Chicken'"),
(@ENTRY,0,2,0,0,0,100,0,12000,19000,35000,48000,11,700,0,0,0,0,0,5,0,0,0,0,0,0,0,"Marisa du'Paige - In Combat - Cast 'Sleep'"),
(@ENTRY,0,3,0,2,0,100,0,0,50,35000,35000,11,512,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marisa du'Paige - Between 0-50% Health - Cast 'Chains of Ice'"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Goblin Engineer SAI
SET @ENTRY := 622;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2200,3800,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Goblin Engineer - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,500,4500,67800,89000,11,3605,1,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - In Combat - Cast 'Summon Remote-Controlled Golem' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodscalp Axe Thrower SAI
SET @ENTRY := 694;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Skullsplitter Axe Thrower SAI
SET @ENTRY := 696;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2200,3800,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,23000,26000,11,3148,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - In Combat - Cast 'Head Crack'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodscalp Mystic SAI
SET @ENTRY := 701;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,1500,2500,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Mystic - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,25000,30000,11,4979,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - In Combat - Cast 'Quick Flame Ward'"),
(@ENTRY,0,2,0,14,0,100,1,500,40,0,0,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodscalp Mystic - Friendly At 500 Health - Cast 'Healing Wave' (No Repeat)"),
(@ENTRY,0,3,4,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `entry` IN (701);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(701, 0, 0, '%s becomes enraged!', 16, 0, 100, 0, 0, 0, 'Bloodscalp Mystic');

-- Skullsplitter Mystic SAI
SET @ENTRY := 780;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,1500,2500,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Mystic - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,14,0,100,1,700,40,0,0,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Skullsplitter Mystic - Friendly At 700 Health - Cast 'Healing Wave' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Mystic - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Skeletal Healer SAI
SET @ENTRY := 787;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,3700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Healer - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,74,0,100,1,0,40,0,0,11,2054,1,0,0,0,0,9,0,0,0,0,0,0,0,"Skeletal Healer - On Friendly Between 0-40% Health - Cast 'Heal'");

-- Splinter Fist Fire Weaver SAI
SET @ENTRY := 891;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3300,7400,11,19816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,1600,4700,18400,19100,11,20296,1,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - In Combat - Cast 'Flamestrike'");

-- Defias Enchanter SAI
SET @ENTRY := 910;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3900,7600,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Enchanter - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,5000,14100,18000,36500,11,3443,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - In Combat - Cast 'Enchanted Quickness'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Kurzen Headshrinker SAI
SET @ENTRY := 941;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kurzen Headshrinker - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,2400,10800,39000,39500,11,7289,1,0,0,0,0,2,0,0,0,0,0,0,0,"Kurzen Headshrinker - In Combat - Cast 'Shrink'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Frostmane Novice SAI
SET @ENTRY := 946;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,5400,11,6949,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmane Novice - In Combat CMC - Cast 'Weak Frostbolt'");

-- Mosshide Mistweaver SAI
SET @ENTRY := 1009;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12554,32,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - Out of Combat - Cast 'Summon Treasure Horde'"),
(@ENTRY,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,0,0,1500,3000,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshide Mistweaver - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,3,0,2,0,100,1,16,30,0,0,11,3288,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - Between 16-30% Health - Cast 'Moss Hide'"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,28,3288,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - Between 0-15% Health - Remove Aura 'Moss Hide'"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mosshide Mystic SAI
SET @ENTRY := 1013;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3300,5100,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshide Mystic - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,0,0,30,1,14400,14400,0,0,11,11436,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshide Mystic - In Combat - Cast 'Slow'"),
(@ENTRY,0,3,0,74,0,80,1,0,40,0,0,11,11986,1,0,0,0,0,9,0,0,0,0,0,0,0,"Mosshide Mystic - On Friendly Between 0-40% Health - Cast 'Healing Wave'"),
(@ENTRY,0,4,0,2,0,100,1,16,30,0,0,11,3288,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - Between 16-30% Health - Cast 'Moss Hide'"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,28,3288,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - Between 0-15% Health - Remove Aura 'Moss Hide'"),
(@ENTRY,0,6,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dragonmaw Shadowwarder SAI
SET @ENTRY := 1038;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,6400,11,20807,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,2200,6200,20200,31000,11,6223,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - In Combat - Cast 'Corruption'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Lost Whelp SAI
SET @ENTRY := 1043;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3600,5300,11,11839,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lost Whelp - In Combat CMC - Cast 'Fireball'");

-- Flamesnorting Whelp SAI
SET @ENTRY := 1044;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3600,5300,11,11839,64,0,0,0,0,2,0,0,0,0,0,0,0,"Flamesnorting Whelp - In Combat CMC - Cast 'Fireball'");

-- Dark Iron Demolitionist SAI
SET @ENTRY := 1054;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Iron Demolitionist - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3600,3800,11,8858,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Demolitionist - In Combat CMC - Cast 'Bomb'"),
(@ENTRY,0,2,0,0,0,100,0,1200,8300,8200,20100,11,7891,3,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Iron Demolitionist - In Combat - Cast 'Gift of Ragnaros'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Riverpaw Shaman SAI
SET @ENTRY := 1065;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Shaman - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,74,0,100,1,0,40,0,0,11,913,1,0,0,0,0,9,0,0,0,0,0,0,0,"Riverpaw Shaman - On Friendly Between 0-40% Health - Cast 'Healing Wave'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Venture Co. Mechanic SAI
SET @ENTRY := 1097;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2200,3800,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Mechanic - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,6500,10000,6500,10000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Mechanic - In Combat - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Frostmane Headhunter SAI
SET @ENTRY := 1123;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Headhunter - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmane Headhunter - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Headhunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Frostmane Shadowcaster SAI
SET @ENTRY := 1124;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,20798,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Shadowcaster - Out of Combat - Cast 'Demon Skin'"),
(@ENTRY,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Shadowcaster - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,500,500,3400,6400,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmane Shadowcaster - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,3,0,0,0,100,0,0,0,180000,186200,11,11980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmane Shadowcaster - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Headhunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Thunderhawk Hatchling SAI
SET @ENTRY := 3247;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,600000,600000,11,325,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhawk Hatchling - Out of Combat - Cast Lightning Shield"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhawk Hatchling - In Combat CMC - Cast Lightning Bolt");

-- Bristleback Hunter SAI
SET @ENTRY := 3258;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Hunter - In Combat CMC - Cast Shoot"),
(@ENTRY,0,1,0,0,0,100,0,9000,14000,9000,14000,11,8806,32,0,0,0,0,5,0,0,0,0,0,0,0,"Bristleback Hunter - In Combat - Cast Poisoned Shot"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - HP@15 - Flee For Assist (No Repeat)");

-- Bristleback Geomancer SAI
SET @ENTRY := 3263;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Geomancer - In Combat CMC - Cast Fireball"),
(@ENTRY,0,1,0,0,0,100,0,5000,6500,17000,22000,11,4979,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - In Combat - Cast Quick Flame Ward"),
(@ENTRY,0,2,0,0,0,100,0,8000,13000,18000,25000,11,20794,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Geomancer - In Combat - Cast Flamestrike"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - HP@15 - Flee For Assist (No Repeat)");

-- Razormane Hunter SAI
SET @ENTRY := 3265;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Hunter - In Combat - Cast Shoot"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - HP@15 - Flee For Assist (No Repeat)");

-- Razormane Geomancer SAI
SET @ENTRY := 3269;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - Out of Combat - Cast Frost Armor"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Geomancer - In Combat CMC - Cast Fireball"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - HP@15 - Flee For Assist (No Repeat)");

-- Kolkar Wrangler SAI
SET @ENTRY := 3272;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Wrangler - In Combat CMC - Cast Shoot"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,9000,14000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Wrangler - In Combat - Cast Net"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - HP@15 - Flee For Assist (No Repeat)");

-- Kolkar Stormer SAI
SET @ENTRY := 3273;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6535,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Stormer - On Aggro - Cast 'Lightning Cloud' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Stormer - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Stormer - HP@15 - Flee For Assist (No Repeat)");
