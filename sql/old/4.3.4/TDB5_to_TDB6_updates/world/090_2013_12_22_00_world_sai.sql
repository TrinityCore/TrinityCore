-- Firehawk Mariner SAI
SET @ENTRY := 35070;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Firehawk Mariner - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,7000,9000,11,17174,1,0,0,0,0,5,0,0,0,0,0,0,0,"Firehawk Mariner - In Combat - Cast 'Concussive Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,8000,11000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firehawk Mariner - Within 5-30 Range - Cast 'Multi-Shot'");

-- Captain Aerthas Firehawk SAI
SET @ENTRY := 35090;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,8000,11000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Within 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,4000,7000,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Aerthas Firehawk - Within 0-5 Range - Cast 'Heroic Strike'");

-- Wavecrest Mariner SAI
SET @ENTRY := 35098;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wavecrest Mariner - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,7000,9000,11,17174,1,0,0,0,0,5,0,0,0,0,0,0,0,"Wavecrest Mariner - In Combat - Cast 'Concussive Shot' (Phase 1)"),
(@ENTRY,0,2,0,9,0,100,0,5,30,8000,11000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wavecrest Mariner - Within 5-30 Range - Cast 'Multi-Shot' (Phase 1)");

-- Captain Elleane Wavecrest SAI
SET @ENTRY := 35102;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,8000,11000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Within 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,4000,7000,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Elleane Wavecrest - Within 0-5 Range - Cast 'Heroic Strike'");

-- Defias Smuggler SAI
SET @ENTRY := 95;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Smuggler - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Smuggler - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,2,0,67,0,100,0,1300,7300,4800,4900,11,53,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Smuggler - Behind Target - Cast 'Backstab'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Smuggler - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Defias Rogue Wizard SAI
SET @ENTRY := 474;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Rogue Wizard - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Rogue Wizard - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,0,0,2300,3900,11,13322,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Rogue Wizard - In Combat CMC - Cast 'Frostbolt'");

-- Kobold Geomancer SAI
SET @ENTRY := 476;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kobold Geomancer - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kobold Geomancer - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,0,0,2300,3900,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kobold Geomancer - In Combat CMC - Cast 'Fireball'");

-- Defias Pillager SAI
SET @ENTRY := 589;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Pillager - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Pillager - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,5400,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Pillager - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Pillager - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Surena Caledon SAI
SET @ENTRY := 881;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surena Caledon - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,4,0,40,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surena Caledon - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,0,0,2300,3900,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Surena Caledon - In Combat CMC - Cast 'Fireball'");

-- Blackhand Dreadweaver SAI
SET @ENTRY := 9817;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,12380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Dreadweaver - On Reset - Cast 'Shadow Channeling' (Normal Dungeon)"),
(@ENTRY,0,1,0,4,0,100,2,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Dreadweaver - On Aggro - Call For Help (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,0,0,3600,6300,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Blackhand Dreadweaver - In Combat - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,9400,21400,22000,28800,11,7068,3,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Dreadweaver - In Combat - Cast 'Veil of Shadow' (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Dreadweaver - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,5,7,1,0,100,2,0,8000,12000,14000,92,0,0,1,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Dreadweaver - Out of Combat - Interrupt Spell (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Dreadweaver - Out of Combat - Set Event Phase 1 (Normal Dungeon)"),
(@ENTRY,0,7,0,1,1,100,2,0,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Dreadweaver - Out of Combat - Play Emote 1 (Normal Dungeon)"),
(@ENTRY,0,8,10,1,1,100,2,4000,4000,4000,4000,11,12380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Dreadweaver - Out of Combat - Cast 'Shadow Channeling' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Dreadweaver - Out of Combat - Set Event Phase 0 (Phase 1) (Normal Dungeon)");

-- Blackhand Summoner SAI
SET @ENTRY := 9818;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3600,6300,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,"Blackhand Summoner - In Combat - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,11,12380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Summoner - On Reset - Cast 'Shadow Channeling' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,2,0,4,0,100,2,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Summoner - On Aggro - Call For Help (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,11400,11400,12700,16700,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Summoner - In Combat - Cast 'Frost Nova' (Normal Dungeon)"),
(@ENTRY,0,4,6,0,0,100,3,30000,35000,0,0,11,15792,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Summoner - In Combat - Cast 'Summon Blackhand Veteran' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Summoner - In Combat - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,6,8,0,0,100,3,40000,45000,0,0,11,15794,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Summoner - In Combat - Cast 'Summon Blackhand Dreadweaver' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Summoner - In Combat - Say Line 1 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,8,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Summoner - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,9,0,1,0,100,2,0,8000,12000,14000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackhand Summoner - Out of Combat - Play Emote 1 (No Repeat) (Normal Dungeon)");

-- Shadowy Initiate SAI
SET @ENTRY := 18716;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,7759,0,0,0,11,47068,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowy Initiate - On Gossip Option 0 Selected - Cast 'Who Are They: Shadowy Initiate Kill Credit' (Phase 1) (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowy Initiate - In Combat CMC - Cast 'Shadow Bolt'");

-- Shadowy Advisor SAI
SET @ENTRY := 18719;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,7760,0,0,0,11,47070,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowy Advisor - On Gossip Option 0 Selected - Cast 'Who Are They: Shadowy Advisor Kill Credit' (Phase 1) (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowy Advisor - In Combat CMC - Cast 'Shadow Bolt'");

-- Surge Needle Sorcerer SAI
SET @ENTRY := 26257;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,51797,64,0,0,0,0,2,0,0,0,0,0,0,0,"Surge Needle Sorcerer - In Combat CMC - Cast 'Arcane Blast'");
