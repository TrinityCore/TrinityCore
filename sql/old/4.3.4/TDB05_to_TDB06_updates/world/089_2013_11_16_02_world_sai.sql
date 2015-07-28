-- Barak Kodobane SAI
SET @ENTRY := 3394;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Barak Kodobane - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Barak Kodobane - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,0,2000,5000,12000,15000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Barak Kodobane - In Combat - Cast 6533"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Barak Kodobane - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barak Kodobane - On Evade - Set Sheath Melee");

-- Nak SAI
SET @ENTRY := 3434;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nak - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nak - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,2,0,100,0,0,100,17500,22500,11,8004,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - Between 0-100% Health - Cast 8004"),
(@ENTRY,0,11,0,0,0,100,1,6000,12000,0,0,11,8154,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nak - In Combat - Cast 8154");

-- Kuz SAI
SET @ENTRY := 3436;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kuz - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kuz - On Aggro - Cast 20792"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kuz - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kuz - Between 0-40 Range - Cast 20792 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kuz - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kuz - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kuz - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kuz - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kuz - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Kuz - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,5000,9000,9000,12000,11,20795,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kuz - In Combat - Cast 20795"),
(@ENTRY,0,11,0,0,0,100,0,8000,12000,12000,16000,11,11831,1,0,0,0,0,2,0,0,0,0,0,0,0,"Kuz - In Combat - Cast 11831");

-- Razormane Pathfinder SAI
SET @ENTRY := 3456;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Pathfinder - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,0,4000,6000,5000,7000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Pathfinder - In Combat - Cast 3391"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Razormane Pathfinder - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Pathfinder - On Evade - Set Sheath Melee");

-- Delmanis the Hated SAI
SET @ENTRY := 3662;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delmanis the Hated - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Delmanis the Hated - On Aggro - Cast 20792"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delmanis the Hated - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Delmanis the Hated - Between 0-40 Range - Cast 20792 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delmanis the Hated - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delmanis the Hated - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delmanis the Hated - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delmanis the Hated - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delmanis the Hated - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Delmanis the Hated - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,6000,10000,12000,16000,11,7101,1,0,0,0,0,2,0,0,0,0,0,0,0,"Delmanis the Hated - In Combat - Cast 7101"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delmanis the Hated - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delmanis the Hated - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Delmanis the Hated - Between 0-15% Health - Flee For Assist");

-- Ilkrud Magthrull SAI
SET @ENTRY := 3664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,0,1,0,100,1,1000,1000,0,0,11,8722,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Out Of Combat - Cast 8722"),
(@ENTRY,0,3,4,4,0,100,1,0,0,0,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ilkrud Magthrull - On Aggro - Cast 20791"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,0,9,2,100,0,0,40,3400,4800,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ilkrud Magthrull - Between 0-40 Range - Cast 20791 (Phase 2)"),
(@ENTRY,0,6,7,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,11,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,12,0,2,0,100,0,0,50,66500,76300,11,6487,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ilkrud Magthrull - Between 0-50% Health - Cast 6487");

-- Boahn SAI
SET @ENTRY := 3672;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boahn - On Aggro - Cast 9532 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,2,100,2,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boahn - Between 0-40 Range - Cast 9532 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 4)"),
(@ENTRY,0,10,0,2,0,100,2,0,40,30000,40000,11,5187,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Between 0-40% Health - Cast 5187 (Normal Dungeon)"),
(@ENTRY,0,11,12,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boahn - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Boahn - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Raene Wolfrunner SAI
SET @ENTRY := 3691;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raene Wolfrunner - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,5,30,9000,13000,11,21390,0,0,0,0,0,5,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 5-30 Range - Cast 21390 (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,5,30,12000,16000,11,15495,0,0,0,0,0,5,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 5-30 Range - Cast 15495 (Phase 2)"),
(@ENTRY,0,9,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,10,11,0,2,100,0,18000,25000,60000,70000,11,22908,1,0,0,0,0,5,0,0,0,0,0,0,0,"Raene Wolfrunner - In Combat - Cast 22908 (Phase 2)"),
(@ENTRY,0,11,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - In Combat - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,12,13,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,13,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,14,15,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,15,16,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,16,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,17,18,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,18,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,19,0,9,0,100,0,0,20,11000,13000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 0-20 Range - Cast 6533"),
(@ENTRY,0,20,21,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,21,22,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,22,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Raene Wolfrunner - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,23,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raene Wolfrunner - On Evade - Set Sheath Melee");

-- Ran Bloodtooth SAI
SET @ENTRY := 3696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ran Bloodtooth - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,5,30,9000,14000,11,14443,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 5-30 Range - Cast 14443 (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,10,11,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,11,12,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,13,14,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,14,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,15,16,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - On Evade - Set Sheath Melee");

-- Wrathtail Sea Witch SAI
SET @ENTRY := 3715;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,8598,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Sea Witch - On Aggro - Cast 8598"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,30,3500,5000,11,8598,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 0-30 Range - Cast 8598 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,25,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 25-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,0,9,0,100,0,0,10,20900,33500,11,2691,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 0-10 Range - Cast 2691"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 0-15% Health - Flee For Assist");

-- Wrathtail Sorceress SAI
SET @ENTRY := 3717;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Sorceress - On Aggro - Cast 20792"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,3400,4800,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 0-40 Range - Cast 20792 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,25,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 25-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,0,0,0,100,0,4500,15700,14100,32600,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - In Combat - Cast 11831"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 0-15% Health - Flee For Assist");

-- Dark Strand Cultist SAI
SET @ENTRY := 3725;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Cultist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Cultist - Out Of Combat - Cast 11939"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Strand Cultist - On Aggro - Cast 20791"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Cultist - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,3900,5900,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Strand Cultist - Between 0-40 Range - Cast 20791 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Cultist - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Cultist - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Cultist - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Cultist - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Cultist - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Cultist - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,0,0,100,0,3700,4600,10900,11300,11,6222,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Strand Cultist - In Combat - Cast 6222");

-- Dark Strand Adept SAI
SET @ENTRY := 3728;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Out Of Combat - Cast 12746"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Strand Adept - On Aggro - Cast 20791"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,3400,5800,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Strand Adept - Between 0-40 Range - Cast 20791 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Adept - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Strand Adept - Between 0-15% Health - Flee For Assist");

-- Apothecary Falthis SAI
SET @ENTRY := 3735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Apothecary Falthis - On Aggro - Cast 20791"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,3400,4800,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Apothecary Falthis - Between 0-40 Range - Cast 20791 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Between 0-7% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Between 0-7% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Between 15-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Apothecary Falthis - Between 0-15% Health - Flee For Assist");

-- Saltspittle Muckdweller SAI
SET @ENTRY := 3740;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saltspittle Muckdweller - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 5-30 Range - Cast 10277 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Saltspittle Muckdweller - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltspittle Muckdweller - On Evade - Set Sheath Melee");

-- Foulweald Pathfinder SAI
SET @ENTRY := 3745;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,1,0,100,1,0,0,0,0,11,6820,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Out Of Combat - Cast 6820"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foulweald Pathfinder - On Aggro - Cast 6660"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,6,9,2,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,7,8,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,9,10,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,11,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,11,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,12,13,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,13,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - On Evade - Set Sheath Melee");

-- Xavian Hellcaller SAI
SET @ENTRY := 3757;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Xavian Hellcaller - On Aggro - Cast 9053"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,4700,5800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 0-40 Range - Cast 9053 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 0-7% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 0-7% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 15-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 0-15% Health - Cast 6925");

-- Severed Druid SAI
SET @ENTRY := 3799;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Severed Druid - On Aggro - Cast 9739"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,3400,4800,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Severed Druid - Between 0-40 Range - Cast 9739 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,0,100,0,25,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - Between 25-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,2,0,100,0,0,75,20600,80800,11,1430,1,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - Between 0-75% Health - Cast 1430");

-- Forsaken Dark Stalker SAI
SET @ENTRY := 3808;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,8218,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - On Respawn - Cast 8218"),
(@ENTRY,0,3,4,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Forsaken Dark Stalker - On Aggro - Cast 10277"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,6,9,2,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 5-30 Range - Cast 10277 (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,7,8,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,9,10,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,11,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,11,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,12,13,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,13,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Forsaken Dark Stalker - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Dark Stalker - On Evade - Set Sheath Melee");

-- Thistlefur Pathfinder SAI
SET @ENTRY := 3926;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,6813,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - On Respawn - Cast 6813"),
(@ENTRY,0,3,4,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thistlefur Pathfinder - On Aggro - Cast 6660"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,6,9,2,100,0,5,30,2300,2800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,7,8,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,9,10,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,11,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,11,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,12,13,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,13,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - On Evade - Set Sheath Melee");

-- Bloodfury Storm Witch SAI
SET @ENTRY := 4027;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Storm Witch - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfury Storm Witch - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Storm Witch - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfury Storm Witch - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Storm Witch - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Storm Witch - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Storm Witch - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Storm Witch - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Storm Witch - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfury Storm Witch - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,6000,10000,40000,45000,11,6535,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfury Storm Witch - In Combat - Cast 6535");

-- Daughter of Cenarius SAI
SET @ENTRY := 4053;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Daughter of Cenarius - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 5-30 Range - Cast 10277 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,0,6000,6000,10000,12000,11,527,1,0,0,0,0,2,0,0,0,0,0,0,0,"Daughter of Cenarius - In Combat - Cast 527"),
(@ENTRY,0,14,0,0,0,100,0,4500,4500,6000,10000,11,527,1,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - In Combat - Cast 527"),
(@ENTRY,0,15,16,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - On Evade - Set Sheath Melee");
