-- Defias Renegade Mage SAI
SET @ENTRY := 450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Renegade Mage - On Aggro - Cast 20793"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,3400,4700,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Renegade Mage - Between 0-40 Range - Cast 20793 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,19200,21200,63900,68200,11,134,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - In Combat - Cast 134"),
(@ENTRY,0,11,0,0,0,100,0,16400,18400,12300,17200,11,4979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - In Combat - Cast 4979"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Renegade Mage - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Renegade Mage - Between 0-15% Health - Flee For Assist");

-- Murloc Minor Oracle SAI
SET @ENTRY := 456;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Minor Oracle - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,3600,5100,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Minor Oracle - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,14,0,100,0,130,40,30900,39000,11,332,1,0,0,0,0,7,0,0,0,0,0,0,0,"Murloc Minor Oracle - On Friendly Unit At 130 Health Within 40 Range - Cast 332"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Minor Oracle - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murloc Minor Oracle - Between 0-15% Health - Flee For Assist");

-- Murloc Hunter SAI
SET @ENTRY := 458;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,0,1,0,100,1,1000,1000,0,0,11,8656,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Out Of Combat - Cast 8656"),
(@ENTRY,0,3,4,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Hunter - On Aggro - Cast 10277"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,6,9,2,100,0,5,30,2900,4800,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Hunter - Between 5-30 Range - Cast 10277 (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,7,8,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,9,10,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,11,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,11,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,12,13,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,13,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murloc Hunter - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Hunter - On Evade - Set Sheath Melee");

-- Marisa du'Paige SAI
SET @ENTRY := 599;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marisa du'Paige - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marisa du'Paige - On Aggro - Cast 9053"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marisa du'Paige - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,3400,5400,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marisa du'Paige - Between 0-40 Range - Cast 9053 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marisa du'Paige - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marisa du'Paige - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marisa du'Paige - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marisa du'Paige - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marisa du'Paige - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Marisa du'Paige - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,12000,19000,35000,48000,11,700,0,0,0,0,0,5,0,0,0,0,0,0,0,"Marisa du'Paige - In Combat - Cast 700"),
(@ENTRY,0,11,0,0,0,80,0,18000,25000,25000,35000,11,228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marisa du'Paige - In Combat - Cast 228"),
(@ENTRY,0,12,0,2,0,100,0,0,50,35000,35000,11,512,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marisa du'Paige - Between 0-50% Health - Cast 512"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marisa du'Paige - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marisa du'Paige - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Marisa du'Paige - Between 0-15% Health - Flee For Assist");

-- Defias Conjurer SAI
SET @ENTRY := 619;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Out Of Combat - Cast 12544"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Conjurer - On Aggro - Cast 9053"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Conjurer - Between 0-40 Range - Cast 9053 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Conjurer - Between 0-15% Health - Flee For Assist");

-- Goblin Engineer SAI
SET @ENTRY := 622;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goblin Engineer - On Aggro - Cast 6660 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,2,100,2,5,30,2200,3800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goblin Engineer - Between 5-30 Range - Cast 6660 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Between 25-80 Range - Start Auto Attack (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Between 0-5 Range - Set Sheath Melee (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Between 0-5 Range - Start Auto Attack (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Between 5-15 Range - Stop Auto Attack (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,2,500,4500,67800,89000,11,3605,1,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - In Combat - Cast 3605 (Normal Dungeon)"),
(@ENTRY,0,14,15,2,0,100,3,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Between 0-15% Health - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Goblin Engineer - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,17,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Engineer - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Skullsplitter Axe Thrower SAI
SET @ENTRY := 696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2200,3800,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 5-30 Range - Cast 10277 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,0,5000,7000,23000,26000,11,3148,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - In Combat - Cast 3148"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Axe Thrower - On Evade - Set Sheath Melee");

-- Bloodscalp Mystic SAI
SET @ENTRY := 701;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Mystic - On Aggro - Cast 10277"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,1500,2500,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 0-40 Range - Cast 10277 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,14,0,100,1,500,40,0,0,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodscalp Mystic - On Friendly Unit At 500 Health Within 40 Range - Cast 11986"),
(@ENTRY,0,11,0,0,0,100,0,3000,4000,25000,30000,11,4979,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - In Combat - Cast 4979"),
(@ENTRY,0,12,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bloodscalp Mystic - Between 0-15% Health - Flee For Assist");

-- Skullsplitter Mystic SAI
SET @ENTRY := 780;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Mystic - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Mystic - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Mystic - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,1500,2500,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Mystic - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Mystic - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Mystic - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Mystic - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Mystic - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Mystic - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Mystic - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,14,0,100,1,700,40,0,0,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Skullsplitter Mystic - On Friendly Unit At 700 Health Within 40 Range - Cast 11986"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Mystic - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Mystic - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skullsplitter Mystic - Between 0-15% Health - Flee For Assist");

-- Kurzen Headshrinker SAI
SET @ENTRY := 941;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kurzen Headshrinker - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,3500,4700,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 0-40 Range - Cast 9613 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,2400,10800,39000,39500,11,7289,1,0,0,0,0,2,0,0,0,0,0,0,0,"Kurzen Headshrinker - In Combat - Cast 7289"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 0-15% Health - Flee For Assist");

-- Dragonmaw Shadowwarder SAI
SET @ENTRY := 1038;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - On Aggro - Cast 20807"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,3500,6400,11,20807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Between 0-40 Range - Cast 20807 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,0,0,100,0,2200,6200,20200,31000,11,6223,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - In Combat - Cast 6223"),
(@ENTRY,0,10,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - Between 0-15% Health - Flee For Assist");

-- Lost Whelp SAI
SET @ENTRY := 1043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Whelp - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,11839,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lost Whelp - On Aggro - Cast 11839"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Whelp - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,3600,5300,11,11839,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lost Whelp - Between 0-40 Range - Cast 11839 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Whelp - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Whelp - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Whelp - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Whelp - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Whelp - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Whelp - Between 30-100% Mana - Decrement Event Phase");

-- Flamesnorting Whelp SAI
SET @ENTRY := 1044;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamesnorting Whelp - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,11839,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamesnorting Whelp - On Aggro - Cast 11839"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamesnorting Whelp - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,3600,5300,11,11839,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamesnorting Whelp - Between 0-40 Range - Cast 11839 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamesnorting Whelp - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamesnorting Whelp - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamesnorting Whelp - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamesnorting Whelp - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamesnorting Whelp - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Flamesnorting Whelp - Between 30-100% Mana - Decrement Event Phase");

-- Venture Co. Geologist SAI
SET @ENTRY := 1096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Geologist - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,5400,9600,24000,37200,11,184,1,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - In Combat - Cast 184"),
(@ENTRY,0,11,0,2,0,100,0,0,50,10100,19800,11,4979,1,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-50% Health - Cast 4979"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-15% Health - Flee For Assist");

-- Venture Co. Mechanic SAI
SET @ENTRY := 1097;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Mechanic - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2200,3800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,14,9,0,100,0,5,30,6500,10000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 5-30 Range - Cast 14443"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,15,16,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Venture Co. Mechanic - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Mechanic - On Evade - Set Sheath Melee");

-- Bluegill Raider SAI
SET @ENTRY := 1418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bluegill Raider - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2700,4900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bluegill Raider - Between 5-30 Range - Cast 10277 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,0,11000,14300,16500,33300,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bluegill Raider - In Combat - Cast 12024"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bluegill Raider - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Raider - On Evade - Set Sheath Melee");

-- Darkeye Bonecaster SAI
SET @ENTRY := 1522;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkeye Bonecaster - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkeye Bonecaster - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,13322,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkeye Bonecaster - On Aggro - Cast 13322"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkeye Bonecaster - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,4000,5000,11,13322,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkeye Bonecaster - Between 0-40 Range - Cast 13322 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkeye Bonecaster - Between 0-7% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkeye Bonecaster - Between 0-7% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkeye Bonecaster - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkeye Bonecaster - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkeye Bonecaster - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Darkeye Bonecaster - Between 15-100% Mana - Decrement Event Phase");

-- Scarlet Neophyte SAI
SET @ENTRY := 1539;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Out Of Combat - Cast 12544"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,13322,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Neophyte - On Aggro - Cast 13322"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,2400,3800,11,13322,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Neophyte - Between 0-40 Range - Cast 13322 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Neophyte - Between 0-15% Health - Flee For Assist");

-- Bloodsail Mage SAI
SET @ENTRY := 1562;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Mage - On Aggro - Cast 20823"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,3600,5900,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Mage - Between 0-40 Range - Cast 20823 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,1200,4700,34200,36800,11,2601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - In Combat - Cast 2601"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Mage - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bloodsail Mage - Between 0-15% Health - Flee For Assist");

-- Bloodsail Warlock SAI
SET @ENTRY := 1564;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Out Of Combat - Random Phase Range (1-2)"),
(@ENTRY,0,2,3,1,2,100,1,0,1000,0,0,11,8722,3,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Out Of Combat - Cast 8722 (Phase 2)"),
(@ENTRY,0,3,0,61,2,100,1,0,1000,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Out Of Combat - Set Event Phase 0 (Phase 2)"),
(@ENTRY,0,4,5,1,4,100,1,0,1000,0,0,11,11939,3,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Out Of Combat - Cast 11939 (Phase 4)"),
(@ENTRY,0,5,0,61,4,100,1,0,1000,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Out Of Combat - Set Event Phase 0 (Phase 4)"),
(@ENTRY,0,6,7,4,0,100,1,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Warlock - On Aggro - Cast 20825"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - On Aggro - Increment Event Phase"),
(@ENTRY,0,8,0,9,8,100,0,0,40,2400,3800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Warlock - Between 0-40 Range - Cast 20825 (Phase 8)"),
(@ENTRY,0,9,10,3,8,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Between 0-15% Mana - Allow Combat Movement (Phase 8)"),
(@ENTRY,0,10,0,61,8,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Between 0-15% Mana - Increment Event Phase (Phase 8)"),
(@ENTRY,0,11,0,9,8,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Between 35-80 Range - Allow Combat Movement (Phase 8)"),
(@ENTRY,0,12,0,9,8,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Between 5-15 Range - Disallow Combat Movement (Phase 8)"),
(@ENTRY,0,13,0,9,8,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Between 0-5 Range - Allow Combat Movement (Phase 8)"),
(@ENTRY,0,14,0,0,8,100,0,6900,20900,15900,15900,11,11980,32,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Warlock - In Combat - Cast 11980 (Phase 8)"),
(@ENTRY,0,15,0,3,16,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Between 30-100% Mana - Decrement Event Phase (Phase 16)"),
(@ENTRY,0,16,17,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Warlock - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bloodsail Warlock - Between 0-15% Health - Flee For Assist");

-- Wolf Master Nandos SAI
SET @ENTRY := 3927;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,80,33700,48800,11,7487,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wolf Master Nandos - Between 0-80% Health - Cast 7487 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,3,0,80,45400,51700,11,7488,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wolf Master Nandos - Between 0-80% Health - Cast 7488 (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,80,69500,69500,11,7489,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wolf Master Nandos - Between 0-80% Health - Cast 7489 (Normal Dungeon)"),
(@ENTRY,0,3,0,4,0,100,3,0,0,0,0,34,4,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wolf Master Nandos - On Aggro - Set Instance Data Field To 4 To Data 1 (Normal Dungeon)"),
(@ENTRY,0,4,0,6,0,100,3,0,0,0,0,34,4,3,0,0,0,0,1,0,0,0,0,0,0,0,"Wolf Master Nandos - On Death - Set Instance Data Field To 4 To Data 3 (Normal Dungeon)"),
(@ENTRY,0,5,0,7,0,100,3,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wolf Master Nandos - On Evade - Set Instance Data Field To 4 To Data 2 (Normal Dungeon)");

-- Fenrus the Devourer SAI
SET @ENTRY := 4274;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2600,7200,23300,49000,11,7125,0,0,0,0,0,5,0,0,0,0,0,0,0,"Fenrus the Devourer - In Combat - Cast 7125 (Normal Dungeon)"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,34,3,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fenrus the Devourer - On Aggro - Set Instance Data Field To 3 To Data 1 (Normal Dungeon)"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,34,3,3,0,0,0,0,1,0,0,0,0,0,0,0,"Fenrus the Devourer - On Death - Set Instance Data Field To 3 To Data 3 (Normal Dungeon)"),
(@ENTRY,0,3,0,7,0,100,3,0,0,0,0,34,3,2,0,0,0,0,1,0,0,0,0,0,0,0,"Fenrus the Devourer - On Evade - Set Instance Data Field To 3 To Data 2 (Normal Dungeon)");

-- Auchenai Vindicator SAI
SET @ENTRY := 18495;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,0,0,600000,600000,11,32861,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - Out Of Combat - Cast 32861 (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,4,0,0,600000,600000,11,38379,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - Out Of Combat - Cast 38379 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,2000,3000,7000,9000,11,17439,1,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Vindicator - In Combat - Cast 17439 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,2000,3000,7000,9000,11,17289,1,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Vindicator - In Combat - Cast 17289 (Heroic Dungeon)"),
(@ENTRY,0,4,0,4,0,20,7,0,0,0,0,11,32853,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - On Aggro - Cast 32853 (Dungeon Only)"),
(@ENTRY,0,5,0,4,0,20,7,0,0,0,0,11,32854,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - On Aggro - Cast 32854 (Dungeon Only)"),
(@ENTRY,0,6,0,4,0,20,7,0,0,0,0,11,32855,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - On Aggro - Cast 32855 (Dungeon Only)"),
(@ENTRY,0,7,0,4,0,20,7,0,0,0,0,11,32856,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - On Aggro - Cast 32856 (Dungeon Only)"),
(@ENTRY,0,8,0,4,0,20,7,0,0,0,0,11,32857,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - On Aggro - Cast 32857 (Dungeon Only)");

-- Auchenai Monk SAI
SET @ENTRY := 18497;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,90,6,8000,10000,0,0,11,32846,1,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Monk - On Target Casting - Cast 32846 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,10000,10000,10000,13000,11,32849,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Monk - In Combat - Cast 32849 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,5000,5000,5000,8000,11,37321,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Monk - In Combat - Cast 37321 (Dungeon Only)"),
(@ENTRY,0,3,0,1,0,100,6,0,0,180000,180000,11,38168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Monk - Out Of Combat - Cast 38168 (Dungeon Only)"),
(@ENTRY,0,4,0,4,0,20,7,0,0,0,0,11,32853,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Monk - On Aggro - Cast 32853 (Dungeon Only)"),
(@ENTRY,0,5,0,4,0,20,7,0,0,0,0,11,32854,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Monk - On Aggro - Cast 32854 (Dungeon Only)"),
(@ENTRY,0,6,0,4,0,20,7,0,0,0,0,11,32855,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Monk - On Aggro - Cast 32855 (Dungeon Only)"),
(@ENTRY,0,7,0,4,0,20,7,0,0,0,0,11,32856,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Monk - On Aggro - Cast 32856 (Dungeon Only)"),
(@ENTRY,0,8,0,4,0,20,7,0,0,0,0,11,32857,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Monk - On Aggro - Cast 32857 (Dungeon Only)");

-- Force-Commander Gorax SAI
SET @ENTRY := 19264;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - On Aggro - Cast 33962"),
(@ENTRY,0,1,0,0,0,100,0,500,1000,3800,6400,11,9080,32,0,0,0,0,2,0,0,0,0,0,0,0,"Force-Commander Gorax - In Combat - Cast 9080"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,33735,1,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - Between 0-30% Health - Cast 33735"),
(@ENTRY,0,3,0,0,0,100,0,10000,15000,12000,16000,11,24193,1,0,0,0,0,5,0,0,0,0,0,0,0,"Force-Commander Gorax - In Combat - Cast 24193"),
(@ENTRY,0,4,0,2,0,100,1,0,90,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - Between 0-90% Health - Cast 33962"),
(@ENTRY,0,5,0,2,0,100,1,0,80,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - Between 0-80% Health - Cast 33962"),
(@ENTRY,0,6,0,2,0,100,1,0,70,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - Between 0-70% Health - Cast 33962"),
(@ENTRY,0,7,0,2,0,100,1,0,60,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - Between 0-60% Health - Cast 33962"),
(@ENTRY,0,8,0,2,0,100,1,0,50,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - Between 0-50% Health - Cast 33962"),
(@ENTRY,0,9,0,2,0,100,1,0,40,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - Between 0-40% Health - Cast 33962"),
(@ENTRY,0,10,0,2,0,100,1,0,30,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - Between 0-30% Health - Cast 33962"),
(@ENTRY,0,11,0,2,0,100,1,0,20,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - Between 0-20% Health - Cast 33962"),
(@ENTRY,0,12,0,2,0,100,1,0,10,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - Between 0-10% Health - Cast 33962"),
(@ENTRY,0,13,0,6,0,100,1,0,0,0,0,11,39012,7,0,0,0,0,1,0,0,0,0,0,0,0,"Force-Commander Gorax - On Death - Cast 39012");

-- Twilight Drakonaar SAI
SET @ENTRY := 20910;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,7,0,0,0,0,34,8,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Drakonaar - On Aggro - Set Instance Data Field To 8 To Data 1 (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,31,1,5,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Drakonaar - On Aggro - Random Phase Range (1-5) (Dungeon Only)"),
(@ENTRY,0,2,0,6,0,100,7,0,0,0,0,34,8,3,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Drakonaar - On Death - Set Instance Data Field To 8 To Data 3 (Dungeon Only)"),
(@ENTRY,0,3,0,7,0,100,7,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Drakonaar - On Evade - Set Instance Data Field To 4 To Data 2 (Dungeon Only)"),
(@ENTRY,0,4,0,0,2,80,2,2000,2000,4000,6000,11,22560,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Drakonaar - In Combat - Cast 22560 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,0,0,2,80,4,5000,5000,8000,11500,11,39033,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Drakonaar - In Combat - Cast 39033 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,6,0,0,4,80,2,3000,3000,8000,12000,11,22559,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Drakonaar - In Combat - Cast 22559 (Normal Dungeon) (Phase 4)"),
(@ENTRY,0,7,0,0,4,80,4,1000,1000,12000,15500,11,39037,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Drakonaar - In Combat - Cast 39037 (Heroic Dungeon) (Phase 4)"),
(@ENTRY,0,8,0,0,8,90,2,5000,5000,10000,10000,11,22642,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Drakonaar - In Combat - Cast 22642 (Normal Dungeon) (Phase 8)"),
(@ENTRY,0,9,0,0,8,80,4,7000,7000,12000,15500,11,39036,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Drakonaar - In Combat - Cast 39036 (Heroic Dungeon) (Phase 8)"),
(@ENTRY,0,10,0,0,16,100,6,2000,2000,2000,4000,11,22561,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Drakonaar - In Combat - Cast 22561 (Dungeon Only) (Phase 16)"),
(@ENTRY,0,11,0,0,0,85,2,3000,3000,8000,10500,11,22558,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Drakonaar - In Combat - Cast 22558 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,85,4,6000,6000,12000,14000,11,39034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Drakonaar - In Combat - Cast 39034 (Heroic Dungeon)");

-- Iron Rune-Smith SAI
SET @ENTRY := 26408;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,33000,36000,11,52701,1,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune-Smith - In Combat - Cast 52701"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,9000,13000,11,52699,0,0,0,0,0,2,0,0,0,0,0,0,0,"Iron Rune-Smith - In Combat - Cast 52699"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune-Smith - On Death - Set Event Phase 1"),
(@ENTRY,0,3,4,8,1,100,1,48046,0,0,0,11,48047,0,0,0,0,0,7,0,0,0,0,0,0,0,"Iron Rune-Smith - On Spellhit By 48046 - Quest Credit (Phase 1)"),
(@ENTRY,0,4,0,61,1,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune-Smith - On Spellhit By 48046 - Forced Despawn (Phase 1)");

-- Dragonflayer Huscarl SAI
SET @ENTRY := 27260;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,6000,9000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Huscarl - Between 0-5 Range - Cast 40505"),
(@ENTRY,0,1,0,0,0,100,0,17000,23000,20000,23000,11,52223,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Huscarl - In Combat - Cast 52223"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,12000,15000,11,49807,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Huscarl - In Combat - Cast 49807"),
(@ENTRY,0,3,0,0,0,100,0,1000,3000,14000,20000,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Huscarl - In Combat - Cast 13730"),
(@ENTRY,0,4,0,9,0,100,0,0,5,10000,16000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Huscarl - Between 0-5 Range - Cast 6713"),
(@ENTRY,0,5,0,13,0,100,0,14000,17000,0,0,11,12555,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonflayer Huscarl - On Target Casting - Cast 12555");

-- Acolyte SAI
SET @ENTRY := 27731;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,14000,19000,11,20828,1,0,0,0,0,1,0,0,0,0,0,0,0,"Acolyte - Between 0-8 Range - Cast 20828 (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,4,0,8,14000,19000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Acolyte - Between 0-8 Range - Cast 15244 (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,2,0,20,8000,13000,11,20832,0,0,0,0,0,2,0,0,0,0,0,0,0,"Acolyte - Between 0-20 Range - Cast 20832 (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,4,0,20,8000,13000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Acolyte - Between 0-20 Range - Cast 14145 (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,4000,8000,7000,10000,11,17439,0,0,0,0,0,5,0,0,0,0,0,0,0,"Acolyte - In Combat - Cast 17439 (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,4,4000,8000,7000,10000,11,17234,0,0,0,0,0,5,0,0,0,0,0,0,0,"Acolyte - In Combat - Cast 17234 (Heroic Dungeon)"),
(@ENTRY,0,6,0,0,0,100,2,6000,10000,20000,30000,11,39621,32,0,0,0,0,5,0,0,0,0,0,0,0,"Acolyte - In Combat - Cast 39621 (Normal Dungeon)"),
(@ENTRY,0,7,0,0,0,100,4,6000,10000,20000,30000,11,58811,32,0,0,0,0,5,0,0,0,0,0,0,0,"Acolyte - In Combat - Cast 58811 (Heroic Dungeon)"),
(@ENTRY,0,8,0,0,0,100,2,11000,15000,35000,45000,11,14875,1,0,0,0,0,6,0,0,0,0,0,0,0,"Acolyte - In Combat - Cast 14875 (Normal Dungeon)"),
(@ENTRY,0,9,0,0,0,100,4,11000,15000,35000,45000,11,46190,1,0,0,0,0,6,0,0,0,0,0,0,0,"Acolyte - In Combat - Cast 46190 (Heroic Dungeon)");

-- Stratholme Citizen SAI
SET @ENTRY := 28340;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,9000,13000,11,52633,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stratholme Citizen - Between 0-5 Range - Cast 52633 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,9000,15000,12000,18000,11,52636,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stratholme Citizen - In Combat - Cast 52636 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,2,16000,21000,21000,29000,11,52634,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stratholme Citizen - In Combat - Cast 52634 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,16000,21000,21000,29000,11,58813,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stratholme Citizen - In Combat - Cast 58813 (Heroic Dungeon)"),
(@ENTRY,0,4,0,8,0,100,2,0,127,0,0,11,52635,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stratholme Citizen - On Spellhit By 0 - Cast 52635 (Normal Dungeon)"),
(@ENTRY,0,5,0,8,0,100,4,0,127,0,0,11,58820,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stratholme Citizen - On Spellhit By 0 - Cast 58820 (Heroic Dungeon)");

-- Nerubian Cocoon SAI
SET @ENTRY := 28413;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nerubian Cocoon - On Respawn - Disallow Combat Movement"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,18,2097152,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nerubian Cocoon - On Respawn - Set Disarmed Flag"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nerubian Cocoon - On Respawn - Increment Event Phase"),
(@ENTRY,0,3,0,6,0,40,1,0,0,0,0,11,51599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nerubian Cocoon - On Death - Summon Creature Captive Footman"),
(@ENTRY,0,4,0,6,0,40,1,0,0,0,0,33,28415,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nerubian Cocoon - On Death - Quest Credit"),
(@ENTRY,0,5,0,6,0,40,1,0,0,0,0,11,51597,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nerubian Cocoon - On Death - Summon Creature Drakkari Captive"),
(@ENTRY,0,6,0,6,0,20,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nerubian Cocoon - On Death - Forced Despawn");

-- Elemental Rift SAI
SET @ENTRY := 28452;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elemental Rift - On Respawn - Stop Auto Attack"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elemental Rift - On Respawn - Disallow Combat Movement"),
(@ENTRY,0,2,0,0,0,100,1,1000,1000,0,0,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elemental Rift - In Combat - Cast 12058"),
(@ENTRY,0,3,0,0,0,100,1,5000,5000,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elemental Rift - In Combat - Cast 9672"),
(@ENTRY,0,4,0,0,0,100,1,10000,10000,0,0,11,51648,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elemental Rift - In Combat - Cast 51648"),
(@ENTRY,0,5,0,0,0,100,1,40000,40000,0,0,11,51648,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elemental Rift - In Combat - Cast 51648"),
(@ENTRY,0,6,0,0,0,100,1,70000,70000,0,0,11,51648,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elemental Rift - In Combat - Cast 51648");

-- Impale Target SAI
SET @ENTRY := 29184;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Impale Target - On Respawn - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,7,100,100,0,0,11,53455,7,0,0,0,0,1,0,0,0,0,0,0,0,"Impale Target - In Combat - Cast 53455 (Dungeon Only)"),
(@ENTRY,0,2,3,9,0,100,7,0,1,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Impale Target - Between 0-1 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Impale Target - Between 0-1 Range - Set Event Phase 1 (Dungeon Only)"),
(@ENTRY,0,4,0,0,0,100,3,3000,3000,0,0,11,53454,7,0,0,0,0,1,0,0,0,0,0,0,0,"Impale Target - In Combat - Cast 53454 (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,5,3000,3000,0,0,11,59446,7,0,0,0,0,1,0,0,0,0,0,0,0,"Impale Target - In Combat - Cast 59446 (Heroic Dungeon)"),
(@ENTRY,0,6,0,0,0,100,7,4000,5000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Impale Target - In Combat - Forced Despawn (Dungeon Only)");

-- Dragonblight Mage Hunter SAI
SET @ENTRY := 32572;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,0,4,12000,15000,11,51758,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Spellhit By school 4 - Cast 51758"),
(@ENTRY,0,1,0,8,0,100,0,0,16,12000,15000,11,51763,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Spellhit By school 16 - Cast 51763"),
(@ENTRY,0,2,0,8,0,100,0,0,32,12000,15000,11,51764,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Spellhit By school 32 - Cast 51764"),
(@ENTRY,0,3,0,8,0,100,0,0,64,12000,15000,11,51766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Spellhit By school 64 - Cast 51766");

-- North Sea Kraken SAI
SET @ENTRY := 34925;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Sea Kraken - On Aggro - Set Event Phase 1"),
(@ENTRY,0,1,0,0,0,100,1,6000,9000,7000,9000,11,66514,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Sea Kraken - In Combat - Cast 66514"),
(@ENTRY,0,2,0,8,1,100,1,66588,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Sea Kraken - On Spellhit By 66588 - Increment Event Phase (Phase 1)"),
(@ENTRY,0,3,0,8,2,100,1,66588,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Sea Kraken - On Spellhit By 66588 - Increment Event Phase (Phase 2)"),
(@ENTRY,0,4,0,8,4,100,1,66588,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Sea Kraken - On Spellhit By 66588 - Increment Event Phase (Phase 4)"),
(@ENTRY,0,5,0,8,8,100,1,66588,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Sea Kraken - On Spellhit By 66588 - Increment Event Phase (Phase 8)"),
(@ENTRY,0,6,0,8,16,100,1,66588,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Sea Kraken - On Spellhit By 66588 - Increment Event Phase (Phase 16)"),
(@ENTRY,0,7,8,8,32,100,1,66588,0,0,0,11,66717,1,0,0,0,0,7,0,0,0,0,0,0,0,"North Sea Kraken - On Spellhit By 66588 - Cast 66717"),
(@ENTRY,0,8,0,61,32,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Sea Kraken - On Spellhit By 66588 - Forced Despawn");

-- Bloodsail Elder Magus SAI
SET @ENTRY := 1653;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Elder Magus - On Aggro - Cast 20823"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Between 0-40 Range - Cast 20823 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,28700,28700,45200,45200,11,20827,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Elder Magus - In Combat - Cast 20827"),
(@ENTRY,0,11,0,0,0,100,0,14900,14900,43000,43000,11,11969,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - In Combat - Cast 11969"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Between 0-15% Health - Flee For Assist");

-- Defias Watchman SAI
SET @ENTRY := 1725;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Watchman - On Aggro - Cast 6660 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,2,100,2,5,30,2200,3800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Watchman - Between 5-30 Range - Cast 6660 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 25-80 Range - Start Auto Attack (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,8,10,9,2,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 0-5 Range - Set Sheath Melee (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 0-5 Range - Start Auto Attack (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 5-15 Range - Stop Auto Attack (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,13,14,2,0,100,3,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 0-15% Health - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Watchman - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,16,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Watchman - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Defias Magician SAI
SET @ENTRY := 1726;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Magician - On Aggro - Cast 9053 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,2,100,2,0,40,4000,6600,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Magician - Between 0-40 Range - Cast 9053 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 4)"),
(@ENTRY,0,11,0,0,0,100,2,0,0,23200,38500,11,5110,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - In Combat - Cast 5110 (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Magician - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Magician - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Skeletal Sorcerer SAI
SET @ENTRY := 1784;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Sorcerer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Sorcerer - On Aggro - Cast 9672"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Sorcerer - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Sorcerer - Between 0-40 Range - Cast 9672 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Sorcerer - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Sorcerer - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Sorcerer - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Sorcerer - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Sorcerer - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Sorcerer - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,4000,8000,12000,20000,11,11969,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Sorcerer - In Combat - Cast 11969");

-- Skeletal Acolyte SAI
SET @ENTRY := 1789;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Acolyte - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Acolyte - On Aggro - Cast 20825"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Acolyte - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,1500,2800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Acolyte - Between 0-40 Range - Cast 20825 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Acolyte - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Acolyte - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Acolyte - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Acolyte - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Acolyte - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Acolyte - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,5000,8000,11000,15000,11,14887,0,0,0,0,0,5,0,0,0,0,0,0,0,"Skeletal Acolyte - In Combat - Cast 14887"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,16588,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Acolyte - Between 0-30% Health - Cast 16588");

-- Scarlet Mage SAI
SET @ENTRY := 1826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Mage - On Aggro - Cast 20822"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Mage - Between 0-40 Range - Cast 20823 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,9000,12000,9000,12000,11,20822,1,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Mage - In Combat - Cast 20822"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Mage - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Mage - Between 0-15% Health - Flee For Assist");

-- Scarlet Hunter SAI
SET @ENTRY := 1831;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Hunter - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Hunter - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Hunter - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Hunter - On Evade - Set Sheath Melee");

-- Scarlet Magus SAI
SET @ENTRY := 1832;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magus - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Magus - On Aggro - Cast 9053"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magus - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Magus - Between 0-40 Range - Cast 9053 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magus - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magus - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magus - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magus - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magus - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magus - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,5000,10000,14000,19000,11,17203,1,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Magus - In Combat - Cast 17203"),
(@ENTRY,0,11,0,0,0,100,0,10000,12000,18000,25000,11,15744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Magus - In Combat - Cast 15744"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magus - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magus - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Magus - Between 0-15% Health - Flee For Assist");

-- Araj the Summoner SAI
SET @ENTRY := 1852;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Araj the Summoner - On Aggro - Cast 15497"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Araj the Summoner - Between 0-40 Range - Cast 15497 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,5000,8000,14000,20000,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - In Combat - Cast 15532"),
(@ENTRY,0,11,0,0,0,100,0,18000,24000,50000,65000,11,17231,1,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - In Combat - Cast 17231"),
(@ENTRY,0,12,0,6,0,100,1,0,0,0,0,11,18661,7,0,0,0,0,1,0,0,0,0,0,0,0,"Araj the Summoner - On Death - Cast 18661");

-- Deeb SAI
SET @ENTRY := 1911;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeb - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deeb - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeb - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deeb - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeb - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeb - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeb - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeb - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeb - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deeb - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,2000,6000,6000,10000,11,2607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deeb - In Combat - Cast 2607"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeb - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeb - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Deeb - Between 0-15% Health - Flee For Assist");
