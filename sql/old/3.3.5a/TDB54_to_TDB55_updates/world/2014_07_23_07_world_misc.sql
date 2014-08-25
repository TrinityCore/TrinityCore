-- Shadow Sprite SAI
SET @ENTRY := 2003;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadow Sprite - In Combat CMC - Cast 'Shadow Bolt'");

-- Bloodfeather Sorceress SAI
SET @ENTRY := 2018;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Sorceress - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodfeather Sorceress - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,0,0,2400,3800,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfeather Sorceress - In Combat CMC - Cast 'Fireball'");

-- Bloodfeather Matriarch SAI
SET @ENTRY := 2021;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfeather Matriarch - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,18000,24000,11,332,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Matriarch - Between 0-50% Health - Cast 'Healing Wave'");

-- Dragonmaw Scout SAI
SET @ENTRY := 2103;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonmaw Scout - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3600,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Scout - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Garneg Charskull SAI
SET @ENTRY := 2108;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Garneg Charskull - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,6000,19600,11,15039,0,0,0,0,0,2,0,0,0,0,0,0,0,"Garneg Charskull - In Combat - Cast 'Flame Shock'"),
(@ENTRY,0,2,0,0,0,100,0,2300,6600,1200,7700,11,184,32,0,0,0,0,1,0,0,0,0,0,0,0,"Garneg Charskull - In Combat - Cast 'Fire Shield II'"),
(@ENTRY,0,3,0,0,0,100,0,10200,17600,33800,61100,11,6725,0,0,0,0,0,2,0,0,0,0,0,0,0,"Garneg Charskull - In Combat - Cast 'Flame Spike'"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Garneg Charskull - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Archmage Ataeric SAI
SET @ENTRY := 2120;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,1500,3000,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Ataeric - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,11000,16000,28000,38000,11,512,0,0,0,0,0,5,0,0,0,0,0,0,0,"Archmage Ataeric - In Combat - Cast 'Chains of Ice'"),
(@ENTRY,0,2,0,0,0,100,0,4000,9000,35000,45000,11,118,1,0,0,0,0,6,0,0,0,0,0,0,0,"Archmage Ataeric - In Combat - Cast 'Polymorph'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ataeric - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Greymist Oracle SAI
SET @ENTRY := 2207;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Greymist Oracle - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,14,0,100,0,190,40,30000,45000,11,913,0,0,0,0,0,7,0,0,0,0,0,0,0,"Greymist Oracle - Friendly At 190 Health - Cast 'Healing Wave'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Greymist Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Syndicate Shadow Mage SAI
SET @ENTRY := 2244;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,4200,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Shadow Mage - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Syndicate Shadow Mage - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Syndicate Saboteur SAI
SET @ENTRY := 2245;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,5900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Saboteur - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,7400,10200,14500,26900,11,6980,1,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Saboteur - In Combat - Cast 'Fire Shot'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Syndicate Saboteur - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Crushridge Mage SAI
SET @ENTRY := 2255;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Crushridge Mage - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,2,0,0,0,100,0,5300,7400,11300,21200,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - In Combat - Cast 'Bloodlust'");

-- Dalaran Theurgist SAI
SET @ENTRY := 2272;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3300,6600,11,20819,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Theurgist - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,1,4000,5300,4600,9900,11,3652,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - In Combat - Cast 'Summon Spirit of Old'  (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Magistrate Henry Maleb SAI
SET @ENTRY := 2276;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,4800,11,12737,64,0,0,0,0,2,0,0,0,0,0,0,0,"Magistrate Henry Maleb - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,3,0,9,0,100,0,0,8,12000,15000,11,15531,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - Within 0-8 Range - Cast 'Frost Nova'"),
(@ENTRY,0,4,0,16,0,100,0,12544,1,10000,20000,11,12544,33,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - On Friendly Unit Missing Buff 'Frost Armor' - Cast 'Frost Armor'"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Henry Maleb - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Baron Vardus SAI
SET @ENTRY := 2306;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3200,7500,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,"Baron Vardus - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,17600,12200,39800,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - In Combat - Cast 'Frost Nova'"),
(@ENTRY,0,2,0,0,0,100,0,1000,3000,12500,29800,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baron Vardus - In Combat - Cast 'Backhand'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Argus Shadow Mage SAI
SET @ENTRY := 2318;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - On Aggro - Set Event Phase 1"),
(@ENTRY,0,1,0,0,1,100,0,0,0,3500,4900,11,20816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Argus Shadow Mage - In Combat CMC - Cast 'Shadow Bolt' (Phase 1)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - Between 0-30% Health - Set Event Phase 2"),
(@ENTRY,0,3,4,0,2,100,1,0,0,0,0,11,4063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - In Combat - Cast 'Argus Shadow Mage Transform' (Phase 2) (No Repeat)"),
(@ENTRY,0,4,5,61,2,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - In Combat - Enable Combat Movement"),
(@ENTRY,0,5,0,61,2,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - In Combat - Say Line 0");

-- Syndicate Wizard SAI
SET @ENTRY := 2319;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Wizard - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,5400,11,20815,64,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Wizard - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,9,0,100,0,5000,9000,25000,35000,11,12824,1,0,0,0,0,6,0,0,0,0,0,0,0,"Syndicate Wizard - Within 0-5 Range - Cast 'Polymorph'");

-- Magistrate Burnside SAI
SET @ENTRY := 2335;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,"Magistrate Burnside - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,12000,15000,11,11969,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - Within 0-8 Range - Cast 'Fire Nova'"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,16000,20000,11,7739,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - In Combat - Cast 'Inferno Shell'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Burnside - Between 0-15% Health - Flee For Assist");

-- Dark Strand Voidcaller SAI
SET @ENTRY := 2337;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Out of Combat - Cast 'Summon Voidwalker' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,20807,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Strand Voidcaller - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dun Garok Rifleman SAI
SET @ENTRY := 2345;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dun Garok Rifleman - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,12000,18000,30000,30000,11,6685,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dun Garok Rifleman - In Combat - Cast 'Piercing Shot'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Rifleman - Between 0-30% Health - Flee For Assist");

-- Dun Garok Priest SAI
SET @ENTRY := 2346;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dun Garok Priest - In Combat CMC - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,74,0,100,0,0,40,15000,21000,11,11642,1,0,0,0,0,9,0,0,0,0,0,0,0,"Dun Garok Priest - On Friendly Between 0-40% Health - Cast 'Heal'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dun Garok Priest - Between 0-30% Health - Flee For Assist");

-- Dalaran Summoner SAI
SET @ENTRY := 2358;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,6200,6400,11,20815,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Summoner - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,2,0,0,100,1,9100,14900,0,0,11,3658,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - In Combat - Cast 'Summon Theurgist' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - In Combat - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,4,0,0,100,1,4700,11100,0,0,11,3655,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - In Combat - Cast 'Summon Shield Guard' (No Repeat)"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - In Combat - Say Line 0 (No Repeat)");

-- Daggerspine Shorehunter SAI
SET @ENTRY := 2369;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2200,3800,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Daggerspine Shorehunter - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Shorehunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Daggerspine Siren SAI
SET @ENTRY := 2371;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Daggerspine Siren - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,22000,27000,11,992,1,0,0,0,0,5,0,0,0,0,0,0,0,"Daggerspine Siren - In Combat - Cast 'Shadow Word: Pain'"),
(@ENTRY,0,2,0,0,0,100,0,11000,15000,17000,21000,11,6728,0,0,0,0,0,6,0,0,0,0,0,0,0,"Daggerspine Siren - In Combat - Cast 'Enveloping Winds'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Siren - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mudsnout Shaman SAI
SET @ENTRY := 2373;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20805,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mudsnout Shaman - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,74,0,100,0,0,40,14000,19000,11,939,1,0,0,0,0,9,0,0,0,0,0,0,0,"Mudsnout Shaman - On Friendly Between 0-40% Health - Cast 'Healing Wave'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudsnout Shaman - Between 0-15% Health - Flee For Assist");

-- Torn Fin Coastrunner SAI
SET @ENTRY := 2375;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Torn Fin Coastrunner - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Coastrunner - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Torn Fin Oracle SAI
SET @ENTRY := 2376;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Torn Fin Oracle - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,0,0,25,25000,35000,11,939,1,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - Between 0-25% Health - Cast 'Healing Wave'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torn Fin Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Hillsbrad Councilman SAI
SET @ENTRY := 2387;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,20806,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hillsbrad Councilman - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,25000,25000,11,122,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - Within 0-5 Range - Cast 'Frost Nova'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Councilman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Warden Belamoore SAI
SET @ENTRY := 2415;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3300,4900,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warden Belamoore - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,10300,10300,14900,37400,11,20828,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - In Combat - Cast 'Cone of Cold'"),
(@ENTRY,0,2,0,0,0,100,0,7600,12900,9800,15900,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Warden Belamoore - In Combat - Cast 'Polymorph'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Jailor Marlgen SAI
SET @ENTRY := 2428;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jailor Marlgen - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,9,0,100,0,0,20,7000,11000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Jailor Marlgen - Within 0-20 Range - Cast 'Net'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jailor Marlgen - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Archmage Ansirem Runeweaver SAI
SET @ENTRY := 2543;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,6300,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,5100,7400,3700,17600,11,512,33,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - In Combat - Cast 'Chains of Ice'"),
(@ENTRY,0,2,0,0,0,100,0,7600,12500,26000,30000,11,118,32,0,0,0,0,6,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - In Combat - Cast 'Polymorph'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Captain Keelhaul SAI
SET @ENTRY := 2548;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2200,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Keelhaul - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,15600,32700,15600,32700,11,7896,1,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Keelhaul - In Combat - Cast 'Exploding Shot'"),
(@ENTRY,0,2,0,0,0,100,0,1200,3200,17200,25200,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Witherbark Shadowcaster SAI
SET @ENTRY := 2553;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,50,1,1000,1000,0,0,11,11939,1,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - Out of Combat - Cast 'Summon Imp' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3600,6300,11,20816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Shadowcaster - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Witherbark Axe Thrower SAI
SET @ENTRY := 2554;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2100,4800,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Axe Thrower - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,0,0,100,0,10200,26000,2500,6700,11,4974,32,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Axe Thrower - In Combat - Cast 'Wither Touch'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Boulderfist Magus SAI
SET @ENTRY := 2567;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,0,0,3500,6400,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Magus - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,3,0,0,0,100,0,6000,9800,15400,23500,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - In Combat - Cast 'Frost Nova'"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Boulderfist Shaman SAI
SET @ENTRY := 2570;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,6400,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Shaman - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,45,0,0,11,6364,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - Between 0-45% Health - Cast 'Searing Totem' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,40,0,0,11,11986,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - Between 0-45% Health - Cast 'Healing Wave' (No Repeat)");

-- Drywhisker Surveyor SAI
SET @ENTRY := 2573;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,6400,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drywhisker Surveyor - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,2,0,0,0,100,0,5100,15000,215000,225000,11,865,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - In Combat - Cast 'Frost Nova'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dark Iron Shadowcaster SAI
SET @ENTRY := 2577;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,8600,11,20816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5500,12400,18200,30700,11,2941,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - In Combat - Cast 'Immolate'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Syndicate Pathstalker SAI
SET @ENTRY := 2587;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2200,3800,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Pathstalker - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Pathstalker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Syndicate Conjuror SAI
SET @ENTRY := 2590;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,50,0,1000,1000,300000,300000,11,25085,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Conjuror - Out of Combat - Cast 'Bright Campfire'"),
(@ENTRY,0,1,0,1,0,100,1,3000,3000,0,0,11,43896,1,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Conjuror - Out of Combat - Cast 'Summon Voidwalker'"),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,6500,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Conjuror - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,3,0,0,0,100,0,2800,20700,18700,35900,11,15970,1,0,0,0,0,6,0,0,0,0,0,0,0,"Syndicate Conjuror - In Combat - Cast 'Sleep'"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Syndicate Conjuror - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Syndicate Magus SAI
SET @ENTRY := 2591;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Magus - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3600,6300,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Magus - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Magus - Between 0-15% Health - Flee For Assist (No Repeat)");
