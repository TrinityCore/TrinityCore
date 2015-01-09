-- Stars' Rest Sentinel SAI
SET @ENTRY := 26448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stars' Rest Sentinel - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,8,100,9000,13000,11,47059,1,0,0,0,0,2,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Between 8-100 Range - Cast 47059 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Between 8-100 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,12,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,15,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stars' Rest Sentinel - On Evade - Set Sheath Melee");

-- Drakkari Shaman SAI
SET @ENTRY := 26639;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,48895,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Shaman - On Aggro - Cast 48895 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4800,11,48895,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Shaman - Between 0-40 Range - Cast 48895 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,59006,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Shaman - On Aggro - Cast 59006 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,3400,4800,11,59006,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Shaman - Between 0-40 Range - Cast 59006 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 15-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,2,0,100,6,0,30,30000,45000,11,47668,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 0-30% Health - Cast 47668 (Dungeon Only)"),
(@ENTRY,0,14,0,14,0,100,6,15000,45,6000,9000,11,59473,1,0,0,0,0,7,0,0,0,0,0,0,0,"Drakkari Shaman - On Friendly Unit At 15000 Health Within 45 Range - Cast 59473 (Dungeon Only)");

-- High Cultist Zangus SAI
SET @ENTRY := 26655;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Cultist Zangus - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Cultist Zangus - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Cultist Zangus - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Cultist Zangus - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Cultist Zangus - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Cultist Zangus - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Cultist Zangus - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Cultist Zangus - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Cultist Zangus - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,4,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"High Cultist Zangus - Between 15-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,10,0,2,0,100,0,0,30,120000,125000,11,51605,1,0,0,0,0,1,0,0,0,0,0,0,0,"High Cultist Zangus - Between 0-30% Health - Cast 51605");

-- Grumbald One-Eye SAI
SET @ENTRY := 26681;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grumbald One-Eye - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grumbald One-Eye - On Aggro - Cast 51779"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grumbald One-Eye - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grumbald One-Eye - Between 0-40 Range - Cast 51779 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grumbald One-Eye - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grumbald One-Eye - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grumbald One-Eye - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grumbald One-Eye - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grumbald One-Eye - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grumbald One-Eye - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,9000,16000,9000,15000,11,13339,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grumbald One-Eye - In Combat - Cast 13339"),
(@ENTRY,0,11,0,9,0,100,2,0,8,18000,21000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grumbald One-Eye - Between 0-8 Range - Cast 11831 (Normal Dungeon)"),
(@ENTRY,0,12,0,2,0,100,0,0,30,120000,130000,11,52495,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grumbald One-Eye - Between 0-30% Health - Cast 52495");

-- Galak Wrangler SAI
SET @ENTRY := 4093;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Wrangler - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Wrangler - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,5,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,5,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,0,3000,5500,9000,15000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Wrangler - In Combat - Cast 6533"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Galak Wrangler - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Wrangler - On Evade - Set Sheath Melee");

-- Galak Scout SAI
SET @ENTRY := 4094;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Scout - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Scout - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Galak Scout - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Scout - On Evade - Set Sheath Melee");

-- Galak Stormer SAI
SET @ENTRY := 4097;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,6535,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Stormer - On Aggro - Cast 6535"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Stormer - Between 0-40 Range - Cast 9532 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,11,2,0,100,1,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Between 0-15% Health - Set Event Phase 2"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Stormer - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Galak Stormer - Between 0-15% Health - Flee For Assist");

-- Gravelsnout Surveyor SAI
SET @ENTRY := 4116;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gravelsnout Surveyor - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20806,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gravelsnout Surveyor - On Aggro - Cast 20806"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gravelsnout Surveyor - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,20806,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gravelsnout Surveyor - Between 0-40 Range - Cast 20806 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gravelsnout Surveyor - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gravelsnout Surveyor - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gravelsnout Surveyor - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gravelsnout Surveyor - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gravelsnout Surveyor - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gravelsnout Surveyor - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,6000,9000,17000,21000,11,6141,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gravelsnout Surveyor - In Combat - Cast 6141"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gravelsnout Surveyor - Between 0-15% Health - Set Event Phase 2"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gravelsnout Surveyor - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gravelsnout Surveyor - Between 0-15% Health - Flee For Assist");

-- Cloud Serpent SAI
SET @ENTRY := 4117;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cloud Serpent - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,8246,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cloud Serpent - On Aggro - Cast 8246"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cloud Serpent - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,8246,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cloud Serpent - Between 0-40 Range - Cast 8246 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cloud Serpent - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cloud Serpent - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cloud Serpent - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cloud Serpent - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cloud Serpent - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cloud Serpent - Between 30-100% Mana - Decrement Event Phase");

-- Elder Cloud Serpent SAI
SET @ENTRY := 4119;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Cloud Serpent - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,8246,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Cloud Serpent - On Aggro - Cast 8246"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Cloud Serpent - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,8246,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Cloud Serpent - Between 0-40 Range - Cast 8246 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Cloud Serpent - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Cloud Serpent - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Cloud Serpent - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Cloud Serpent - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Cloud Serpent - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Cloud Serpent - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,9,0,100,0,0,30,7000,11000,11,421,1,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Cloud Serpent - Between 0-30 Range - Cast 421");

-- Keeper Ordanus SAI
SET @ENTRY := 4273;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Keeper Ordanus - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Keeper Ordanus - Between 0-40 Range - Cast 9532 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,25,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - Between 25-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,3500,6200,20900,34300,11,12747,1,0,0,0,0,5,0,0,0,0,0,0,0,"Keeper Ordanus - In Combat - Cast 12747"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Keeper Ordanus - Between 0-15% Health - Flee For Assist");

-- Scarlet Evoker SAI
SET @ENTRY := 4289;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Evoker - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,2601,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Evoker - On Aggro - Cast 2601 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Evoker - On Aggro - Cast 9053 (Normal Dungeon)"),
(@ENTRY,0,3,0,4,0,100,3,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Evoker - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Evoker - Between 0-40 Range - Cast 9053 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Evoker - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Evoker - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Evoker - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Evoker - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Evoker - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Evoker - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,2,6000,8000,14000,29000,11,8422,1,0,0,0,0,5,0,0,0,0,0,0,0,"Scarlet Evoker - In Combat - Cast 8422 (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Evoker - Between 0-15% Health - Set Event Phase 2 (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Evoker - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Evoker - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Scarlet Diviner SAI
SET @ENTRY := 4291;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Diviner - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Diviner - On Aggro - Cast 9053 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Diviner - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Diviner - Between 0-40 Range - Cast 9053 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Diviner - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Diviner - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Diviner - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Diviner - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Diviner - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Diviner - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,11,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Diviner - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Diviner - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Diviner - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Scarlet Sorcerer SAI
SET @ENTRY := 4294;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Sorcerer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Sorcerer - On Aggro - Cast 9672 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Sorcerer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Sorcerer - Between 0-40 Range - Cast 9672 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Sorcerer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Sorcerer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Sorcerer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Sorcerer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Sorcerer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Sorcerer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,2,6000,8000,18000,21000,11,6146,1,0,0,0,0,5,0,0,0,0,0,0,0,"Scarlet Sorcerer - In Combat - Cast 6146 (Normal Dungeon)"),
(@ENTRY,0,11,12,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Sorcerer - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Sorcerer - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Sorcerer - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Scarlet Conjuror SAI
SET @ENTRY := 4297;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Conjuror - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,3,1000,1000,0,0,11,8985,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Conjuror - Out Of Combat - Cast 8985 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Conjuror - On Aggro - Cast 9053 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Conjuror - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Conjuror - Between 0-40 Range - Cast 9053 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Conjuror - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Conjuror - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Conjuror - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Conjuror - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Conjuror - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Conjuror - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,12,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Conjuror - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Conjuror - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Conjuror - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Firemane Flamecaller SAI
SET @ENTRY := 4334;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firemane Flamecaller - On Aggro - Cast 9053"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firemane Flamecaller - Between 0-40 Range - Cast 9053 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,1000,5000,600000,600000,11,18968,1,0,0,0,0,1,0,0,0,0,0,0,0,"Firemane Flamecaller - In Combat - Cast 18968"),
(@ENTRY,0,11,0,0,0,100,0,9000,16000,30000,45000,11,11990,1,0,0,0,0,2,0,0,0,0,0,0,0,"Firemane Flamecaller - In Combat - Cast 11990");

-- Defias Taskmaster SAI
SET @ENTRY := 4417;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Taskmaster - On Aggro - Cast 6660 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,5,30,2200,3800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Taskmaster - Between 5-30 Range - Cast 6660 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,7,9,0,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - Between 25-80 Range - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - Between 25-80 Range - Start Auto Attack (Normal Dungeon)"),
(@ENTRY,0,8,9,9,0,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - Between 0-5 Range - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - Between 0-5 Range - Set Sheath Melee (Normal Dungeon)"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - Between 0-5 Range - Start Auto Attack (Normal Dungeon)"),
(@ENTRY,0,11,12,9,0,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - Between 5-15 Range - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,13,0,9,0,100,2,5,30,32000,39000,11,6685,1,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Taskmaster - Between 5-30 Range - Cast 6685 (Normal Dungeon)"),
(@ENTRY,0,14,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Taskmaster - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Defias Wizard SAI
SET @ENTRY := 4418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Wizard - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Wizard - On Aggro - Cast 9053 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Wizard - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3300,5600,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Wizard - Between 0-40 Range - Cast 9053 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Wizard - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Wizard - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Wizard - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Wizard - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Wizard - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Wizard - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,2,1100,1100,42600,63500,11,4979,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Wizard - In Combat - Cast 4979 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,3300,7800,9600,14200,11,113,32,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Wizard - In Combat - Cast 113 (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Wizard - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Wizard - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Wizard - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Murkgill Hunter SAI
SET @ENTRY := 4458;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkgill Hunter - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2600,4800,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkgill Hunter - Between 5-30 Range - Cast 10277 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murkgill Hunter - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Hunter - On Evade - Set Sheath Melee");

-- Murkgill Oracle SAI
SET @ENTRY := 4459;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Oracle - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkgill Oracle - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Oracle - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkgill Oracle - Between 0-40 Range - Cast 9532 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Oracle - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Oracle - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Oracle - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Oracle - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Oracle - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Oracle - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,14,0,100,0,700,40,25000,35000,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Murkgill Oracle - On Friendly Unit At 700 Health Within 40 Range - Cast 11986"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Oracle - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Oracle - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murkgill Oracle - Between 0-15% Health - Flee For Assist");

-- Murkgill Lord SAI
SET @ENTRY := 4460;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - In Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - Out Of Combat - Cast 12544"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkgill Lord - On Aggro - Cast 9672"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkgill Lord - Between 0-40 Range - Cast 9672 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,0,9800,11100,16100,25700,11,38033,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - In Combat - Cast 38033"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murkgill Lord - Between 0-15% Health - Flee For Assist");

-- Scarlet Spellbinder SAI
SET @ENTRY := 4494;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Spellbinder - On Aggro - Cast 20822"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Spellbinder - Between 0-40 Range - Cast 20822 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,6000,9000,15000,18500,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - In Combat - Cast 11831"),
(@ENTRY,0,11,0,0,0,100,0,4000,6000,20000,25000,11,11436,1,0,0,0,0,5,0,0,0,0,0,0,0,"Scarlet Spellbinder - In Combat - Cast 11436"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Spellbinder - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Spellbinder - Between 0-15% Health - Flee For Assist");

-- Death's Head Adept SAI
SET @ENTRY := 4516;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Adept - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Adept - On Aggro - Cast 9672 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Adept - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Adept - Between 0-40 Range - Cast 9672 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Adept - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Adept - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Adept - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Adept - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Adept - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Adept - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,2,3000,6000,10000,15000,11,113,1,0,0,0,0,5,0,0,0,0,0,0,0,"Death's Head Adept - In Combat - Cast 113 (Normal Dungeon)"),
(@ENTRY,0,11,12,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Adept - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Adept - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Death's Head Adept - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Death's Head Priest SAI
SET @ENTRY := 4517;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,3,1000,1000,1800000,1800000,11,1245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Out Of Combat - Cast 1245 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Priest - On Aggro - Cast 9613 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Priest - Between 0-40 Range - Cast 9613 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,0,2,0,100,2,0,40,14000,20000,11,6063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Between 0-40% Health - Cast 6063 (Normal Dungeon)"),
(@ENTRY,0,12,13,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Death's Head Priest - Between 0-15% Health - Flee For Assist (Normal Dungeon)");
