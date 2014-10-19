-- Atal'ai Priest SAI
SET @ENTRY := 5269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - On Reset - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,31976,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Out of Combat - Cast 'Shadow Shield' (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,2,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Priest - On Aggro - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,2,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Priest - Within 0-40 Range - Cast 'Shadow Bolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,5,6,3,1,100,2,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Mana - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,6,0,61,1,100,2,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Mana - Increment Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Within 35-80 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,1,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Within 5-15 Range - Disable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,9,1,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Within 0-5 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,10,0,3,1,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 30-100% Mana - Decrement Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,11,0,14,0,100,2,1000,30,11000,15000,11,11642,1,0,0,0,0,7,0,0,0,0,0,0,0,"Atal'ai Priest - Friendly At 1000 Health - Cast 'Heal' (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Health - Set Event Phase 3 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Health - Enable Combat Movement (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,8,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,15,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - On Reset - Disable Combat Movement"),
(@ENTRY,0,16,0,1,0,100,0,1000,1000,1800000,1800000,11,31976,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Out of Combat - Cast 'Shadow Shield'"),
(@ENTRY,0,17,18,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Priest - On Aggro - Cast 'Shadow Bolt'"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - On Aggro - Increment Phase"),
(@ENTRY,0,19,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Priest - Within 0-40 Range - Cast 'Shadow Bolt' (Phase 1)"),
(@ENTRY,0,20,21,3,1,100,0,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Mana - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,21,0,61,1,100,0,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Mana - Increment Phase (Phase 1)"),
(@ENTRY,0,22,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,23,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,24,0,9,1,100,0,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,25,0,3,1,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 30-100% Mana - Decrement Phase (Phase 1)"),
(@ENTRY,0,26,0,14,0,100,0,1000,30,11000,15000,11,11642,1,0,0,0,0,7,0,0,0,0,0,0,0,"Atal'ai Priest - Friendly At 1000 Health - Cast 'Heal'"),
(@ENTRY,0,27,28,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,28,29,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,29,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,8,0,0,0,0,0,0,0,"Atal'ai Priest - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Atal'ai Witch Doctor SAI
SET @ENTRY := 5259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,2,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - On Reset - Disable Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,2,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - On Aggro - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - On Aggro - Increment Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3500,5200,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Within 0-40 Range - Cast 'Lightning Bolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,4,5,3,1,100,2,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 0-15% Mana - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 0-15% Mana - Increment Phase (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,6,0,9,1,100,2,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Within 35-80 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Within 5-15 Range - Disable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,8,0,9,1,100,2,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Within 0-5 Range - Enable Combat Movement (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 30-100% Mana - Decrement Phase (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,4900,13100,13100,18400,11,12058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - In Combat - Cast 'Chain Lightning' (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,10900,26100,17100,35100,11,11641,1,0,0,0,0,5,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - In Combat - Cast 'Hex' (Normal Dungeon)"),
(@ENTRY,0,12,0,14,0,100,2,1800,40,12700,23100,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Friendly At 1800 Health - Cast 'Healing Wave' (Normal Dungeon)"),
(@ENTRY,0,13,14,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 0-15% Health - Set Event Phase 3 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 0-15% Health - Enable Combat Movement (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Witch Doctor - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Tarren Mill Lookout SAI
SET @ENTRY := 18094;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Lookout - On Aggro - Cast 15620 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,1,100,2,5,30,2300,5000,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 5-30 Range - Cast 15620 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Lookout - On Aggro - Cast 16100 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,1,100,4,5,30,2300,5000,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 5-30 Range - Cast 16100 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 25-80 Range - Start Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,14,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 0-5 Range - Set Sheath Melee (Dungeon Only) (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 0-5 Range - Start Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 5-15 Range - Stop Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,17,18,0,1,100,6,14000,19000,14000,19000,11,17174,1,0,0,0,0,5,0,0,0,0,0,0,0,"Tarren Mill Lookout - In Combat - Cast 17174 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,18,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - In Combat - Set Sheath Ranged (Dungeon Only) (Phase 1)"),
(@ENTRY,0,19,20,0,1,100,6,8000,11000,17000,21000,11,35511,1,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Lookout - In Combat - Cast 35511 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,20,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - In Combat - Set Sheath Ranged (Dungeon Only) (Phase 1)"),
(@ENTRY,0,21,22,2,0,100,7,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 0-15% Health - Increment Event Phase (Dungeon Only)"),
(@ENTRY,0,22,23,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 0-15% Health - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,23,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tarren Mill Lookout - Between 0-15% Health - Flee For Assist (Dungeon Only)"),
(@ENTRY,0,24,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Lookout - On Evade - Set Sheath Melee (Dungeon Only)");

-- Feralfen Hunter SAI
SET @ENTRY := 18113;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,0,1,0,100,1,1000,1000,0,0,11,32060,1,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Out Of Combat - Cast 32060"),
(@ENTRY,0,3,4,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Feralfen Hunter - On Aggro - Cast 6660"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,6,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Feralfen Hunter - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,7,8,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,9,10,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,11,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,13,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,14,0,0,0,100,0,4000,8000,18000,24000,11,31975,0,0,0,0,0,2,0,0,0,0,0,0,0,"Feralfen Hunter - In Combat - Cast 31975"),
(@ENTRY,0,15,16,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Feralfen Hunter - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Hunter - On Evade - Set Sheath Melee");

-- Tuurem Hunter SAI
SET @ENTRY := 18457;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tuurem Hunter - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tuurem Hunter - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tuurem Hunter - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tuurem Hunter - On Evade - Set Sheath Melee");

-- Unliving Stalker SAI
SET @ENTRY := 18501;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Stalker - On Aggro - Cast 15547 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,5,30,2300,5000,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Stalker - Between 5-30 Range - Cast 15547 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Stalker - On Aggro - Cast 16100 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,0,100,4,5,30,2300,5000,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Stalker - Between 5-30 Range - Cast 16100 (Heroic Dungeon)"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,10,11,9,0,100,6,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,12,13,9,0,100,6,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,15,16,9,0,100,6,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,17,0,0,0,100,6,5000,5000,20000,20000,11,32829,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - In Combat - Cast 32829 (Dungeon Only)"),
(@ENTRY,0,18,0,9,0,100,2,5,20,10000,12000,11,31975,1,0,0,0,0,5,0,0,0,0,0,0,0,"Unliving Stalker - Between 5-20 Range - Cast 31975 (Normal Dungeon)"),
(@ENTRY,0,19,0,9,0,100,4,5,20,10000,12000,11,35511,1,0,0,0,0,5,0,0,0,0,0,0,0,"Unliving Stalker - Between 5-20 Range - Cast 35511 (Heroic Dungeon)"),
(@ENTRY,0,20,0,9,0,100,6,5,20,15000,16000,11,37551,1,0,0,0,0,5,0,0,0,0,0,0,0,"Unliving Stalker - Between 5-20 Range - Cast 37551 (Dungeon Only)"),
(@ENTRY,0,21,0,9,0,100,6,5,20,15000,16000,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - Between 5-20 Range - Set Sheath Ranged (Dungeon Only)"),
(@ENTRY,0,22,23,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - On Evade - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,23,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - On Evade - Forced Despawn (Dungeon Only)");

-- Darkspear Axe Thrower SAI
SET @ENTRY := 18970;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Axe Thrower - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 5-30 Range - Cast 10277 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Axe Thrower - On Evade - Set Sheath Melee");

-- Master Daellis Dawnstrike SAI
SET @ENTRY := 19705;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,0,50,9000,12000,11,35964,1,0,0,0,0,2,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 0-50 Range - Cast 35964 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 0-50 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,12,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,15,16,9,0,100,0,0,5,16000,21000,11,35963,1,0,0,0,0,2,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 0-5 Range - Cast 35963"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,79,30,150,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 0-5 Range - Set Ranged Movement Distance 30 Angle 150"),
(@ENTRY,0,17,18,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,20,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - On Evade - Set Sheath Melee");

-- Sunfury Archer SAI
SET @ENTRY := 19707;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Archer - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Archer - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,10,40,9000,12000,11,37847,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Archer - Between 10-40 Range - Cast 37847 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 10-40 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,13,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,15,0,9,0,100,0,0,20,12000,15000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Archer - Between 0-20 Range - Cast 12024"),
(@ENTRY,0,16,0,9,0,100,1,0,10,0,0,79,30,150,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 0-10 Range - Set Ranged Movement Distance 30 Angle 150"),
(@ENTRY,0,17,18,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunfury Archer - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,20,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Archer - On Evade - Set Sheath Melee");

-- Sunfury Geologist SAI
SET @ENTRY := 19779;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,36645,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Geologist - On Aggro - Cast 36645"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,36645,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Geologist - Between 5-30 Range - Cast 36645 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,5,5000,9000,11,35918,32,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Geologist - Between 0-5 Range - Cast 35918"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunfury Geologist - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,19,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Geologist - On Evade - Set Sheath Melee");

-- Sunfury Bowman SAI
SET @ENTRY := 20207;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - On Respawn - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - On Respawn - Stop Auto Attack"),
(@ENTRY,0,2,3,1,0,100,0,5000,5000,10000,70000,11,33796,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Out Of Combat - Cast 33796"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Out Of Combat - Set Sheath Ranged"),
(@ENTRY,0,4,5,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Bowman - On Aggro - Cast 6660"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - On Aggro - Increment Event Phase"),
(@ENTRY,0,6,7,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Bowman - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,10,40,7000,9000,11,37847,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Bowman - Between 10-40 Range - Cast 37847 (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Between 10-40 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,13,14,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,17,0,9,0,100,0,0,20,12000,15000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Bowman - Between 0-20 Range - Cast 12024"),
(@ENTRY,0,18,19,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,19,20,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,20,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunfury Bowman - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,21,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Bowman - On Evade - Set Sheath Melee");

-- Greater Crust Burster SAI
SET @ENTRY := 21380;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,500,500,11,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - Out Of Combat - Cast 20567"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - Out Of Combat - Set Not Attackable & Not Selectable Flag"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,28,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - On Aggro - Remove Aura 20567"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - On Aggro - Remove Aura 29147"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - On Aggro - Cast 37752"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - On Aggro - Disallow Combat Movement"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - On Aggro - Remove Not Attackable & Not Selectable Flag"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - On Aggro - Set Event Phase 1"),
(@ENTRY,0,8,0,0,0,100,0,1000,1000,2100,4500,11,31747,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Crust Burster - In Combat - Cast 31747"),
(@ENTRY,0,9,0,0,0,100,0,1000,1000,2100,4500,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - In Combat - Disallow Combat Movement"),
(@ENTRY,0,10,0,0,0,100,0,10000,20000,45000,50000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Crust Burster - In Combat - Cast 32738"),
(@ENTRY,0,11,12,9,0,100,1,20,60,0,0,11,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - Between 20-60 Range - Cast 20567"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - Between 20-60 Range - Cast 29147"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - Between 20-60 Range - Set Event Phase 2"),
(@ENTRY,0,14,15,9,0,100,1,0,8,0,0,28,20567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - Between 0-8 Range - Remove Aura 20567"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - Between 0-8 Range - Remove Aura 29147"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - Between 0-8 Range - Cast 37752"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - Between 0-8 Range - Disallow Combat Movement"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - Between 0-8 Range - Remove Not Attackable & Not Selectable Flag"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - Between 0-8 Range - Set Event Phase 1"),
(@ENTRY,0,20,21,7,0,100,1,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - On Evade - Cast 29147"),
(@ENTRY,0,21,0,61,0,100,0,0,0,0,0,14,0,100,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Crust Burster - On Evade - Remove 100% Threat");

-- Skettis Talonite SAI
SET @ENTRY := 21650;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Talonite - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Talonite - Between 5-30 Range - Cast 10277"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,13,0,0,0,100,0,6000,10000,9000,14000,11,11428,1,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Talonite - In Combat - Cast 11428"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Talonite - On Evade - Set Sheath Melee");

-- Dragonmaw Drake-Rider SAI
SET @ENTRY := 21719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2200,3800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - Between 5-30 Range - Cast 6660"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,13,0,0,0,100,0,4000,6000,12000,16000,11,38859,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - In Combat - Cast 38859"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - On Evade - Set Sheath Melee"),
(@ENTRY,0,15,0,6,0,100,1,0,0,0,0,33,22197,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - On Death - Quest Credit");

-- Dragonmaw Elite SAI
SET @ENTRY := 22331;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,38858,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Elite - On Aggro - Cast 38858"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,80,2300,3900,11,38858,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 5-80 Range - Cast 38858 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 5-80 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,45,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 45-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 45-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,0,0,100,0,6000,9000,12000,16000,11,38861,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonmaw Elite - In Combat - Cast 38861"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - In Combat - Set Sheath Ranged"),
(@ENTRY,0,15,0,0,0,100,0,4000,6000,12000,16000,11,38859,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonmaw Elite - In Combat - Cast 38859"),
(@ENTRY,0,16,17,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,19,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Elite - On Evade - Set Sheath Melee"),
(@ENTRY,0,20,0,6,0,100,1,0,0,0,0,33,22197,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonmaw Elite - On Death - Quest Credit");

-- Unbound Dryad SAI
SET @ENTRY := 30860;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,55217,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Dryad - On Aggro - Cast 55217"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,8,40,2300,3900,11,55217,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Dryad - Between 8-40 Range - Cast 55217 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - Between 8-40 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - Between 35-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,11,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,0,3000,9000,9000,13000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Dryad - In Combat - Cast 11976"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Dryad - On Evade - Set Sheath Melee");

-- Elenna Edune SAI
SET @ENTRY := 24738;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elenna Edune - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2600,3500,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elenna Edune - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - On Evade - Set Sheath Melee");

-- Silverbrook Trapper SAI
SET @ENTRY := 26679;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silverbrook Trapper - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silverbrook Trapper - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,20,9000,15000,11,13608,1,0,0,0,0,2,0,0,0,0,0,0,0,"Silverbrook Trapper - Between 0-20 Range - Cast 13608"),
(@ENTRY,0,14,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverbrook Trapper - On Evade - Set Sheath Melee");

-- 7th Legion Wyrm Hunter SAI
SET @ENTRY := 26779;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - On Aggro - Cast 15620"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - Between 5-30 Range - Cast 15620 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - On Evade - Set Sheath Melee");

-- Amberpine Scout SAI
SET @ENTRY := 27117;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amberpine Scout - On Aggro - Cast 15547"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amberpine Scout - Between 5-30 Range - Cast 15547 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,5,9000,12000,11,35918,33,0,0,0,0,2,0,0,0,0,0,0,0,"Amberpine Scout - Between 0-5 Range - Cast 35918"),
(@ENTRY,0,14,0,2,0,100,0,0,30,12000,20000,11,31567,1,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - Between 0-30% Health - Cast 31567"),
(@ENTRY,0,15,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amberpine Scout - On Evade - Set Sheath Melee");

-- 7th Legion Sentinel SAI
SET @ENTRY := 27162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Sentinel - On Aggro - Cast 15547"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Sentinel - Between 5-30 Range - Cast 15547 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,0,9000,14000,17000,22000,11,49481,1,0,0,0,0,5,0,0,0,0,0,0,0,"7th Legion Sentinel - In Combat - Cast 49481"),
(@ENTRY,0,14,0,0,0,100,0,9000,14000,17000,22000,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - In Combat - Set Sheath Ranged"),
(@ENTRY,0,15,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Sentinel - On Evade - Set Sheath Melee");

-- Moa'ki Warrior SAI
SET @ENTRY := 27178;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,38556,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moa'ki Warrior - On Aggro - Cast 38556"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,35,2300,3900,11,38556,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moa'ki Warrior - Between 5-35 Range - Cast 38556 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - Between 5-35 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moa'ki Warrior - On Evade - Set Sheath Melee");

-- Argent Crusade Rifleman SAI
SET @ENTRY := 27351;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Argent Crusade Rifleman - On Aggro - Cast 15547"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Argent Crusade Rifleman - Between 5-30 Range - Cast 15547 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,15,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Crusade Rifleman - On Evade - Set Sheath Melee");

-- Thane Torvald Eriksson SAI
SET @ENTRY := 27377;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,50512,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thane Torvald Eriksson - On Aggro - Cast 50512"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,0,50,2300,3900,11,50512,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 0-50 Range - Cast 50512"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 0-50 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,0,0,100,0,9000,12000,12000,15000,11,52813,1,0,0,0,0,2,0,0,0,0,0,0,0,"Thane Torvald Eriksson - In Combat - Cast 52813"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - In Combat - Set Sheath Ranged"),
(@ENTRY,0,8,9,9,0,100,0,45,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 45-80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 45-80 Range - Start Auto Attack"),
(@ENTRY,0,10,11,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,13,14,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,15,0,0,0,100,0,8000,13000,9000,15000,11,34829,1,0,0,0,0,6,0,0,0,0,0,0,0,"Thane Torvald Eriksson - In Combat - Cast 34829"),
(@ENTRY,0,16,0,9,0,100,0,10,70,15000,20000,11,56843,0,0,0,0,0,5,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 10-70 Range - Cast 56843"),
(@ENTRY,0,17,0,2,0,100,0,0,30,15000,19000,11,57057,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 0-30% Health - Cast 57057"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Torvald Eriksson - On Evade - Set Sheath Melee");

-- Fordragon Marksman SAI
SET @ENTRY := 27540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,32103,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fordragon Marksman - On Aggro - Cast 32103"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,40,5000,7000,11,32103,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fordragon Marksman - Between 5-40 Range - Cast 32103 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - Between 5-40 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - Between 35-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,3,30,10000,17000,11,7896,0,0,0,0,0,5,0,0,0,0,0,0,0,"Fordragon Marksman - Between 3-30 Range - Cast 7896"),
(@ENTRY,0,14,0,0,0,100,0,12000,17000,22000,26000,11,49474,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - In Combat - Cast 49474"),
(@ENTRY,0,15,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - On Evade - Set Sheath Melee");

-- Darkspear Spear Thrower SAI
SET @ENTRY := 27560;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Spear Thrower - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,35,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Between 5-35 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Between 5-35 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,30,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Between 30-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Between 30-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,20,9000,14000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Between 0-20 Range - Cast 12024"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - On Evade - Set Sheath Melee");

-- Alliance Conscript SAI
SET @ENTRY := 27564;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Conscript - On Aggro - Cast 15620"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Conscript - Between 5-30 Range - Cast 15620 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,5,5000,9000,11,29426,1,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Conscript - Between 0-5 Range - Cast 29426"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Conscript - On Evade - Set Sheath Melee");

-- Fordragon Sentinel SAI
SET @ENTRY := 27576;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fordragon Sentinel - On Aggro - Cast 15547"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fordragon Sentinel - Between 5-30 Range - Cast 15547 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,0,9000,16000,18000,24000,11,49481,1,0,0,0,0,5,0,0,0,0,0,0,0,"Fordragon Sentinel - In Combat - Cast 49481"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Sentinel - On Evade - Set Sheath Melee");

-- 7th Legion Elite SAI
SET @ENTRY := 27588;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,50092,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Elite - On Aggro - Cast 50092"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,50092,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Elite - Between 5-30 Range - Cast 50092 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,20,9000,12000,11,62312,1,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Elite - Between 0-20 Range - Cast 62312"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - On Evade - Set Sheath Melee");

-- 7th Legion Elite SAI
SET @ENTRY := 27713;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,50092,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Elite - On Aggro - Cast 50092"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,50092,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Elite - Between 5-30 Range - Cast 50092 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,20,9000,12000,11,62312,1,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Elite - Between 0-20 Range - Cast 62312"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Elite - On Evade - Set Sheath Melee");

-- Horde Conscript SAI
SET @ENTRY := 27749;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Conscript - On Aggro - Cast 15620"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Conscript - Between 5-30 Range - Cast 15620 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,5,7000,9000,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Conscript - Between 0-5 Range - Cast 29426"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Conscript - On Evade - Set Sheath Melee");

-- "Wyrmbait" SAI
SET @ENTRY := 27843;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"'Wyrmbait' - On Aggro - Cast 15620"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"'Wyrmbait' - Between 5-30 Range - Cast 15620 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"'Wyrmbait' - On Evade - Set Sheath Melee");

-- Legion Commander Tyralion SAI
SET @ENTRY := 27844;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Legion Commander Tyralion - On Aggro - Cast 15620"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Legion Commander Tyralion - Between 5-30 Range - Cast 15620 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Tyralion - On Evade - Set Sheath Melee");

-- Legion Commander Yorik SAI
SET @ENTRY := 27857;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Legion Commander Yorik - On Aggro - Cast 15620"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Legion Commander Yorik - Between 5-30 Range - Cast 15620 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - On Evade - Set Sheath Melee");

-- Wastes Scavenger SAI
SET @ENTRY := 28005;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,50403,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastes Scavenger - On Aggro - Cast 50403"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,3000,5000,11,50403,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastes Scavenger - Between 5-30 Range - Cast 50403 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - On Evade - Set Sheath Melee");

-- Frenzyheart Tracker SAI
SET @ENTRY := 28077;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Tracker - On Aggro - Cast 22907"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,3000,5000,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Tracker - Between 5-30 Range - Cast 22907"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,13,0,0,0,100,0,10000,14000,60000,65000,11,53432,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - In Combat - Cast 53432"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - On Evade - Set Sheath Melee");

-- Dark Rune Elementalist SAI
SET @ENTRY := 27962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Out Of Combat - Set Event Phase 0 (Dungeon Only)"),
(@ENTRY,0,2,0,1,0,100,7,1000,1000,0,0,11,51475,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Out Of Combat - Cast 51475 (Dungeon Only)"),
(@ENTRY,0,3,0,1,0,100,3,3000,3000,0,0,11,51776,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Out Of Combat - Cast 51776 (Normal Dungeon)"),
(@ENTRY,0,4,0,1,0,100,5,3000,3000,0,0,11,59025,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Out Of Combat - Cast 59025 (Heroic Dungeon)"),
(@ENTRY,0,5,6,4,0,100,3,0,0,0,0,11,53314,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Elementalist - On Aggro - Cast 53314 (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,7,0,9,1,100,2,0,40,4000,6000,11,53314,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Elementalist - Between 0-40 Range - Cast 53314 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,4,0,100,5,0,0,0,0,11,59024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Elementalist - On Aggro - Cast 59024 (Heroic Dungeon)"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,10,0,9,1,100,4,0,40,4000,6000,11,59024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Elementalist - Between 0-40 Range - Cast 59024 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,11,12,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,14,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,15,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,16,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,17,0,2,0,100,7,0,30,0,0,11,32693,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Between 0-30% Health - Cast 32693 (Dungeon Only)");

-- Dark Rune Theurgist SAI
SET @ENTRY := 27963;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Theurgist - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Theurgist - On Aggro - Cast 15801 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Theurgist - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4800,11,15801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Theurgist - Between 0-40 Range - Cast 15801 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,35010,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Theurgist - On Aggro - Cast 35010 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Theurgist - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,3400,4800,11,35010,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Theurgist - Between 0-40 Range - Cast 35010 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Theurgist - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Theurgist - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Theurgist - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Theurgist - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Theurgist - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,11,51484,33,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Theurgist - Between 0-5 Range - Cast 51484 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Theurgist - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,14,0,0,0,100,2,9000,12000,9000,12000,11,53167,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Theurgist - In Combat - Cast 53167 (Normal Dungeon)"),
(@ENTRY,0,15,0,0,0,100,4,9000,12000,9000,12000,11,59152,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Theurgist - In Combat - Cast 59152 (Heroic Dungeon)");

-- Frenzyheart Hunter SAI
SET @ENTRY := 28079;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Hunter - On Aggro - Cast 15547"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Hunter - Between 5-30 Range - Cast 15547 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,9,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,0,8000,11000,12000,15000,11,52270,1,0,0,0,0,5,0,0,0,0,0,0,0,"Frenzyheart Hunter - In Combat - Cast 52270"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Hunter - On Evade - Set Sheath Melee");

-- Frenzyheart Scavenger SAI
SET @ENTRY := 28081;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,54617,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Scavenger - On Aggro - Cast 54617"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,40,2300,3900,11,54617,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Between 5-40 Range - Cast 54617 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Between 5-40 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Between 35-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Scavenger - On Evade - Set Sheath Melee");

-- Drakkari Water Binder SAI
SET @ENTRY := 28303;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Water Binder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Water Binder - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Water Binder - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Water Binder - Between 0-40 Range - Cast 9532 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Water Binder - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Water Binder - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Water Binder - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Water Binder - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Water Binder - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Water Binder - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,8000,16000,25000,30000,11,54399,1,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Water Binder - In Combat - Cast 54399");

-- Dragonflayer Spiritualist SAI
SET @ENTRY := 28410;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,7,0,0,0,0,11,51587,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - On Aggro - Cast 51587 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - On Aggro - Increment Event Phase (Dungeon Only)"),
(@ENTRY,0,3,0,9,1,100,6,0,40,2400,3800,11,51587,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Between 0-40 Range - Cast 51587 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,0,0,100,6,1500,4000,8000,10000,11,51588,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - In Combat - Cast 51588 (Dungeon Only)"),
(@ENTRY,0,10,0,14,0,100,6,7000,100,7000,7000,11,51586,1,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - On Friendly Unit At 7000 Health Within 100 Range - Cast 51586 (Dungeon Only)"),
(@ENTRY,0,11,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)");

-- K3 Bruiser SAI
SET @ENTRY := 29910;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,9,0,100,1,0,20,11000,16000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"K3 Bruiser - Between 0-20 Range - Cast 12024"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - Between 0-20 Range - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,45,2300,3900,11,23337,0,0,0,0,0,2,0,0,0,0,0,0,0,"K3 Bruiser - Between 5-45 Range - Cast 23337 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - Between 5-45 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - Between 35-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"K3 Bruiser - On Evade - Set Sheath Melee");
