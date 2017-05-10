-- 
-- DB/SAI: Update Silverpine Forest
-- 7th Legion Scout SAI
SET @ENTRY := 45883;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,84442,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Scout - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,84442,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Scout - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,67,0,100,0,9000,12000,0,0,11,79862,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Scout - On Behind Target - Cast 'Backstab'"),
(@ENTRY,0,3,0,9,0,100,0,0,12,13600,14500,11,79584,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Scout - Within 0-12 Range - Cast 'Fan of Knives'"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Scout - Between 0-30% Health - Cast 'Shadowstep' (No Repeat)");
-- 7th Legion Scout SAI
SET @ENTRY := 46040;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,84442,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Scout - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,84442,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Scout - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,67,0,100,0,9000,12000,0,0,11,79862,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Scout - On Behind Target - Cast 'Backstab'"),
(@ENTRY,0,3,0,9,0,100,0,0,12,13600,14500,11,79584,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Scout - Within 0-12 Range - Cast 'Fan of Knives'"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Scout - Between 0-30% Health - Cast 'Shadowstep' (No Repeat)");
-- 7th Legion Submariner SAI
SET @ENTRY := 46065;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,86249,64,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Submariner - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,17000,11,81087,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Submariner - Within 0-5 Range - Cast 'Puncture Wound'");
-- Abomination SAI
SET @ENTRY := 46058;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,40,17000,19000,11,50335,0,0,0,0,0,2,0,0,0,0,0,0,0,"Abomination - Within 8-40 Range - Cast 'Scourge Hook'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,12000,15000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Abomination - In Combat - Cast 'Cleave'");
-- Ambermill Brewmaster SAI
SET @ENTRY := 3577;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Brewmaster - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,15000,20000,11,37591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ambermill Brewmaster - In Combat - Cast 'Drunken Haze'");
-- Ambermill Magister SAI
SET @ENTRY := 1914;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,3200,11,13878,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ambermill Magister - In Combat - Cast 'Scorch'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Magister - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,7000,9000,17000,22000,11,79856,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ambermill Magister - In Combat - Cast 'Flamestrike'");
-- Ambermill Miner SAI
SET @ENTRY := 3578;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Miner - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,12000,14500,11,39214,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ambermill Miner - In Combat - Cast 'Pierce Armor'");
-- Ambermill Portal Guardian SAI
SET @ENTRY := 45753;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Portal Guardian - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,60000,65000,11,87191,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Portal Guardian - In Combat - Cast 'Mana Shield'");
-- Ambermill Warder SAI
SET @ENTRY := 1913;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Warder - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,18000,22000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Warder - In Combat - Cast 'Improved Blocking'"),
(@ENTRY,0,2,0,0,0,100,0,12000,15000,30000,32000,11,86817,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Warder - In Combat - Cast 'Spell Ward'");
-- Ambermill Watcher SAI
SET @ENTRY := 1888;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Watcher - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,15000,17000,11,17140,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ambermill Watcher - In Combat - Cast 'Holy Fire'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,15000,21000,11,11640,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Watcher - Between 0-40% Health - Cast 'Renew'"),
(@ENTRY,0,3,0,14,0,100,0,150,40,15000,18000,11,11640,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ambermill Watcher - Friendly At 150 Health - Cast 'Renew'"),
(@ENTRY,0,4,0,1,0,100,0,500,1000,1800000,1800000,11,48168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Watcher - Out of Combat - Cast 'Inner Fire'");
-- Ambermill Witchalok SAI
SET @ENTRY := 1889;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,87222,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ambermill Witchalok - In Combat - Cast 'Throw Witchalok Blade'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Witchalok - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,50,1,8000,8000,0,0,11,87225,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Witchalok - In Combat - Cast 'Summon Doomskull' (No Repeat)"),
(@ENTRY,0,3,0,0,0,50,1,8000,8000,0,0,11,87224,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambermill Witchalok - In Combat - Cast 'Summon Wolfoids' (No Repeat)");
-- Aquarius the Unbound SAI
SET @ENTRY := 47009;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,81167,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aquarius the Unbound - In Combat - Cast 'Ice Lance'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,1800000,1800000,11,79865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aquarius the Unbound - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,13600,14500,11,79850,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aquarius the Unbound - Within 0-8 Range - Cast 'Frost Nova'");
-- Arcane Fiend SAI
SET @ENTRY := 45766;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,87249,3,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Fiend - On Just Died - Cast 'Arcane Expulsion' (No Repeat)");
-- Berard the Moon-Crazed SAI
SET @ENTRY := 46992;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Berard the Moon-Crazed - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Berard the Moon-Crazed - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,86237,0,0,0,0,0,1,0,0,0,0,0,0,0,"Berard the Moon-Crazed - On Respawn - Cast 'Stalking' (No Repeat)"),
(@ENTRY,0,3,0,7,0,100,1,0,0,0,0,11,86237,0,0,0,0,0,1,0,0,0,0,0,0,0,"Berard the Moon-Crazed - On Evade - Cast 'Stalking' (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,11,79864,0,0,0,0,0,2,0,0,0,0,0,0,0,"Berard the Moon-Crazed - Between 0-30% Health - Cast 'Shadowstep' (No Repeat)"),
(@ENTRY,0,5,0,0,0,100,0,3000,4500,12000,15000,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Berard the Moon-Crazed - In Combat - Cast 'Sinister Strike'");
-- NPC talk text insert
SET @ENTRY := 46992;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Bloodfang Berserker SAI
SET @ENTRY := 46050;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,63227,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfang Berserker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfang Berserker - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,18000,20000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfang Berserker - In Combat - Cast 'Slam'");
-- NPC talk text insert
SET @ENTRY := 46050;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Bloodfang Berserker SAI
SET @ENTRY := 45860;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,63227,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfang Berserker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfang Berserker - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,18000,20000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfang Berserker - In Combat - Cast 'Slam'");
-- NPC talk text insert
SET @ENTRY := 45860;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Bloodfang Scavenger SAI
SET @ENTRY := 44547;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,25000,30000,11,84308,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfang Scavenger - In Combat - Cast 'Furious Howl'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,14000,15000,11,78509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfang Scavenger - Within 0-30 Range - Cast 'Torch Toss'");
-- Bloodfang Scavenger SAI
SET @ENTRY := 44549;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,25000,30000,11,84308,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfang Scavenger - In Combat - Cast 'Furious Howl'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,14000,15000,11,78509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfang Scavenger - Within 0-30 Range - Cast 'Torch Toss'");
-- Bloodfang Stalker SAI
SET @ENTRY := 45195;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,86237,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfang Stalker - On Respawn - Cast 'Stalking' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,86237,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfang Stalker - On Evade - Cast 'Stalking' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,79864,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfang Stalker - Between 0-30% Health - Cast 'Shadowstep' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,3000,4500,12000,15000,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfang Stalker - In Combat - Cast 'Sinister Strike'");
-- Bolgaff SAI
SET @ENTRY := 47003;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,87603,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bolgaff - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,7000,8000,15000,20000,11,79721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bolgaff - In Combat - Cast 'Explosive Shot'"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,22000,25000,11,23601,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bolgaff - In Combat - Cast 'Scatter Shot'");
-- Caretaker Smithers SAI
SET @ENTRY := 45219;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,81173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Smithers - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Smithers - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,81764,0,0,0,0,0,2,0,0,0,0,0,0,0,"Caretaker Smithers - On Aggro - Cast 'Throw Lantern' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,4000,8000,15000,17500,11,81767,0,0,0,0,0,2,0,0,0,0,0,0,0,"Caretaker Smithers - In Combat - Cast 'Lantern Blaze'");
-- NPC talk text insert
SET @ENTRY := 45219;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Dark Ranger SAI
SET @ENTRY := 44632;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Ranger - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,22000,11,80009,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Ranger - In Combat - Cast 'Serpent Sting'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,66000,67000,11,22910,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger - Within 0-5 Range - Cast 'Immolation Trap'");
-- Darktusk Boar SAI
SET @ENTRY := 46575;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darktusk Boar - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,84873,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darktusk Boar - Between 0-40% Health - Cast 'Wallow'");
-- Deathguard Elite SAI
SET @ENTRY := 51858;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deathguard Elite - In Combat - Cast 'Shoot'");
-- Deathguard Elite SAI
SET @ENTRY := 51854;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deathguard Elite - In Combat - Cast 'Shoot'");
-- Dreadguard SAI
SET @ENTRY := 44911;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadguard - In Combat - Cast 'Shoot'");
-- Dreadguard SAI
SET @ENTRY := 51855;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadguard - In Combat - Cast 'Shoot'");
-- Dwarven Infantry SAI
SET @ENTRY := 45855;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,18000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dwarven Infantry - Within 0-8 Range - Cast 'Whirlwind'"),
(@ENTRY,0,1,0,0,0,100,0,9000,15000,25000,28000,11,7020,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dwarven Infantry - In Combat - Cast 'Stoneform'");
-- Dwarven Infantry SAI
SET @ENTRY := 46039;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,18000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dwarven Infantry - Within 0-8 Range - Cast 'Whirlwind'"),
(@ENTRY,0,1,0,0,0,100,0,9000,15000,25000,28000,11,7020,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dwarven Infantry - In Combat - Cast 'Stoneform'");
-- Effritus SAI
SET @ENTRY := 47012;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,81173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Effritus - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Effritus - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,0,0,50,14000,21000,11,28995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Effritus - Between 0-50% Health - Cast 'Stoneskin'");
-- NPC talk text insert
SET @ENTRY := 47012;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Elemental Servitor SAI
SET @ENTRY := 45711;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,12000,13000,11,81167,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elemental Servitor - In Combat - Cast 'Ice Lance'");
-- Fenwick Thatros SAI
SET @ENTRY := 47008;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,54633,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fenwick Thatros - Between 0-30% Health - Cast 'Drink Healing Potion' (No Repeat)"),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,80472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fenwick Thatros - On Aggro - Cast 'Elixir of Agility' (No Repeat)"),
(@ENTRY,0,2,0,4,0,50,1,0,0,0,0,11,80471,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fenwick Thatros - On Aggro - Cast 'Potion of Strength' (No Repeat)"),
(@ENTRY,0,3,0,4,0,50,1,0,0,0,0,11,80473,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fenwick Thatros - On Aggro - Cast 'Tonic of Health' (No Repeat)");
-- Ferocious Grizzled Bear SAI
SET @ENTRY := 1778;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ferocious Grizzled Bear - In Combat - Cast 'Swipe'"),
(@ENTRY,0,1,0,2,0,100,1,0,45,0,0,11,84868,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ferocious Grizzled Bear - Between 0-45% Health - Cast 'Hibernate' (No Repeat)");
-- Forest Ettin SAI
SET @ENTRY := 44367;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,17000,22000,11,80146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Forest Ettin - In Combat - Cast 'Bonk'"),
(@ENTRY,0,1,0,0,0,100,0,12000,15000,28000,35000,11,88421,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forest Ettin - In Combat - Cast 'Log Smash'");
-- Forsaken Mage SAI
SET @ENTRY := 46048;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79858,64,0,0,0,0,2,0,0,0,0,0,0,0,"Forsaken Mage - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,1800000,1800000,11,79865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Mage - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,13600,14500,11,79850,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Mage - Within 0-8 Range - Cast 'Frost Nova'"),
(@ENTRY,0,3,0,0,0,100,0,6000,9000,25000,28000,11,79860,1,0,0,0,0,2,0,0,0,0,0,0,0,"Forsaken Mage - In Combat - Cast 'Blizzard'"),
(@ENTRY,0,4,0,0,0,100,0,11000,11000,22000,23000,11,79859,1,0,0,0,0,2,0,0,0,0,0,0,0,"Forsaken Mage - In Combat - Cast 'Ice Lance'");
-- Forsaken Vanguard SAI
SET @ENTRY := 46086;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,18000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Forsaken Vanguard - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,11000,12000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Forsaken Vanguard - Within 0-5 Range - Cast 'Hamstring'");
-- General Marstone SAI
SET @ENTRY := 45995;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Marstone - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,1,0,16,0,100,0,19514,1,15000,30000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Marstone - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'"),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,14000,18000,11,79913,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Marstone - In Combat - Cast 'Chain Lightning'");
-- Giant Rabid Bear SAI
SET @ENTRY := 1797;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,22000,25000,11,3150,0,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Rabid Bear - In Combat - Cast 'Rabies'"),
(@ENTRY,0,1,0,2,0,100,1,0,45,0,0,11,84868,0,0,0,0,0,1,0,0,0,0,0,0,0,"Giant Rabid Bear - Between 0-45% Health - Cast 'Hibernate' (No Repeat)");
-- Gorefang SAI
SET @ENTRY := 12431;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorefang - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorefang - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,13000,15500,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorefang - Within 0-5 Range - Cast 'Rend'"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorefang - On Aggro - Cast 'Leaping Rush' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 12431;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Hand of Ravenclaw SAI
SET @ENTRY := 1870;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,14000,16000,11,3263,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hand of Ravenclaw - In Combat - Cast 'Touch of Ravenclaw'");
-- Hillsbrad Refugee SAI
SET @ENTRY := 44966;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,14000,16000,11,87104,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Refugee - In Combat - Cast 'Might of Lordaeron'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Refugee - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Hillsbrad Refugee SAI
SET @ENTRY := 44954;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,14000,16000,11,87104,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Refugee - In Combat - Cast 'Might of Lordaeron'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Refugee - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Hillsbrad Worgen SAI
SET @ENTRY := 45254;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,25,0,0,11,32714,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Worgen - Between 0-25% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,25,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Worgen - Between 0-25% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 45254;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Hillsbrad Worgen SAI
SET @ENTRY := 46063;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,25,0,0,11,32714,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Worgen - Between 0-25% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,25,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Worgen - Between 0-25% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 46063;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Hillsbrad Worgen SAI
SET @ENTRY := 45255;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,25,0,0,11,32714,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Worgen - Between 0-25% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,25,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Worgen - Between 0-25% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 45255;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Hillsbrad Worgen SAI
SET @ENTRY := 46064;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,25,0,0,11,32714,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Worgen - Between 0-25% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,25,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hillsbrad Worgen - Between 0-25% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 46064;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Inconspicuous Bear SAI
SET @ENTRY := 45750;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,25,15000,18000,11,87187,0,0,0,0,0,2,0,0,0,0,0,0,0,"Inconspicuous Bear - Within 8-25 Range - Cast 'Feral Charge'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,25000,27500,11,87185,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inconspicuous Bear - In Combat - Cast 'Demoralizing Roar'"),
(@ENTRY,0,2,0,0,0,100,0,2000,4500,12000,15000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Inconspicuous Bear - In Combat - Cast 'Swipe'");
-- Krethis the Shadowspinner SAI
SET @ENTRY := 12433;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,1784,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krethis the Shadowspinner - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,1784,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krethis the Shadowspinner - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,17000,20000,11,13884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krethis the Shadowspinner - In Combat - Cast 'Withering Poison'"),
(@ENTRY,0,3,0,9,0,100,0,0,30,12000,14500,11,12023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krethis the Shadowspinner - Within 0-30 Range - Cast 'Web'");
-- Loremaster Dibbs SAI
SET @ENTRY := 46061;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Loremaster Dibbs - In Combat - Cast 'Arcane Missiles'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,14000,16000,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loremaster Dibbs - Within 0-8 Range - Cast 'Arcane Explosion'"),
(@ENTRY,0,2,0,0,0,100,0,6000,8000,18000,20000,11,79880,0,0,0,0,0,2,0,0,0,0,0,0,0,"Loremaster Dibbs - In Combat - Cast 'Slow'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,21655,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loremaster Dibbs - Between 0-30% Health - Cast 'Blink' (No Repeat)"),
(@ENTRY,0,4,0,0,0,100,0,9000,12000,28000,32000,11,79868,0,0,0,0,0,2,0,0,0,0,0,0,0,"Loremaster Dibbs - In Combat - Cast 'Arcane Blast'");
-- Lost Son of Arugal SAI
SET @ENTRY := 47015;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,16000,20000,11,7124,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lost Son of Arugal - In Combat - Cast 'Arugal's Gift'");
-- Marsh Crocolisk SAI
SET @ENTRY := 45896;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,14000,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marsh Crocolisk - In Combat - Cast 'Powerful Bite'"),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,87228,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marsh Crocolisk - Between 0-40% Health - Cast 'Thick Hide' (No Repeat)");
-- Nightlash SAI
SET @ENTRY := 46981;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,28993,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nightlash - In Combat - Cast 'Banshee Wail'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,17000,18000,11,3485,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nightlash - Within 0-8 Range - Cast 'Wail of Nightlash'");
-- Phin Odelic SAI
SET @ENTRY := 46059;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Phin Odelic - In Combat - Cast 'Arcane Missiles'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,14000,16000,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phin Odelic - Within 0-8 Range - Cast 'Arcane Explosion'"),
(@ENTRY,0,2,0,0,0,100,0,6000,8000,18000,20000,11,79880,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phin Odelic - In Combat - Cast 'Slow'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,21655,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phin Odelic - Between 0-30% Health - Cast 'Blink' (No Repeat)"),
(@ENTRY,0,4,0,0,0,100,0,9000,12000,28000,32000,11,79868,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phin Odelic - In Combat - Cast 'Arcane Blast'");
-- Rabid Worg SAI
SET @ENTRY := 1766;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,22000,26000,11,3150,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Worg - In Combat - Cast 'Rabies'");
-- Skitterweb Lurker SAI
SET @ENTRY := 1781;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,18000,24000,11,82715,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skitterweb Lurker - In Combat - Cast 'Flee into the Shadows'");
-- Skitterweb Matriarch SAI
SET @ENTRY := 44906;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,87084,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skitterweb Matriarch - On Aggro - Cast 'Summon Spiderlings' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,15000,18000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skitterweb Matriarch - In Combat - Cast 'Venom Splash'");
-- Skitterweb Striker SAI
SET @ENTRY := 1780;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,9000,19000,20000,11,13884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skitterweb Striker - In Combat - Cast 'Withering Poison'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,14000,11,87081,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skitterweb Striker - Within 0-5 Range - Cast 'Strike'");
-- Thule Ravenclaw SAI
SET @ENTRY := 47023;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77721,64,0,0,0,0,2,0,0,0,0,0,0,0,"Thule Ravenclaw - In Combat - Cast 'Shadow Weave'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,31976,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thule Ravenclaw - Between 0-30% Health - Cast 'Shadow Shield' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,12000,33000,35000,11,7655,1,0,0,0,0,2,0,0,0,0,0,0,0,"Thule Ravenclaw - In Combat - Cast 'Hex of Ravenclaw'");
-- Vile Fin Oracle SAI
SET @ENTRY := 46573;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Oracle - In Combat - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Vile Fin Oracle SAI
SET @ENTRY := 1908;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Oracle - In Combat - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Vile Fin Tidehunter SAI
SET @ENTRY := 1768;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidehunter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,10,16000,19000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidehunter - Within 0-10 Range - Cast 'Splash'");
-- Vile Fin Tidehunter SAI
SET @ENTRY := 46574;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidehunter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,10,16000,19000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidehunter - Within 0-10 Range - Cast 'Splash'");
-- Worgen Commando SAI
SET @ENTRY := 45861;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,87603,64,0,0,0,0,2,0,0,0,0,0,0,0,"Worgen Commando - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,7000,8000,15000,20000,11,79721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Worgen Commando - In Combat - Cast 'Explosive Shot'"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,22000,25000,11,80003,0,0,0,0,0,2,0,0,0,0,0,0,0,"Worgen Commando - In Combat - Cast 'Black Arrow'");
-- Worgen Commando SAI
SET @ENTRY := 46038;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,87603,64,0,0,0,0,2,0,0,0,0,0,0,0,"Worgen Commando - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,7000,8000,15000,20000,11,79721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Worgen Commando - In Combat - Cast 'Explosive Shot'"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,22000,25000,11,80003,0,0,0,0,0,2,0,0,0,0,0,0,0,"Worgen Commando - In Combat - Cast 'Black Arrow'");
-- Worgen Sentry SAI
SET @ENTRY := 44987;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Worgen Sentry - On Aggro - Cast 'Battle Roar' (No Repeat)");
-- Bloodfang Berserker SAI
SET @ENTRY := 45860;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,63227,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfang Berserker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfang Berserker - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,18000,20000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfang Berserker - In Combat - Cast 'Slam'");
-- NPC talk text insert
SET @ENTRY := 45860;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Worgen Warbringer SAI
SET @ENTRY := 46037;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,63227,0,0,0,0,0,1,0,0,0,0,0,0,0,"Worgen Warbringer - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Worgen Warbringer - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,18000,20000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Worgen Warbringer - In Combat - Cast 'Slam'");
-- NPC talk text insert
SET @ENTRY := 46037;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
