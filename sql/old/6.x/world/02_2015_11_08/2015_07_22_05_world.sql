-- DB/SAI: Update Durotar

-- 1.
-- Armored Scorpid SAI
SET @ENTRY := 3126;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,24000,26000,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Armored Scorpid - Between 0-50% Health - Cast 'Harden'");

-- 2.
-- Bloodtalon Raptor SAI
SET @ENTRY := 37956;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodtalon Raptor - On Aggro - Cast 'Rushing Charge' (No Repeat)");

-- 3.
-- Bloodtalon Scythemaw SAI
SET @ENTRY := 3123;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodtalon Scythemaw - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4500,24000,25000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodtalon Scythemaw - In Combat - Cast 'Rend'");

-- 4.
-- Bloodtalon Taillasher SAI
SET @ENTRY := 3122;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodtalon Taillasher - On Aggro - Cast 'Rushing Charge' (No Repeat)");

-- 5.
-- Burning Blade Apprentice SAI
SET @ENTRY := 3198;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77721,64,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Apprentice - In Combat - Cast 'Shadow Weave'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,3000,5000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Out of Combat - Cast 'Summon Voidwalker' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,6000,8000,60000,65000,11,80174,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Apprentice - In Combat - Cast 'Felblood'");

-- 6.
-- Burning Blade Cultist SAI
SET @ENTRY := 3199;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79938,64,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Cultist - In Combat - Cast 'Incinerate'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Cultist - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,3000,5000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Cultist - Out of Combat - Cast 'Summon Imp' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,6000,8000,60000,65000,11,80174,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Cultist - In Combat - Cast 'Felblood'");

-- 7.
-- Burning Blade Fanatic SAI
SET @ENTRY := 3197;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,11000,16000,22000,11,5262,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Fanatic - In Combat - Cast 'Fanatic Blade'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,60000,65000,11,80174,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Fanatic - In Combat - Cast 'Felblood'");

-- 8.
-- Burning Blade Neophyte SAI
SET @ENTRY := 3196;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79932,64,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Neophyte - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Neophyte - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79954,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Neophyte - Out of Combat - Cast 'Fel Armor'"),
(@ENTRY,0,3,0,0,0,100,0,6000,8000,60000,65000,11,80174,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Neophyte - In Combat - Cast 'Felblood'");

-- 9.
-- Burning Blade Thug SAI
SET @ENTRY := 3195;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,15000,18000,11,80146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Thug - In Combat - Cast 'Bonk'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,60000,65000,11,80174,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Thug - In Combat - Cast 'Felblood'"),
(@ENTRY,0,2,0,0,0,100,0,2000,4000,25000,26000,11,80182,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Thug - In Combat - Cast 'Uppercut'");

-- 10.
-- Captain Flat Tusk SAI
SET @ENTRY := 5824;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Flat Tusk - On Respawn - Cast 'Razor Mane' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,12000,11,77558,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Flat Tusk - Within 0-5 Range - Cast 'Bloody Strike'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Flat Tusk - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,79733,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Flat Tusk - On Aggro - Cast 'Commanding Shout' (No Repeat)");

-- 12.
-- Clattering Scorpid SAI
SET @ENTRY := 3125;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,32000,38000,11,79687,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clattering Scorpid - In Combat - Cast 'Sundering Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,2000,9000,15000,24000,11,73672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clattering Scorpid - In Combat - Cast 'Envenom'");

-- 13.
-- Corrupted Bloodtalon SAI
SET @ENTRY := 37961;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corrupted Bloodtalon - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,25000,26000,11,79774,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Bloodtalon - In Combat - Cast 'Corrupted'");

-- 14.
-- Darkspear Shaman SAI
SET @ENTRY := 38326;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,73212,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Shaman - In Combat - Cast 'Lightning Bolt'");

-- 15.
-- Darkspear Watcher SAI
SET @ENTRY := 38217;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Watcher - In Combat - Cast 'Shoot'");

-- 16.
-- Death Flayer SAI
SET @ENTRY := 5823;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,24000,26000,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Flayer - Between 0-50% Health - Cast 'Harden'"),
(@ENTRY,0,1,0,0,0,100,0,3500,4500,15000,24000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Flayer - In Combat - Cast 'Venom Splash'");

-- 17.
-- Den Grunt SAI
SET @ENTRY := 5952;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Den Grunt - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Den Grunt - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Den Grunt - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 5952;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 18.
-- Dire Mottled Boar SAI
SET @ENTRY := 3099;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dire Mottled Boar - On Aggro - Cast 'Rushing Charge' (No Repeat)");

-- 19.
-- Dreadmaw Crocolisk SAI
SET @ENTRY := 3110;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,16000,11,12166,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaw Crocolisk - Within 0-5 Range - Cast 'Muscle Tear'");

-- 20.
-- Dreadmaw Toothgnasher SAI
SET @ENTRY := 39452;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,16000,11,12166,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaw Toothgnasher - Within 0-5 Range - Cast 'Muscle Tear'");

-- 21.
-- Drowned Thunder Lizard SAI
SET @ENTRY := 39464;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,22000,25000,11,73958,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drowned Thunder Lizard - In Combat - Cast 'Lightning Discharge'");

-- 22.
-- Dustwind Harpy SAI
SET @ENTRY := 3115;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Harpy - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,12000,19000,11,77522,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwind Harpy - In Combat - Cast 'Swoop'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,13000,24000,11,80215,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Harpy - Between 0-50% Health - Cast 'Dustwind'");

-- 23.
-- Dustwind Pillager SAI
SET @ENTRY := 3116;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Pillager - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,11000,18000,24000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwind Pillager - In Combat - Cast 'Rend Flesh'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,13000,24000,11,80215,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Pillager - Between 0-50% Health - Cast 'Dustwind'");

-- 24.
-- Dustwind Savage SAI
SET @ENTRY := 3117;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Savage - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,18000,22000,11,75930,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwind Savage - In Combat - Cast 'Mangle'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,13000,24000,11,80215,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Savage - Between 0-50% Health - Cast 'Dustwind'");

-- 25.
-- Dustwind Storm Witch SAI
SET @ENTRY := 3118;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77160,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwind Storm Witch - In Combat - Cast 'Nimbus Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,0,0,50,13000,24000,11,80215,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 0-50% Health - Cast 'Dustwind'"),
(@ENTRY,0,3,0,0,0,100,0,7000,9000,24000,26000,11,12058,0,0,0,0,0,4,0,0,0,0,0,0,0,"Dustwind Storm Witch - In Combat - Cast 'Chain Lightning'");

-- 26.
-- Elder Mottled Boar SAI
SET @ENTRY := 3100;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,3385,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Mottled Boar - On Aggro - Cast 'Boar Charge' (No Repeat)");

-- 27.
-- Encrusted Surf Crawler SAI
SET @ENTRY := 3108;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,24000,26000,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Encrusted Surf Crawler - Between 0-50% Health - Cast 'Harden'");

-- 28.
-- Felstalker SAI
SET @ENTRY := 3102;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,18000,24000,11,79616,0,0,0,0,0,2,1,0,0,0,0,0,0,"Felstalker - Between 0-40% Health - Cast 'Drain Life'");

-- 29.
-- Felweaver Scornn SAI
SET @ENTRY := 5822;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,3000,5000,0,0,11,30842,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Out of Combat - Cast 'Summon Felhunter' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79934,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Out of Combat - Cast 'Demon Armor'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,16000,23000,11,79933,0,0,0,0,0,2,1,0,0,0,0,0,0,"Felweaver Scornn - Between 0-40% Health - Cast 'Drain Life'");

-- 30.
-- Foaming Sea Elemental SAI
SET @ENTRY := 39272;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,32011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foaming Sea Elemental - In Combat - Cast 'Water Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,24000,27000,11,79831,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foaming Sea Elemental - In Combat - Cast 'Wave Crash'");

-- 31.
-- Furious Earthguard SAI
SET @ENTRY := 39595;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,16000,18000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,"Furious Earthguard - In Combat - Cast 'Earth Spike'");

-- 32.
-- Gaur Icehorn SAI
SET @ENTRY := 39352;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,76423,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gaur Icehorn - Between 0-30% Health - Cast 'Taunka Rage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gaur Icehorn - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 39352;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Taunka Rage',10677);

-- 33.
-- Gazz'uz SAI
SET @ENTRY := 3204;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gazz'uz - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,20798,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Out of Combat - Cast 'Demon Skin'"),
(@ENTRY,0,3,0,0,0,100,0,12000,18000,25000,35000,11,172,0,0,0,0,0,4,0,0,0,0,0,0,0,"Gazz'uz - In Combat - Cast 'Corruption'");

-- 34.
-- Geolord Mottle SAI
SET @ENTRY := 5826;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,16000,18000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,"Geolord Mottle - In Combat - Cast 'Earth Spike'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79927,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geolord Mottle - Out of Combat - Cast 'Earth Shield'");

-- 35.
-- Ghislania SAI
SET @ENTRY := 39351;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,76429,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ghislania - In Combat - Cast 'Static Burst'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,19000,21000,11,79913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghislania - In Combat - Cast 'Chain Lightning'");

-- 36.
-- Griswold Hanniston SAI
SET @ENTRY := 39353;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Griswold Hanniston - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,22000,26000,11,76490,0,0,0,0,0,1,0,0,0,0,0,0,0,"Griswold Hanniston - In Combat - Cast 'Flurry of Claws'");

-- NPC talk text insert
SET @ENTRY := 39353;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'What''s the matter, chum... never seen a worgen before?',12,0,100,0,0,0, 'on Aggro Text',39521);

-- 37.
-- Kor'kron Deathbringer SAI
SET @ENTRY := 42946;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,77808,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Deathbringer - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4500,6500,15400,19200,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Deathbringer - In Combat - Cast 'Cleave'");

-- 38.
-- Mature Surf Crawler SAI
SET @ENTRY := 3107;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,17000,22000,11,78744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mature Surf Crawler - In Combat - Cast 'Bubblebeam'");

-- 39.
-- Mottled Boar SAI
SET @ENTRY := 3098;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,79581,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mottled Boar - In Combat - Cast 'Angry Snort'");

-- 40.
-- Naj'tess SAI
SET @ENTRY := 39072;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,24000,32000,11,79782,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naj'tess - In Combat - Cast 'Orb of Corruption'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,34000,38000,11,73424,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naj'tess - In Combat - Cast 'Shrink'");

-- 41.
-- Northwatch Infantryman SAI
SET @ENTRY := 39260;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,14000,15000,11,78826,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Infantryman - Between 0-40% Health - Cast 'Evasion'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,78894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Infantryman - On Aggro - Cast 'Leaping Cleave' (No Repeat)");

-- 42.
-- Northwatch Lug SAI
SET @ENTRY := 39245;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,14000,17000,11,75356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Lug - In Combat - Cast 'Fisticuffs'");

-- 43.
-- Northwatch Lug SAI
SET @ENTRY := 39249;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,14000,17000,11,75356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Lug - In Combat - Cast 'Fisticuffs'");

-- 44.
-- Northwatch Marine SAI
SET @ENTRY := 39267;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,18000,19000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Marine - In Combat - Cast 'Hamstring'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,22000,27000,11,79726,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Marine - In Combat - Cast 'Ticking Time Bomb'");

-- 45.
-- Ticking Time Bomb SAI
SET @ENTRY := 42776;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,11,79728,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ticking Time Bomb - On Respawn - Cast 'Explosion' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ticking Time Bomb - On Respawn - Despawn In 3000 ms (No Repeat)");

-- 46.
-- Northwatch Ranger SAI
SET @ENTRY := 39261;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Ranger - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,5,30,15000,18000,11,78754,1,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Ranger - Within 5-30 Range - Cast 'Arcane Shot'"),
(@ENTRY,0,2,5,9,0,100,0,0,10,60000,65000,11,78578,1,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Ranger - Within 0-10 Range - Cast 'Immolation Trap'");

-- 47.
-- Northwatch Scout SAI
SET @ENTRY := 39317;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Scout - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Scout - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Scout - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,3,5,9,0,100,0,0,10,15000,22000,11,79584,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Scout - Within 0-10 Range - Cast 'Fan of Knives'");

-- 48.
-- Northwatch Sharpshooter SAI
SET @ENTRY := 39268;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Sharpshooter - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,5,30,18000,21000,11,79721,1,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Sharpshooter - Within 5-30 Range - Cast 'Explosive Shot'"),
(@ENTRY,0,2,5,9,0,100,0,5,30,35000,45000,11,79719,1,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Sharpshooter - Within 5-30 Range - Cast 'Pinpoint'");

-- 49.
-- Pygmy Surf Crawler SAI
SET @ENTRY := 39004;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,19000,11,79765,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pygmy Surf Crawler - In Combat - Cast 'Bubble Blast'");

-- 50.
-- Raider Jhash SAI
SET @ENTRY := 10676;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raider Jhash - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,20,7000,9000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raider Jhash - Within 0-20 Range - Cast 'Net'");

-- 51.
-- Razor Hill Grunt SAI
SET @ENTRY := 5953;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Razor Hill Grunt - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razor Hill Grunt - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razor Hill Grunt - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,5,9,0,100,0,0,5,14000,19000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razor Hill Grunt - Within 0-5 Range - Cast 'Cleave'");

-- NPC talk text insert
SET @ENTRY := 5953;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 52.
-- Razormane Battleguard SAI
SET @ENTRY := 3114;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Battleguard - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,300000,300000,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Battleguard - Out of Combat - Cast 'Razor Mane'"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,25000,31000,11,77558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Battleguard - In Combat - Cast 'Bloody Strike'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Battleguard - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Battleguard - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3114;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 53.
-- Razormane Dustrunner SAI
SET @ENTRY := 3113;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Dustrunner - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Dustrunner - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,300000,300000,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Dustrunner - Out of Combat - Cast 'Razor Mane'"),
(@ENTRY,0,3,0,0,0,100,0,6000,8000,27000,33000,11,6950,1,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Dustrunner - In Combat - Cast 'Faerie Fire'");

-- 54.
-- Razormane Quilboar SAI
SET @ENTRY := 3111;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,17000,24500,11,80146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Quilboar - In Combat - Cast 'Bonk'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,300000,300000,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Quilboar - Out of Combat - Cast 'Razor Mane'");

-- 55.
-- Razormane Scout SAI
SET @ENTRY := 3112;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80149,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Scout - On Aggro - Cast 'Throw Axe' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,300000,300000,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Out of Combat - Cast 'Razor Mane'");

-- 56.
-- Sarkoth SAI
SET @ENTRY := 3281;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,18000,25000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sarkoth - In Combat - Cast 'Venom Splash'");

-- 57.
-- Scorpid Worker SAI
SET @ENTRY := 3124;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,18500,24900,11,6751,32,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpid Worker - In Combat - Cast 'Weak Poison'");

-- 58.
-- Screamslash SAI
SET @ENTRY := 39385;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screamslash - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,24000,26000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Screamslash - In Combat - Cast 'Rend'");

-- 59.
-- Sen'jin Watcher SAI
SET @ENTRY := 3297;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sen'jin Watcher - In Combat - Cast 'Shoot'");

-- 60.
-- Sergeant Curtis SAI
SET @ENTRY := 5809;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,78894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sergeant Curtis - On Aggro - Cast 'Leaping Cleave' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,22000,27000,11,79726,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sergeant Curtis - In Combat - Cast 'Ticking Time Bomb'");

-- 61.
-- Spitescale Siren SAI
SET @ENTRY := 38301;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32011,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitescale Siren - In Combat - Cast 'Water Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,22000,24000,11,15117,1,0,0,0,0,4,0,0,0,0,0,0,0,"Spitescale Siren - In Combat - Cast 'Chain Lightning'");

-- 62.
-- Spitescale Wavethrasher SAI
SET @ENTRY := 38300;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,17000,23000,11,79810,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitescale Wavethrasher - In Combat - Cast 'Frost Cleave'");

-- 63.
-- Surf Crawler SAI
SET @ENTRY := 3106;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,17000,22000,11,78744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Surf Crawler - In Combat - Cast 'Bubblebeam'");

-- 64.
-- Swollen Voidwalker SAI
SET @ENTRY := 39603;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,19000,25000,11,80132,0,0,0,0,0,2,0,0,0,0,0,0,0,"Swollen Voidwalker - In Combat - Cast 'Unbound Darkness'");

-- 65.
-- Teeming Waterguard SAI
SET @ENTRY := 39596;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,24000,26000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teeming Waterguard - In Combat - Cast 'Splash'");

-- 66.
-- Venomtail Scorpid SAI
SET @ENTRY := 3127;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,15000,24000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venomtail Scorpid - In Combat - Cast 'Venom Splash'");

-- 67.
-- Vile Familiar SAI
SET @ENTRY := 3101;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,11921,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Familiar - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 68.
-- Wayward Plainstrider SAI
SET @ENTRY := 39337;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wayward Plainstrider - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,1,2000,3000,0,0,11,73757,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wayward Plainstrider - Out of Combat - Cast 'Water Walk' (No Repeat)");

-- 69.
-- Wildmane Cat SAI
SET @ENTRY := 38046;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildmane Cat - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,18000,22000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildmane Cat - In Combat - Cast 'Swipe'"),
(@ENTRY,0,2,0,1,0,30,0,45000,55000,120000,300000,11,71232,0,0,0,0,0,9,38141,8,25,0,0,0,0,"Wildmane Cat - Out of Combat - Cast 'Wild Pounce'");

-- 70.
-- Yarrog Baneshadow SAI
SET @ENTRY := 3183;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,35913,64,0,0,0,0,2,0,0,0,0,0,0,0,"Yarrog Baneshadow - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,"Yarrog Baneshadow - Out of Combat - Cast 'Shadow Channelling' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,12000,22000,29000,11,37628,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yarrog Baneshadow - In Combat - Cast 'Fel Immolate'");

-- 71.
-- Docile Island Boar SAI
SET @ENTRY := 38141;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,71232,0,1000,2000,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Docile Island Boar - On Spellhit 'Wild Pounce' - Kill Self"),
(@ENTRY,0,1,0,61,0,100,0,71232,0,1000,2000,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Docile Island Boar - On Spellhit 'Wild Pounce' - Despawn In 2000 ms");
