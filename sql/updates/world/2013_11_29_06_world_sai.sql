-- Azure Spellbinder SAI
SET @ENTRY := 27635;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbinder - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,50702,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Spellbinder - On Aggro - Cast 50702 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbinder - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,5000,7000,11,50702,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Spellbinder - Between 0-40 Range - Cast 50702 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,59212,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Spellbinder - On Aggro - Cast 59212 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbinder - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,5000,7000,11,59212,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Spellbinder - Between 0-40 Range - Cast 59212 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbinder - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbinder - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbinder - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbinder - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbinder - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbinder - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,2,6000,9000,9000,12000,11,38047,1,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Spellbinder - In Combat - Cast 38047 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,6000,9000,9000,12000,11,50566,1,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Spellbinder - In Combat - Cast 50566 (Heroic Dungeon)"),
(@ENTRY,0,15,0,0,0,100,6,9000,12000,4000,8000,11,50572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Spellbinder - In Combat - Cast 50572 (Dungeon Only)");

-- Azure Ley-Whelp SAI
SET @ENTRY := 27636;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Ley-Whelp - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,50705,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Ley-Whelp - On Aggro - Cast 50705 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Ley-Whelp - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,4000,6000,11,50705,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Ley-Whelp - Between 0-40 Range - Cast 50705 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,59210,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Ley-Whelp - On Aggro - Cast 59210 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Ley-Whelp - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,4000,6000,11,59210,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Ley-Whelp - Between 0-40 Range - Cast 59210 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Ley-Whelp - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Ley-Whelp - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Ley-Whelp - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Ley-Whelp - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Ley-Whelp - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Ley-Whelp - Between 15-100% Mana - Decrement Event Phase (Dungeon Only)");

-- Ring-Lord Sorceress SAI
SET @ENTRY := 27687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,50715,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ring-Lord Sorceress - On Aggro - Cast 50715 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,15000,19000,11,50715,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-40 Range - Cast 50715 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,59278,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ring-Lord Sorceress - On Aggro - Cast 59278 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,5,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,15000,19000,11,59278,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-40 Range - Cast 59278 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,2,9000,12000,15000,18000,11,16102,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ring-Lord Sorceress - In Combat - Cast 16102 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,9000,12000,15000,18000,11,61402,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ring-Lord Sorceress - In Combat - Cast 61402 (Heroic Dungeon)"),
(@ENTRY,0,15,16,2,0,100,7,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-15% Health - Set Event Phase 3 (Dungeon Only)"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-15% Health - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Between 0-15% Health - Flee For Assist (Dungeon Only)");

-- Fordragon High Priest SAI
SET @ENTRY := 27677;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,25054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fordragon High Priest - On Aggro - Cast 25054"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,25054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fordragon High Priest - Between 0-40 Range - Cast 25054 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,18000,25000,40000,53000,11,32595,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - In Combat - Cast 32595"),
(@ENTRY,0,11,0,0,0,100,0,9000,15000,15000,23000,11,49306,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - In Combat - Cast 49306"),
(@ENTRY,0,12,0,14,0,100,0,3000,40,17000,21000,11,25058,1,0,0,0,0,7,0,0,0,0,0,0,0,"Fordragon High Priest - On Friendly Unit At 3000 Health Within 40 Range - Cast 25058"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,11,49348,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon High Priest - Between 0-15% Health - Cast 49348");

-- Warsong Shaman SAI
SET @ENTRY := 27678;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,39945,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Shaman - On Aggro - Cast 39945"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,30,6000,8000,11,39945,0,0,0,0,0,5,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-30 Range - Cast 39945 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,2000,4000,600000,600000,11,34827,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - In Combat - Cast 34827"),
(@ENTRY,0,11,0,0,0,100,0,8000,14000,11000,15000,11,25025,0,0,0,0,0,5,0,0,0,0,0,0,0,"Warsong Shaman - In Combat - Cast 25025"),
(@ENTRY,0,12,0,0,0,100,0,8000,13000,25000,31000,11,33560,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - In Combat - Cast 33560"),
(@ENTRY,0,13,0,14,0,100,0,5000,40,15000,18000,11,49309,1,0,0,0,0,7,0,0,0,0,0,0,0,"Warsong Shaman - On Friendly Unit At 5000 Health Within 40 Range - Cast 49309"),
(@ENTRY,0,14,0,14,0,100,0,3000,40,12000,15000,11,16367,1,0,0,0,0,7,0,0,0,0,0,0,0,"Warsong Shaman - On Friendly Unit At 3000 Health Within 40 Range - Cast 16367");

-- Dahlia Suntouch SAI
SET @ENTRY := 27680;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dahlia Suntouch - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,28993,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dahlia Suntouch - On Aggro - Cast 28993"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dahlia Suntouch - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,28993,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dahlia Suntouch - Between 0-40 Range - Cast 28993 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dahlia Suntouch - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dahlia Suntouch - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dahlia Suntouch - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dahlia Suntouch - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dahlia Suntouch - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dahlia Suntouch - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,6000,11000,9000,12000,11,51899,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dahlia Suntouch - In Combat - Cast 51899"),
(@ENTRY,0,11,0,0,0,100,0,5000,6000,15000,18000,11,51897,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dahlia Suntouch - In Combat - Cast 51897");

-- Frigid Necromancer Attacker SAI
SET @ENTRY := 27687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,2000,4000,60000,70000,11,50324,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - In Combat - Cast 50324");

-- Master Necromancer SAI
SET @ENTRY := 27732;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Necromancer - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Necromancer - On Aggro - Cast 15537 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Necromancer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,5000,7000,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Necromancer - Between 0-40 Range - Cast 15537 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,61558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Necromancer - On Aggro - Cast 61558 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Necromancer - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,5000,7000,11,61558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Necromancer - Between 0-40 Range - Cast 61558 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Necromancer - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Necromancer - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Necromancer - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Necromancer - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Necromancer - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Master Necromancer - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,6,5000,9000,90000,180000,11,52611,1,0,0,0,0,1,0,0,0,0,0,0,0,"Master Necromancer - In Combat - Cast 52611 (Dungeon Only)");

-- High Elf Mage-Priest SAI
SET @ENTRY := 27747;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Elf Mage-Priest - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,7,0,0,0,0,11,34232,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Elf Mage-Priest - On Aggro - Cast 34232 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Elf Mage-Priest - On Aggro - Increment Event Phase (Dungeon Only)"),
(@ENTRY,0,3,0,9,1,100,6,0,40,3400,4800,11,34232,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Elf Mage-Priest - Between 0-40 Range - Cast 34232 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Elf Mage-Priest - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Elf Mage-Priest - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Elf Mage-Priest - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Elf Mage-Priest - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Elf Mage-Priest - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"High Elf Mage-Priest - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,10,0,14,0,100,6,5000,40,12000,18000,11,15586,1,0,0,0,0,7,0,0,0,0,0,0,0,"High Elf Mage-Priest - On Friendly Unit At 5000 Health Within 40 Range - Cast 15586 (Dungeon Only)");

-- High Shaman Bloodpaw SAI
SET @ENTRY := 27762;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Shaman Bloodpaw - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,22414,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Shaman Bloodpaw - On Aggro - Cast 22414"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Shaman Bloodpaw - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,22414,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Shaman Bloodpaw - Between 0-40 Range - Cast 22414 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Shaman Bloodpaw - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Shaman Bloodpaw - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Shaman Bloodpaw - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Shaman Bloodpaw - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Shaman Bloodpaw - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,4,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"High Shaman Bloodpaw - Between 15-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,9000,12000,9000,12000,11,22355,1,0,0,0,0,5,0,0,0,0,0,0,0,"High Shaman Bloodpaw - In Combat - Cast 22355"),
(@ENTRY,0,11,0,0,0,100,0,2000,5000,9000,12000,11,19133,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Shaman Bloodpaw - In Combat - Cast 19133"),
(@ENTRY,0,12,0,2,0,100,0,0,30,14000,21000,11,28902,1,0,0,0,0,1,0,0,0,0,0,0,0,"High Shaman Bloodpaw - Between 0-30% Health - Cast 28902");

-- Necrolord Horus SAI
SET @ENTRY := 27805;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Horus - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Necrolord Horus - On Aggro - Cast 20298"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Horus - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,20298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Necrolord Horus - Between 0-40 Range - Cast 20298 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Horus - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Horus - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Horus - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Horus - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Horus - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Horus - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,4000,8000,9000,12000,11,51340,32,0,0,0,0,5,0,0,0,0,0,0,0,"Necrolord Horus - In Combat - Cast 51340");

-- Necrolord X'avius SAI
SET @ENTRY := 27826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord X'avius - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Necrolord X'avius - On Aggro - Cast 20298"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord X'avius - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,20298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Necrolord X'avius - Between 0-40 Range - Cast 20298 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord X'avius - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord X'avius - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord X'avius - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord X'avius - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord X'avius - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord X'avius - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,9000,12000,15000,18000,11,51337,1,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord X'avius - In Combat - Cast 51337");

-- Rainspeaker Oracle SAI
SET @ENTRY := 28025;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rainspeaker Oracle - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,15305,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rainspeaker Oracle - On Aggro - Cast 15305"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rainspeaker Oracle - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,6000,8000,11,15305,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rainspeaker Oracle - Between 0-40 Range - Cast 15305 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rainspeaker Oracle - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rainspeaker Oracle - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rainspeaker Oracle - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rainspeaker Oracle - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rainspeaker Oracle - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Rainspeaker Oracle - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,3000,6000,12000,15000,11,54919,1,0,0,0,0,5,0,0,0,0,0,0,0,"Rainspeaker Oracle - In Combat - Cast 54919");

-- Sparktouched Oracle SAI
SET @ENTRY := 28112;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sparktouched Oracle - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,54916,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sparktouched Oracle - On Aggro - Cast 54916"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sparktouched Oracle - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,54916,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sparktouched Oracle - Between 0-40 Range - Cast 54916 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sparktouched Oracle - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sparktouched Oracle - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sparktouched Oracle - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sparktouched Oracle - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sparktouched Oracle - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sparktouched Oracle - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,9,0,100,0,0,30,9000,12000,11,12549,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sparktouched Oracle - Between 0-30 Range - Cast 12549");

-- Snowflake SAI
SET @ENTRY := 28153;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowflake - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,50721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowflake - On Aggro - Cast 50721 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowflake - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,2,100,2,0,40,3400,4800,11,50721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowflake - Between 0-40 Range - Cast 50721 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,59280,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowflake - On Aggro - Cast 59280 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowflake - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,2,100,4,0,40,3400,4800,11,59280,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowflake - Between 0-40 Range - Cast 59280 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,7,8,3,2,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowflake - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowflake - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowflake - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,10,0,9,2,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowflake - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,11,0,9,2,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowflake - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,12,0,0,0,100,7,5000,9000,0,0,11,44604,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowflake - In Combat - Cast 44604 (Dungeon Only)");
