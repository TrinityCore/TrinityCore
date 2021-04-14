-- 
-- DB/SAI: Update Blasted Lands
-- Akubar the Seer SAI
SET @ENTRY := 8298;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79884,64,0,0,0,0,2,0,0,0,0,0,0,0,"Akubar the Seer - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - Out of Combat - Cast 'Water Shield'"),
(@ENTRY,0,2,0,16,0,100,0,79892,1,15000,30000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - On Friendly Unit Missing Buff 'Water Shield' - Cast 'Water Shield'"),
(@ENTRY,0,3,0,9,0,100,0,0,8,14000,14500,11,79890,0,0,0,0,0,2,0,0,0,0,0,0,0,"Akubar the Seer - Within 0-8 Range - Cast 'Flame Shock'"),
(@ENTRY,0,4,0,0,0,100,0,5000,7000,19000,22000,11,39591,1,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - In Combat - Cast 'Searing Totem'"),
(@ENTRY,0,5,0,0,0,100,0,12000,15000,25000,31000,11,79886,1,0,0,0,0,2,0,0,0,0,0,0,0,"Akubar the Seer - In Combat - Cast 'Lava Burst'");
-- Ashmane Boar SAI
SET @ENTRY := 5992;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,0,0,0,0,0,11,11351,33,0,0,0,0,1,0,0,0,0,0,0,0,"Ashmane Boar - On Reset - Cast 'Fire Shield'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,12898,33,0,0,0,0,1,0,0,0,0,0,0,0,"Ashmane Boar - On Reset - Cast 'Smoke Aura Visual'"),
(@ENTRY,0,2,0,9,0,50,1,5,20,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashmane Boar - Within 5-20 Range - Cast 'Rushing Charge' (No Repeat)");
-- Blackleaf SAI
SET @ENTRY := 45260;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,13000,11,36247,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackleaf - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,25000,11,84469,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackleaf - In Combat - Cast 'Fel Immolate'");
-- Bloodwash Acolyte SAI
SET @ENTRY := 41423;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwash Acolyte - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Acolyte - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,15000,17000,11,84465,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwash Acolyte - In Combat - Cast 'Frost Arrow'"),
(@ENTRY,0,3,0,2,0,100,1,0,25,0,0,11,84454,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Acolyte - Between 0-25% Health - Cast 'Bloodwash' (No Repeat)");
-- Bloodwash Barbarian SAI
SET @ENTRY := 41386;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Barbarian - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,25,0,0,11,84454,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Barbarian - Between 0-25% Health - Cast 'Bloodwash' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,5000,15000,20000,11,83639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwash Barbarian - In Combat - Cast 'Bloodbath'");
-- Bloodwash Enchantress SAI
SET @ENTRY := 41387;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,31281,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwash Enchantress - In Combat - Cast 'Bloodbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Enchantress - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,25,0,0,11,84454,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Enchantress - Between 0-25% Health - Cast 'Bloodwash' (No Repeat)");
-- Bloodwash Gambler SAI
SET @ENTRY := 41404;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Gambler - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,25,0,0,11,84454,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Gambler - Between 0-25% Health - Cast 'Bloodwash' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4500,6000,17500,19500,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwash Gambler - In Combat - Cast 'Rend'"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,84309,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwash Gambler - On Aggro - Cast 'Coin Toss' (No Repeat)");
-- Bloodwash Idolater SAI
SET @ENTRY := 41405;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32011,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwash Idolater - In Combat - Cast 'Water Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Idolater - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,25,0,0,11,84454,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Idolater - Between 0-25% Health - Cast 'Bloodwash' (No Repeat)"),
(@ENTRY,0,3,0,9,0,100,0,0,10,14000,18000,11,78799,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwash Idolater - Within 0-10 Range - Cast 'Wave Crash'");
-- Bloodwash Zealot SAI
SET @ENTRY := 41422;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Zealot - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Zealot - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwash Zealot - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,25,0,0,11,84454,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwash Zealot - Between 0-25% Health - Cast 'Bloodwash' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 41422;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Bonepicker Felfeeder SAI
SET @ENTRY := 5983;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,37945,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonepicker Felfeeder - In Combat - Cast 'Fel Fireball'");
-- Captain Metlek SAI
SET @ENTRY := 42231;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,81173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Metlek - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Metlek - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Metlek - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,2000,4500,12000,12500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Metlek - In Combat - Cast 'Cleave'"),
(@ENTRY,0,4,0,0,0,100,0,6000,9000,17000,22000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Metlek - In Combat - Cast 'Mortal Strike'");
-- NPC talk text insert
SET @ENTRY := 42231;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Cassia the Slitherqueen SAI
SET @ENTRY := 45258;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cassia the Slitherqueen - In Combat - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cassia the Slitherqueen - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,17000,21000,11,17170,1,0,0,0,0,2,0,0,0,0,0,0,0,"Cassia the Slitherqueen - In Combat - Cast 'Fatal Sting'"),
(@ENTRY,0,3,0,2,0,100,0,0,40,45000,55000,11,11835,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cassia the Slitherqueen - Between 0-40% Health - Cast 'Power Word: Shield'");
-- Chief Prospector Hondo SAI
SET @ENTRY := 41173;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Prospector Hondo - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Prospector Hondo - On Aggro - Cast 'Throw' (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,17000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Prospector Hondo - Within 0-5 Range - Cast 'Pierce Armor'"),
(@ENTRY,0,3,0,0,0,100,0,5000,7000,22000,26000,11,80382,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Prospector Hondo - In Combat - Cast 'Dirt Toss'"),
(@ENTRY,0,4,0,0,0,100,0,12000,13000,9000,18000,11,79726,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Prospector Hondo - In Combat - Cast 'Ticking Time Bomb'");
-- NPC talk text insert
SET @ENTRY := 41173;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Is that box walking on its own? Am I going mad? Quick,someone check the canary!',12,0,100,0,0,0, 'on Aggro Text',41195);
-- Clack the Reaver SAI
SET @ENTRY := 8301;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,11000,12000,11,21067,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clack the Reaver - In Combat - Cast 'Poison Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,22000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clack the Reaver - In Combat - Cast 'Venom Splash'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,15000,16000,11,79840,1,0,0,0,0,1,0,0,0,0,0,0,0,"Clack the Reaver - Between 0-40% Health - Cast 'Harden'");
-- Corrupted Darkwood Treant SAI
SET @ENTRY := 45119;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,13000,11,36247,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Darkwood Treant - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,25000,11,84469,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Darkwood Treant - In Combat - Cast 'Fel Immolate'");
-- Darktail Bonepicker SAI
SET @ENTRY := 42235;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darktail Bonepicker - On Aggro - Cast 'Sprint' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,22000,25000,11,8139,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darktail Bonepicker - In Combat - Cast 'Fevered Fatigue'");
-- Darkwood Treant SAI
SET @ENTRY := 45118;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,9000,14000,11,33844,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkwood Treant - Within 0-30 Range - Cast 'Entangling Roots'");
-- Deatheye SAI
SET @ENTRY := 8302;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,83657,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deatheye - In Combat - Cast 'Hellgaze'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,24000,27000,11,77576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deatheye - In Combat - Cast 'Stone Breath'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,9000,9000,11,54663,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deatheye - Between 0-40% Health - Cast 'Fatal Bite'");
-- Doomguard Destroyer SAI
SET @ENTRY := 41470;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,38742,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doomguard Destroyer - In Combat - Cast 'Fel Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,18000,22000,11,84451,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doomguard Destroyer - In Combat - Cast 'Wing Buffet'"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,15000,16000,11,84502,1,0,0,0,0,5,0,0,0,0,0,0,0,"Doomguard Destroyer - In Combat - Cast 'Rain of Chaos'");
-- Dreadlord Defiler SAI
SET @ENTRY := 41471;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,13000,11,13860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadlord Defiler - In Combat - Cast 'Mind Blast'"),
(@ENTRY,0,1,0,0,0,100,0,6000,11000,19000,24000,11,37624,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadlord Defiler - In Combat - Cast 'Carrion Swarm'");
-- Dreadmaul Ambusher SAI
SET @ENTRY := 41136;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ambusher - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,17000,18000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ambusher - Within 0-5 Range - Cast 'Uppercut'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,20000,22000,11,81140,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ambusher - In Combat - Cast 'Thunderclap'"),
(@ENTRY,0,3,0,0,0,100,0,2000,5000,35000,41000,11,11960,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ambusher - In Combat - Cast 'Curse of the Dreadmaul'"),
(@ENTRY,0,4,0,0,0,100,0,9000,14000,25000,28000,11,84333,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ambusher - In Combat - Cast 'Summon Dreadmaul'");
-- NPC talk text insert
SET @ENTRY := 41136;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Dreadmaul Brute SAI
SET @ENTRY := 5976;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Brute - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,8,25,19000,20000,11,83015,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Brute - Within 8-25 Range - Cast 'Heroic Leap'"),
(@ENTRY,0,2,0,0,0,100,0,2000,5000,35000,41000,11,11960,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Brute - In Combat - Cast 'Curse of the Dreadmaul'"),
(@ENTRY,0,3,0,0,0,100,0,9000,14000,25000,28000,11,84333,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Brute - In Combat - Cast 'Summon Dreadmaul'"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Brute - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,5,0,2,0,100,1,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Brute - Between 0-30% Health - Say Line 1 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 5976;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Dreadmaul Captive SAI
SET @ENTRY := 41127;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Captive - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 41127;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Dreadmaul Mauler SAI
SET @ENTRY := 5977;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Mauler - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,20000,22000,11,81140,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Mauler - In Combat - Cast 'Thunderclap'"),
(@ENTRY,0,2,0,0,0,100,0,2000,5000,35000,41000,11,11960,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Mauler - In Combat - Cast 'Curse of the Dreadmaul'"),
(@ENTRY,0,3,0,0,0,100,0,9000,14000,25000,28000,11,84333,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Mauler - In Combat - Cast 'Summon Dreadmaul'"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Mauler - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,5,0,2,0,100,1,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Mauler - Between 0-30% Health - Say Line 1 (No Repeat)"),
(@ENTRY,0,6,0,9,0,100,0,0,5,17000,18000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Mauler - Within 0-5 Range - Cast 'Uppercut'");
-- NPC talk text insert
SET @ENTRY := 5977;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927),
(@ENTRY,1,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Dreadmaul Ogre SAI
SET @ENTRY := 5974;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ogre - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,35000,41000,11,11960,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ogre - In Combat - Cast 'Curse of the Dreadmaul'"),
(@ENTRY,0,2,0,0,0,100,0,9000,14000,25000,28000,11,84333,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ogre - In Combat - Cast 'Summon Dreadmaul'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre - Between 0-30% Health - Say Line 1 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 5974;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927),
(@ENTRY,1,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Dreadmaul Ogre Mage SAI
SET @ENTRY := 5975;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79858,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,79850,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - Within 0-8 Range - Cast 'Frost Nova'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,15000,16000,11,79859,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - In Combat - Cast 'Ice Lance'"),
(@ENTRY,0,3,0,0,0,100,0,9000,14000,25000,28000,11,84333,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - In Combat - Cast 'Summon Dreadmaul'"),
(@ENTRY,0,4,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 5975;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Dreadmaul Warlock SAI
SET @ENTRY := 5978;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79938,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Warlock - In Combat - Cast 'Incinerate'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,44977,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Warlock - Out of Combat - Cast 'Fel Armor'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,17000,17500,11,79937,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Warlock - In Combat - Cast 'Immolate'"),
(@ENTRY,0,3,0,0,0,100,0,9000,14000,25000,28000,11,84333,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Warlock - In Combat - Cast 'Summon Dreadmaul'"),
(@ENTRY,0,4,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Warlock - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 5978;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);
-- Dreadscorn SAI
SET @ENTRY := 8304;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadscorn - In Combat - Cast 'Strike'"),
(@ENTRY,0,1,0,0,0,100,0,6000,10000,18000,26000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadscorn - In Combat - Cast 'Backhand'"),
(@ENTRY,0,2,0,2,0,100,1,0,25,0,0,11,21049,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadscorn - Between 0-25% Health - Cast 'Bloodlust' (No Repeat)");
-- Drowned Gilnean Merchant SAI
SET @ENTRY := 42244;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,84309,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drowned Gilnean Merchant - On Aggro - Cast 'Coin Toss' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4500,14000,15500,11,84306,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drowned Gilnean Merchant - In Combat - Cast 'Soaking'");
-- Drowned Gilnean Sailor SAI
SET @ENTRY := 42248;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drowned Gilnean Sailor - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4500,14000,15500,11,84306,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drowned Gilnean Sailor - In Combat - Cast 'Soaking'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,25000,29000,11,84308,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drowned Gilnean Sailor - In Combat - Cast 'Furious Howl'");
-- Drowned Gilnean Settler SAI
SET @ENTRY := 42249;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,11000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drowned Gilnean Settler - Within 0-5 Range - Cast 'Swipe'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4500,15000,15500,11,84306,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drowned Gilnean Settler - In Combat - Cast 'Soaking'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,25000,29000,11,84308,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drowned Gilnean Settler - In Combat - Cast 'Furious Howl'");
-- Enthralled Cultist SAI
SET @ENTRY := 41254;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,84325,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enthralled Cultist - Between 0-30% Health - Cast 'Fel-Infused' (No Repeat)");
-- Felguard Sentry SAI
SET @ENTRY := 6011;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felguard Sentry - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,3500,12000,13500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felguard Sentry - In Combat - Cast 'Cleave'");
-- Felhound SAI
SET @ENTRY := 6010;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,15000,17000,11,81082,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felhound - In Combat - Cast 'Noxious Breath'"),
(@ENTRY,0,1,0,2,0,100,0,0,55,14000,21000,11,79616,1,0,0,0,0,2,0,0,0,0,0,0,0,"Felhound - Between 0-55% Health - Cast 'Drain Life'");
-- Felscale Crawler SAI
SET @ENTRY := 45087;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,14000,11,84466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felscale Crawler - In Combat - Cast 'Felbreath'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,15000,16000,11,79840,1,0,0,0,0,1,0,0,0,0,0,0,0,"Felscale Crawler - Between 0-40% Health - Cast 'Harden'");
-- Felspore Bog Lord SAI
SET @ENTRY := 45125;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,17000,25000,11,79825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felspore Bog Lord - In Combat - Cast 'Summon Unstable Mushroom'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,18000,18000,11,84472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felspore Bog Lord - Between 0-40% Health - Cast 'Rejuvenation'");
-- Gomegaz SAI
SET @ENTRY := 41166;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gomegaz - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gomegaz - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,14000,17000,11,84426,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gomegaz - In Combat - Cast 'Felbreath'");
-- NPC talk text insert
SET @ENTRY := 41166;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Grunter SAI
SET @ENTRY := 8303;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grunter - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grunter - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,12000,13000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grunter - In Combat - Cast 'Tendon Rip'"),
(@ENTRY,0,3,0,0,0,100,0,2000,9000,9000,25000,11,79581,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grunter - In Combat - Cast 'Angry Snort'"),
(@ENTRY,0,4,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grunter - On Aggro - Cast 'Rushing Charge' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 8303;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Illycor SAI
SET @ENTRY := 41163;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,14000,22000,11,84257,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illycor - In Combat - Cast 'The Reckoning: Cancel Phase and Teleport'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,18000,27000,11,84298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illycor - In Combat - Cast 'Optic Link'");
-- Jarroc Torn-Wing SAI
SET @ENTRY := 41164;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,13000,11,36247,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jarroc Torn-Wing - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,25000,11,84469,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jarroc Torn-Wing - In Combat - Cast 'Fel Immolate'"),
(@ENTRY,0,2,0,0,0,100,0,7000,14000,21000,32000,11,84451,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jarroc Torn-Wing - In Combat - Cast 'Wing Buffet'");
-- Magronos the Unyielding SAI
SET @ENTRY := 8297;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magronos the Unyielding - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magronos the Unyielding - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,17000,18000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magronos the Unyielding - Within 0-5 Range - Cast 'Uppercut'"),
(@ENTRY,0,3,0,0,0,100,0,6000,14000,19000,22500,11,22859,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magronos the Unyielding - In Combat - Cast 'Mortal Cleave'"),
(@ENTRY,0,4,0,0,0,100,0,14000,18000,35000,36000,11,78827,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magronos the Unyielding - In Combat - Cast 'Bladestorm'");
-- NPC talk text insert
SET @ENTRY := 8297;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Marl Wormthorn SAI
SET @ENTRY := 42334;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Marl Wormthorn - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79833,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marl Wormthorn - Out of Combat - Cast 'Mark of the Wild'"),
(@ENTRY,0,2,0,0,0,100,0,7000,9000,14000,20000,11,33844,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marl Wormthorn - In Combat - Cast 'Entangling Roots'"),
(@ENTRY,0,3,0,2,0,100,0,0,40,19000,27000,11,12160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marl Wormthorn - Between 0-40% Health - Cast 'Rejuvenation'");
-- Mojo the Twisted SAI
SET @ENTRY := 8296;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20298,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mojo the Twisted - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79954,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mojo the Twisted - Out of Combat - Cast 'Fel Armor'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,31976,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mojo the Twisted - Between 0-30% Health - Cast 'Shadow Shield' (No Repeat)");
-- Mordak Nightbender SAI
SET @ENTRY := 45257;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77722,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mordak Nightbender - In Combat - Cast 'Void Whip'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79934,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordak Nightbender - Out of Combat - Cast 'Demon Armor'"),
(@ENTRY,0,2,0,0,0,100,0,8000,12000,19000,26000,11,79930,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mordak Nightbender - In Combat - Cast 'Corruption'"),
(@ENTRY,0,3,0,2,0,100,0,0,40,14000,21000,11,84533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mordak Nightbender - Between 0-40% Health - Cast 'Drain Life'");
-- Narixxus the Doombringer SAI
SET @ENTRY := 45262;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,13600,14500,11,36255,0,0,0,0,0,1,0,0,0,0,0,0,0,"Narixxus the Doombringer - Within 0-8 Range - Cast 'Chaos Nova'");
-- Nethergarde Defender SAI
SET @ENTRY := 51792;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Defender - On Aggro - Cast 'Shoot' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,13500,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Defender - Within 0-5 Range - Cast 'Heroic Strike'"),
(@ENTRY,0,2,0,13,0,100,0,2000,4500,20000,30000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Defender - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'"),
(@ENTRY,0,3,0,2,0,100,0,0,40,9000,11000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Defender - Between 0-40% Health - Cast 'Improved Blocking'");
-- Nethergarde Defender SAI
SET @ENTRY := 41158;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Defender - On Aggro - Cast 'Shoot' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,13500,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Defender - Within 0-5 Range - Cast 'Heroic Strike'"),
(@ENTRY,0,2,0,13,0,100,0,2000,4500,20000,30000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Defender - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'"),
(@ENTRY,0,3,0,2,0,100,0,0,40,9000,11000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Defender - Between 0-40% Health - Cast 'Improved Blocking'");
-- Nethergarde Engineer SAI
SET @ENTRY := 5997;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Engineer - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,12000,15000,11,79721,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Engineer - In Combat - Cast 'Explosive Shot'"),
(@ENTRY,0,3,0,0,0,100,0,8000,12000,22000,26000,11,79726,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Engineer - In Combat - Cast 'Ticking Time Bomb'");
-- Nethergarde Footman SAI
SET @ENTRY := 45031;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,13500,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Footman - Within 0-5 Range - Cast 'Heroic Strike'"),
(@ENTRY,0,1,0,13,0,100,0,2000,4500,20000,30000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Footman - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,9000,11000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Footman - Between 0-40% Health - Cast 'Improved Blocking'");
-- Nethergarde Foreman SAI
SET @ENTRY := 5998;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,14000,15000,11,81140,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Foreman - Within 0-8 Range - Cast 'Thunderclap'"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,18000,24000,11,5115,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Foreman - In Combat - Cast 'Battle Command'");
-- Nethergarde Miner SAI
SET @ENTRY := 5996;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,38557,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Miner - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Miner - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,21000,26000,11,80382,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Miner - In Combat - Cast 'Dirt Toss'"),
(@ENTRY,0,3,0,9,0,100,0,0,5,12000,13000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Miner - Within 0-5 Range - Cast 'Pierce Armor'");
-- Oath-Chained Infernal SAI
SET @ENTRY := 41253;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,84392,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oath-Chained Infernal - On Aggro - Cast 'Fel Streak' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,17000,22000,11,12743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oath-Chained Infernal - In Combat - Cast 'Immolation'");
-- Okril'lon Defender SAI
SET @ENTRY := 51791;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Okril'lon Defender - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,12500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okril'lon Defender - In Combat - Cast 'Cleave'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,17000,22000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okril'lon Defender - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,28000,32000,11,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okril'lon Defender - In Combat - Cast 'Battle Shout'");
-- Okril'lon Defender SAI
SET @ENTRY := 41138;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Okril'lon Defender - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,12500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okril'lon Defender - In Combat - Cast 'Cleave'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,17000,22000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okril'lon Defender - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,28000,32000,11,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okril'lon Defender - In Combat - Cast 'Battle Shout'");
-- Okril'lon Infantry SAI
SET @ENTRY := 42359;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,12500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okril'lon Infantry - In Combat - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,17000,22000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okril'lon Infantry - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,28000,32000,11,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okril'lon Infantry - In Combat - Cast 'Battle Shout'");
-- Okril'lon Scout SAI
SET @ENTRY := 42228;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80149,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okril'lon Scout - On Aggro - Cast 'Throw Axe' (No Repeat)"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okril'lon Scout - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okril'lon Scout - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,0,0,40,14000,14500,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okril'lon Scout - Between 0-40% Health - Cast 'Shadowstep'");
-- Ravage SAI
SET @ENTRY := 8300;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,20,0,0,11,82797,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravage - Within 0-20 Range - Cast 'Leaping Bite' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4500,4500,18500,19200,11,7367,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravage - In Combat - Cast 'Infected Bite'"),
(@ENTRY,0,2,0,0,0,50,0,7000,8000,10000,25000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravage - In Combat - Cast 'Rend'"),
(@ENTRY,0,3,0,0,0,80,0,5000,9000,18000,21000,11,3149,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravage - In Combat - Cast 'Furious Howl'");
-- Razelikh the Defiler SAI
SET @ENTRY := 41280;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razelikh the Defiler - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razelikh the Defiler - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,60,0,0,11,77374,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razelikh the Defiler - Between 0-60% Health - Cast 'Summon Minion' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,2000,4500,12000,14000,11,8255,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razelikh the Defiler - In Combat - Cast 'Strong Cleave'"),
(@ENTRY,0,4,0,0,0,100,0,8000,11000,24000,28000,11,13459,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razelikh the Defiler - In Combat - Cast 'Decimate'");
-- NPC talk text insert
SET @ENTRY := 41280;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Reassuring Nethergarde Foreman SAI
SET @ENTRY := 41171;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,13600,14500,11,81140,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reassuring Nethergarde Foreman - Within 0-8 Range - Cast 'Thunderclap'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,15000,11,5115,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reassuring Nethergarde Foreman - In Combat - Cast 'Battle Command'");
-- Redstone Basilisk SAI
SET @ENTRY := 5990;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,14000,16000,11,83657,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redstone Basilisk - In Combat - Cast 'Hellgaze'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,22000,24000,11,77576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redstone Basilisk - In Combat - Cast 'Stone Breath'");
-- Rofilian Dane SAI
SET @ENTRY := 41133;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rofilian Dane - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rofilian Dane - On Evade - Cast 'Stealth' (No Repeat)");
-- Shadowsworn Adept SAI
SET @ENTRY := 6006;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77721,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Adept - In Combat - Cast 'Shadow Weave'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,75073,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Adept - Within 0-8 Range - Cast 'Shadow Nova'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,77471,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Adept - Between 0-30% Health - Cast 'Shadow Shield' (No Repeat)");
-- Shadowsworn Dreadweaver SAI
SET @ENTRY := 6009;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77722,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - In Combat - Cast 'Void Whip'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,22000,11,79930,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - In Combat - Cast 'Corruption'"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79930,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - Out of Combat - Cast 'Corruption'");
-- Shadowsworn Enforcer SAI
SET @ENTRY := 6007;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,14000,16000,11,35373,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Enforcer - Within 0-8 Range - Cast 'Shadowfury'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,13000,11,32916,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Enforcer - In Combat - Cast 'Shadow Cleave'");
-- Shadowsworn Obstructor SAI
SET @ENTRY := 41191;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,18000,19000,11,77129,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Obstructor - In Combat - Cast 'Disrupt Ritual'");
-- Shadowsworn Occultist SAI
SET @ENTRY := 42297;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,84325,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Occultist - Between 0-30% Health - Cast 'Fel-Infused' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,20000,25000,11,78904,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Occultist - In Combat - Cast 'Scorched Earth'");
-- Shadowsworn Ritualist SAI
SET @ENTRY := 6004;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,84325,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Ritualist - Between 0-30% Health - Cast 'Fel-Infused' (No Repeat)");
-- Shadowsworn Spellblade SAI
SET @ENTRY := 42296;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,84325,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Spellblade - Between 0-30% Health - Cast 'Fel-Infused' (No Repeat)"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,82635,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Spellblade - On Aggro - Cast 'Flaming Leap' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,20000,25000,11,78904,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Spellblade - In Combat - Cast 'Scorched Earth'"),
(@ENTRY,0,3,0,0,0,100,0,8000,11000,28000,33000,11,17277,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Spellblade - In Combat - Cast 'Blast Wave'");
-- Shadowsworn Thug SAI
SET @ENTRY := 6005;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,18000,22000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Thug - Within 0-5 Range - Cast 'Uppercut'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,15000,15500,11,3148,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Thug - In Combat - Cast 'Head Crack'");
-- Shadowsworn Warlock SAI
SET @ENTRY := 6008;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79939,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Warlock - In Combat - Cast 'Chaos Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,22000,27000,11,79955,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowsworn Warlock - In Combat - Cast 'Rain of Fire'");
-- Shahandana SAI
SET @ENTRY := 41165;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,13000,11,36040,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shahandana - In Combat - Cast 'Fel Flamestrike'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,22000,11,37629,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shahandana - In Combat - Cast 'Melt Flesh'"),
(@ENTRY,0,2,0,0,0,100,0,8000,14000,33000,36000,11,34017,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shahandana - In Combat - Cast 'Rain of Chaos'");
-- Snickerfang Hyena SAI
SET @ENTRY := 5985;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,20,0,0,11,82797,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snickerfang Hyena - Within 0-20 Range - Cast 'Leaping Bite' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4500,4500,18500,19200,11,7367,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snickerfang Hyena - In Combat - Cast 'Infected Bite'"),
(@ENTRY,0,2,0,0,0,50,0,7000,8000,10000,25000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snickerfang Hyena - In Combat - Cast 'Rend'"),
(@ENTRY,0,3,0,0,0,80,0,5000,9000,18000,21000,11,3149,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snickerfang Hyena - In Combat - Cast 'Furious Howl'");
-- Spirit of Grol SAI
SET @ENTRY := 41267;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,18000,22000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spirit of Grol - Within 0-5 Range - Cast 'Uppercut'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,25000,25000,11,16555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spirit of Grol - In Combat - Cast 'Drowning Death'"),
(@ENTRY,0,2,0,2,0,100,0,0,35,8000,11000,11,84310,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Grol - Between 0-35% Health - Cast 'Bloodlust'");
-- Spiteflayer SAI
SET @ENTRY := 8299;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spiteflayer - On Aggro - Cast 'Sprint' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,14000,11,37945,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spiteflayer - In Combat - Cast 'Fel Fireball'");
-- Surwich Warden SAI
SET @ENTRY := 51542;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Surwich Warden - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,11000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Surwich Warden - Within 0-5 Range - Cast 'Cleave'");
-- Tainted Black Bear SAI
SET @ENTRY := 42336;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tainted Black Bear - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3500,4500,60000,65000,11,84497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tainted Black Bear - In Combat - Cast 'Feltaint'");
-- Tainted Nightstalker SAI
SET @ENTRY := 42337;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,60000,65000,11,84497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tainted Nightstalker - In Combat - Cast 'Feltaint'");
-- Tainted Screecher SAI
SET @ENTRY := 42338;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,60000,65000,11,84497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tainted Screecher - In Combat - Cast 'Feltaint'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,9000,9000,11,54663,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tainted Screecher - Between 0-40% Health - Cast 'Fatal Bite'");
-- Tak'arili SAI
SET @ENTRY := 41134;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tak'arili - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tak'arili - On Evade - Cast 'Stealth' (No Repeat)");
-- Teremus the Devourer SAI
SET @ENTRY := 7846;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,13600,14500,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Teremus the Devourer - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,19000,24000,11,9573,0,0,0,0,0,2,0,0,0,0,0,0,0,"Teremus the Devourer - In Combat - Cast 'Flame Breath'"),
(@ENTRY,0,2,0,0,0,100,0,4000,5000,15000,15500,11,11130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Teremus the Devourer - In Combat - Cast 'Knock Away'"),
(@ENTRY,0,3,0,2,0,100,0,0,60,26000,29000,11,12667,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teremus the Devourer - Between 0-60% Health - Cast 'Soul Consumption'");
