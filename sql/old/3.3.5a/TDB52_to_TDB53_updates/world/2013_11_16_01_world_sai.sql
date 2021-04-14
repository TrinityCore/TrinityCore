-- Scarshield Grunt <Scarshield Legion> SAI fix
UPDATE `smart_scripts` SET `event_flags`=0, `comment`= 'Scarshield Grunt - Between 0-5 Range - Cast 11976' WHERE `entryorguid`=9043;

-- Shadow Sprite SAI
SET @ENTRY := 2003;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadow Sprite - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadow Sprite - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadow Sprite - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadow Sprite - Between 0-40 Range - Cast 9613 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadow Sprite - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadow Sprite - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadow Sprite - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadow Sprite - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadow Sprite - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadow Sprite - Between 30-100% Mana - Decrement Event Phase");

-- Bloodfeather Matriarch SAI
SET @ENTRY := 2021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Matriarch - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfeather Matriarch - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Matriarch - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfeather Matriarch - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Matriarch - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Matriarch - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Matriarch - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Matriarch - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Matriarch - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Matriarch - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,2,0,100,0,0,50,18000,24000,11,332,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Matriarch - Between 0-50% Health - Cast 332");

-- Greymist Oracle SAI
SET @ENTRY := 2207;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Oracle - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greymist Oracle - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Oracle - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greymist Oracle - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Oracle - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Oracle - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Oracle - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Oracle - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Oracle - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Oracle - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,14,0,100,0,190,40,30000,45000,11,913,0,0,0,0,0,7,0,0,0,0,0,0,0,"Greymist Oracle - On Friendly Unit At 190 Health Within 40 Range - Cast 913"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Oracle - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greymist Oracle - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Greymist Oracle - Between 0-15% Health - Flee For Assist");

-- Dark Strand Voidcaller SAI
SET @ENTRY := 2337;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Out Of Combat - Cast 12746"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Strand Voidcaller - On Aggro - Cast 20807"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,2400,3800,11,20807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Between 0-40 Range - Cast 20807 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Strand Voidcaller - Between 0-15% Health - Flee For Assist");

-- Captain Keelhaul SAI
SET @ENTRY := 2548;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Keelhaul - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2200,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Keelhaul - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,14,9,0,100,0,5,30,15600,32700,11,7896,1,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Keelhaul - Between 5-30 Range - Cast 7896"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,15,0,0,0,100,0,1200,3200,17200,25200,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - In Combat - Cast 13730"),
(@ENTRY,0,16,17,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Captain Keelhaul - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,19,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - On Evade - Set Sheath Melee");

-- Vilebranch Axe Thrower SAI
SET @ENTRY := 2639;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2200,3800,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 5-30 Range - Cast 10277 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vilebranch Axe Thrower - On Evade - Set Sheath Melee");

-- Bristleback Shaman SAI
SET @ENTRY := 2953;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Shaman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Shaman - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Shaman - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Shaman - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Shaman - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Shaman - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Shaman - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Shaman - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Shaman - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Shaman - Between 30-100% Mana - Decrement Event Phase");

-- Vile Familiar SAI
SET @ENTRY := 3101;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,11921,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Familiar - On Aggro - Cast 11921"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,4800,6800,11,11921,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Familiar - Between 0-40 Range - Cast 11921 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Vile Familiar - Between 0-15% Health - Flee For Assist");

-- Razormane Scout SAI
SET @ENTRY := 3112;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Scout - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2200,3800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Scout - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Razormane Scout - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - On Evade - Set Sheath Melee");

-- Dustwind Storm Witch SAI
SET @ENTRY := 3118;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwind Storm Witch - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,11,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 0-15% Health - Flee For Assist");

-- Kolkar Outrunner SAI
SET @ENTRY := 3120;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Outrunner - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2200,3800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kolkar Outrunner - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Outrunner - On Evade - Set Sheath Melee");

-- Burning Blade Apprentice SAI
SET @ENTRY := 3198;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Out Of Combat - Cast 12746"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Apprentice - On Aggro - Cast 20791"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,2400,3800,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 0-40 Range - Cast 20791 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 0-15% Health - Flee For Assist");

-- Fizzle Darkstorm SAI
SET @ENTRY := 3203;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Darkstorm - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Darkstorm - Out Of Combat - Cast 11939"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fizzle Darkstorm - On Aggro - Cast 20791"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Darkstorm - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,2400,3800,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fizzle Darkstorm - Between 0-40 Range - Cast 20791 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Darkstorm - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Darkstorm - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Darkstorm - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Darkstorm - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Darkstorm - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Darkstorm - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,0,2,0,100,0,0,50,20000,30000,11,7290,1,0,0,0,0,2,0,0,0,0,0,0,0,"Fizzle Darkstorm - Between 0-50% Health - Cast 7290"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Darkstorm - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle Darkstorm - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Fizzle Darkstorm - Between 0-15% Health - Flee For Assist");

-- Gazz'uz SAI
SET @ENTRY := 3204;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,20798,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Out Of Combat - Cast 20798"),
(@ENTRY,0,2,0,1,0,100,1,3000,3000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Out Of Combat - Cast 12746"),
(@ENTRY,0,3,4,4,0,100,1,0,0,0,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gazz'uz - On Aggro - Cast 20791"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,0,9,2,100,0,0,40,3400,5200,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gazz'uz - Between 0-40 Range - Cast 20791 (Phase 2)"),
(@ENTRY,0,6,7,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,11,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,12,0,0,0,100,0,5000,8000,30000,45000,11,172,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gazz'uz - In Combat - Cast 172"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gazz'uz - Between 0-15% Health - Flee For Assist");

-- Thunderhawk Hatchling SAI
SET @ENTRY := 3247;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhawk Hatchling - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,600000,600000,11,325,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhawk Hatchling - Out Of Combat - Cast 325"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhawk Hatchling - On Aggro - Cast 9532"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhawk Hatchling - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhawk Hatchling - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhawk Hatchling - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhawk Hatchling - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhawk Hatchling - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhawk Hatchling - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhawk Hatchling - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhawk Hatchling - Between 30-100% Mana - Decrement Event Phase");

-- Bristleback Hunter SAI
SET @ENTRY := 3258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Hunter - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Hunter - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,0,0,2,100,0,9000,14000,9000,14000,11,8806,32,0,0,0,0,5,0,0,0,0,0,0,0,"Bristleback Hunter - In Combat - Cast 8806 (Phase 2)"),
(@ENTRY,0,14,0,0,2,100,0,9000,14000,9000,14000,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - In Combat - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,15,16,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bristleback Hunter - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Hunter - On Evade - Set Sheath Melee");

-- Bristleback Geomancer SAI
SET @ENTRY := 3263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Geomancer - On Aggro - Cast 20793"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Geomancer - Between 0-40 Range - Cast 20793 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,0,8000,13000,18000,25000,11,20794,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Geomancer - In Combat - Cast 20794"),
(@ENTRY,0,11,0,0,0,100,0,5000,6500,17000,22000,11,4979,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - In Combat - Cast 4979"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Geomancer - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bristleback Geomancer - Between 0-15% Health - Flee For Assist");

-- Razormane Hunter SAI
SET @ENTRY := 3265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Hunter - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,6,9,2,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Hunter - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Razormane Hunter - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Hunter - On Evade - Set Sheath Melee");

-- Razormane Geomancer SAI
SET @ENTRY := 3269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - Out Of Combat - Cast 12544"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Geomancer - On Aggro - Cast 20793"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,2400,3800,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Geomancer - Between 0-40 Range - Cast 20793 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Geomancer - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Razormane Geomancer - Between 0-15% Health - Flee For Assist");

-- Kolkar Wrangler SAI
SET @ENTRY := 3272;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Wrangler - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,0,4000,6000,9000,14000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Wrangler - In Combat - Cast 12024"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kolkar Wrangler - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Wrangler - On Evade - Set Sheath Melee");

-- Kolkar Stormer SAI
SET @ENTRY := 3273;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Stormer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,6535,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Stormer - On Aggro - Cast 6535"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Stormer - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Stormer - Between 0-40 Range - Cast 9532 (Phase 2)"),
(@ENTRY,0,4,5,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Stormer - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Stormer - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Stormer - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Stormer - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Stormer - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Stormer - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,11,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Stormer - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Stormer - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kolkar Stormer - Between 0-15% Health - Flee For Assist");

-- Bael'dun Rifleman SAI
SET @ENTRY := 3377;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'dun Rifleman - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bael'dun Rifleman - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Rifleman - On Evade - Set Sheath Melee");
