-- Wastewander Shadow Mage SAI
SET @ENTRY := 5617;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Out Of Combat - Cast 12746"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Shadow Mage - On Aggro - Cast 20825"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Between 0-40 Range - Cast 20825 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,0,6000,9000,19000,26000,11,20826,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewander Shadow Mage - In Combat - Cast 20826"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Wastewander Shadow Mage - Between 0-15% Health - Flee For Assist");

-- Sandfury Axe Thrower SAI
SET @ENTRY := 5646;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Axe Thrower - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2200,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 5-30 Range - Cast 10277 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sandfury Axe Thrower - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Axe Thrower - On Evade - Set Sheath Melee");

-- Sandfury Firecaller SAI
SET @ENTRY := 5647;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Firecaller - On Aggro - Cast 20823"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 0-40 Range - Cast 20823 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,85,0,8000,14000,20000,26000,11,11990,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Firecaller - In Combat - Cast 11990"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sandfury Firecaller - Between 0-15% Health - Flee For Assist");

-- Ogom the Wretched SAI
SET @ENTRY := 5711;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogom the Wretched - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,3,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogom the Wretched - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ogom the Wretched - On Aggro - Cast 12471 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogom the Wretched - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,3400,4800,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ogom the Wretched - Between 0-40 Range - Cast 12471 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogom the Wretched - Between 0-7% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogom the Wretched - Between 0-7% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogom the Wretched - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogom the Wretched - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ogom the Wretched - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,2,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ogom the Wretched - Between 15-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,9100,15200,37900,57700,11,11639,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ogom the Wretched - In Combat - Cast 11639 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,54300,54300,20700,26200,11,12493,33,0,0,0,0,5,0,0,0,0,0,0,0,"Ogom the Wretched - In Combat - Cast 12493 (Normal Dungeon)");

-- Hukku SAI
SET @ENTRY := 5715;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,3,1000,1000,0,0,11,12790,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku - Out Of Combat - Cast 12790 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hukku - On Aggro - Cast 12471 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3400,4800,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hukku - Between 0-40 Range - Cast 12471 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,2,0,30,16400,29900,11,9081,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hukku - Between 0-30 Range - Cast 9081 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,3,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku - Between 0-7% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku - Between 0-7% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,2,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku - Between 15-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,9400,18200,21200,31300,11,12279,32,0,0,0,0,5,0,0,0,0,0,0,0,"Hukku - In Combat - Cast 12279 (Normal Dungeon)");

-- Felweaver Scornn SAI
SET @ENTRY := 5822;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felweaver Scornn - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,5600,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felweaver Scornn - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,11,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Felweaver Scornn - Between 0-15% Health - Flee For Assist");

-- Azzere the Skyblade SAI
SET @ENTRY := 5834;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azzere the Skyblade - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azzere the Skyblade - On Aggro - Cast 13375"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azzere the Skyblade - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azzere the Skyblade - Between 0-40 Range - Cast 13375 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azzere the Skyblade - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azzere the Skyblade - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azzere the Skyblade - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azzere the Skyblade - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azzere the Skyblade - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azzere the Skyblade - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,80,0,4000,9000,22000,29000,11,6725,1,0,0,0,0,2,0,0,0,0,0,0,0,"Azzere the Skyblade - In Combat - Cast 6725");

-- Brokespear SAI
SET @ENTRY := 5838;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brokespear - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brokespear - Between 5-30 Range - Cast 10277 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,0,6000,12000,9000,15000,11,7992,32,0,0,0,0,5,0,0,0,0,0,0,0,"Brokespear - In Combat - Cast 7992"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Brokespear - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - On Evade - Set Sheath Melee");

-- Heggin Stonewhisker SAI
SET @ENTRY := 5847;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Heggin Stonewhisker - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,0,6000,12000,9000,14000,11,6979,40,0,0,0,0,2,0,0,0,0,0,0,0,"Heggin Stonewhisker - In Combat - Cast 6979"),
(@ENTRY,0,14,0,0,0,100,0,6000,12000,9000,14000,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - In Combat - Set Faction 0"),
(@ENTRY,0,15,16,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - On Evade - Set Sheath Melee");

-- Baelog SAI
SET @ENTRY := 6906;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baelog - On Aggro - Cast 15620 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,1,100,2,5,30,2300,3900,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baelog - Between 5-30 Range - Cast 15620 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Between 25-80 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Between 0-5 Range - Set Sheath Melee (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Between 0-5 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Between 5-15 Range - Stop Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,2,4000,7000,9000,13000,11,14516,1,0,0,0,0,2,0,0,0,0,0,0,0,"Baelog - In Combat - Cast 14516 (Normal Dungeon)"),
(@ENTRY,0,14,15,2,0,100,3,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Between 0-15% Health - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Baelog - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,17,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Revelosh SAI
SET @ENTRY := 6910;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revelosh - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Revelosh - On Aggro - Cast 15801 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revelosh - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Revelosh - Between 0-40 Range - Cast 15801 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revelosh - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revelosh - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revelosh - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revelosh - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revelosh - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Revelosh - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,2,8000,13000,18000,25000,11,16006,1,0,0,0,0,2,0,0,0,0,0,0,0,"Revelosh - In Combat - Cast 16006 (Normal Dungeon)"),
(@ENTRY,0,11,12,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revelosh - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revelosh - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Revelosh - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Black Broodling SAI
SET @ENTRY := 7047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Broodling - On Aggro - Cast 13375"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2800,3600,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Broodling - Between 0-40 Range - Cast 13375 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,8,1,100,1,16007,0,0,0,23,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - On Spellhit By 16007 - Increment Event Phase (Phase 1)"),
(@ENTRY,0,11,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,12,0,8,2,100,1,16007,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - On Spellhit By 16007 - Increment Event Phase (Phase 2)"),
(@ENTRY,0,13,0,9,4,100,0,0,40,2800,3600,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Broodling - Between 0-40 Range - Cast 13375 (Phase 3)"),
(@ENTRY,0,14,15,3,4,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 0-15% Mana - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,15,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 0-15% Mana - Increment Event Phase (Phase 3)"),
(@ENTRY,0,16,0,9,4,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 35-80 Range - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,17,0,9,4,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 5-15 Range - Disallow Combat Movement (Phase 3)"),
(@ENTRY,0,18,0,9,4,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 0-5 Range - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,19,0,0,4,100,0,0,0,1000,1000,11,47704,33,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - In Combat - Cast 47704 (Phase 3)"),
(@ENTRY,0,20,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,21,0,0,0,100,0,0,0,1000,1000,11,47704,33,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - In Combat - Cast 47704"),
(@ENTRY,0,22,0,6,0,100,1,0,0,0,0,11,16027,7,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - On Death - Cast 16027");

-- Scalding Broodling SAI
SET @ENTRY := 7048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalding Broodling - On Aggro - Cast 13375"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2800,3600,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalding Broodling - Between 0-40 Range - Cast 13375 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,8,1,100,1,16007,0,0,0,23,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - On Spellhit By 16007 - Increment Event Phase (Phase 1)"),
(@ENTRY,0,11,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,12,0,8,2,100,1,16007,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - On Spellhit By 16007 - Increment Event Phase (Phase 2)"),
(@ENTRY,0,13,0,9,4,100,0,0,40,2800,3600,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalding Broodling - Between 0-40 Range - Cast 13375 (Phase 3)"),
(@ENTRY,0,14,15,3,4,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 0-15% Mana - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,15,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 0-15% Mana - Increment Event Phase (Phase 3)"),
(@ENTRY,0,16,0,9,4,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 35-80 Range - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,17,0,9,4,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 5-15 Range - Disallow Combat Movement (Phase 3)"),
(@ENTRY,0,18,0,9,4,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 0-5 Range - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,19,0,0,4,100,0,0,0,1000,1000,11,47704,33,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - In Combat - Cast 47704 (Phase 3)"),
(@ENTRY,0,20,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,21,0,0,0,100,0,0,0,1000,1000,11,47704,33,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - In Combat - Cast 47704"),
(@ENTRY,0,22,0,6,0,100,1,0,0,0,0,11,16027,7,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - On Death - Cast 16027");

-- Flamescale Broodling SAI
SET @ENTRY := 7049;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamescale Broodling - On Aggro - Cast 13375"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2800,3600,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamescale Broodling - Between 0-40 Range - Cast 13375 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,8,1,100,1,16007,0,0,0,23,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - On Spellhit By 16007 - Increment Event Phase (Phase 1)"),
(@ENTRY,0,11,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,12,0,8,2,100,1,16007,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - On Spellhit By 16007 - Increment Event Phase (Phase 2)"),
(@ENTRY,0,13,0,9,4,100,0,0,40,2800,3600,11,13375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamescale Broodling - Between 0-40 Range - Cast 13375 (Phase 3)"),
(@ENTRY,0,14,15,3,4,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 0-15% Mana - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,15,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 0-15% Mana - Increment Event Phase (Phase 3)"),
(@ENTRY,0,16,0,9,4,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 35-80 Range - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,17,0,9,4,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 5-15 Range - Disallow Combat Movement (Phase 3)"),
(@ENTRY,0,18,0,9,4,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 0-5 Range - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,19,0,0,4,100,0,0,0,1000,1000,11,47704,33,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - In Combat - Cast 47704 (Phase 3)"),
(@ENTRY,0,20,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,21,0,0,0,100,0,0,0,1000,1000,11,47704,33,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - In Combat - Cast 47704"),
(@ENTRY,0,22,0,0,0,100,0,6700,12700,8200,13300,11,13342,1,0,0,0,0,2,0,0,0,0,0,0,0,"Flamescale Broodling - In Combat - Cast 13342"),
(@ENTRY,0,23,0,6,0,100,1,0,0,0,0,11,16027,7,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - On Death - Cast 16027");

-- Jaedenar Warlock SAI
SET @ENTRY := 7120;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Out Of Combat - Cast 11939"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Warlock - On Aggro - Cast 9613"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,8699,1,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 0-30% Health - Cast 8699"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 0-15% Health - Flee For Assist");

-- Deadwood Pathfinder SAI
SET @ENTRY := 7155;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Pathfinder - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2200,3800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Pathfinder - Between 5-30 Range - Cast 6660"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,10,0,9,0,100,0,0,5,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,13,14,9,0,100,0,5,30,6000,12000,11,6685,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Pathfinder - Between 5-30 Range - Cast 6685"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,15,0,0,0,100,0,5000,9000,125000,130000,11,13583,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Pathfinder - In Combat - Cast 13583"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Pathfinder - On Evade - Set Sheath Melee");

-- Deadwood Shaman SAI
SET @ENTRY := 7158;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,600000,600000,11,13585,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - Out Of Combat - Cast 13585"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Shaman - On Aggro - Cast 9532"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Shaman - Between 0-40 Range - Cast 9532 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,0,0,100,0,2500,7000,120000,130000,11,13583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Shaman - In Combat - Cast 13583"),
(@ENTRY,0,12,0,0,0,100,0,5500,9000,6500,9500,11,12058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Shaman - In Combat - Cast 12058");

-- Shadowforge Sharpshooter SAI
SET @ENTRY := 7290;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - On Aggro - Cast 6660 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,1,100,2,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 5-30 Range - Cast 6660 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 25-80 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 0-5 Range - Set Sheath Melee (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 0-5 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 5-15 Range - Stop Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,13,14,0,1,100,2,9000,13000,30000,36000,11,6685,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - In Combat - Cast 6685 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - In Combat - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,15,16,2,0,100,3,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 0-15% Health - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,18,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Death's Head Geomancer SAI
SET @ENTRY := 7335;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Geomancer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Geomancer - On Aggro - Cast 9053 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Geomancer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Geomancer - Between 0-40 Range - Cast 9053 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Geomancer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Geomancer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Geomancer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Geomancer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Geomancer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Geomancer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,2,8000,10000,6000,15000,11,6725,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death's Head Geomancer - In Combat - Cast 6725 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,12000,16000,8000,20000,11,11436,1,0,0,0,0,5,0,0,0,0,0,0,0,"Death's Head Geomancer - In Combat - Cast 11436 (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Geomancer - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Geomancer - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Death's Head Geomancer - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Death's Head Necromancer SAI
SET @ENTRY := 7337;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,3,1000,1000,0,0,11,12420,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Out Of Combat - Cast 12420 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,11445,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - On Aggro - Cast 11445 (Normal Dungeon)"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Necromancer - On Aggro - Cast 9613 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Necromancer - Between 0-40 Range - Cast 9613 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,12,0,0,0,100,2,8000,15000,18000,25000,11,11443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Necromancer - In Combat - Cast 11443 (Normal Dungeon)"),
(@ENTRY,0,13,14,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Death's Head Necromancer - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Dark Keeper Ofgut SAI
SET @ENTRY := 9442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Ofgut - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Ofgut - On Aggro - Cast 15230 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Ofgut - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Ofgut - Between 0-40 Range - Cast 15230 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Ofgut - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Ofgut - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Ofgut - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Ofgut - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Ofgut - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Ofgut - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,7000,12000,18000,24000,11,7121,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Ofgut - In Combat - Cast 7121 (Normal Dungeon)");

-- Dark Keeper Pelver SAI
SET @ENTRY := 9443;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Pelver - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Pelver - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Pelver - On Aggro - Cast 12675 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Pelver - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Pelver - Between 0-40 Range - Cast 12675 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Pelver - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Pelver - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Pelver - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Pelver - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Pelver - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Pelver - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)");

-- Bloodaxe Evoker SAI
SET @ENTRY := 9693;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,13748,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodaxe Evoker - On Aggro - Cast 13748 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,13748,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodaxe Evoker - Between 0-40 Range - Cast 13748 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,0,0,75,2,12000,14000,25000,30000,11,15743,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - In Combat - Cast 15743 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,80,2,7000,9000,15000,20000,11,15744,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - In Combat - Cast 15744 (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bloodaxe Evoker - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Bloodaxe Summoner SAI
SET @ENTRY := 9717;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Summoner - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodaxe Summoner - On Aggro - Cast 15791 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Summoner - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,5800,11,15791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodaxe Summoner - Between 0-40 Range - Cast 15791 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Summoner - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Summoner - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Summoner - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Summoner - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Summoner - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Summoner - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,90,2,6000,9000,13000,18000,11,15532,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Summoner - In Combat - Cast 15532 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,75,2,8000,12000,25000,30000,11,15734,1,0,0,0,0,6,0,0,0,0,0,0,0,"Bloodaxe Summoner - In Combat - Cast 15734 (Normal Dungeon)");

-- Skul SAI
SET @ENTRY := 10393;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,16799,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skul - On Aggro - Cast 16799 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,16799,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skul - Between 0-40 Range - Cast 16799 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,0,0,0,50,2,6000,8000,16000,20000,11,15499,1,0,0,0,0,5,0,0,0,0,0,0,0,"Skul - In Combat - Cast 15499 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,40,2,9000,11000,9000,11000,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skul - In Combat - Cast 15230 (Normal Dungeon)"),
(@ENTRY,0,13,14,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skul - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skul - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Crimson Sorcerer SAI
SET @ENTRY := 10422;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - In Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - Out Of Combat - Cast 12544"),
(@ENTRY,0,2,0,1,0,100,0,3000,3000,1800000,1800000,11,17150,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - Out Of Combat - Cast 17150"),
(@ENTRY,0,3,4,4,0,100,1,0,0,0,0,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Sorcerer - On Aggro - Cast 15230"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,0,9,1,100,0,0,40,2400,3800,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Sorcerer - Between 0-40 Range - Cast 15230 (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Sorcerer - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,12,0,0,0,100,2,7000,14000,21000,26000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Crimson Sorcerer - In Combat - Cast 13323 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,5000,6000,8500,10000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Sorcerer - In Combat - Cast 14145 (Normal Dungeon)");

-- Chromatic Whelp SAI
SET @ENTRY := 10442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chromatic Whelp - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,16249,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Whelp - On Aggro - Cast 16249 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chromatic Whelp - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,12167,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Whelp - Between 0-40 Range - Cast 12167 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chromatic Whelp - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chromatic Whelp - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chromatic Whelp - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chromatic Whelp - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chromatic Whelp - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Chromatic Whelp - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,16200,26500,7000,27900,11,16249,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Whelp - In Combat - Cast 16249 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,10800,19600,15700,20400,11,16250,1,0,0,0,0,2,0,0,0,0,0,0,0,"Chromatic Whelp - In Combat - Cast 16250 (Normal Dungeon)");

-- Scholomance Adept SAI
SET @ENTRY := 10469;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Adept - On Aggro - Cast 15043 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3200,4800,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Adept - Between 0-40 Range - Cast 15043 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,2,7300,17300,9400,14300,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - In Combat - Cast 15244 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,7600,19700,12200,24700,11,15499,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Adept - In Combat - Cast 15499 (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Adept - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scholomance Adept - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Scholomance Necrolyte SAI
SET @ENTRY := 10476;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Necrolyte - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Necrolyte - On Aggro - Cast 12739 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Necrolyte - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Necrolyte - Between 0-40 Range - Cast 12739 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Necrolyte - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Necrolyte - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Necrolyte - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Necrolyte - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Necrolyte - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Necrolyte - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,1400,6200,7400,22000,11,17234,1,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Necrolyte - In Combat - Cast 17234 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,1400,22000,22000,33200,11,17151,32,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Necrolyte - In Combat - Cast 17151 (Normal Dungeon)");

-- Urok Ogre Magus SAI
SET @ENTRY := 10602;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15979,0,0,0,0,0,2,0,0,0,0,0,0,0,"Urok Ogre Magus - On Aggro - Cast 15979 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15979,0,0,0,0,0,2,0,0,0,0,0,0,0,"Urok Ogre Magus - Between 0-40 Range - Cast 15979 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,8000,11000,17000,24000,11,13747,1,0,0,0,0,5,0,0,0,0,0,0,0,"Urok Ogre Magus - In Combat - Cast 13747 (Normal Dungeon)"),
(@ENTRY,0,11,0,2,0,100,2,0,30,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Urok Ogre Magus - Between 0-30% Health - Cast 6742 (Normal Dungeon)");

-- Crimson Rifleman SAI
SET @ENTRY := 11054;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,17353,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Rifleman - On Aggro - Cast 17353 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,3,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,5,30,2300,3900,11,17353,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Rifleman - Between 5-30 Range - Cast 17353 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,7,9,0,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - Between 25-80 Range - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - Between 25-80 Range - Start Auto Attack (Normal Dungeon)"),
(@ENTRY,0,8,9,9,0,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - Between 0-5 Range - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - Between 0-5 Range - Set Sheath Melee (Normal Dungeon)"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - Between 0-5 Range - Start Auto Attack (Normal Dungeon)"),
(@ENTRY,0,11,12,9,0,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - Between 5-15 Range - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,13,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Rifleman - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Highborne Summoner SAI
SET @ENTRY := 11466;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Summoner - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highborne Summoner - On Aggro - Cast 12466 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Summoner - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highborne Summoner - Between 0-40 Range - Cast 12466 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Summoner - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Summoner - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Summoner - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Summoner - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Summoner - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Summoner - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,8000,11000,9000,12000,11,13341,0,0,0,0,0,5,0,0,0,0,0,0,0,"Highborne Summoner - In Combat - Cast 13341 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,12000,16000,18000,22000,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Summoner - In Combat - Cast 15063 (Normal Dungeon)");

-- Prince Raze SAI
SET @ENTRY := 10647;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Raze - On Aggro - Cast 9053"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,4700,5800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Raze - Between 0-40 Range - Cast 9053 (Phase 1)"),
(@ENTRY,0,5,0,9,1,100,0,0,40,13000,16000,11,16570,1,0,0,0,0,5,0,0,0,0,0,0,0,"Prince Raze - Between 0-40 Range - Cast 16570 (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,12,0,9,0,100,0,0,8,12000,18000,11,11969,1,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Between 0-8 Range - Cast 11969"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Prince Raze - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Between 0-15% Health - Cast 6925");

-- Eldreth Apparition SAI
SET @ENTRY := 11471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Apparition - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,18100,1,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Apparition - Out Of Combat - Cast 18100 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,16799,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Apparition - On Aggro - Cast 16799 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Apparition - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,16799,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Apparition - Between 0-40 Range - Cast 16799 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Apparition - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Apparition - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Apparition - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Apparition - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Apparition - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Apparition - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,7000,12000,20000,27500,11,22744,1,0,0,0,0,6,0,0,0,0,0,0,0,"Eldreth Apparition - In Combat - Cast 22744 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,11000,14000,20000,30000,11,15244,1,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Apparition - In Combat - Cast 15244 (Normal Dungeon)");

-- Alzzin the Wildshaper SAI
SET @ENTRY := 11492;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alzzin the Wildshaper - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,1,0,0,1,100,2,4000,8000,14000,18000,11,22691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alzzin the Wildshaper - In Combat - Cast 22691 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,2,0,0,1,100,2,2000,5000,15000,20000,11,22661,0,0,0,0,0,5,0,0,0,0,0,0,0,"Alzzin the Wildshaper - In Combat - Cast 22661 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,3,0,0,1,100,2,10000,12000,12000,16000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alzzin the Wildshaper - In Combat - Cast 10101 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,2,1,100,3,0,80,0,0,11,22660,1,0,0,0,0,1,0,0,0,0,0,0,0,"Alzzin the Wildshaper - Between 0-80% Health - Cast 22660 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alzzin the Wildshaper - Between 0-80% Health - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,0,2,100,2,2000,5000,3000,6000,11,19319,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alzzin the Wildshaper - In Combat - Cast 19319 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,0,2,100,2,4000,8000,20000,25000,11,22689,1,0,0,0,0,2,0,0,0,0,0,0,0,"Alzzin the Wildshaper - In Combat - Cast 22689 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,8,9,2,2,100,3,0,60,0,0,11,22688,1,0,0,0,0,1,0,0,0,0,0,0,0,"Alzzin the Wildshaper - Between 0-60% Health - Cast 22688 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alzzin the Wildshaper - Between 0-60% Health - Increment Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,2,1000,3000,3000,6000,11,22128,32,0,0,0,0,1,0,0,0,0,0,0,0,"Alzzin the Wildshaper - In Combat - Cast 22128 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,2000,4000,5000,10000,11,22662,32,0,0,0,0,5,0,0,0,0,0,0,0,"Alzzin the Wildshaper - In Combat - Cast 22662 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,7000,10000,9000,14000,11,7948,33,0,0,0,0,1,0,0,0,0,0,0,0,"Alzzin the Wildshaper - In Combat - Cast 7948 (Normal Dungeon)"),
(@ENTRY,0,13,14,2,0,100,3,0,40,0,0,28,22688,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alzzin the Wildshaper - Between 0-40% Health - Remove Aura 22688 (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,23,0,2,0,0,0,0,1,0,0,0,0,0,0,0,"Alzzin the Wildshaper - Between 0-40% Health - Decrement Event Phase (Normal Dungeon)");

-- Irondeep Shaman SAI
SET @ENTRY := 11600;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Shaman - On Aggro - Cast 15801 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,3400,4800,11,15801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Shaman - Between 0-40 Range - Cast 15801 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,2,7000,9000,55000,65000,11,15786,1,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - In Combat - Cast 15786 (Normal Dungeon)"),
(@ENTRY,0,12,0,2,0,100,2,0,50,15000,20000,11,12492,1,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Between 0-50% Health - Cast 12492 (Normal Dungeon)"),
(@ENTRY,0,13,14,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Irondeep Shaman - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Whitewhisker Geomancer SAI
SET @ENTRY := 11604;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,500,1000,600000,600000,11,18968,1,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - In Combat - Cast 18968 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Whitewhisker Geomancer - On Aggro - Cast 15228 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3400,4800,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Between 0-40 Range - Cast 15228 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Morloch SAI
SET @ENTRY := 11657;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morloch - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morloch - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,2,1000,1000,0,0,11,11939,1,0,0,0,0,1,0,0,0,0,0,0,0,"Morloch - Out Of Combat - Cast 11939 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morloch - On Aggro - Cast 15537 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morloch - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,0,9,1,100,2,0,40,3400,4800,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morloch - Between 0-40 Range - Cast 15537 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morloch - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morloch - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morloch - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morloch - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morloch - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Morloch - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,6000,9000,120000,130000,11,12741,1,0,0,0,0,2,0,0,0,0,0,0,0,"Morloch - In Combat - Cast 12741 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,11000,14000,9000,15000,11,17228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morloch - In Combat - Cast 17228 (Normal Dungeon)");

-- Snowblind Windcaller SAI
SET @ENTRY := 11675;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Windcaller - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Windcaller - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowblind Windcaller - On Aggro - Cast 9532 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Windcaller - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,3400,4800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowblind Windcaller - Between 0-40 Range - Cast 9532 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Windcaller - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Windcaller - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Windcaller - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Windcaller - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Windcaller - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Windcaller - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,5000,8000,12000,16000,11,9532,1,0,0,0,0,6,0,0,0,0,0,0,0,"Snowblind Windcaller - In Combat - Cast 9532 (Normal Dungeon)");

-- Warsong Shaman SAI
SET @ENTRY := 11683;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20805,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Shaman - On Aggro - Cast 20805"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,3400,4800,11,20805,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-40 Range - Cast 20805 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,2,0,100,0,0,30,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-30% Health - Cast 6742"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-15% Health - Flee For Assist");

-- Wildpaw Mystic SAI
SET @ENTRY := 11838;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - Out Of Combat - Set Event Phase 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,37361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildpaw Mystic - On Aggro - Cast 37361 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,3400,4800,11,37361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildpaw Mystic - Between 0-40 Range - Cast 37361 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,2,6000,9000,16000,19000,11,12058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wildpaw Mystic - In Combat - Cast 12058 (Normal Dungeon)"),
(@ENTRY,0,12,0,2,0,100,2,0,50,12000,16000,11,11986,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - Between 0-50% Health - Cast 11986 (Normal Dungeon)");

-- Ambassador Malcin SAI
SET @ENTRY := 12865;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Malcin - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ambassador Malcin - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Malcin - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ambassador Malcin - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Malcin - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Malcin - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Malcin - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Malcin - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Malcin - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Malcin - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,5000,9000,15000,25000,11,8282,32,0,0,0,0,2,0,0,0,0,0,0,0,"Ambassador Malcin - In Combat - Cast 8282");

-- Baron Aquanis SAI
SET @ENTRY := 12876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Aquanis - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baron Aquanis - On Aggro - Cast 15043 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Aquanis - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baron Aquanis - Between 0-40 Range - Cast 15043 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Aquanis - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Aquanis - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Aquanis - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Aquanis - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Aquanis - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Aquanis - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,7000,12000,14000,19000,11,14907,1,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Aquanis - In Combat - Cast 14907 (Normal Dungeon)");

-- Lorgus Jett SAI
SET @ENTRY := 12902;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorgus Jett - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,600000,600000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lorgus Jett - Out Of Combat - Cast 12550 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,12167,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lorgus Jett - On Aggro - Cast 12167 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorgus Jett - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,12167,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lorgus Jett - Between 0-40 Range - Cast 12167 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorgus Jett - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorgus Jett - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorgus Jett - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorgus Jett - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorgus Jett - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lorgus Jett - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)");

-- Hearthsinger Forresten SAI
SET @ENTRY := 10558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hearthsinger Forresten - On Aggro - Cast 16100 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,1,100,2,5,30,2300,3900,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 5-30 Range - Cast 16100 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 25-80 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 0-5 Range - Set Sheath Melee (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 0-5 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 5-15 Range - Stop Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,13,14,0,0,100,2,9000,14000,9000,14000,11,14443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Hearthsinger Forresten - In Combat - Cast 14443 (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - In Combat - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,15,0,0,0,100,2,3000,5000,12000,19000,11,16244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - In Combat - Cast 16244 (Normal Dungeon)"),
(@ENTRY,0,16,0,0,0,100,2,7000,9000,20000,25000,11,16798,1,0,0,0,0,6,0,0,0,0,0,0,0,"Hearthsinger Forresten - In Combat - Cast 16798 (Normal Dungeon)"),
(@ENTRY,0,17,18,2,0,100,3,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 0-15% Health - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Hearthsinger Forresten - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,20,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hearthsinger Forresten - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Mastok Wrilehiss SAI
SET @ENTRY := 12737;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mastok Wrilehiss - On Aggro - Cast 15620"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mastok Wrilehiss - Between 5-30 Range - Cast 15620"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,13,0,9,0,100,0,0,5,5000,7000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mastok Wrilehiss - Between 0-5 Range - Cast 15284"),
(@ENTRY,0,14,0,0,0,100,0,9000,15000,14000,18000,11,23600,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - In Combat - Cast 23600"),
(@ENTRY,0,15,0,2,0,100,0,0,30,120000,130000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - On Evade - Set Sheath Melee");
