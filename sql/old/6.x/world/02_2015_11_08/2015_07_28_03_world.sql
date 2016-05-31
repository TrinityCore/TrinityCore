-- 
-- DB/SAI: Update Westfall
-- Brack SAI
SET @ENTRY := 520;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brack - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,6700,12500,21000,33600,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brack - In Combat - Cast 'Hamstring'"),
(@ENTRY,0,2,0,0,0,100,0,25300,25300,47000,56000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brack - In Combat - Cast 'Pierce Armor'"),
(@ENTRY,0,3,0,0,0,100,0,11000,11500,11600,25500,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brack - In Combat - Cast 'Strike'");
-- Chasm Slime SAI
SET @ENTRY := 42669;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,40,0,0,11,80570,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chasm Slime - Between 0-40% Health - Cast 'Mimic' (No Repeat)");
-- Coyote SAI
SET @ENTRY := 834;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,10,0,30000,600000,120000,600000,4,1018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coyote - Out of Combat - Play Sound 1018"),
(@ENTRY,0,1,0,61,0,100,0,30000,600000,120000,600000,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coyote - Out of Combat - Play Emote 393"),
(@ENTRY,0,2,0,0,0,100,0,7000,12000,24000,32000,11,80362,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coyote - In Combat - Cast 'Crushing Bite'");
-- Coyote Packleader SAI
SET @ENTRY := 833;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,10,0,30000,600000,120000,600000,4,1018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coyote Packleader - Out of Combat - Play Sound 1018"),
(@ENTRY,0,1,0,61,0,100,0,30000,600000,120000,600000,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coyote Packleader - Out of Combat - Play Emote 393"),
(@ENTRY,0,2,0,0,0,100,0,7000,12000,24000,32000,11,80362,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coyote Packleader - In Combat - Cast 'Crushing Bite'");
-- Defias Henchman SAI
SET @ENTRY := 594;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,78894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Henchman - On Aggro - Cast 'Leaping Cleave' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,0,0,55,12000,21000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Henchman - Between 0-55% Health - Cast 'Improved Blocking'");
-- Defias Knuckleduster SAI
SET @ENTRY := 449;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,75356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Knuckleduster - In Combat - Cast 'Fisticuffs'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,80597,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Knuckleduster - Between 0-30% Health - Cast 'Bash and Smash' (No Repeat)");
-- Defias Pillager SAI
SET @ENTRY := 589;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,13878,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Pillager - In Combat - Cast 'Scorch'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79849,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Pillager - Out of Combat - Cast 'Molten Armor'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,13600,14500,11,79857,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Pillager - Within 0-8 Range - Cast 'Blast Wave'");
-- Energized Harvest Reaper SAI
SET @ENTRY := 42342;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,20000,11,7342,0,0,0,0,0,2,0,0,0,0,0,0,0,"Energized Harvest Reaper - In Combat - Cast 'Wide Slash'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,25000,29000,11,80572,0,0,0,0,0,1,0,0,0,0,0,0,0,"Energized Harvest Reaper - Between 0-40% Health - Cast 'Energize!'");
-- Fleshripper SAI
SET @ENTRY := 1109;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,9500,17500,22300,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fleshripper - In Combat - Cast 'Rend'");
-- Foe Reaper 4000 SAI
SET @ENTRY := 573;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,20000,11,7342,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foe Reaper 4000 - In Combat - Cast 'Wide Slash'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,25000,29000,11,80572,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foe Reaper 4000 - Between 0-40% Health - Cast 'Energize!'");
-- Goretusk SAI
SET @ENTRY := 157;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goretusk - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5500,7800,18500,26300,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goretusk - In Combat - Cast 'Gore'");
-- Greater Fleshripper SAI
SET @ENTRY := 154;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,9500,17500,22300,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Fleshripper - In Combat - Cast 'Rend'");
-- Harvest Watcher SAI
SET @ENTRY := 114;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,20000,11,7342,0,0,0,0,0,2,0,0,0,0,0,0,0,"Harvest Watcher - In Combat - Cast 'Wide Slash'");
-- Hulking Goretusk SAI
SET @ENTRY := 42357;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hulking Goretusk - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5500,7800,18500,26300,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hulking Goretusk - In Combat - Cast 'Gore'");
-- Jango Spothide SAI
SET @ENTRY := 42653;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,35,18000,25000,11,79853,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jango Spothide - Between 0-35% Health - Cast 'Evasion'"),
(@ENTRY,0,1,0,0,0,100,0,3500,9000,24000,28000,11,3136,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jango Spothide - In Combat - Cast 'Frenzied Command'");
-- Master Digger SAI
SET @ENTRY := 1424;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Digger - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,6000,12000,27000,33000,11,80382,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Digger - In Combat - Cast 'Dirt Toss'"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,18000,27000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Digger - In Combat - Cast 'Pierce Armor'");
-- Moonbrook Thug SAI
SET @ENTRY := 42677;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonbrook Thug - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5500,7800,18500,21200,11,80146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moonbrook Thug - In Combat - Cast 'Bonk'");
-- Murloc Hunter SAI
SET @ENTRY := 458;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Hunter - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,3000,5000,0,0,11,8656,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Out of Combat - Cast 'Summon Crawler' (No Repeat)");
-- Murloc Minor Oracle SAI
SET @ENTRY := 456;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5500,7500,12500,18500,11,79831,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Minor Oracle - In Combat - Cast 'Wave Crash'"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - Out of Combat - Cast 'Water Shield'"),
(@ENTRY,0,3,0,16,0,100,0,79892,1,15000,30000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - On Friendly Unit Missing Buff 'Water Shield' - Cast 'Water Shield'");
-- Murloc Netter SAI
SET @ENTRY := 513;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Netter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,20,14000,17000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Netter - Within 0-20 Range - Cast 'Net'"),
(@ENTRY,0,2,0,0,0,100,0,4500,7500,14500,17500,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Netter - In Combat - Cast 'Sunder Armor'");
-- Murloc Oracle SAI
SET @ENTRY := 517;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Oracle - In Combat - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Oracle - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,2,1,100,1,0,30,0,0,11,11835,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Oracle - Between 0-30% Health - Cast 'Power Word: Shield' (Phase 1) (No Repeat)");
-- Murloc Raider SAI
SET @ENTRY := 515;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Raider - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,20,14000,17000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Raider - Within 0-20 Range - Cast 'Net'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,27500,33500,11,80522,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Raider - In Combat - Cast 'Demoralizing Mmmrrrggglll'");
-- Murloc Tidehunter SAI
SET @ENTRY := 127;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32011,64,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Tidehunter - In Combat - Cast 'Water Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Tidehunter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,15,13600,14500,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Tidehunter - Within 0-15 Range - Cast 'Splash'");
-- Old Murk-Eye SAI
SET @ENTRY := 391;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,14000,11,80555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Old Murk-Eye - In Combat - Cast 'Sonic Spear'"),
(@ENTRY,0,1,0,0,0,100,0,12000,15000,27000,35000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,"Old Murk-Eye - In Combat - Cast 'Splash'"),
(@ENTRY,0,2,3,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Old Murk-Eye - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Old Murk-Eye - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 391;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Protector Bialon SAI
SET @ENTRY := 487;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Bialon - In Combat - Cast 'Shoot'");
-- Protector Deni SAI
SET @ENTRY := 870;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Deni - In Combat - Cast 'Shoot'");
-- Protector Dorana SAI
SET @ENTRY := 869;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Dorana - In Combat - Cast 'Shoot'");
-- Protector Dutfield SAI
SET @ENTRY := 489;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Dutfield - In Combat - Cast 'Shoot'");
-- Protector Gariel SAI
SET @ENTRY := 490;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Gariel - In Combat - Cast 'Shoot'");
-- Protector Korelor SAI
SET @ENTRY := 874;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Korelor - In Combat - Cast 'Shoot'");
-- Protector Leick SAI
SET @ENTRY := 876;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Leick - In Combat - Cast 'Shoot'");
-- Protector Weaver SAI
SET @ENTRY := 488;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Weaver - In Combat - Cast 'Shoot'");
-- Riverpaw Bandit SAI
SET @ENTRY := 452;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Bandit - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,0,0,40,25000,28000,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Bandit - Between 0-40% Health - Cast 'Shadowstep'"),
(@ENTRY,0,2,0,0,0,100,0,7500,12400,21000,22000,11,30478,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Bandit - In Combat - Cast 'Hemorrhage'"),
(@ENTRY,0,3,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Bandit - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 452;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text',46596),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text',1870);
-- Riverpaw Bandit SAI
SET @ENTRY := 54371;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Bandit - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,0,0,40,25000,28000,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Bandit - Between 0-40% Health - Cast 'Shadowstep'"),
(@ENTRY,0,2,0,0,0,100,0,7500,12400,21000,22000,11,30478,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Bandit - In Combat - Cast 'Hemorrhage'"),
(@ENTRY,0,3,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Bandit - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 54371;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text',46596),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text',1870);
-- Riverpaw Brute SAI
SET @ENTRY := 124;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Brute - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4500,6200,18500,22000,11,77558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Brute - In Combat - Cast 'Bloody Strike'"),
(@ENTRY,0,2,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Brute - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 124;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text',46596),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text',1870);
-- Riverpaw Brute SAI
SET @ENTRY := 54372;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Brute - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4500,6200,18500,22000,11,77558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Brute - In Combat - Cast 'Bloody Strike'"),
(@ENTRY,0,2,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Brute - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 54372;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text',46596),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text',1870);
-- Riverpaw Gnoll SAI
SET @ENTRY := 117;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Gnoll - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3500,7200,14500,16500,11,80475,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Gnoll - In Combat - Cast 'Riverpaw Brand'"),
(@ENTRY,0,2,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Gnoll - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 117;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text',46596),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text',1870);
-- Riverpaw Herbalist SAI
SET @ENTRY := 501;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Herbalist - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,50,0,1000,1000,120000,120000,11,80472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Herbalist - In Combat - Cast 'Elixir of Agility'"),
(@ENTRY,0,2,0,0,0,50,0,1000,1000,120000,120000,11,80471,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Herbalist - In Combat - Cast 'Potion of Strength'"),
(@ENTRY,0,3,0,0,0,50,0,1000,1000,120000,120000,11,80473,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Herbalist - In Combat - Cast 'Tonic of Health'"),
(@ENTRY,0,4,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Herbalist - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 501;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text',46596),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text',1870);
-- Riverpaw Herbalist SAI
SET @ENTRY := 54373;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Herbalist - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,50,0,1000,1000,120000,120000,11,80472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Herbalist - In Combat - Cast 'Elixir of Agility'"),
(@ENTRY,0,2,0,0,0,50,0,1000,1000,120000,120000,11,80471,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Herbalist - In Combat - Cast 'Potion of Strength'"),
(@ENTRY,0,3,0,0,0,50,0,1000,1000,120000,120000,11,80473,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Herbalist - In Combat - Cast 'Tonic of Health'"),
(@ENTRY,0,4,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Herbalist - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 54373;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text',46596),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text',1870);
-- Riverpaw Mongrel SAI
SET @ENTRY := 123;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mongrel - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3500,7200,14500,16500,11,80475,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Mongrel - In Combat - Cast 'Riverpaw Brand'"),
(@ENTRY,0,2,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mongrel - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 123;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text',46596),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text',1870);
-- Riverpaw Mystic SAI
SET @ENTRY := 453;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3500,4500,12500,15500,11,79913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Mystic - In Combat - Cast 'Chain Lightning'"),
(@ENTRY,0,2,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,0,14,0,100,0,250,40,15000,18000,11,79924,0,0,0,0,0,7,0,0,0,0,0,0,0,"Riverpaw Mystic - Friendly At 250 Health - Cast 'Healing Wave'"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,11,79924,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Mystic - Between 0-30% Health - Cast 'Healing Wave' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 453;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text',46596),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text',1870);
-- Riverpaw Scout SAI
SET @ENTRY := 500;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Scout - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Scout - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,5000,7000,9000,10500,11,78509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Scout - In Combat - Cast 'Torch Toss'");
-- NPC talk text insert
SET @ENTRY := 500;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text',46596),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text',1870);
-- Riverpaw Shaman SAI
SET @ENTRY := 1065;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Riverpaw Shaman - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,3,0,16,0,100,0,12550,1,15000,30000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverpaw Shaman - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'");
-- Sand Crawler SAI
SET @ENTRY := 830;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7200,13500,18900,11,80380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sand Crawler - In Combat - Cast 'Sand Breath'");
-- Sea Crawler SAI
SET @ENTRY := 831;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7200,13500,18900,11,80380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sea Crawler - In Combat - Cast 'Sand Breath'"),
(@ENTRY,0,1,0,0,0,100,0,8500,12300,22000,34000,11,78744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sea Crawler - In Combat - Cast 'Bubblebeam'");
-- Sentinel Hill Guard SAI
SET @ENTRY := 42407;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Hill Guard - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,12000,15000,24000,33000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Hill Guard - In Combat - Cast 'Shield Block'"),
(@ENTRY,0,2,0,0,0,100,0,8000,8500,13000,13200,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Hill Guard - In Combat - Cast 'Revenge'");
-- Sergeant Brashclaw SAI
SET @ENTRY := 506;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,79853,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sergeant Brashclaw - Between 0-30% Health - Cast 'Evasion' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3200,18000,22000,11,3136,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sergeant Brashclaw - In Combat - Cast 'Frenzied Command'");
-- Shore Crawler SAI
SET @ENTRY := 1216;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7200,13500,18900,11,80380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shore Crawler - In Combat - Cast 'Sand Breath'"),
(@ENTRY,0,1,0,0,0,100,0,8500,12300,22000,34000,11,78744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shore Crawler - In Combat - Cast 'Bubblebeam'"),
(@ENTRY,0,2,0,2,0,100,1,0,42,0,0,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shore Crawler - Between 0-42% Health - Cast 'Harden' (No Repeat)");
-- Skeletal Miner SAI
SET @ENTRY := 623;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,15000,16000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Miner - In Combat - Cast 'Strike'");
-- Slark SAI
SET @ENTRY := 519;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5500,7500,12500,18500,11,79831,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slark - In Combat - Cast 'Wave Crash'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slark - Out of Combat - Cast 'Water Shield'"),
(@ENTRY,0,2,0,16,0,100,0,79892,1,15000,30000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slark - On Friendly Unit Missing Buff 'Water Shield' - Cast 'Water Shield'");
-- Undead Dynamiter SAI
SET @ENTRY := 625;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,500,4500,14000,32000,11,7395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Undead Dynamiter - In Combat - Cast 'Deadmines Dynamite'"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Undead Dynamiter - Out of Combat - Cast 'Birth' (No Repeat)");
-- Undead Excavator SAI
SET @ENTRY := 624;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,5000,16000,11,5137,0,0,0,0,0,2,0,0,0,0,0,0,0,"Undead Excavator - In Combat - Cast 'Call of the Grave'"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Undead Excavator - Out of Combat - Cast 'Birth' (No Repeat)");
-- Vultros SAI
SET @ENTRY := 462;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,9500,17500,22300,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vultros - In Combat - Cast 'Rend'");
