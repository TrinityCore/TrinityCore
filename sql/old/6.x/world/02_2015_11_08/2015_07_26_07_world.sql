-- 
-- DB/SAI: Southern Barrens
-- Alliance Field Defender SAI
SET @ENTRY := 39040;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,11000,12500,11,70316,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Field Defender - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,15000,19000,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Field Defender - In Combat - Cast 'Heroic Strike'");
-- Awkward Gangly Orc SAI
SET @ENTRY := 38033;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Awkward Gangly Orc - In Combat - Cast 'Backhand'"),
(@ENTRY,0,1,0,13,0,100,0,2000,4500,20000,30000,11,11978,0,0,0,0,0,7,0,0,0,0,0,0,0,"Awkward Gangly Orc - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Kick'");
-- Azzere the Skyblade SAI
SET @ENTRY := 5834;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,13375,64,0,0,0,0,2,0,0,0,0,0,0,0,"Azzere the Skyblade - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,18000,22000,11,6725,1,0,0,0,0,2,0,0,0,0,0,0,0,"Azzere the Skyblade - In Combat - Cast 'Flame Spike'");
-- Bael'dun Excavator SAI
SET @ENTRY := 3374;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'dun Excavator - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,22000,26000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'dun Excavator - In Combat - Cast 'Sunder Armor'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Excavator - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Bael'dun Foreman SAI
SET @ENTRY := 3375;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Foreman - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,21000,24000,11,6257,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'dun Foreman - In Combat - Cast 'Torch Toss'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Foreman - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Bael'dun Soldier SAI
SET @ENTRY := 3376;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'dun Soldier - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,18000,22000,11,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Soldier - In Combat - Cast 'Battle Shout'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Soldier - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,2000,3000,12000,13000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'dun Soldier - In Combat - Cast 'Cleave'");
-- Barrens Brave SAI
SET @ENTRY := 38290;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Barrens Brave - In Combat - Cast 'Shoot'");
-- Barrens Operative SAI
SET @ENTRY := 37924;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barrens Operative - On Respawn - Cast 'Sneak' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barrens Operative - On Evade - Cast 'Sneak' (No Repeat)"),
(@ENTRY,0,2,0,67,0,100,0,9000,12000,0,0,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Barrens Operative - On Behind Target - Cast 'Backstab'"),
(@ENTRY,0,3,0,2,0,100,0,0,40,18000,22000,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Barrens Operative - Between 0-40% Health - Cast 'Shadowstep'"),
(@ENTRY,0,4,0,9,0,100,0,0,5,24000,26000,11,14902,0,0,0,0,0,2,0,0,0,0,0,0,0,"Barrens Operative - Within 0-5 Range - Cast 'Cheap Shot'");
-- Bramblescar Growth SAI
SET @ENTRY := 37212;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bramblescar Growth - On Aggro - Disable Combat Movement (No Repeat)");
-- Bristleback Assault Boar SAI
SET @ENTRY := 37536;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,44531,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Assault Boar - On Aggro - Cast 'Dash' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Assault Boar - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Bristleback Bladewarden SAI
SET @ENTRY := 37511;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,82610,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Bladewarden - In Combat - Cast 'Quilboar Rush'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Bladewarden - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Bristleback Onlooker SAI
SET @ENTRY := 37529;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Onlooker - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Bristleback Thornweaver SAI
SET @ENTRY := 3261;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Thornweaver - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Thornweaver - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,20,9000,12000,11,12747,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Thornweaver - Within 0-20 Range - Cast 'Entangling Roots'");
-- Captain Gerogg Hammertoe SAI
SET @ENTRY := 5851;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,13000,11,76622,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Gerogg Hammertoe - Within 0-5 Range - Cast 'Sunder Armor'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,14000,16000,11,3419,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Gerogg Hammertoe - Between 0-50% Health - Cast 'Improved Blocking'"),
(@ENTRY,0,2,0,0,0,100,0,2000,4500,18000,22000,11,78660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Gerogg Hammertoe - In Combat - Cast 'Devastate'");
-- Captain Peake SAI
SET @ENTRY := 37157;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Peake - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,32000,35000,11,32971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Peake - In Combat - Cast 'Deadly Poison'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,20000,22000,11,42972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Peake - In Combat - Cast 'Blind'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Peake - Between 0-15% Health - Flee For Assist (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 37157;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Guards!I expect this $r to be clapped into chains!',12,0,100,0,0,0, 'on Aggro Text',36947);
-- Desolation Grunt SAI
SET @ENTRY := 37706;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desolation Grunt - On Aggro - Cast 'Battle Shout' (No Repeat)");
-- Desolation Guard SAI
SET @ENTRY := 38070;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Desolation Guard - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,0,5,9000,12000,11,40505,1,0,0,0,0,2,0,0,0,0,0,0,0,"Desolation Guard - Within 0-5 Range - Cast 'Cleave'");
-- Desolation Raider SAI
SET @ENTRY := 37922;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,14500,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Desolation Raider - Within 0-5 Range - Cast 'Sunder Armor'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,82836,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desolation Raider - Between 0-30% Health - Cast 'Blood Fury' (No Repeat)");
-- Deviate Crone SAI
SET @ENTRY := 38940;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Crone - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deviate Crone - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,20,9000,12000,11,12747,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Crone - Within 0-20 Range - Cast 'Entangling Roots'"),
(@ENTRY,0,3,0,2,0,100,0,0,40,14000,21000,11,72922,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deviate Crone - Between 0-40% Health - Cast 'Regrowth'");
-- Deviate Plainstrider SAI
SET @ENTRY := 37091;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,80807,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deviate Plainstrider - On Respawn - Cast 'Sand Blast' (No Repeat)");
-- Deviate Terrortooth SAI
SET @ENTRY := 37090;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deviate Terrortooth - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,15000,21000,11,80608,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deviate Terrortooth - In Combat - Cast 'Summon Pebble'");
-- Deviate Thornweaver SAI
SET @ENTRY := 38884;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Thornweaver - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deviate Thornweaver - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,20,9000,12000,11,12747,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Thornweaver - Within 0-20 Range - Cast 'Entangling Roots'");
-- Disturbed Earth Elemental SAI
SET @ENTRY := 37553;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,15000,18000,11,82841,0,0,0,0,0,2,0,0,0,0,0,0,0,"Disturbed Earth Elemental - In Combat - Cast 'Rock Bash'"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,82839,0,0,0,0,0,1,0,0,0,0,0,0,0,"Disturbed Earth Elemental - On Respawn - Cast 'Hardened' (No Repeat)"),
(@ENTRY,0,2,0,16,0,100,0,82839,1,12000,13000,11,82839,0,0,0,0,0,1,0,0,0,0,0,0,0,"Disturbed Earth Elemental - On Friendly Unit Missing Buff 'Hardened' - Cast 'Hardened'");
-- Dusthoof Giraffe SAI
SET @ENTRY := 37082;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,16000,19000,11,82829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dusthoof Giraffe - In Combat - Cast 'Choking Dust'");
-- Elder Zhevra SAI
SET @ENTRY := 37088;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,19000,22000,11,32023,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Zhevra - In Combat - Cast 'Hoof Stomp'");
-- Escaped Stonetalon Prisoner SAI
SET @ENTRY := 37171;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Escaped Stonetalon Prisoner - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Escaped Stonetalon Prisoner - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 37171;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Excavation Raider SAI
SET @ENTRY := 39153;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Excavation Raider - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,120000,125000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Excavation Raider - In Combat - Cast 'Battle Shout'");
-- Feegly the Exiled SAI
SET @ENTRY := 39174;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,25000,30000,11,7020,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - In Combat - Cast 'Stoneform'"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 39174;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Fenton Frazzlecraz SAI
SET @ENTRY := 39281;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,18000,21000,11,37591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fenton Frazzlecraz - In Combat - Cast 'Drunken Haze'");
-- Ferocious Jungle Vine SAI
SET @ENTRY := 38912;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ferocious Jungle Vine - On Aggro - Disable Combat Movement (No Repeat)");
-- Frazzlecraz Foreman SAI
SET @ENTRY := 39279;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frazzlecraz Foreman - On Aggro - Cast 'Commanding Shout' (No Repeat)"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frazzlecraz Foreman - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frazzlecraz Foreman - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 39279;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Frazzlecraz Miner SAI
SET @ENTRY := 39280;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frazzlecraz Miner - In Combat - Cast 'Throw Dynamite'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frazzlecraz Miner - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,12000,12500,11,58461,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frazzlecraz Miner - Within 0-5 Range - Cast 'Sunder Armor'");
-- Geopriest Gukk'rok SAI
SET @ENTRY := 5863;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,18000,25000,11,75068,0,0,0,0,0,2,0,0,0,0,0,0,0,"Geopriest Gukk'rok - In Combat - Cast 'Lava Burst'"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,15000,15500,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,"Geopriest Gukk'rok - In Combat - Cast 'Earth Spike'"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79927,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geopriest Gukk'rok - Out of Combat - Cast 'Earth Shield'"),
(@ENTRY,0,3,0,16,0,100,0,79927,1,15000,30000,11,79927,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geopriest Gukk'rok - On Friendly Unit Missing Buff 'Earth Shield' - Cast 'Earth Shield'");
-- Grasping Overgrowth SAI
SET @ENTRY := 37548;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grasping Overgrowth - On Aggro - Disable Combat Movement (No Repeat)");
-- Gray's Abomination SAI
SET @ENTRY := 38333;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,40,14000,17000,11,59395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gray's Abomination - Within 8-40 Range - Cast 'Abomination Hook'");
-- Hagg Taurenbane SAI
SET @ENTRY := 5859;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hagg Taurenbane - On Aggro - Cast 'Battle Stance' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,12000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hagg Taurenbane - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,25000,30000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hagg Taurenbane - Within 0-8 Range - Cast 'Demoralizing Shout'"),
(@ENTRY,0,3,0,0,0,100,0,2000,4500,12000,20000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hagg Taurenbane - In Combat - Cast 'Hamstring'");
-- Hecklefang Scavenger SAI
SET @ENTRY := 37086;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,15000,16500,11,80797,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hecklefang Scavenger - In Combat - Cast 'Generic Quest Invisibility 5'");
-- Henry Zykes SAI
SET @ENTRY := 37165;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,12000,13000,11,82801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Henry Zykes - In Combat - Cast 'Foreman's Pickaxe'");
-- Hexmaster Bastoon SAI
SET @ENTRY := 38826;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,26000,28000,11,12493,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hexmaster Bastoon - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,72975,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hexmaster Bastoon - Between 0-30% Health - Cast 'Shadow Barrier' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,2000,2500,16000,19000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hexmaster Bastoon - In Combat - Cast 'Shadow Word: Pain'"),
(@ENTRY,0,3,0,9,0,100,0,0,20,22000,27000,11,8988,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hexmaster Bastoon - Within 0-20 Range - Cast 'Silence'");
-- High Road Scout SAI
SET @ENTRY := 37159;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Road Scout - On Aggro - Cast 'Throw' (No Repeat)");
-- Honor's Stand Footman SAI
SET @ENTRY := 37161;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,0,4500,4500,20000,30000,11,82800,0,0,0,0,0,7,0,0,0,0,0,0,0,"Honor's Stand Footman - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,25000,30000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor's Stand Footman - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor's Stand Footman - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Honor's Stand Guard SAI
SET @ENTRY := 37180;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Honor's Stand Guard - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,12000,13000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor's Stand Guard - Between 0-50% Health - Cast 'Shield Block'"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,12000,15000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Honor's Stand Guard - In Combat - Cast 'Revenge'");
-- Honor's Stand Officer SAI
SET @ENTRY := 37216;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Honor's Stand Officer - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,120000,125000,11,80983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor's Stand Officer - In Combat - Cast 'Commanding Shout'");
-- Honor's Stand Peasant SAI
SET @ENTRY := 34855;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor's Stand Peasant - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Honor's Stand Sharpshooter SAI
SET @ENTRY := 34848;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor's Stand Sharpshooter - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Horde Field Defender SAI
SET @ENTRY := 37659;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,13000,11,70316,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Field Defender - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,16000,21000,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Field Defender - In Combat - Cast 'Heroic Strike'");
-- Hunter Hill Brave SAI
SET @ENTRY := 37204;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hunter Hill Brave - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,12000,11,40505,1,0,0,0,0,2,0,0,0,0,0,0,0,"Hunter Hill Brave - Within 0-5 Range - Cast 'Cleave'");
-- Hunter Hill Scout SAI
SET @ENTRY := 37170;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hunter Hill Scout - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,12000,15000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hunter Hill Scout - In Combat - Cast 'Cleave'");
-- Karga Rageroar SAI
SET @ENTRY := 38663;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,58743,0,0,0,0,0,2,0,0,0,0,0,0,0,"Karga Rageroar - On Aggro - Cast 'Intercept' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,13000,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,"Karga Rageroar - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,2,0,0,0,100,0,6000,8000,24000,25000,11,48696,0,0,0,0,0,2,0,0,0,0,0,0,0,"Karga Rageroar - In Combat - Cast 'Intimidating Roar'"),
(@ENTRY,0,3,0,0,0,100,0,3000,12000,19000,27000,11,12054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Karga Rageroar - In Combat - Cast 'Rend'");
-- Kolkar Marauder SAI
SET @ENTRY := 3275;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Marauder - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,12000,12500,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Marauder - In Combat - Cast 'Strike'"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,25000,29000,11,8014,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Marauder - In Combat - Cast 'Tetanus'");
-- Kona Thunderwalk SAI
SET @ENTRY := 38384;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,19030,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kona Thunderwalk - On Aggro - Cast 'Bear Form' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,9000,12000,11,12161,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kona Thunderwalk - In Combat - Cast 'Maul'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,25000,30000,11,15727,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kona Thunderwalk - In Combat - Cast 'Demoralizing Roar'");
-- Landquaker Bull SAI
SET @ENTRY := 37556;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,15000,17000,11,33840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Landquaker Bull - In Combat - Cast 'Earth Rumble'");
-- Landquaker Kodo SAI
SET @ENTRY := 37555;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,16000,19000,11,6266,0,0,0,0,0,1,0,0,0,0,0,0,0,"Landquaker Kodo - In Combat - Cast 'Kodo Stomp'");
-- Lashvine SAI
SET @ENTRY := 37093;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,69867,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lashvine - Between 0-30% Health - Cast 'Barrens Bloom' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4500,12000,14000,11,82803,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lashvine - In Combat - Cast 'Lashing Flurry'");
-- Malgin Barleybrew SAI
SET @ENTRY := 5848;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,12000,22000,11,74759,0,0,0,0,0,2,0,0,0,0,0,0,0,"Malgin Barleybrew - In Combat - Cast 'Bottle of Grog'"),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,3631,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malgin Barleybrew - Between 0-40% Health - Cast 'Battle Fury' (No Repeat)");
-- Mangletooth SAI
SET @ENTRY := 37940;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79884,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mangletooth - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mangletooth - Out of Combat - Cast 'Water Shield'"),
(@ENTRY,0,2,0,16,0,100,0,79892,1,15000,30000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mangletooth - On Friendly Unit Missing Buff 'Water Shield' - Cast 'Water Shield'"),
(@ENTRY,0,3,0,0,0,100,0,4000,4500,12000,13000,11,79890,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mangletooth - In Combat - Cast 'Flame Shock'"),
(@ENTRY,0,4,0,0,0,100,0,9000,12000,25000,28000,11,79886,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mangletooth - In Combat - Cast 'Lava Burst'"),
(@ENTRY,0,5,0,0,0,100,0,6000,8000,33000,37000,11,39591,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mangletooth - In Combat - Cast 'Searing Totem'");
-- Merciless Jungle Vine SAI
SET @ENTRY := 38942;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Merciless Jungle Vine - On Aggro - Disable Combat Movement (No Repeat)");
-- Nightmare Mass SAI
SET @ENTRY := 37753;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,12000,15000,11,82812,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightmare Mass - In Combat - Cast 'Insanity'");
-- Nightmare Stalker SAI
SET @ENTRY := 37736;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,19000,22000,11,82811,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Stalker - In Combat - Cast 'Corrupted Dreams'");
-- Northwatch Defender SAI
SET @ENTRY := 38624;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,22000,28000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Defender - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,1,0,2,0,100,0,0,60,18000,21000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Defender - Between 0-60% Health - Cast 'Shield Block'");
-- Northwatch Guard SAI
SET @ENTRY := 38636;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Guard - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,12000,13000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Guard - Between 0-50% Health - Cast 'Shield Block'"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,12000,15000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Guard - In Combat - Cast 'Revenge'");
-- Northwatch Recon SAI
SET @ENTRY := 37585;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,22000,28000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Recon - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,13000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Recon - Within 0-5 Range - Cast 'Heroic Strike'");
-- Northwatch Siege Engineer SAI
SET @ENTRY := 38327;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Siege Engineer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,3500,25000,32000,11,82830,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Siege Engineer - In Combat - Cast 'Crushing Bash'");
-- Oasis Snapjaw SAI
SET @ENTRY := 3461;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,7000,18000,26000,11,80604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oasis Snapjaw - In Combat - Cast 'Crushing Bite'"),
(@ENTRY,0,1,0,0,0,100,0,4000,9000,15000,22000,11,6530,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oasis Snapjaw - In Combat - Cast 'Sling Dirt'");
-- Ol' Durty Pete SAI
SET @ENTRY := 38875;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,73100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ol' Durty Pete - In Combat - Cast 'Shoot'");
-- Outgrowth SAI
SET @ENTRY := 37092;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,16000,25000,11,82810,0,0,0,0,0,2,0,0,0,0,0,0,0,"Outgrowth - In Combat - Cast 'Wild Spore'");
-- Plains Pridemane SAI
SET @ENTRY := 37207;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,44531,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plains Pridemane - On Aggro - Cast 'Dash' (No Repeat)");
-- Plains Prowler SAI
SET @ENTRY := 37206;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,15000,16000,11,24331,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plains Prowler - In Combat - Cast 'Rake'");
-- Rageroar Grunt SAI
SET @ENTRY := 38658;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,14500,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rageroar Grunt - Within 0-5 Range - Cast 'Sunder Armor'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,82836,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rageroar Grunt - Between 0-30% Health - Cast 'Blood Fury' (No Repeat)");
-- Rageroar Lieutenant SAI
SET @ENTRY := 38659;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rageroar Lieutenant - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rageroar Lieutenant - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rageroar Lieutenant - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 38659;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Razorfen Servitor SAI
SET @ENTRY := 6132;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorfen Servitor - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Razormane Pathfinder SAI
SET @ENTRY := 37560;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,74613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Pathfinder - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,5,30,22000,24000,11,82844,1,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Pathfinder - Within 5-30 Range - Cast 'Toxic Shot'"),
(@ENTRY,0,3,0,9,0,100,0,0,20,8000,9000,11,70218,1,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Pathfinder - Within 0-20 Range - Cast 'Boar Net'");
-- Razormane Seer SAI
SET @ENTRY := 37661;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,57780,64,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Seer - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Seer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,33907,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Seer - Out of Combat - Cast 'Thorns'"),
(@ENTRY,0,3,0,16,0,100,0,33907,1,15000,30000,11,33907,1,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Seer - On Friendly Unit Missing Buff 'Thorns' - Cast 'Thorns'");
-- Razormane Warfrenzy SAI
SET @ENTRY := 37660;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Warfrenzy - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,17000,22000,11,82610,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Warfrenzy - In Combat - Cast 'Quilboar Rush'");
-- Sabersnout SAI
SET @ENTRY := 37513;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sabersnout - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sabersnout - On Just Died - Say Line 1 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,12000,13000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sabersnout - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,3,0,0,0,100,0,6000,8000,15000,18000,11,82610,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sabersnout - In Combat - Cast 'Quilboar Rush'"),
(@ENTRY,0,4,0,0,0,100,0,9000,12000,26000,33000,11,70171,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sabersnout - In Combat - Cast 'Fear'"),
(@ENTRY,0,5,6,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sabersnout - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,6,0,61,0,100,1,0,30,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sabersnout - Between 0-30% Health - Say Line 2 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 37513;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You, <Snort> you are strong <Gurgle>. But... Strong enough for THE BOARPOCALYPSE?',14,0,100,0,0,0, 'on Aggro Text',37129),
(@ENTRY,1,0, 'You ... survive the boars? <Snort> So many boars! So sad! <Gurgle>',12,0,100,0,0,0, 'on Death Text',37130),
(@ENTRY,2,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Sapper Specialist SAI
SET @ENTRY := 37925;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sapper Specialist - In Combat - Cast 'Throw Dynamite'"),
(@ENTRY,0,1,0,2,0,100,1,0,10,0,0,11,82867,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sapper Specialist - Between 0-10% Health - Cast 'Sapper Charge' (No Repeat)");
-- Savannah Boar SAI
SET @ENTRY := 37559;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,44530,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savannah Boar - On Aggro - Cast 'Boar Charge' (No Repeat)");
-- Silithid Harvester SAI
SET @ENTRY := 3253;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,25000,32000,11,7278,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Harvester - In Combat - Cast 'Summon Harvester Swarm'");
-- Snort the Heckler SAI
SET @ENTRY := 5829;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,15000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snort the Heckler - In Combat - Cast 'Tendon Rip'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,22000,26000,11,7951,32,0,0,0,0,2,0,0,0,0,0,0,0,"Snort the Heckler - In Combat - Cast 'Toxic Spit'");
-- Stormsnout SAI
SET @ENTRY := 3240;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,12000,13000,11,15611,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormsnout - In Combat - Cast 'Lizard Bolt'");
-- Swinegart Spearhide SAI
SET @ENTRY := 5864;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,15000,17000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Swinegart Spearhide - In Combat - Cast 'Pierce Armor'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swinegart Spearhide - On Aggro - Cast 'Battle Stance' (No Repeat)");
-- Taurajo Looter SAI
SET @ENTRY := 37743;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,20,0,500,1000,600000,600000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Taurajo Looter - Out of Combat - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,13000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Taurajo Looter - In Combat - Cast 'Sinister Strike'"),
(@ENTRY,0,2,0,0,0,100,0,6000,8000,19000,23000,11,3583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Taurajo Looter - In Combat - Cast 'Deadly Poison'"),
(@ENTRY,0,3,0,2,0,100,0,0,30,14000,15000,11,6434,1,0,0,0,0,1,0,0,0,0,0,0,0,"Taurajo Looter - Between 0-30% Health - Cast 'Slice and Dice'");
-- NPC talk text insert
SET @ENTRY := 37743;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Grab anything you think we can fence.',12,0,50,1,0,0, 'say Text',37310),
(@ENTRY,0,1, 'There\'s got to be more. Double check the bodies!',12,0,50,1,0,0, 'say Text',37315),
(@ENTRY,0,2, 'Hey did anyone loot the mailbox yet?',12,0,50,1,0,0, 'say Text',37314),
(@ENTRY,0,3, 'Most of this stuff is beads and hides. Where\'s all the treasure?',12,0,50,1,0,0, 'say Text',37312),
(@ENTRY,0,4, 'Time is wasting. I want this place picked cleaned before they counter-attack',12,0,50,1,0,0, 'say Text',37313),
(@ENTRY,0,5, 'Has anyone seen the quilboar they had caged up over here?',12,0,50,1,0,0, 'say Text',37317),
(@ENTRY,0,6, 'Have we cleaned out the inn yet? Burn the rest of it when you\'re done!',12,0,50,1,0,0, 'say Text',37311),
(@ENTRY,0,7, 'Hurry it up. The soldiers have already pulled out of here',12,0,50,1,0,0, 'say Text',37309);
-- Terrortooth Runner SAI
SET @ENTRY := 37083;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terrortooth Runner - On Aggro - Cast 'Rushing Charge' (No Repeat)");
-- Terrortooth Scytheclaw SAI
SET @ENTRY := 37084;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,16000,20000,11,82796,0,0,0,0,0,2,0,0,0,0,0,0,0,"Terrortooth Scytheclaw - In Combat - Cast 'Scytheclaw'");
-- Three-Tooth SAI
SET @ENTRY := 38941;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Three-Tooth - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,9000,12000,11,12747,1,0,0,0,0,2,0,0,0,0,0,0,0,"Three-Tooth - Within 0-20 Range - Cast 'Entangling Roots'"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,35000,36000,11,73136,0,0,0,0,0,1,0,0,0,0,0,0,0,"Three-Tooth - In Combat - Cast 'Summon Vine with Ground Burst'");
-- Thunderhawk Cloudscraper SAI
SET @ENTRY := 37557;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3500,12000,13000,11,36594,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhawk Cloudscraper - In Combat - Cast 'Lightning Breath'");
-- Thunderhead SAI
SET @ENTRY := 37208;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,12000,13000,11,15611,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhead - In Combat - Cast 'Lizard Bolt'");
-- Tower Warden SAI
SET @ENTRY := 37160;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tower Warden - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,17000,22000,11,75964,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tower Warden - In Combat - Cast 'Beatdown'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tower Warden - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Towering Plainstrider SAI
SET @ENTRY := 37085;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,"Towering Plainstrider - On Aggro - Cast 'Sprint' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,15000,19000,11,81678,0,0,0,0,0,2,0,0,0,0,0,0,0,"Towering Plainstrider - In Combat - Cast 'Eye Peck'");
-- Triumph Sentry SAI
SET @ENTRY := 39136;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Triumph Sentry - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,12000,13000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Triumph Sentry - Between 0-50% Health - Cast 'Shield Block'"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,12000,15000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Triumph Sentry - In Combat - Cast 'Revenge'");
-- Triumph Vanguard SAI
SET @ENTRY := 37923;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,25000,30000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Triumph Vanguard - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,12000,13000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Triumph Vanguard - Between 0-50% Health - Cast 'Shield Block'");
-- Twinbraid's Bodyguard SAI
SET @ENTRY := 39156;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twinbraid's Bodyguard - In Combat - Cast 'Shoot'");
-- Una'fe Watcher SAI
SET @ENTRY := 37220;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Una'fe Watcher - In Combat - Cast 'Shoot'");
-- Unstable Spore SAI
SET @ENTRY := 44265;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,20000,22000,11,79826,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unstable Spore - Out of Combat - Cast 'Unstable Cloud'");
-- Walpole's Bodyguard SAI
SET @ENTRY := 38385;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Walpole's Bodyguard - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,12000,13000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Walpole's Bodyguard - Between 0-50% Health - Cast 'Shield Block'"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,12000,15000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Walpole's Bodyguard - In Combat - Cast 'Revenge'");
-- Wildhammer Mercenary SAI
SET @ENTRY := 37977;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,15000,16000,11,82837,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildhammer Mercenary - Within 0-40 Range - Cast 'Stormhammer'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,11000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildhammer Mercenary - Within 0-5 Range - Cast 'Kick'");
-- Wounded Bael'dun Officer SAI
SET @ENTRY := 39220;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wounded Bael'dun Officer - On Aggro - Cast 'Defensive Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,14000,16000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wounded Bael'dun Officer - In Combat - Cast 'Backhand'");
