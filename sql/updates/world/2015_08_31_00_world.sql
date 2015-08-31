-- Feathermoon Archer SAI
SET @ENTRY := 40360;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Feathermoon Archer - In Combat CMC - Cast 'Shoot'");

-- Horde Poacher SAI
SET @ENTRY := 40069;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Poacher - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,15000,18000,11,78841,1,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Poacher - Within 5-30 Range - Cast 'Aimed Shot'"),
(@ENTRY,0,2,0,9,0,100,0,0,20,8000,9000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Poacher - Within 0-20 Range - Cast 'Net'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Poacher - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Feralas Sentinel SAI
SET @ENTRY := 39972;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,74613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Feralas Sentinel - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,11000,11,15496,1,0,0,0,0,2,0,0,0,0,0,0,0,"Feralas Sentinel - Within 0-5 Range - Cast 'Cleave'");

-- Gordunni Channeler SAI
SET @ENTRY := 39965;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,3000,4500,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Channeler - In Combat CMC - Cast 'Arcane Missiles'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,22000,25000,11,79860,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Channeler - In Combat - Cast 'Blizzard'"),
(@ENTRY,0,2,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Channeler - On Aggro - Say Line 0 (No Repeat)");

-- Caryssia Moonhunter SAI
SET @ENTRY := 39946;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Caryssia Moonhunter - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,0,5,9000,11000,11,40505,1,0,0,0,0,2,0,0,0,0,0,0,0,"Caryssia Moonhunter - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,35000,36000,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Caryssia Moonhunter - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,3,0,0,0,100,0,6000,9000,120000,125000,11,32064,1,0,0,0,0,1,0,0,0,0,0,0,0,"Caryssia Moonhunter - In Combat - Cast 'Battle Shout'"),
(@ENTRY,0,4,0,11,0,100,1,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caryssia Moonhunter - On Respawn - Cast 'Battle Stance' (No Repeat)");
