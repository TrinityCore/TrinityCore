-- 
-- DB/SAI: Update Dustwallow Marsh
-- Acidic Swamp Ooze SAI
SET @ENTRY := 4393;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,17000,21000,11,73135,0,0,0,0,0,2,0,0,0,0,0,0,0,"Acidic Swamp Ooze - In Combat - Cast 'Old Friends: Quest Accept & Bind'");
-- Archmage Tervosh SAI
SET @ENTRY := 4967;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,1800000,1800000,11,7120,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Tervosh - Out of Combat - Cast 'Proudmoore's Defense'");
-- Bloodfen Lashtail SAI
SET @ENTRY := 4357;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,18000,24000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfen Lashtail - In Combat - Cast 'Lash'");
-- Bloodfen Razormaw SAI
SET @ENTRY := 4356;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,25000,27000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfen Razormaw - In Combat - Cast 'Infected Wound'");
-- Brackenwall Enforcer SAI
SET @ENTRY := 10036;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brackenwall Enforcer - On Aggro - Cast 'Throw' (No Repeat)");
-- Brimgore SAI
SET @ENTRY := 4339;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,16000,22000,11,87387,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brimgore - In Combat - Cast 'Flame Breath'");
-- Bubbling Swamp Ooze SAI
SET @ENTRY := 4394;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,17000,21000,11,73135,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bubbling Swamp Ooze - In Combat - Cast 'Old Friends: Quest Accept & Bind'");
-- Burgle Eye SAI
SET @ENTRY := 14230;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burgle Eye - Out of Combat - Cast 'Water Shield'"),
(@ENTRY,0,1,0,16,0,100,0,79892,1,15000,30000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burgle Eye - On Friendly Unit Missing Buff 'Water Shield' - Cast 'Water Shield'"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,17000,20000,11,79831,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burgle Eye - In Combat - Cast 'Wave Crash'");
-- Crown Hoodlum SAI
SET @ENTRY := 38006;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,70074,64,0,0,0,0,2,0,0,0,0,0,0,0,"Crown Hoodlum - In Combat - Cast 'Spray Chemical'");
-- Darkfang Creeper SAI
SET @ENTRY := 4412;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,22000,24000,11,7992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkfang Creeper - In Combat - Cast 'Slowing Poison'");
-- Darkfang Venomspitter SAI
SET @ENTRY := 4414;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,12500,11,7951,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkfang Venomspitter - In Combat - Cast 'Toxic Spit'");
-- Darkmist Broodqueen SAI
SET @ENTRY := 45227;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3500,14000,15000,11,69964,32,0,0,0,0,2,0,0,0,0,0,0,0,"Darkmist Broodqueen - In Combat - Cast 'Poison'");
-- Darkmist Recluse SAI
SET @ENTRY := 4378;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,20000,25000,11,43133,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkmist Recluse - In Combat - Cast 'Debilitating Poison'");
-- Darkmist Silkspinner SAI
SET @ENTRY := 4379;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,9000,11000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkmist Silkspinner - Within 0-30 Range - Cast 'Web'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,16000,20000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkmist Silkspinner - In Combat - Cast 'Poison'");
-- Darkmist Spider SAI
SET @ENTRY := 4376;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,18000,22000,11,69964,32,0,0,0,0,2,0,0,0,0,0,0,0,"Darkmist Spider - In Combat - Cast 'Poison'");
-- Darkmist Widow SAI
SET @ENTRY := 4380;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,16000,21000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Darkmist Widow - In Combat - Cast 'Poison'");
-- Dart SAI
SET @ENTRY := 14232;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,14000,18000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dart - In Combat - Cast 'Rend Flesh'");
-- Deadmire SAI
SET @ENTRY := 4841;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,18000,20000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadmire - In Combat - Cast 'Rend'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,30000,35000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadmire - In Combat - Cast 'Tendon Rip'");
-- Defias Conjuror SAI
SET @ENTRY := 23590;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Conjuror - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjuror - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjuror - Out of Combat - Cast 'Frost Armor'");
-- Defias Diver SAI
SET @ENTRY := 23591;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,43107,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Diver - On Aggro - Cast 'Spear Throw' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Diver - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Defias Rummager SAI
SET @ENTRY := 23589;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Rummager - On Aggro - Cast 'Throw' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Rummager - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Deserter Lieutenant SAI
SET @ENTRY := 23637;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,0,2000,4500,20000,30000,11,11972,0,0,0,0,0,7,0,0,0,0,0,0,0,"Deserter Lieutenant - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'");
-- Drogoth the Roamer SAI
SET @ENTRY := 14231;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,19000,25000,11,81146,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drogoth the Roamer - In Combat - Cast 'War Stomp'");
-- Drywallow Crocolisk SAI
SET @ENTRY := 4341;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,24000,26000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drywallow Crocolisk - In Combat - Cast 'Tendon Rip'");
-- Drywallow Daggermaw SAI
SET @ENTRY := 4345;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,45000,50000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drywallow Daggermaw - In Combat - Cast 'Pierce Armor'");
-- Drywallow Snapper SAI
SET @ENTRY := 4343;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,18000,23000,11,87471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drywallow Snapper - In Combat - Cast 'Snapjaw'");
-- Elder Murk Thresher SAI
SET @ENTRY := 4390;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,45000,50000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Murk Thresher - In Combat - Cast 'Pierce Armor'"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Murk Thresher - On Respawn - Cast 'Thrash' (No Repeat)");
-- Emberstrife SAI
SET @ENTRY := 10321;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,14000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emberstrife - In Combat - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,25000,28000,11,9573,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emberstrife - In Combat - Cast 'Flame Breath'"),
(@ENTRY,0,2,3,2,0,100,1,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emberstrife - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emberstrife - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 10321;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Firemane Ash Tail SAI
SET @ENTRY := 4331;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,13600,14500,11,11969,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Ash Tail - Within 0-8 Range - Cast 'Fire Nova'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,18968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Ash Tail - Out of Combat - Cast 'Fire Shield'"),
(@ENTRY,0,2,0,16,0,100,0,18968,1,15000,30000,11,18968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Ash Tail - On Friendly Unit Missing Buff 'Fire Shield' - Cast 'Fire Shield'");
-- Firemane Flamecaller SAI
SET @ENTRY := 4334;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Firemane Flamecaller - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,18968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - Out of Combat - Cast 'Fire Shield'"),
(@ENTRY,0,2,0,16,0,100,0,18968,1,15000,30000,11,18968,1,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - On Friendly Unit Missing Buff 'Fire Shield' - Cast 'Fire Shield'"),
(@ENTRY,0,3,0,0,0,100,0,6000,9000,24000,26000,11,11990,1,0,0,0,0,4,0,0,0,0,0,0,0,"Firemane Flamecaller - In Combat - Cast 'Rain of Fire'");
-- Firemane Scalebane SAI
SET @ENTRY := 4328;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,13600,14500,11,11971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Scalebane - Within 0-8 Range - Cast 'Sunder Armor'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,18968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Scalebane - Out of Combat - Cast 'Fire Shield'"),
(@ENTRY,0,2,0,16,0,100,0,18968,1,15000,30000,11,18968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Scalebane - On Friendly Unit Missing Buff 'Fire Shield' - Cast 'Fire Shield'"),
(@ENTRY,0,3,0,13,0,100,0,2000,4500,20000,30000,11,11972,0,0,0,0,0,7,0,0,0,0,0,0,0,"Firemane Scalebane - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'");
-- Firemane Scout SAI
SET @ENTRY := 4329;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,18968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Scout - Out of Combat - Cast 'Fire Shield'"),
(@ENTRY,0,1,0,16,0,100,0,18968,1,15000,30000,11,18968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Scout - On Friendly Unit Missing Buff 'Fire Shield' - Cast 'Fire Shield'");
-- Garn Mathers SAI
SET @ENTRY := 23679;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Garn Mathers - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Giant Darkfang Spider SAI
SET @ENTRY := 4415;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,16000,21000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Darkfang Spider - In Combat - Cast 'Poison'");
-- Goreclaw the Ravenous SAI
SET @ENTRY := 23873;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,54487,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goreclaw the Ravenous - On Aggro - Cast 'Jump Attack' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,18000,22000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goreclaw the Ravenous - In Combat - Cast 'Gore'");
-- Grimtotem Breaker SAI
SET @ENTRY := 23592;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,15000,17000,11,43108,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Breaker - In Combat - Cast 'Bone Breaker'");
-- Grimtotem Destroyer SAI
SET @ENTRY := 23594;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,17000,19000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Destroyer - In Combat - Cast 'War Stomp'");
-- Grimtotem Earthbinder SAI
SET @ENTRY := 23595;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,19000,22000,11,15786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Earthbinder - In Combat - Cast 'Earthbind Totem'"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,12000,13000,11,32910,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Earthbinder - In Combat - Cast 'Windfury'");
-- Grimtotem Elder SAI
SET @ENTRY := 23714;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Elder - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Elder - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,14,0,100,0,600,40,15000,18000,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Grimtotem Elder - Friendly At 600 Health - Cast 'Healing Wave'");
-- Grimtotem Spirit-Shifter SAI
SET @ENTRY := 23593;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,43110,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Spirit-Shifter - On Aggro - Cast 'Summon Spirit Wolf' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,12000,13000,11,11824,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Spirit-Shifter - In Combat - Cast 'Shock'");
-- Guard Edward SAI
SET @ENTRY := 4922;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Edward - On Aggro - Cast 'Defensive Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Edward - In Combat - Cast 'Strike'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,17000,19000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Edward - In Combat - Cast 'Whirlwind'");
-- Guard Jarad SAI
SET @ENTRY := 4923;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Jarad - On Aggro - Cast 'Defensive Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Jarad - In Combat - Cast 'Strike'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,17000,19000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Jarad - In Combat - Cast 'Whirlwind'");
-- Guard Kahil SAI
SET @ENTRY := 5091;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Kahil - On Aggro - Cast 'Defensive Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Kahil - In Combat - Cast 'Strike'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,17000,19000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Kahil - In Combat - Cast 'Whirlwind'");
-- Guard Lana SAI
SET @ENTRY := 5092;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lana - On Aggro - Cast 'Defensive Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Lana - In Combat - Cast 'Strike'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,17000,19000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lana - In Combat - Cast 'Whirlwind'");
-- Guard Narrisha SAI
SET @ENTRY := 5093;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Narrisha - On Aggro - Cast 'Defensive Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Narrisha - In Combat - Cast 'Strike'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,17000,19000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Narrisha - In Combat - Cast 'Whirlwind'");
-- Guard Tark SAI
SET @ENTRY := 5094;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Tark - On Aggro - Cast 'Defensive Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Tark - In Combat - Cast 'Strike'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,17000,19000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Tark - In Combat - Cast 'Whirlwind'");
-- Hayoc SAI
SET @ENTRY := 14234;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,79085,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hayoc - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,9000,14000,11,21059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hayoc - In Combat - Cast 'Acid Spit'");
-- Lady Jaina Proudmoore SAI
SET @ENTRY := 4968;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20692,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,45000,55000,11,20681,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Cast 'Summon Water Elementals'"),
(@ENTRY,0,2,0,0,0,100,0,5000,9000,15000,17000,11,20679,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Cast 'Fire Blast'"),
(@ENTRY,0,3,0,0,0,100,0,8000,12000,25000,28000,11,20680,1,0,0,0,0,4,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Cast 'Blizzard'"),
(@ENTRY,0,4,0,2,0,100,0,0,50,14000,21000,11,20682,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - Between 0-50% Health - Cast 'Teleport'");
-- Lieutenant Aden SAI
SET @ENTRY := 23951;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Aden - In Combat - Cast 'Shoot'");
-- Lieutenant Nath SAI
SET @ENTRY := 23949;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Nath - In Combat - Cast 'Shoot'");
-- Lord Angler SAI
SET @ENTRY := 14236;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Angler - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Marine Anderson SAI
SET @ENTRY := 24842;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Marine Anderson - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,0,20,9000,11000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marine Anderson - Within 0-20 Range - Cast 'Net'");
-- Marine Halters SAI
SET @ENTRY := 24841;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Marine Halters - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,0,20,9000,11000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marine Halters - Within 0-20 Range - Cast 'Net'");
-- Medic Helaina SAI
SET @ENTRY := 5200;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,1000,40,15000,18000,11,7162,0,0,0,0,0,7,0,0,0,0,0,0,0,"Medic Helaina - Friendly At 1000 Health - Cast 'First Aid'");
-- Medic Tamberlyn SAI
SET @ENTRY := 5199;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,1000,40,15000,18000,11,7162,0,0,0,0,0,7,0,0,0,0,0,0,0,"Medic Tamberlyn - Friendly At 1000 Health - Cast 'First Aid'");
-- Mirefin Ambusher SAI
SET @ENTRY := 23701;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,13000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mirefin Ambusher - In Combat - Cast 'Sinister Strike'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,13600,14500,11,9462,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mirefin Ambusher - Within 0-5 Range - Cast 'Mirefin Fungus'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Ambusher - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Mirefin Coastrunner SAI
SET @ENTRY := 4362;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Coastrunner - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,13000,11,37998,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mirefin Coastrunner - In Combat - Cast 'Piercing Strike'");
-- Mirefin Muckdweller SAI
SET @ENTRY := 4361;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,32000,35000,11,6278,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mirefin Muckdweller - In Combat - Cast 'Creeping Mold'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,13600,14500,11,9462,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mirefin Muckdweller - Within 0-5 Range - Cast 'Mirefin Fungus'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Muckdweller - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Mirefin Murloc SAI
SET @ENTRY := 4359;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mirefin Murloc - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Murloc - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,3000,5000,0,0,11,8656,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Murloc - Out of Combat - Cast 'Summon Crawler' (No Repeat)");
-- Mirefin Oracle SAI
SET @ENTRY := 4363;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mirefin Oracle - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Oracle - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Oracle - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,3,0,16,0,100,0,12550,1,15000,30000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Oracle - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'");
-- Mottled Drywallow Crocolisk SAI
SET @ENTRY := 4344;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,90171,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mottled Drywallow Crocolisk - In Combat - Cast 'Jagged Tooth Snap'");
-- Muckshell Clacker SAI
SET @ENTRY := 4401;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,25000,27000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Muckshell Clacker - In Combat - Cast 'Tendon Rip'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muckshell Clacker - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Muckshell Pincer SAI
SET @ENTRY := 4403;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,15000,21000,11,75004,0,0,0,0,0,2,0,0,0,0,0,0,0,"Muckshell Pincer - In Combat - Cast 'Pinch'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muckshell Pincer - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Muckshell Scrabbler SAI
SET @ENTRY := 4404;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Muckshell Scrabbler - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muckshell Scrabbler - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Mudsprocket Bruiser SAI
SET @ENTRY := 23636;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mudsprocket Bruiser - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,0,20,8000,9000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mudsprocket Bruiser - Within 0-20 Range - Cast 'Net'");
-- Murk Thresher SAI
SET @ENTRY := 4389;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murk Thresher - On Respawn - Cast 'Thrash' (No Repeat)");
-- Noxious Flayer SAI
SET @ENTRY := 4346;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,43132,0,0,0,0,0,2,0,0,0,0,0,0,0,"Noxious Flayer - In Combat - Cast 'Poison Burst'");
-- Murk Thresher SAI
SET @ENTRY := 4389;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murk Thresher - On Respawn - Cast 'Thrash' (No Repeat)");
-- Noxious Flayer SAI
SET @ENTRY := 4346;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,43132,0,0,0,0,0,2,0,0,0,0,0,0,0,"Noxious Flayer - In Combat - Cast 'Poison Burst'");
-- Noxious Reaver SAI
SET @ENTRY := 4347;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,14000,15000,11,43132,0,0,0,0,0,2,0,0,0,0,0,0,0,"Noxious Reaver - In Combat - Cast 'Poison Burst'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,12000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Noxious Reaver - Within 0-5 Range - Cast 'Swoop'");
-- Noxious Shredder SAI
SET @ENTRY := 4348;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noxious Shredder - On Respawn - Cast 'Thrash' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,18000,24000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Noxious Shredder - In Combat - Cast 'Poison'");
-- Oozeworm SAI
SET @ENTRY := 14237;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oozeworm - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,17000,22000,11,66954,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oozeworm - In Combat - Cast 'Acidic Strike'");
-- Overlord Mok'Morokk SAI
SET @ENTRY := 4500;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,18000,11,6749,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overlord Mok'Morokk - In Combat - Cast 'Wide Swipe'");
-- Private Hendel SAI
SET @ENTRY := 4966;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,17000,21000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Private Hendel - In Combat - Cast 'Rend'");
-- Ripscale SAI
SET @ENTRY := 14233;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,15000,15000,11,33912,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ripscale - In Combat - Cast 'Rip'"),
(@ENTRY,0,1,0,0,0,100,0,6000,7000,24000,28000,11,7367,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ripscale - In Combat - Cast 'Infected Bite'");
-- Risen Husk SAI
SET @ENTRY := 23555;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,40,12000,12000,11,37933,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Husk - Between 0-40% Health - Cast 'Consume Flesh'"),
(@ENTRY,0,1,0,61,0,100,0,0,40,12000,12000,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Husk - Between 0-40% Health - Say Line 0"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,42511,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Husk - On Just Died - Cast 'Summon Restless Apparition' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 23555;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You''ll never leave here alive!',16,0,100,0,0,0, 'combat Text',21319);
-- Risen Spirit SAI
SET @ENTRY := 23554;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,15000,20000,11,43127,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Spirit - In Combat - Cast 'Intangible Presence'"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,42511,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Spirit - On Just Died - Cast 'Summon Restless Apparition' (No Repeat)");
-- Restless Apparition SAI
SET @ENTRY := 23861;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,500,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Restless Apparition - Out of Combat - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 23861;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Go away, whoever you are! Witch Hill is mine... mine!',12,0,50,1,0,0, 'say Text',22359),
(@ENTRY,0,1, 'Why have you come here, outsider? You will only find pain! Our fate will be yours...',12,0,50,1,0,0, 'say Text',22363),
(@ENTRY,0,2, 'It is too late for Jarl... its hold is too strong...',12,0,50,1,0,0, 'say Text',22366),
(@ENTRY,0,3, 'The darkness... the corruption... they came too quickly for anyone to know...',12,0,50,1,0,0, 'say Text',22362),
(@ENTRY,0,4, 'The manor... someone else... will soon be consumed...',12,0,50,1,0,0, 'say Text',22361),
(@ENTRY,0,5, 'The darkness will consume all... all the living...',12,0,50,1,0,0, 'say Text',22364);
-- Scorchscale Drake SAI
SET @ENTRY := 23687;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,12000,14000,11,13374,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorchscale Drake - In Combat - Cast 'Fire Blast'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,19000,24000,11,8873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorchscale Drake - In Combat - Cast 'Flame Breath'");
-- Searing Hatchling SAI
SET @ENTRY := 4323;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,9000,11000,11,11985,0,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Hatchling - In Combat - Cast 'Fireball'");
-- Searing Whelp SAI
SET @ENTRY := 4324;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,9000,11000,11,11021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Whelp - In Combat - Cast 'Flamespit'");
-- Smolderwing SAI
SET @ENTRY := 23789;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,15000,18000,11,42433,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderwing - In Combat - Cast 'Smolderwing Fire Breath'");
-- Spiny Rock Crab SAI
SET @ENTRY := 44390;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,25000,28000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spiny Rock Crab - In Combat - Cast 'Tendon Rip'");
-- Strashaz Hydra SAI
SET @ENTRY := 4374;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,15000,18000,11,16128,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Hydra - In Combat - Cast 'Infected Bite'"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Strashaz Hydra - On Respawn - Cast 'Thrash' (No Repeat)");
-- Strashaz Myrmidon SAI
SET @ENTRY := 4368;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,10000,12000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Myrmidon - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,14000,20000,11,18812,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Myrmidon - In Combat - Cast 'Knockdown'");
-- Strashaz Serpent Guard SAI
SET @ENTRY := 4366;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,11000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Serpent Guard - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,16000,19000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Serpent Guard - In Combat - Cast 'Rend'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,22000,28000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Serpent Guard - In Combat - Cast 'Disarm'");
-- Strashaz Siren SAI
SET @ENTRY := 4371;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15587,64,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Siren - In Combat - Cast 'Mind Blast'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Strashaz Siren - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,18000,20000,11,15654,1,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Siren - In Combat - Cast 'Shadow Word: Pain'");
-- Strashaz Sorceress SAI
SET @ENTRY := 4370;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,12737,64,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Sorceress - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Strashaz Sorceress - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,9000,15000,15500,11,15499,1,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Sorceress - In Combat - Cast 'Frost Shock'"),
(@ENTRY,0,3,0,9,0,100,0,0,8,13600,14500,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,"Strashaz Sorceress - Within 0-8 Range - Cast 'Frost Nova'");
-- Strashaz Warrior SAI
SET @ENTRY := 4364;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,10000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Warrior - Within 0-5 Range - Cast 'Hamstring'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,16000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Warrior - In Combat - Cast 'Mortal Strike'");
-- The Rot SAI
SET @ENTRY := 14235;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,5000,7000,11,21067,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Rot - Within 0-30 Range - Cast 'Poison Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,15000,17000,11,22595,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Rot - In Combat - Cast 'Poison Shock'");
-- Theramore Deserter SAI
SET @ENTRY := 5057;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Deserter - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Theramore Guard SAI
SET @ENTRY := 4979;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Theramore Guard - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,12000,13000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Guard - Between 0-50% Health - Cast 'Shield Block'"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,12000,15000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Theramore Guard - In Combat - Cast 'Revenge'");
-- Theramore Infiltrator SAI
SET @ENTRY := 4834;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Infiltrator - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Infiltrator - On Respawn - Cast 'Sneak' (No Repeat)"),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Infiltrator - On Evade - Cast 'Sneak' (No Repeat)");
-- Tidelord Rrurgaz SAI
SET @ENTRY := 16072;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,18000,19000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tidelord Rrurgaz - Within 0-5 Range - Cast 'Rend'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,33000,35000,11,16244,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidelord Rrurgaz - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,25000,27500,11,86699,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tidelord Rrurgaz - In Combat - Cast 'Shockwave'");
-- Withervine Creeper SAI
SET @ENTRY := 4382;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,15,21000,25000,11,43130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withervine Creeper - Within 0-15 Range - Cast 'Creeping Vines'");
-- Withervine Rager SAI
SET @ENTRY := 4385;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,25,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withervine Rager - Between 0-25% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,25,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withervine Rager - Between 0-25% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 4385;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
