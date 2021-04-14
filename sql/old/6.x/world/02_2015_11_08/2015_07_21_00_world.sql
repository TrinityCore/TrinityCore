-- Azuremyst Isle Update
-- 1
-- Aberrant Owlbeast SAI
SET @ENTRY := 17187;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,8000,15800,11,31270,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aberrant Owlbeast - In Combat - Cast 'Moonfire'");

-- 2
-- Barbed Crawler SAI
SET @ENTRY := 17217;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,500,1000,600000,600000,11,31271,1,0,0,0,0,1,0,0,0,0,0,0,0,"Barbed Crawler - In Combat - Cast 'Thorns'");

-- 3
-- Blood Elf Bandit SAI
SET @ENTRY := 17591;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,75,5916,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Bandit - On Reset - Add Aura 'Shadowstalker Stealth' (No Repeat)"),
(@ENTRY,0,1,0,4,0,75,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Bandit - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,5000,8000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Elf Bandit - Within 0-5 Range - Cast 'Sinister Strike'"),
(@ENTRY,0,3,0,67,0,100,0,9000,14000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Elf Bandit - On Behind Target - Cast 'Backstab'"),
(@ENTRY,0,4,0,0,0,100,0,9000,14000,16000,21000,11,15691,1,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Elf Bandit - In Combat - Cast 'Eviscerate'");

-- 4
-- Blood Elf Scout SAI
SET @ENTRY := 16521;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Scout - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,4000,9000,30000,30000,11,25602,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Elf Scout - In Combat - Cast 'Faerie Fire'");

-- 5
-- Bristlelimb Windcaller SAI
SET @ENTRY := 17184;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,16000,21000,11,31272,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bristlelimb Windcaller - In Combat - Cast 'Wind Shock'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,20000,30000,11,32131,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bristlelimb Windcaller - Between 0-30% Health - Cast 'Rejuvenation'");

-- 6
-- Chieftain Oomooroo SAI
SET @ENTRY := 17448;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,6000,9000,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chieftain Oomooroo - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,18501,1,0,0,0,0,1,0,0,0,0,0,0,0,"Chieftain Oomooroo - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chieftain Oomooroo - Between 0-30% Health - Say Line 0 (No Repeat)");
-- Creature Text
SET @ENTRY := 17448;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
insert into `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) values
(@ENTRY,0,0,'%s becomes enraged!',16,0,100,0,0,0,10677,0,'Chieftain Oomooroo');

-- 7
-- Quel'dorei Magewraith SAI
SET @ENTRY := 17612;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,11921,64,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'dorei Magewraith - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,0,40,9000,13000,11,31595,64,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'dorei Magewraith - In Combat - Cast 'Arcane Bolt'"),
(@ENTRY,0,2,0,13,0,100,0,9000,11000,0,0,11,31596,64,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'dorei Magewraith - On Victim Casting - Cast 'Counterspell'"),
(@ENTRY,0,3,0,6,0,100,0,0,0,0,0,11,30790,3,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'dorei Magewraith - On Just Died - Cast 'Arcane Domination'"),
(@ENTRY,0,4,0,6,0,100,1,0,0,0,0,15,9595,0,0,0,0,0,16,0,0,0,0,0,0,0,"Quel'dorei Magewraith - On Just Died - Quest Credit '' (No Repeat)");

-- 8
-- Siltfin Hunter SAI
SET @ENTRY := 17192;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Siltfin Hunter - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Siltfin Hunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 9
-- Siltfin Oracle SAI
SET @ENTRY := 17191;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Siltfin Oracle - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Siltfin Oracle - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,3,0,16,0,100,0,12550,1,15000,30000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'");

-- 10
-- Stillpine Hunter SAI
SET @ENTRY := 17439;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stillpine Hunter - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 11
-- Stillpine Raider SAI
SET @ENTRY := 17495;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,11000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stillpine Raider - Within 0-5 Range - Cast 'Heroic Strike'");

-- 12
-- Surveyor Candress SAI
SET @ENTRY := 16522;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Surveyor Candress - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,4,0,61,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Surveyor Candress - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,25,0,100,0,0,0,0,0,11,31515,1,0,0,0,0,1,0,0,0,0,0,0,0,"Surveyor Candress - On Reset - Cast 'Red Beam'");
