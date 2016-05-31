-- Coldmine Explorer SAI
SET @ENTRY := 13096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Explorer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Explorer - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Explorer - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Explorer - On Aggro - Cast 15242 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Explorer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3400,4800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Explorer - Between 0-40 Range - Cast 15242 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Explorer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Explorer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Explorer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Explorer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Explorer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Explorer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,9000,13000,10000,15000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmine Explorer - In Combat - Cast 14145 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,15000,19000,16000,21000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coldmine Explorer - In Combat - Cast 15244 (Normal Dungeon)");

-- Irondeep Explorer SAI
SET @ENTRY := 13099;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Explorer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,3,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Explorer - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Explorer - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Explorer - On Aggro - Cast 15242 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Explorer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3400,4800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Explorer - Between 0-40 Range - Cast 15242 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Explorer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Explorer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Explorer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Explorer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Explorer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Explorer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,9000,13000,10000,15000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Explorer - In Combat - Cast 14145 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,15000,19000,16000,21000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Explorer - In Combat - Cast 15244 (Normal Dungeon)");

-- Seasoned Coldmine Explorer SAI
SET @ENTRY := 13546;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - On Aggro - Cast 15242 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3400,4800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - Between 0-40 Range - Cast 15242 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,9000,13000,10000,15000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - In Combat - Cast 14145 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,15000,19000,16000,21000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - In Combat - Cast 15244 (Normal Dungeon)");

-- Veteran Coldmine Explorer SAI
SET @ENTRY := 13547;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - On Aggro - Cast 15242 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3400,4800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - Between 0-40 Range - Cast 15242 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,9000,13000,10000,15000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - In Combat - Cast 14145 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,15000,19000,16000,21000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - In Combat - Cast 15244 (Normal Dungeon)");

-- Champion Coldmine Explorer SAI
SET @ENTRY := 13548;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Explorer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Explorer - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Explorer - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Coldmine Explorer - On Aggro - Cast 15242 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Explorer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3400,4800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Coldmine Explorer - Between 0-40 Range - Cast 15242 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Explorer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Explorer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Explorer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Explorer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Explorer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Explorer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,9000,13000,10000,15000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Coldmine Explorer - In Combat - Cast 14145 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,15000,19000,16000,21000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Coldmine Explorer - In Combat - Cast 15244 (Normal Dungeon)");

-- Ashenvale Outrunner SAI
SET @ENTRY := 12856;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,20540,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - On Respawn - Cast 20540"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Outrunner - On Aggro - Cast 6660"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 5-30 Range - Cast 6660"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,0,100,0,5,30,35900,52300,11,18545,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 5-30 Range - Cast 18545"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,8,9,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,10,11,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,13,14,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,15,0,9,0,100,0,0,5,7100,15300,11,8646,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Outrunner - Between 0-5 Range - Cast 8646"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Outrunner - On Evade - Set Sheath Melee");

-- Warsong Scout SAI
SET @ENTRY := 12862;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Scout - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Scout - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Warsong Scout - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - On Evade - Set Sheath Melee");

-- Warsong Runner SAI
SET @ENTRY := 12863;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Runner - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Runner - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Warsong Runner - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - On Evade - Set Sheath Melee");

-- Warsong Outrider SAI
SET @ENTRY := 12864;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Outrider - On Aggro - Cast 6660"),
(@ENTRY,0,3,4,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Outrider - Between 5-30 Range - Cast 6660"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,5,6,9,0,100,0,5,30,35900,52300,11,18545,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Outrider - Between 5-30 Range - Cast 18545"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,7,8,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,9,10,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Outrider - On Evade - Set Sheath Melee");

-- Silverwing Sentinel SAI
SET @ENTRY := 12896;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silverwing Sentinel - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Silverwing Sentinel - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - On Evade - Set Sheath Melee");

-- Primalist Thurloga SAI
SET @ENTRY := 13236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primalist Thurloga - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primalist Thurloga - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Primalist Thurloga - On Aggro - Cast 15234 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primalist Thurloga - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,3400,4800,11,15234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Primalist Thurloga - Between 0-40 Range - Cast 15234 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primalist Thurloga - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primalist Thurloga - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primalist Thurloga - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primalist Thurloga - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primalist Thurloga - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Primalist Thurloga - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,9000,13000,11000,15000,11,16006,1,0,0,0,0,2,0,0,0,0,0,0,0,"Primalist Thurloga - In Combat - Cast 16006 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,7000,8000,14000,17000,11,15616,0,0,0,0,0,5,0,0,0,0,0,0,0,"Primalist Thurloga - In Combat - Cast 15616 (Normal Dungeon)"),
(@ENTRY,0,13,0,2,0,100,2,0,50,48000,60000,11,15786,1,0,0,0,0,1,0,0,0,0,0,0,0,"Primalist Thurloga - Between 0-50% Health - Cast 15786 (Normal Dungeon)"),
(@ENTRY,0,14,0,2,0,100,2,0,30,15000,22000,11,15982,1,0,0,0,0,1,0,0,0,0,0,0,0,"Primalist Thurloga - Between 0-30% Health - Cast 15982 (Normal Dungeon)");

-- Lokholar the Ice Lord SAI
SET @ENTRY := 13256;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lokholar the Ice Lord - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lokholar the Ice Lord - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,21369,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lokholar the Ice Lord - On Aggro - Cast 21369 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lokholar the Ice Lord - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,3400,4800,11,21369,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lokholar the Ice Lord - Between 0-40 Range - Cast 21369 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lokholar the Ice Lord - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lokholar the Ice Lord - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lokholar the Ice Lord - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lokholar the Ice Lord - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lokholar the Ice Lord - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lokholar the Ice Lord - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,9000,14000,16000,19000,11,14907,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lokholar the Ice Lord - In Combat - Cast 14907 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,15000,20000,16000,19000,11,19133,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lokholar the Ice Lord - In Combat - Cast 19133 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,4000,6000,3400,4800,11,21367,1,0,0,0,0,6,0,0,0,0,0,0,0,"Lokholar the Ice Lord - In Combat - Cast 21367 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,2,11000,16000,10000,14000,11,16869,1,0,0,0,0,6,0,0,0,0,0,0,0,"Lokholar the Ice Lord - In Combat - Cast 16869 (Normal Dungeon)"),
(@ENTRY,0,15,0,5,0,100,3,0,0,0,0,11,21307,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lokholar the Ice Lord - On Killed Unit - Cast 21307 (Normal Dungeon)");

-- Seasoned Irondeep Explorer SAI
SET @ENTRY := 13540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - On Aggro - Cast 15242 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3400,4800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - Between 0-40 Range - Cast 15242 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,9000,13000,10000,15000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - In Combat - Cast 14145 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,15000,19000,16000,21000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - In Combat - Cast 15244 (Normal Dungeon)");

-- Veteran Irondeep Explorer SAI
SET @ENTRY := 13541;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - On Aggro - Cast 15242 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3400,4800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - Between 0-40 Range - Cast 15242 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,9000,13000,10000,15000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - In Combat - Cast 14145 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,15000,19000,16000,21000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - In Combat - Cast 15244 (Normal Dungeon)");

-- Champion Irondeep Explorer SAI
SET @ENTRY := 13542;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Explorer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Explorer - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Explorer - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Irondeep Explorer - On Aggro - Cast 15242 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Explorer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3400,4800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Irondeep Explorer - Between 0-40 Range - Cast 15242 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Explorer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Explorer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Explorer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Explorer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Explorer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Explorer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,9000,13000,10000,15000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Champion Irondeep Explorer - In Combat - Cast 14145 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,15000,19000,16000,21000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Champion Irondeep Explorer - In Combat - Cast 15244 (Normal Dungeon)");

-- Cho'Rush the Observer SAI
SET @ENTRY := 14324;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,3,0,0,0,0,30,1,4,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - In Combat - Set Random Phase (Normal Dungeon)"),
(@ENTRY,0,2,0,4,1,100,3,0,0,0,0,11,15234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cho'Rush the Observer - On Aggro - Cast 15234 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 0-40 Range - Cast 15234 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,0,1,100,2,9000,14000,10000,12000,11,15305,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cho'Rush the Observer - In Combat - Cast 15305 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,0,1,100,2,7000,12000,35000,40000,11,8376,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - In Combat - Cast 8376 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,2,1,100,2,0,50,15000,22000,11,15982,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 0-50% Health - Cast 15982 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,12,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,13,0,4,4,100,3,0,0,0,0,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cho'Rush the Observer - On Aggro - Cast 17290 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,14,0,9,4,100,2,0,30,2400,3800,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 0-30 Range - Cast 17290 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,15,16,3,4,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,16,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,17,0,9,4,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,18,0,9,4,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,19,0,9,4,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,20,0,0,4,100,2,8000,11000,10000,14000,11,15531,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - In Combat - Cast 15531 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,21,0,0,4,100,2,16000,20000,10000,14000,11,13745,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - In Combat - Cast 13745 (Normal Dungeon) (Phase 3)"),
(@ENTRY,0,22,0,3,8,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 4)"),
(@ENTRY,0,23,0,1,0,100,2,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Out Of Combat - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,24,0,0,0,100,2,2000,4000,4000,6000,11,17194,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cho'Rush the Observer - In Combat - Cast 17194 (Normal Dungeon)"),
(@ENTRY,0,25,0,0,0,100,2,12000,15000,40000,50000,11,17139,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - In Combat - Cast 17139 (Normal Dungeon)"),
(@ENTRY,0,26,0,0,0,100,2,9000,11000,19000,24000,11,22884,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - In Combat - Cast 22884 (Normal Dungeon)"),
(@ENTRY,0,27,0,2,0,100,2,0,30,10000,15000,11,16170,33,0,0,0,0,1,0,0,0,0,0,0,0,"Cho'Rush the Observer - Between 0-30% Health - Cast 16170 (Normal Dungeon)");

-- Lethtendris SAI
SET @ENTRY := 14327;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lethtendris - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,22709,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lethtendris - On Aggro - Cast 22709"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lethtendris - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,100,4800,6800,11,22709,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lethtendris - Between 0-100 Range - Cast 22709 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lethtendris - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lethtendris - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,45,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lethtendris - Between 45-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lethtendris - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lethtendris - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,20,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lethtendris - Between 20-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,2,7000,12000,25000,30000,11,12742,1,0,0,0,0,5,0,0,0,0,0,0,0,"Lethtendris - In Combat - Cast 12742 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,8000,13000,13000,18000,11,17228,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lethtendris - In Combat - Cast 17228 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,2000,9000,15000,35000,11,16247,33,0,0,0,0,2,0,0,0,0,0,0,0,"Lethtendris - In Combat - Cast 16247 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,9000,12000,18000,22000,11,13338,33,0,0,0,0,6,0,0,0,0,0,0,0,"Lethtendris - In Combat - Cast 13338 (Normal Dungeon)");

-- Pimgib SAI
SET @ENTRY := 14349;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pimgib - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pimgib - On Aggro - Cast 15228 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pimgib - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pimgib - Between 0-40 Range - Cast 15228 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pimgib - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pimgib - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pimgib - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pimgib - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pimgib - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Pimgib - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,8000,12000,11000,15000,11,16046,1,0,0,0,0,1,0,0,0,0,0,0,0,"Pimgib - In Combat - Cast 16046 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,5000,7000,14000,19000,11,22713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pimgib - In Combat - Cast 22713 (Normal Dungeon)"),
(@ENTRY,0,12,0,2,0,100,2,0,50,30000,30000,11,22710,1,0,0,0,0,1,0,0,0,0,0,0,0,"Pimgib - Between 0-50% Health - Cast 22710 (Normal Dungeon)");

-- Silverwing Elite SAI
SET @ENTRY := 14715;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silverwing Elite - On Aggro - Cast 15620"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,4800,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silverwing Elite - Between 5-30 Range - Cast 15620 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,5,6100,15900,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silverwing Elite - Between 0-5 Range - Cast 15496"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Silverwing Elite - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Elite - On Evade - Set Sheath Melee");

-- Sentinel Farsong SAI
SET @ENTRY := 14733;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Farsong - On Aggro - Cast 15620"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Farsong - Between 5-30 Range - Cast 15620 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sentinel Farsong - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Farsong - On Evade - Set Sheath Melee");

-- Bonechewer Backbreaker SAI
SET @ENTRY := 16810;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Backbreaker - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Backbreaker - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Backbreaker - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Backbreaker - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Backbreaker - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Backbreaker - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Backbreaker - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Backbreaker - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Backbreaker - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Backbreaker - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,7000,11000,9000,14000,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Backbreaker - In Combat - Cast 16583"),
(@ENTRY,0,11,0,2,0,100,0,0,30,30000,30000,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Backbreaker - Between 0-30% Health - Cast 6742");

-- Gan'arg Engineer SAI
SET @ENTRY := 16948;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gan'arg Engineer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,7978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gan'arg Engineer - On Aggro - Cast 7978"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gan'arg Engineer - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,30,4000,6000,11,7978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gan'arg Engineer - Between 0-30 Range - Cast 7978 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gan'arg Engineer - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gan'arg Engineer - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gan'arg Engineer - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gan'arg Engineer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gan'arg Engineer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gan'arg Engineer - Between 15-100% Mana - Decrement Event Phase");

-- Angered Nether-wraith SAI
SET @ENTRY := 17870;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angered Nether-wraith - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,39337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Angered Nether-wraith - On Aggro - Cast 39337"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angered Nether-wraith - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,4000,5500,11,39337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Angered Nether-wraith - Between 0-40 Range - Cast 39337 (Phase 1)"),
(@ENTRY,0,4,0,0,1,100,0,13000,16000,12000,17000,11,38205,1,0,0,0,0,2,0,0,0,0,0,0,0,"Angered Nether-wraith - In Combat - Cast 38205 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angered Nether-wraith - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angered Nether-wraith - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angered Nether-wraith - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angered Nether-wraith - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angered Nether-wraith - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Angered Nether-wraith - Between 15-100% Mana - Decrement Event Phase (Phase 2)");
