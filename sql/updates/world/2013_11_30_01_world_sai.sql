-- Earthen Stoneguard SAI
SET @ENTRY := 29960;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,9,0,100,1,0,20,11000,16000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Stoneguard - Between 0-20 Range - Cast 12024"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - Between 0-20 Range - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,45,2300,3900,11,23337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Stoneguard - Between 5-45 Range - Cast 23337 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - Between 5-45 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - Between 35-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stoneguard - On Evade - Set Sheath Melee");

-- Dragonflayer Strategist SAI
SET @ENTRY := 23956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,42772,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Strategist - On Aggro - Cast 42772 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,5,30,2300,5000,11,42772,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Strategist - Between 5-30 Range - Cast 42772 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,59685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Strategist - On Aggro - Cast 59685 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,0,100,4,5,30,2300,5000,11,59685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Strategist - Between 5-30 Range - Cast 59685 (Heroic Dungeon)"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,10,11,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,12,13,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,15,16,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,17,0,0,0,100,2,4500,5000,11000,16000,11,54962,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Strategist - In Combat - Cast 54962 (Normal Dungeon)"),
(@ENTRY,0,18,0,0,0,100,4,4500,5000,11000,16000,11,60227,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Strategist - In Combat - Cast 60227 (Heroic Dungeon)"),
(@ENTRY,0,19,0,0,0,100,6,7500,9000,13000,15000,11,42972,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Strategist - In Combat - Cast 42972 (Dungeon Only)"),
(@ENTRY,0,20,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Strategist - On Evade - Set Sheath Melee (Dungeon Only)");

-- Proto-Drake Handler SAI
SET @ENTRY := 24082;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,54983,0,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Handler - On Aggro - Cast 54983 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,8,25,2300,5000,11,54983,0,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Handler - Between 8-25 Range - Cast 54983 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - Between 8-25 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,59696,0,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Handler - On Aggro - Cast 59696 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,0,100,4,8,25,2300,5000,11,59696,0,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Handler - Between 8-25 Range - Cast 59696 (Heroic Dungeon)"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - Between 8-25 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,10,11,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,12,13,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,15,16,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,17,0,0,0,100,2,2000,3000,8000,9500,11,38621,1,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Handler - In Combat - Cast 38621 (Normal Dungeon)"),
(@ENTRY,0,18,0,0,0,100,4,2000,3000,8000,9500,11,59695,1,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Handler - In Combat - Cast 59695 (Heroic Dungeon)"),
(@ENTRY,0,19,0,16,0,100,2,43664,100,15000,21000,11,43664,32,0,0,0,0,7,0,0,0,0,0,0,0,"Proto-Drake Handler - On Friendly Unit Missing Buff _spellNameFirstParam_ - Cast 43664 (Normal Dungeon)"),
(@ENTRY,0,20,0,16,0,100,4,59694,100,15000,21000,11,59694,32,0,0,0,0,7,0,0,0,0,0,0,0,"Proto-Drake Handler - On Friendly Unit Missing Buff _spellNameFirstParam_ - Cast 59694 (Heroic Dungeon)"),
(@ENTRY,0,21,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Handler - On Evade - Set Sheath Melee (Dungeon Only)");

-- Proto-Drake Rider SAI
SET @ENTRY := 24849;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,43665,0,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Rider - On Aggro - Cast 43665 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,1,100,2,5,30,9000,17000,11,43665,0,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Rider - Between 5-30 Range - Cast 43665 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,59603,0,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Rider - On Aggro - Cast 59603 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,1,100,4,5,30,9000,17000,11,59603,0,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Rider - Between 5-30 Range - Cast 59603 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - Between 25-80 Range - Start Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,14,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - Between 0-5 Range - Set Sheath Melee (Dungeon Only) (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - Between 0-5 Range - Start Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - Between 5-15 Range - Stop Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,17,0,0,0,100,2,6000,7500,11000,17000,11,31551,1,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Rider - In Combat - Cast 31551 (Normal Dungeon)"),
(@ENTRY,0,18,0,0,0,100,4,6000,7500,11000,17000,11,59605,1,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Rider - In Combat - Cast 59605 (Heroic Dungeon)"),
(@ENTRY,0,19,0,0,0,100,2,3000,4500,9000,12500,11,32908,1,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Rider - In Combat - Cast 32908 (Normal Dungeon)"),
(@ENTRY,0,20,0,0,0,100,4,3000,4500,9000,12500,11,59604,1,0,0,0,0,2,0,0,0,0,0,0,0,"Proto-Drake Rider - In Combat - Cast 59604 (Heroic Dungeon)"),
(@ENTRY,0,21,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Proto-Drake Rider - On Evade - Set Sheath Melee (Dungeon Only)");

-- Risen Drakkari Handler SAI
SET @ENTRY := 26637;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,0,0,100,7,500,500,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - In Combat - Dismount (Dungeon Only)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,51224,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - In Combat - Summon Creature Drakkari Raptor Mount (Dungeon Only)"),
(@ENTRY,0,4,5,4,0,100,3,0,0,0,0,11,49712,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Handler - On Aggro - Cast 49712 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,6,7,9,0,100,2,5,30,2300,5000,11,49712,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Handler - Between 5-30 Range - Cast 49712 (Normal Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,8,9,4,0,100,5,0,0,0,0,11,59001,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Handler - On Aggro - Cast 59001 (Heroic Dungeon)"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,10,11,9,0,100,4,5,30,2300,5000,11,59001,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Handler - Between 5-30 Range - Cast 59001 (Heroic Dungeon)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,12,13,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,14,15,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,17,18,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,19,0,0,0,100,6,0,0,6000,9000,11,49711,0,0,0,0,0,5,0,0,0,0,0,0,0,"Risen Drakkari Handler - In Combat - Cast 49711 (Dungeon Only)"),
(@ENTRY,0,20,0,0,0,100,6,7000,11000,8000,12000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Handler - In Combat - Cast 6253 (Dungeon Only)"),
(@ENTRY,0,21,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Handler - On Evade - Set Sheath Melee (Dungeon Only)");

-- Horde Ranger SAI
SET @ENTRY := 26801;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - On Aggro - Remove Aura 47543 (Dungeon Only)"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Ranger - On Aggro - Cast 15620 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,6,9,0,100,2,5,30,2300,3800,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Ranger - Between 5-30 Range - Cast 15620 (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,7,8,4,0,100,5,0,0,0,0,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Ranger - On Aggro - Cast 22907 (Heroic Dungeon)"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,9,10,9,0,100,4,5,30,2300,3800,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Ranger - Between 5-30 Range - Cast 22907 (Heroic Dungeon)"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,11,12,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,13,14,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,16,17,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,18,19,9,0,100,2,5,45,9500,10000,11,47777,1,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Ranger - Between 5-45 Range - Cast 47777 (Normal Dungeon)"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Between 5-45 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,20,21,9,0,100,4,5,45,9500,10000,11,56933,1,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Ranger - Between 5-45 Range - Cast 56933 (Heroic Dungeon)"),
(@ENTRY,0,21,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - Between 5-45 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,22,0,0,0,100,6,12000,15000,16100,19000,11,48191,5,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - In Combat - Cast 48191 (Dungeon Only)"),
(@ENTRY,0,23,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Ranger - On Evade - Set Sheath Melee (Dungeon Only)");

-- Azure Inquisitor SAI
SET @ENTRY := 27633;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,51454,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Inquisitor - On Aggro - Cast 51454 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,1,100,2,5,30,5000,7000,11,51454,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Inquisitor - Between 5-30 Range - Cast 51454 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,59209,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Inquisitor - On Aggro - Cast 59209 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,1,100,4,5,30,5000,7000,11,59209,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Inquisitor - Between 5-30 Range - Cast 59209 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Between 25-80 Range - Start Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,14,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Between 0-5 Range - Set Sheath Melee (Dungeon Only) (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Between 0-5 Range - Start Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Between 5-15 Range - Stop Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,17,0,0,0,100,6,4000,7000,9000,12000,11,50573,1,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Inquisitor - In Combat - Cast 50573 (Dungeon Only)"),
(@ENTRY,0,18,0,9,0,100,6,0,10,14000,20000,11,50690,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - Between 0-10 Range - Cast 50690 (Dungeon Only)"),
(@ENTRY,0,19,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Inquisitor - On Evade - Set Sheath Melee (Dungeon Only)");

-- Don Carlos SAI
SET @ENTRY := 28132;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,0,1,0,100,7,1000,1000,0,0,11,50736,1,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Out Of Combat - Cast 50736 (Dungeon Only)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Don Carlos - On Aggro - Cast 16100 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,6,9,0,100,2,5,30,2300,5000,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Don Carlos - Between 5-30 Range - Cast 16100 (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,7,8,4,0,100,5,0,0,0,0,11,16496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Don Carlos - On Aggro - Cast 16496 (Heroic Dungeon)"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,9,10,9,0,100,4,5,30,2300,5000,11,16496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Don Carlos - Between 5-30 Range - Cast 16496 (Heroic Dungeon)"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,11,12,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,13,14,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,16,17,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,18,0,0,0,100,2,9000,14000,22000,26000,11,12024,1,0,0,0,0,5,0,0,0,0,0,0,0,"Don Carlos - In Combat - Cast 12024 (Normal Dungeon)"),
(@ENTRY,0,19,0,0,0,100,4,9000,14000,22000,26000,11,50762,1,0,0,0,0,5,0,0,0,0,0,0,0,"Don Carlos - In Combat - Cast 50762 (Heroic Dungeon)"),
(@ENTRY,0,20,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - On Evade - Set Sheath Melee (Dungeon Only)");

-- Dark Necromancer SAI
SET @ENTRY := 28200;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Necromancer - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - On Aggro - Cast 15537 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Necromancer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,5000,7000,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - Between 0-40 Range - Cast 15537 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,61558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - On Aggro - Cast 61558 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Necromancer - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,5000,7000,11,61558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - Between 0-40 Range - Cast 61558 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Necromancer - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Necromancer - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Necromancer - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Necromancer - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Necromancer - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Necromancer - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,2,7000,11000,21000,25000,11,20812,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - In Combat - Cast 20812 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,7000,11000,21000,25000,11,52498,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - In Combat - Cast 52498 (Heroic Dungeon)"),
(@ENTRY,0,15,0,0,0,100,2,14000,18000,15000,21000,11,58772,1,0,0,0,0,6,0,0,0,0,0,0,0,"Dark Necromancer - In Combat - Cast 58772 (Normal Dungeon)"),
(@ENTRY,0,16,0,0,0,100,4,14000,18000,15000,21000,11,58770,1,0,0,0,0,6,0,0,0,0,0,0,0,"Dark Necromancer - In Combat - Cast 58770 (Heroic Dungeon)");

-- Hemet Nesingwary SAI
SET @ENTRY := 28451;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,51742,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hemet Nesingwary - On Aggro - Cast 51742"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,51742,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hemet Nesingwary - Between 5-30 Range - Cast 51742 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Evade - Set Sheath Melee");

-- Scarlet Crusader SAI
SET @ENTRY := 28529;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Crusader - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Crusader - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Crusader - On Evade - Set Sheath Melee");

-- Storming Vortex SAI
SET @ENTRY := 28547;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Storming Vortex - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,53044,0,0,0,0,0,2,0,0,0,0,0,0,0,"Storming Vortex - On Aggro - Cast 53044 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Storming Vortex - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4800,11,53044,0,0,0,0,0,2,0,0,0,0,0,0,0,"Storming Vortex - Between 0-40 Range - Cast 53044 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,59169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Storming Vortex - On Aggro - Cast 59169 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Storming Vortex - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,3400,4800,11,59169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Storming Vortex - Between 0-40 Range - Cast 59169 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Storming Vortex - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Storming Vortex - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Storming Vortex - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Storming Vortex - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Storming Vortex - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Storming Vortex - Between 15-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,9,0,100,4,0,5,9000,18000,11,60236,0,0,0,0,0,6,0,0,0,0,0,0,0,"Storming Vortex - Between 0-5 Range - Cast 60236 (Heroic Dungeon)");

-- Anub'ar Prime Guard SAI
SET @ENTRY := 29128;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,54309,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Prime Guard - On Aggro - Cast 54309 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,30,10000,13000,11,54309,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Between 0-30 Range - Cast 54309 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,59352,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Prime Guard - On Aggro - Cast 59352 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,30,10000,13000,11,59352,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Between 0-30 Range - Cast 59352 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,7,0,5,0,0,11,54314,33,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Between 0-5 Range - Cast 54314 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Prime Guard - Between 15-100% Mana - Decrement Event Phase (Dungeon Only)");

-- Savage Hill Scavenger SAI
SET @ENTRY := 29404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,50403,0,0,0,0,0,2,0,0,0,0,0,0,0,"Savage Hill Scavenger - On Aggro - Cast 50403"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,50,5000,8000,11,50403,0,0,0,0,0,5,0,0,0,0,0,0,0,"Savage Hill Scavenger - Between 5-50 Range - Cast 50403 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - Between 5-50 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,45,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - Between 45-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - Between 45-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,25,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - Between 5-25 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - Between 5-25 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - On Evade - Set Sheath Melee");

-- Stormforged Tracker SAI
SET @ENTRY := 29652;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Tracker - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Tracker - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,0,9000,12000,9000,12000,11,46982,1,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Tracker - In Combat - Cast 46982"),
(@ENTRY,0,14,0,0,0,100,0,9000,12000,9000,12000,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - In Combat - Set Sheath Ranged"),
(@ENTRY,0,15,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Tracker - On Evade - Set Sheath Melee");

-- Snowdrift Jormungar SAI
SET @ENTRY := 29390;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,500,500,11,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - Out Of Combat - Cast 20567"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - Out Of Combat - Set Not Attackable & Not Selectable Flag"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,28,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - On Aggro - Remove Aura 20567"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - On Aggro - Remove Aura 29147"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - On Aggro - Cast 37752"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - On Aggro - Disallow Combat Movement"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - On Aggro - Remove Not Attackable & Not Selectable Flag"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - On Aggro - Set Event Phase 1"),
(@ENTRY,0,8,9,0,0,100,0,1000,3000,5000,7000,11,50293,0,0,0,0,0,5,0,0,0,0,0,0,0,"Snowdrift Jormungar - In Combat - Cast 50293"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - In Combat - Disallow Combat Movement"),
(@ENTRY,0,10,0,0,0,100,0,20400,20400,45000,50000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowdrift Jormungar - In Combat - Cast 32738"),
(@ENTRY,0,11,12,9,0,100,1,20,60,0,0,11,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - Between 20-60 Range - Cast 20567"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - Between 20-60 Range - Cast 29147"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - Between 20-60 Range - Set Event Phase 2"),
(@ENTRY,0,14,15,9,0,100,1,0,8,0,0,28,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - Between 0-8 Range - Remove Aura 20567"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - Between 0-8 Range - Remove Aura 29147"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - Between 0-8 Range - Cast 37752"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - Between 0-8 Range - Disallow Combat Movement"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - Between 0-8 Range - Remove Not Attackable & Not Selectable Flag"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - Between 0-8 Range - Set Event Phase 1"),
(@ENTRY,0,20,21,7,0,100,1,0,0,0,0,11,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - On Evade - Cast 20567"),
(@ENTRY,0,21,22,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - On Evade - Set Event Phase 1"),
(@ENTRY,0,22,23,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - On Evade - Cast 29147"),
(@ENTRY,0,23,24,61,0,100,0,0,0,0,0,14,0,100,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - On Evade - Remove 100% Threat"),
(@ENTRY,0,24,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowdrift Jormungar - On Evade - Set Not Attackable & Not Selectable Flag");

-- Sunreaver Scout SAI
SET @ENTRY := 30233;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Scout - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Scout - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,9,1,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Scout - Between 5-30 Range - Cast 17174 (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Scout - Between 5-30 Range - Cast 14443 (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Scout - On Evade - Set Sheath Melee");

-- Silver Covenant Scout SAI
SET @ENTRY := 30238;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Scout - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,9,1,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 5-30 Range - Cast 17174 (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 5-30 Range - Cast 14443 (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Scout - On Evade - Set Sheath Melee");

-- Silver Covenant Horseman SAI
SET @ENTRY := 30263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Horseman - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,9,1,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 5-30 Range - Cast 17174 (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 5-30 Range - Cast 14443 (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Horseman - On Evade - Set Sheath Melee");

-- Sunreaver Hawkrider SAI
SET @ENTRY := 30265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Hawkrider - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,9,1,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 5-30 Range - Cast 17174 (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 5-30 Range - Cast 14443 (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Hawkrider - On Evade - Set Sheath Melee");

-- Jormuttar SAI
SET @ENTRY := 30340;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,500,500,11,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - Out Of Combat - Cast 20567"),
(@ENTRY,0,1,0,61,0,100,0,0,0,500,500,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - Out Of Combat - Set Not Attackable & Not Selectable Flag"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,28,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - On Aggro - Remove Aura 20567"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - On Aggro - Remove Aura 29147"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - On Aggro - Cast 37752"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - On Aggro - Disallow Combat Movement"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - On Aggro - Remove Not Attackable & Not Selectable Flag"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - On Aggro - Set Event Phase 1"),
(@ENTRY,0,8,9,0,0,100,0,1000,1000,3000,5000,11,61597,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jormuttar - In Combat - Cast 61597"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - In Combat - Disallow Combat Movement"),
(@ENTRY,0,10,0,0,0,100,0,11000,16000,15000,20000,11,61598,1,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - In Combat - Cast 61598"),
(@ENTRY,0,11,0,0,0,100,0,10000,20000,45000,50000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jormuttar - In Combat - Cast 32738"),
(@ENTRY,0,12,13,9,0,100,1,30,60,0,0,11,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - Between 30-60 Range - Cast 20567"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - Between 30-60 Range - Cast 29147"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - Between 30-60 Range - Set Event Phase 2"),
(@ENTRY,0,15,16,9,0,100,1,0,8,0,0,28,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - Between 0-8 Range - Remove Aura 20567"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - Between 0-8 Range - Remove Aura 29147"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - Between 0-8 Range - Cast 37752"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - Between 0-8 Range - Disallow Combat Movement"),
(@ENTRY,0,19,20,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - Between 0-8 Range - Remove Not Attackable & Not Selectable Flag"),
(@ENTRY,0,20,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - Between 0-8 Range - Set Event Phase 1"),
(@ENTRY,0,21,22,7,0,100,1,0,0,0,0,11,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - On Evade - Cast 20567"),
(@ENTRY,0,22,23,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - On Evade - Set Event Phase 1"),
(@ENTRY,0,23,24,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - On Evade - Cast 29147"),
(@ENTRY,0,24,25,61,0,100,0,0,0,0,0,14,0,100,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - On Evade - Remove 100% Threat"),
(@ENTRY,0,25,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jormuttar - On Evade - Set Not Attackable & Not Selectable Flag");

-- Nesingwary Game Warden SAI
SET @ENTRY := 30737;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nesingwary Game Warden - On Aggro - Cast 16100"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 5-30 Range - Cast 16100 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,20,9000,13000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 0-20 Range - Cast 6533"),
(@ENTRY,0,14,15,9,1,100,0,5,30,8000,10000,11,31942,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 5-30 Range - Cast 31942 (Phase 1)"),
(@ENTRY,0,15,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,16,0,9,0,100,0,0,45,7000,9000,11,23337,1,0,0,0,0,6,0,0,0,0,0,0,0,"Nesingwary Game Warden - Between 0-45 Range - Cast 23337"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nesingwary Game Warden - On Evade - Set Sheath Melee");

-- Shandaral Hunter Spirit SAI
SET @ENTRY := 30864;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Between 5-30 Range - Cast 6660"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,13,14,0,0,100,0,4000,8000,9000,14000,11,54615,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - In Combat - Cast 54615"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - In Combat - Set Sheath Ranged"),
(@ENTRY,0,15,0,0,0,100,0,9000,15000,15000,22000,11,47168,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - In Combat - Cast 47168"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - On Evade - Set Sheath Melee");

-- Syreian the Bonecarver SAI
SET @ENTRY := 32438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,38952,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - On Aggro - Cast 38952"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,50092,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - Between 5-30 Range - Cast 50092 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,0,1,100,0,12000,15000,11000,14000,11,38952,1,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - In Combat - Cast 38952 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - In Combat - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,12,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,15,0,9,0,100,0,0,5,12000,16000,11,47168,1,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - Between 0-5 Range - Cast 47168"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syreian the Bonecarver - On Evade - Set Sheath Melee");

-- Deep Jormungar SAI
SET @ENTRY := 34920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,500,500,11,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Out Of Combat - Cast 56503"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Out Of Combat - Set Not Attackable & Not Selectable Flag"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,28,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Remove Aura 56503"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Remove Aura 29147"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Cast 37752"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Disallow Combat Movement"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Remove Not Attackable & Not Selectable Flag"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Set Event Phase 1"),
(@ENTRY,0,8,9,0,0,100,0,1000,1000,3000,5000,11,61597,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Jormungar - In Combat - Cast 61597"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - In Combat - Disallow Combat Movement"),
(@ENTRY,0,10,0,0,0,100,0,11000,16000,15000,20000,11,61598,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - In Combat - Cast 61598"),
(@ENTRY,0,11,0,0,0,100,0,10000,20000,45000,50000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Jormungar - In Combat - Cast 32738"),
(@ENTRY,0,12,13,9,0,100,1,30,60,0,0,11,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Between 30-60 Range - Cast 56503"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Between 30-60 Range - Cast 29147"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Between 30-60 Range - Set Event Phase 2"),
(@ENTRY,0,15,16,9,0,100,1,0,8,0,0,28,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Between 0-8 Range - Remove Aura 56503"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Between 0-8 Range - Remove Aura 29147"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Between 0-8 Range - Cast 37752"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Between 0-8 Range - Disallow Combat Movement"),
(@ENTRY,0,19,20,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Between 0-8 Range - Remove Not Attackable & Not Selectable Flag"),
(@ENTRY,0,20,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Between 0-8 Range - Set Event Phase 1"),
(@ENTRY,0,21,22,7,0,100,1,0,0,0,0,11,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Cast 56503"),
(@ENTRY,0,22,23,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Set Event Phase 1"),
(@ENTRY,0,23,24,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Cast 29147"),
(@ENTRY,0,24,25,61,0,100,0,0,0,0,0,14,0,100,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Remove 100% Threat"),
(@ENTRY,0,25,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Set Not Attackable & Not Selectable Flag");

-- Titanium Vanguard SAI
SET @ENTRY := 28838;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,53059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - On Aggro - Cast 53059 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,5,30,14000,21000,11,53059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - Between 5-30 Range - Cast 53059 (Normal Dungeon)"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - Between 5-30 Range - Start Auto Attack (Normal Dungeon)"),
(@ENTRY,0,7,8,4,0,100,5,0,0,0,0,11,59178,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - On Aggro - Cast 59178 (Heroic Dungeon)"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,9,10,9,0,100,4,5,30,14000,21000,11,59178,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - Between 5-30 Range - Cast 59178 (Heroic Dungeon)"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - Between 5-30 Range - Start Auto Attack (Heroic Dungeon)"),
(@ENTRY,0,12,0,0,0,100,7,4000,6000,0,0,11,58619,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - In Combat - Cast 58619 (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,6,12000,15000,12000,15000,11,58619,0,0,0,0,0,6,0,0,0,0,0,0,0,"Titanium Vanguard - In Combat - Cast 58619 (Dungeon Only)"),
(@ENTRY,0,14,15,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,16,17,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,19,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Vanguard - On Evade - Set Sheath Melee (Dungeon Only)");

-- Infesting Jormungar SAI
SET @ENTRY := 30148;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,500,500,11,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - Out Of Combat - Cast 20567"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - Out Of Combat - Set Not Attackable & Not Selectable Flag"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,28,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - On Aggro - Remove Aura 20567"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - On Aggro - Remove Aura 29147"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - On Aggro - Cast 37752"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - On Aggro - Disallow Combat Movement"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - On Aggro - Remove Not Attackable & Not Selectable Flag"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - On Aggro - Set Event Phase 1"),
(@ENTRY,0,8,0,0,0,100,0,3000,6000,18000,21000,11,56103,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infesting Jormungar - In Combat - Cast 56103"),
(@ENTRY,0,9,0,0,0,100,0,9000,12000,19000,23000,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infesting Jormungar - In Combat - Cast 48287"),
(@ENTRY,0,10,0,0,0,100,0,20400,20400,45000,50000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infesting Jormungar - In Combat - Cast 32738"),
(@ENTRY,0,11,12,9,0,100,1,10,60,0,0,11,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - Between 10-60 Range - Cast 20567"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - Between 10-60 Range - Cast 29147"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - Between 10-60 Range - Set Event Phase 2"),
(@ENTRY,0,14,15,9,0,100,1,0,8,0,0,28,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - Between 0-8 Range - Remove Aura 20567"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - Between 0-8 Range - Remove Aura 29147"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - Between 0-8 Range - Cast 37752"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - Between 0-8 Range - Disallow Combat Movement"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - Between 0-8 Range - Remove Not Attackable & Not Selectable Flag"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - Between 0-8 Range - Set Event Phase 1"),
(@ENTRY,0,20,21,7,0,100,1,0,0,0,0,11,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - On Evade - Cast 20567"),
(@ENTRY,0,21,22,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - On Evade - Set Event Phase 1"),
(@ENTRY,0,22,23,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - On Evade - Cast 29147"),
(@ENTRY,0,23,24,61,0,100,0,0,0,0,0,14,0,100,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - On Evade - Remove 100% Threat"),
(@ENTRY,0,24,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infesting Jormungar - On Evade - Set Not Attackable & Not Selectable Flag");

-- Drakkari God Hunter SAI
SET @ENTRY := 29820;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,35946,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari God Hunter - On Aggro - Cast 35946 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,5,30,2300,5000,11,35946,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 5-30 Range - Cast 35946 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,59146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari God Hunter - On Aggro - Cast 59146 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,0,100,4,5,30,2300,5000,11,59146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 5-30 Range - Cast 59146 (Heroic Dungeon)"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,7000,10000,12000,15000,11,55624,1,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari God Hunter - In Combat - Cast 55624 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,4,7000,10000,12000,15000,11,58973,1,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari God Hunter - In Combat - Cast 58973 (Heroic Dungeon)"),
(@ENTRY,0,12,13,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,14,15,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,17,18,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,19,0,0,0,100,6,3000,5000,33000,37000,11,55798,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - In Combat - Cast 55798 (Dungeon Only)"),
(@ENTRY,0,20,0,0,0,100,6,18000,21000,19000,23000,11,55625,0,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari God Hunter - In Combat - Cast 55625 (Dungeon Only)"),
(@ENTRY,0,21,0,2,0,100,6,0,30,12000,15000,11,31567,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - Between 0-30% Health - Cast 31567 (Dungeon Only)"),
(@ENTRY,0,22,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari God Hunter - On Evade - Set Sheath Melee (Dungeon Only)");

-- Alliance Ranger SAI
SET @ENTRY := 26802;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - On Aggro - Remove Aura 47543 (Dungeon Only)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Ranger - On Aggro - Cast 15620 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,6,9,0,100,2,5,30,2300,3800,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Ranger - Between 5-30 Range - Cast 15620 (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,7,8,4,0,100,5,0,0,0,0,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Ranger - On Aggro - Cast 22907 (Heroic Dungeon)"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,9,10,9,0,100,4,5,30,2300,3800,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Ranger - Between 5-30 Range - Cast 22907 (Heroic Dungeon)"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,11,12,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,13,14,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,16,17,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,18,19,9,0,100,2,5,45,9500,10000,11,47777,1,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Ranger - Between 5-45 Range - Cast 47777 (Normal Dungeon)"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Between 5-45 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,20,21,9,0,100,4,5,45,9500,10000,11,56933,1,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Ranger - Between 5-45 Range - Cast 56933 (Heroic Dungeon)"),
(@ENTRY,0,21,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - Between 5-45 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,22,0,0,0,100,6,12000,15000,16100,19000,11,48191,5,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - In Combat - Cast 48191 (Dungeon Only)"),
(@ENTRY,0,23,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Ranger - On Evade - Set Sheath Melee (Dungeon Only)");

-- Phasing Stalker SAI
SET @ENTRY := 18559;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Stalker - On Aggro - Cast 15547 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,5,30,2300,5000,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Stalker - Between 5-30 Range - Cast 15547 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Stalker - On Aggro - Cast 16100 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,0,100,4,5,30,2300,5000,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Stalker - Between 5-30 Range - Cast 16100 (Heroic Dungeon)"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,10,11,9,0,100,6,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,12,13,9,0,100,6,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,15,16,9,0,100,6,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,18,0,0,0,100,6,5000,5000,20000,20000,11,32829,1,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - In Combat - Cast 32829 (Dungeon Only)"),
(@ENTRY,0,19,0,9,0,100,2,5,20,10000,12000,11,31975,1,0,0,0,0,5,0,0,0,0,0,0,0,"Phasing Stalker - Between 5-20 Range - Cast 31975 (Normal Dungeon)"),
(@ENTRY,0,20,0,9,0,100,4,5,20,10000,12000,11,35511,1,0,0,0,0,5,0,0,0,0,0,0,0,"Phasing Stalker - Between 5-20 Range - Cast 35511 (Heroic Dungeon)"),
(@ENTRY,0,21,22,9,0,100,6,5,20,15000,16000,11,37551,1,0,0,0,0,5,0,0,0,0,0,0,0,"Phasing Stalker - Between 5-20 Range - Cast 37551 (Dungeon Only)"),
(@ENTRY,0,22,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - Between 5-20 Range - Set Sheath Ranged (Dungeon Only)"),
(@ENTRY,0,23,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - On Evade - Set Sheath Melee (Dungeon Only)");
