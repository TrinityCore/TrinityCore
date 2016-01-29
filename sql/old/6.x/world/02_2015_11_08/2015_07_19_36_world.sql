-- Zul'Farrak
-- 1.
-- Chief Ukorz Sandscalp SAI
SET @ENTRY := 7267;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12000,16000,7500,24500,11,11837,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - In Combat - Cast 'Wide Slash'"),
(@ENTRY,0,1,0,0,0,100,0,6000,20000,8500,19500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - In Combat - Cast 'Cleave'"),
(@ENTRY,0,2,0,5,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - On Killed Unit - Say Line 0"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - Between 0-30% Health - Say Line 1 (No Repeat)"),
(@ENTRY,0,5,0,2,0,100,1,0,60,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - Between 0-60% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,6,0,2,0,100,1,0,60,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - Between 0-60% Health - Say Line 2 (No Repeat)"),
(@ENTRY,0,7,0,4,0,100,1,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Ukorz Sandscalp - On Aggro - Say Line 3 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 7267;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Die, outlander!',14,0,100,0,0,5877, 'combat Text', 6226),
(@ENTRY,1,0, 'Feel the fury of the sands!',14,0,100,0,0,5879, 'combat Text', 6227),
(@ENTRY,2,0, 'The Sandfury reign supreme!',14,0,100,0,0,5878, 'combat Text', 6228),
(@ENTRY,3,0, 'This desert be mine!',14,0,100,0,0,5876, 'combat Text', 6225);

-- 2.
-- Dustwraith SAI
SET @ENTRY := 10081;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,3600,7300,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwraith - Within 0-5 Range - Cast 'Sinister Strike'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,17000,18000,11,12251,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwraith - In Combat - Cast 'Virulent Poison'");

-- 3.
-- Gahz'rilla SAI
SET @ENTRY := 7273;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,21000,22000,23000,11,11836,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gahz'rilla - In Combat - Cast 'Freeze Solid'"),
(@ENTRY,0,1,0,0,0,100,0,27000,31000,16000,28000,11,11902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gahz'rilla - In Combat - Cast 'Gahz'rilla Slam'"),
(@ENTRY,0,2,0,0,0,100,0,8500,36000,8500,27000,11,11131,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gahz'rilla - In Combat - Cast 'Icicle'");

-- 4.
-- Hydromancer Velratha SAI
SET @ENTRY := 7795;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,78801,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hydromancer Velratha - In Combat - Cast 'Water Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,12491,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hydromancer Velratha - Between 0-50% Health - Cast 'Healing Wave' (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,20,14000,16000,11,78802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hydromancer Velratha - Within 0-20 Range - Cast 'Crashing Wave'");

-- 5.
-- Nekrum Gutchewer SAI
SET @ENTRY := 7796;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6500,16500,16900,21500,11,8600,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nekrum Gutchewer - In Combat - Cast 'Fevered Plague'");

-- 6.
-- Ruuzlu SAI
SET @ENTRY := 7797;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,12,0,100,0,20,20,30000,30000,11,77720,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ruuzlu - Target Between 20-20% Health - Cast 'Execute'"),
(@ENTRY,0,1,0,0,0,100,0,8000,13000,7500,18500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ruuzlu - In Combat - Cast 'Cleave'");

-- 7.
-- Sandfury Executioner SAI
SET @ENTRY := 7274;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Executioner - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,8000,13000,8000,23000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Executioner - In Combat - Cast 'Cleave'"),
(@ENTRY,0,2,0,5,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Executioner - On Killed Unit - Say Line 1");

-- NPC talk text insert
SET @ENTRY := 7274;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Let the executions begin!',14,0,100,0,0,5874, 'combat Say', 6223),
(@ENTRY,1,0, 'Justice is done!',14,0,100,0,0,5875, 'combat Say', 6224);

-- 8.
-- Theka the Martyr SAI
SET @ENTRY := 7272;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,11089,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theka the Martyr - Between 0-30% Health - Cast 'Theka Transform' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,15700,18800,10900,22900,11,8600,0,0,0,0,0,2,0,0,0,0,0,0,0,"Theka the Martyr - In Combat - Cast 'Fevered Plague'");

-- 9.
-- Zerillis SAI
SET @ENTRY := 10082;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Zerillis - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,12000,25000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zerillis - Within 0-20 Range - Cast 'Net'"),
(@ENTRY,0,2,0,0,0,100,0,6000,11000,5800,16000,11,12551,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zerillis - In Combat - Cast 'Frost Shot'");

-- 10.
-- Sandarr Dunereaver SAI
SET @ENTRY := 10080;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,16000,26000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandarr Dunereaver - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,1,0,0,0,100,0,6000,12000,25000,34000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandarr Dunereaver - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,2,0,0,0,100,0,10000,20000,15000,24000,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandarr Dunereaver - In Combat - Cast 'Pummel'");

-- 11.
-- Shadowpriest Sezz'ziz SAI
SET @ENTRY := 7275;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowpriest Sezz'ziz - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,11000,16000,22000,32000,11,13704,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpriest Sezz'ziz - In Combat - Cast 'Psychic Scream'"),
(@ENTRY,0,2,0,14,0,100,0,2000,40,27800,34200,11,8362,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowpriest Sezz'ziz - Friendly At 2000 Health - Cast 'Renew'"),
(@ENTRY,0,3,0,14,0,100,0,3000,40,14200,25300,11,12039,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowpriest Sezz'ziz - Friendly At 3000 Health - Cast 'Heal'"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,11,8362,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpriest Sezz'ziz - Between 0-30% Health - Cast 'Renew' (No Repeat)");
