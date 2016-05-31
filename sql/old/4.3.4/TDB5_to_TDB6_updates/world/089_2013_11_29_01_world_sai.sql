-- Skeletal Shadowcaster SAI
SET @ENTRY := 7340;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Shadowcaster - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Shadowcaster - On Aggro - Cast 9613 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Shadowcaster - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Shadowcaster - Between 0-40 Range - Cast 9613 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Shadowcaster - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Shadowcaster - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Shadowcaster - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Shadowcaster - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Shadowcaster - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Shadowcaster - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,6000,10000,7000,14000,11,12248,33,0,0,0,0,5,0,0,0,0,0,0,0,"Skeletal Shadowcaster - In Combat - Cast 12248 (Normal Dungeon)"),
(@ENTRY,0,11,0,7,0,100,3,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Shadowcaster - On Evade - Forced Despawn (Normal Dungeon)");

-- Southsea Freebooter SAI
SET @ENTRY := 7856;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Freebooter - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2200,3800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Freebooter - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Southsea Freebooter - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - On Evade - Set Sheath Melee");

-- Death's Head Cultist SAI
SET @ENTRY := 7872;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Cultist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Cultist - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Cultist - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Cultist - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Cultist - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Cultist - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Cultist - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Cultist - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Cultist - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Cultist - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,9000,12500,8000,13000,11,11433,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Cultist - In Combat - Cast 11433");

-- Cyclok the Mad SAI
SET @ENTRY := 8202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cyclok the Mad - On Aggro - Cast 20829"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,20829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cyclok the Mad - Between 0-40 Range - Cast 20829 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,7000,11000,15000,19000,11,11975,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - In Combat - Cast 11975"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - Between 0-30% Health - Cast 6742");

-- Hukku's Imp SAI
SET @ENTRY := 8658;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku's Imp - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,180000,180000,11,11770,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku's Imp - In Combat - Cast 11770 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,11762,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hukku's Imp - On Aggro - Cast 11762 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku's Imp - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,30,3100,4900,11,11762,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hukku's Imp - Between 0-30 Range - Cast 11762 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku's Imp - Between 0-7% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku's Imp - Between 0-7% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku's Imp - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku's Imp - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku's Imp - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,2,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku's Imp - Between 15-100% Mana - Decrement Event Phase (Normal Dungeon)");

-- Anvilrage Reservist SAI
SET @ENTRY := 8901;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,3,0,0,0,0,11,9128,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - In Combat - Cast 9128 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,100,3,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Reservist - On Aggro - Cast 6660 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,5,6,9,1,100,2,5,30,2200,3800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 5-30 Range - Cast 6660 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,9,1,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 25-80 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,10,9,1,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,11,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 0-5 Range - Set Sheath Melee (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 0-5 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,13,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 5-15 Range - Stop Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,14,0,0,0,100,2,4000,6000,12000,15000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Reservist - In Combat - Cast 9080 (Normal Dungeon)"),
(@ENTRY,0,15,0,0,0,100,2,8000,11000,6000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Reservist - In Combat - Cast 11976 (Normal Dungeon)"),
(@ENTRY,0,16,17,2,0,100,3,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 0-15% Health - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,19,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Hate'rel SAI
SET @ENTRY := 9034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hate'rel - On Aggro - Cast 15232 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4800,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hate'rel - Between 0-40 Range - Cast 15232 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,9,0,100,2,0,5,5000,7000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hate'rel - Between 0-5 Range - Cast 15580 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,9000,14000,40000,48000,11,15232,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - In Combat - Cast 15232 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,14000,17000,15000,20000,11,15232,1,0,0,0,0,5,0,0,0,0,0,0,0,"Hate'rel - In Combat - Cast 15232 (Normal Dungeon)"),
(@ENTRY,0,13,0,21,0,100,3,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - On Just Reached Home - Set Instance Data Field To 4 To Data 2 (Normal Dungeon)");

-- Vile'rel SAI
SET @ENTRY := 9036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15587,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile'rel - On Aggro - Cast 15587 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,30,3400,4800,11,15587,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile'rel - Between 0-30 Range - Cast 15587 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,20000,30000,60000,120000,11,11974,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - In Combat - Cast 11974 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,15000,20000,15000,20000,11,15585,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - In Combat - Cast 15585 (Normal Dungeon)"),
(@ENTRY,0,12,0,2,0,100,2,0,50,16000,20000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - Between 0-50% Health - Cast 15586 (Normal Dungeon)"),
(@ENTRY,0,13,0,21,0,100,3,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - On Just Reached Home - Set Instance Data Field To 4 To Data 2 (Normal Dungeon)");

-- Seeth'rel SAI
SET @ENTRY := 9038;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seeth'rel - On Aggro - Cast 12675 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,3400,4800,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seeth'rel - Between 0-40 Range - Cast 12675 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,2,9000,14000,19000,24000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - In Combat - Cast 15244 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,12000,16000,20000,23000,11,12674,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - In Combat - Cast 12674 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,3000,5000,64000,75000,11,15044,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - In Combat - Cast 15044 (Normal Dungeon)"),
(@ENTRY,0,14,0,21,0,100,3,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - On Just Reached Home - Set Instance Data Field To 4 To Data 2 (Normal Dungeon)");

-- Warder Stilgiss SAI
SET @ENTRY := 9041;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Out Of Combat - Cast 12544 (Normal Dungeon)"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warder Stilgiss - On Aggro - Cast 12675 (Normal Dungeon)"),
(@ENTRY,0,3,0,4,0,100,3,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warder Stilgiss - Between 0-40 Range - Cast 12675 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,3,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,2,7000,9000,14000,18000,11,12674,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - In Combat - Cast 12674 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,3000,4000,65000,70000,11,15044,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - In Combat - Cast 15044 (Normal Dungeon)"),
(@ENTRY,0,13,0,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,14,0,2,0,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,15,0,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Warder Stilgiss - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,16,0,7,0,100,3,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - On Evade - Set Event Phase 0 (Normal Dungeon)");

-- Spirestone Ogre Magus SAI
SET @ENTRY := 9201;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Ogre Magus - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15979,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spirestone Ogre Magus - On Aggro - Cast 15979 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Ogre Magus - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15979,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spirestone Ogre Magus - Between 0-40 Range - Cast 15979 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Ogre Magus - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Ogre Magus - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Ogre Magus - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Ogre Magus - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Ogre Magus - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Ogre Magus - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,2,0,100,2,0,40,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Ogre Magus - Between 0-40% Health - Cast 6742 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,6000,9000,20000,30000,11,13747,1,0,0,0,0,2,0,0,0,0,0,0,0,"Spirestone Ogre Magus - In Combat - Cast 13747 (Normal Dungeon)");

-- Spirestone Lord Magus SAI
SET @ENTRY := 9217;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spirestone Lord Magus - On Aggro - Cast 15230 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spirestone Lord Magus - Between 0-40 Range - Cast 15230 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,7000,12000,14000,19000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Spirestone Lord Magus - In Combat - Cast 13323 (Normal Dungeon)"),
(@ENTRY,0,11,0,2,0,100,2,0,50,25000,30000,11,8365,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - Between 0-50% Health - Cast 8365 (Normal Dungeon)"),
(@ENTRY,0,12,0,2,0,100,2,0,30,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - Between 0-30% Health - Cast 6742 (Normal Dungeon)");

-- Smolderthorn Headhunter SAI
SET @ENTRY := 9241;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15795,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Headhunter - On Aggro - Cast 15795 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,1,100,2,5,30,2300,3900,11,15795,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 5-30 Range - Cast 15795 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 25-80 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 0-5 Range - Set Sheath Melee (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 0-5 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 5-15 Range - Stop Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,13,14,9,0,100,2,5,30,9000,13000,11,16001,1,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 5-30 Range - Cast 16001 (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,15,0,0,0,100,2,5000,10000,22000,26000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Headhunter - In Combat - Cast 6016 (Normal Dungeon)"),
(@ENTRY,0,16,17,2,0,100,3,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 0-15% Health - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,19,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Scarshield Warlock SAI
SET @ENTRY := 9257;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarshield Warlock - On Aggro - Cast 12471 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarshield Warlock - Between 0-40 Range - Cast 12471 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,4,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,2,10000,20000,60000,75000,11,15125,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - In Combat - Cast 15125 (Normal Dungeon)"),
(@ENTRY,0,11,12,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarshield Warlock - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Firebrand Darkweaver SAI
SET @ENTRY := 9261;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Darkweaver - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Darkweaver - On Aggro - Cast 12471 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Darkweaver - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Darkweaver - Between 0-40 Range - Cast 12471 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Darkweaver - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Darkweaver - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Darkweaver - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Darkweaver - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Darkweaver - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Darkweaver - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,0,0,50,2,4000,6000,30000,45000,11,15128,32,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Darkweaver - In Combat - Cast 15128 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,9000,14000,9000,14000,11,15090,1,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Darkweaver - In Combat - Cast 15090 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,1000,4000,12000,15000,11,16071,32,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Darkweaver - In Combat - Cast 16071 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,12000,15000,12000,15000,11,14887,1,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Darkweaver - In Combat - Cast 14887 (Normal Dungeon)"),
(@ENTRY,0,14,15,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Darkweaver - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Darkweaver - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Firebrand Darkweaver - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Firebrand Invoker SAI
SET @ENTRY := 9262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Invoker - On Aggro - Cast 15242 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Invoker - Between 0-40 Range - Cast 15242 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,0,0,50,2,4000,6000,30000,45000,11,15128,32,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Invoker - In Combat - Cast 15128 (Normal Dungeon)"),
(@ENTRY,0,11,0,1,0,100,2,8000,10000,11000,14000,11,12470,1,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - Out Of Combat - Cast 12470 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,12000,16000,14000,18000,11,12468,0,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Invoker - In Combat - Cast 12468 (Normal Dungeon)"),
(@ENTRY,0,13,14,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Firebrand Invoker - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Smolderthorn Axe Thrower SAI
SET @ENTRY := 9267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15795,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - On Aggro - Cast 15795 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,1,100,2,5,30,2300,3900,11,15795,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 5-30 Range - Cast 15795 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 25-80 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 0-5 Range - Set Sheath Melee (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 0-5 Range - Start Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 5-15 Range - Stop Auto Attack (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,2,6000,9000,9000,12000,11,3391,1,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - In Combat - Cast 3391 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,2,9000,14000,11000,15000,11,11428,1,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - In Combat - Cast 11428 (Normal Dungeon)"),
(@ENTRY,0,15,16,2,0,100,3,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 0-15% Health - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,18,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Smolderthorn Seer SAI
SET @ENTRY := 9269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,600000,600000,11,13585,1,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Out Of Combat - Cast 13585 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Seer - On Aggro - Cast 15801 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,15801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Seer - Between 0-40 Range - Cast 15801 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,0,14,0,100,2,3000,40,15000,25000,11,12492,1,0,0,0,0,7,0,0,0,0,0,0,0,"Smolderthorn Seer - On Friendly Unit At 3000 Health Within 40 Range - Cast 12492 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,3000,6000,12000,15000,11,15802,32,0,0,0,0,5,0,0,0,0,0,0,0,"Smolderthorn Seer - In Combat - Cast 15802 (Normal Dungeon)"),
(@ENTRY,0,13,14,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Smolderthorn Seer - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Dark Keeper Vorfalk SAI
SET @ENTRY := 9437;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - On Aggro - Cast 15234 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - Between 0-40 Range - Cast 15234 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,6000,9000,7000,10000,11,15306,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - In Combat - Cast 15306 (Normal Dungeon)");

-- Dark Keeper Bethek SAI
SET @ENTRY := 9438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Bethek - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Bethek - On Aggro - Cast 15228 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Bethek - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Bethek - Between 0-40 Range - Cast 15228 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Bethek - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Bethek - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Bethek - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Bethek - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Bethek - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Bethek - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,3000,5000,15000,20000,11,12738,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Bethek - In Combat - Cast 12738 (Normal Dungeon)");

-- Dark Keeper Uggel SAI
SET @ENTRY := 9439;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Uggel - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Uggel - On Aggro - Cast 15232 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Uggel - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Uggel - Between 0-40 Range - Cast 15232 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Uggel - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Uggel - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Uggel - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Uggel - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Uggel - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Uggel - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,5000,7000,12000,18000,11,14875,33,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Keeper Uggel - In Combat - Cast 14875 (Normal Dungeon)");

-- Lordaeron Sentry SAI
SET @ENTRY := 17815;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lordaeron Sentry - On Aggro - Cast 15620 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,1,100,2,5,30,2300,5000,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 5-30 Range - Cast 15620 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lordaeron Sentry - On Aggro - Cast 16100 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,1,100,4,5,30,2300,5000,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 5-30 Range - Cast 16100 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 25-80 Range - Start Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,14,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 0-5 Range - Set Sheath Melee (Dungeon Only) (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 0-5 Range - Start Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 5-15 Range - Stop Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,17,18,2,0,100,7,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 0-15% Health - Increment Event Phase (Dungeon Only)"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 0-15% Health - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 0-15% Health - Flee For Assist (Dungeon Only)"),
(@ENTRY,0,20,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - On Evade - Set Sheath Melee (Dungeon Only)");

-- Durnholde Rifleman SAI
SET @ENTRY := 17820;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Rifleman - On Aggro - Cast 16100 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,1,100,2,5,30,2300,5000,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 5-30 Range - Cast 16100 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Rifleman - On Aggro - Cast 22907 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,1,100,4,5,30,2300,5000,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 5-30 Range - Cast 22907 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 25-80 Range - Start Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,14,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 0-5 Range - Set Sheath Melee (Dungeon Only) (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 0-5 Range - Start Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 5-15 Range - Stop Auto Attack (Dungeon Only) (Phase 1)"),
(@ENTRY,0,17,18,9,1,100,2,5,30,9000,15000,11,31942,1,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 5-30 Range - Cast 31942 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,18,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,19,20,9,1,100,4,5,30,9000,15000,11,38383,1,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 5-30 Range - Cast 38383 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,20,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,21,22,2,0,100,7,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 0-15% Health - Increment Event Phase (Dungeon Only)"),
(@ENTRY,0,22,23,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 0-15% Health - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,23,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 0-15% Health - Flee For Assist (Dungeon Only)"),
(@ENTRY,0,24,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - On Evade - Set Sheath Melee (Dungeon Only)");

-- Wastewalker Slave SAI
SET @ENTRY := 17963;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,6,1000,1000,900000,900000,11,34880,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - Out Of Combat - Cast 34880 (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewalker Slave - On Aggro - Cast 15497 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,2,100,2,0,40,2400,3800,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewalker Slave - Between 0-40 Range - Cast 15497 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,6,4,0,100,5,0,0,0,0,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewalker Slave - On Aggro - Cast 12675 (Heroic Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,7,0,9,2,100,4,0,40,2400,3800,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastewalker Slave - Between 0-40 Range - Cast 12675 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,8,9,3,2,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,9,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,10,0,9,2,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,11,0,9,2,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,12,0,9,2,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,13,0,3,4,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 4)"),
(@ENTRY,0,14,0,0,0,100,2,5000,8000,15000,20000,11,32192,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - In Combat - Cast 32192 (Normal Dungeon)"),
(@ENTRY,0,15,0,0,0,100,4,5000,8000,15000,20000,11,15531,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - In Combat - Cast 15531 (Heroic Dungeon)"),
(@ENTRY,0,16,17,2,0,100,7,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - Between 0-15% Health - Increment Event Phase (Dungeon Only)"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastewalker Slave - Between 0-15% Health - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Wastewalker Slave - Between 0-15% Health - Flee For Assist (Dungeon Only)");



-- Shienor Sorcerer SAI
SET @ENTRY := 18450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shienor Sorcerer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,0,0,100,1,0,0,0,0,11,32924,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shienor Sorcerer - In Combat - Cast 32924"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,26098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shienor Sorcerer - On Aggro - Cast 26098"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shienor Sorcerer - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,26098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shienor Sorcerer - Between 0-40 Range - Cast 26098 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shienor Sorcerer - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shienor Sorcerer - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shienor Sorcerer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shienor Sorcerer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shienor Sorcerer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shienor Sorcerer - Between 30-100% Mana - Decrement Event Phase (Phase 4)"),
(@ENTRY,0,11,0,0,0,100,0,6000,10000,12000,16000,11,32907,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shienor Sorcerer - In Combat - Cast 32907"),
(@ENTRY,0,12,0,0,0,100,0,10000,14000,18000,25000,11,6728,1,0,0,0,0,6,0,0,0,0,0,0,0,"Shienor Sorcerer - In Combat - Cast 6728"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shienor Sorcerer - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shienor Sorcerer - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shienor Sorcerer - Between 0-15% Health - Flee For Assist");

-- Skithian Dreadhawk SAI
SET @ENTRY := 18452;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skithian Dreadhawk - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 5-30 Range - Cast 10277 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,0,5000,8000,14000,18000,11,32908,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skithian Dreadhawk - In Combat - Cast 32908"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skithian Dreadhawk - On Evade - Set Sheath Melee");

-- Infinite Vanquisher SAI
SET @ENTRY := 18995;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Vanquisher - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,7,1000,1000,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Vanquisher - Out Of Combat - Cast 31326 (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Vanquisher - On Aggro - Cast 12739 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Vanquisher - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,3500,4700,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Vanquisher - Between 0-40 Range - Cast 12739 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,4,0,100,5,0,0,0,0,11,15472,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Vanquisher - On Aggro - Cast 15472 (Heroic Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Vanquisher - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,7,0,9,1,100,4,0,40,3500,4700,11,15472,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Vanquisher - Between 0-40 Range - Cast 15472 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Vanquisher - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Vanquisher - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Vanquisher - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Vanquisher - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Vanquisher - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,2,7500,9000,2400,5500,11,15241,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat - Cast 15241 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,7500,9000,2400,5500,11,36807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat - Cast 36807 (Heroic Dungeon)"),
(@ENTRY,0,15,0,0,0,100,2,5900,6000,5900,6000,11,13341,1,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat - Cast 13341 (Normal Dungeon)"),
(@ENTRY,0,16,0,0,0,100,4,5900,6000,5900,6000,11,38526,1,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Vanquisher - In Combat - Cast 38526 (Heroic Dungeon)"),
(@ENTRY,0,17,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Vanquisher - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,18,0,7,0,100,7,0,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Vanquisher - On Evade - Cast 31326 (Dungeon Only)");

-- Cobalt Serpent SAI
SET @ENTRY := 19428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,17503,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - On Aggro - Cast 17503 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4800,11,17503,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - Between 0-40 Range - Cast 17503 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,38238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - On Aggro - Cast 38238 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,3400,4800,11,38238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - Between 0-40 Range - Cast 38238 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,2,4000,5000,8000,11000,11,38193,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat - Cast 38193 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,4000,5000,8000,11000,11,38133,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat - Cast 38133 (Heroic Dungeon)"),
(@ENTRY,0,15,0,0,0,100,6,6000,7000,7000,13000,11,38110,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat - Cast 38110 (Dungeon Only)");

-- Ango'rosh Warlock SAI
SET @ENTRY := 19732;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Out Of Combat - Cast 13787"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Out Of Combat - Random Phase Range (1-2)"),
(@ENTRY,0,3,4,1,1,100,1,0,1000,0,0,11,8722,3,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Out Of Combat - Cast 8722 (Phase 1)"),
(@ENTRY,0,4,0,61,1,100,0,0,0,0,0,23,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Out Of Combat - Increment Event Phase (Phase 1)"),
(@ENTRY,0,5,6,1,2,100,1,0,1000,0,0,11,11939,3,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Out Of Combat - Cast 11939 (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Out Of Combat - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,4,4,100,1,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Warlock - On Aggro - Cast 20825 (Phase 3)"),
(@ENTRY,0,8,0,9,4,100,0,0,40,2400,3800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Warlock - Between 0-40 Range - Cast 20825 (Phase 3)"),
(@ENTRY,0,9,10,3,4,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Between 0-15% Mana - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,10,0,61,4,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Between 0-15% Mana - Increment Event Phase (Phase 3)"),
(@ENTRY,0,11,0,9,4,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Between 35-80 Range - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,12,0,9,4,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Between 5-15 Range - Disallow Combat Movement (Phase 3)"),
(@ENTRY,0,13,0,9,4,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Between 0-5 Range - Allow Combat Movement (Phase 3)"),
(@ENTRY,0,14,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Warlock - Between 30-100% Mana - Decrement Event Phase");

-- Dark Conclave Shadowmancer SAI
SET @ENTRY := 19826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - On Aggro - Cast 9613"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,0,9000,16000,12000,20000,11,27641,1,0,0,0,0,6,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - In Combat - Cast 27641"),
(@ENTRY,0,12,0,2,0,100,1,0,40,0,0,11,16588,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Between 0-40% Health - Cast 16588"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Conclave Shadowmancer - Between 0-15% Health - Flee For Assist");

-- Ethereal Arcanist SAI
SET @ENTRY := 21405;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Arcanist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,32936,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Arcanist - On Aggro - Cast 32936"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,33833,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Arcanist - On Aggro - Cast 33833"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Arcanist - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,33833,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Arcanist - Between 0-40 Range - Cast 33833 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Arcanist - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Arcanist - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Arcanist - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Arcanist - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Arcanist - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Arcanist - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,0,3000,6000,9000,15000,11,39039,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Arcanist - In Combat - Cast 39039"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Arcanist - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Arcanist - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ethereal Arcanist - Between 0-15% Health - Flee For Assist");

-- Dragonmaw Subjugator SAI
SET @ENTRY := 21718;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Subjugator - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,11,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,13,0,6,0,100,1,0,0,0,0,33,22197,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonmaw Subjugator - On Death - Quest Credit");

-- Deathshadow Spellbinder SAI
SET @ENTRY := 22342;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,39102,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - On Respawn - Cast 39102"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,33447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Spellbinder - On Aggro - Cast 33447"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,33447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Between 0-40 Range - Cast 33447 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,0,9000,14000,14000,20000,11,22744,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deathshadow Spellbinder - In Combat - Cast 22744"),
(@ENTRY,0,12,0,0,0,100,0,6000,9000,7000,14000,11,31999,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Spellbinder - In Combat - Cast 31999"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Between 0-15% Health - Flee For Assist");

-- Deathshadow Warlock SAI
SET @ENTRY := 22363;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,39102,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - On Respawn - Cast 39102"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,2,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Out Of Combat - Cast 13787"),
(@ENTRY,0,3,0,1,0,100,1,3000,3000,0,0,11,38980,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Out Of Combat - Cast 38980"),
(@ENTRY,0,4,5,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Warlock - On Aggro - Cast 9613"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - On Aggro - Increment Event Phase"),
(@ENTRY,0,6,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Warlock - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,0,4000,8000,18000,24000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Warlock - In Combat - Cast 11962"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Deathshadow Warlock - Between 0-15% Health - Flee For Assist");

-- Magnataur Patriarch SAI
SET @ENTRY := 26295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,38556,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magnataur Patriarch - On Aggro - Cast 38556"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,0,35,2300,3900,11,38556,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magnataur Patriarch - Between 0-35 Range - Cast 38556"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - Between 0-35 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magnataur Patriarch - On Evade - Set Sheath Melee");

-- Snowfall Glade Wolvar SAI
SET @ENTRY := 26198;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,43413,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - On Aggro - Cast 43413"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,43413,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Between 5-30 Range - Cast 43413 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,20,9000,14000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Between 0-20 Range - Cast 6533"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - On Evade - Set Sheath Melee");

-- Snowfall Glade Shaman SAI
SET @ENTRY := 26201;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Shaman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,600000,600000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Shaman - Out Of Combat - Cast 12550"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowfall Glade Shaman - On Aggro - Cast 12548"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Shaman - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,20,3400,4800,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowfall Glade Shaman - Between 0-20 Range - Cast 12548 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Shaman - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Shaman - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,15,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Shaman - Between 15-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,10,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Shaman - Between 5-10 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Shaman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Shaman - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,14,0,100,0,4000,40,23000,30000,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Snowfall Glade Shaman - On Friendly Unit At 4000 Health Within 40 Range - Cast 11986");

-- Nexus Guardian SAI
SET @ENTRY := 26276;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Guardian - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,47425,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Guardian - On Aggro - Cast 47425"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Guardian - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,35,3400,4800,11,47425,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Guardian - Between 0-35 Range - Cast 47425 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Guardian - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Guardian - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,30,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Guardian - Between 30-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Guardian - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Guardian - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Guardian - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,9,0,100,0,0,5,9000,13000,11,51857,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Guardian - Between 0-5 Range - Cast 51857");

-- Anub'ar Cultist SAI
SET @ENTRY := 26319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Cultist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,51605,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Cultist - On Aggro - Cast 51605"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anub'ar Cultist - On Aggro - Cast 9613"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Cultist - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,3400,4800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anub'ar Cultist - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Cultist - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Cultist - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Cultist - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Cultist - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Cultist - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Cultist - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,16,0,100,0,47257,25,12000,16000,11,47257,1,0,0,0,0,7,0,0,0,0,0,0,0,"Anub'ar Cultist - On Friendly Unit Missing Buff _spellNameFirstParam_ - Cast 47257");

-- Redfang Hunter SAI
SET @ENTRY := 26356;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redfang Hunter - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redfang Hunter - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,20,11000,16000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Redfang Hunter - Between 0-20 Range - Cast 12024"),
(@ENTRY,0,14,0,9,0,100,0,0,5,4000,7000,11,30639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redfang Hunter - Between 0-5 Range - Cast 30639"),
(@ENTRY,0,15,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redfang Hunter - On Evade - Set Sheath Melee"),
(@ENTRY,0,16,0,6,0,100,1,0,0,0,0,11,47034,39,0,0,0,0,2,0,0,0,0,0,0,0,"Redfang Hunter - On Death - Cast 47034");

-- Solstice Hunter SAI
SET @ENTRY := 26389;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Solstice Hunter - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Solstice Hunter - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,5,30,9000,13000,11,14443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Solstice Hunter - Between 5-30 Range - Cast 14443 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,8,9,0,1,100,0,7000,9000,19000,24000,11,52604,1,0,0,0,0,5,0,0,0,0,0,0,0,"Solstice Hunter - In Combat - Cast 52604 (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - In Combat - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,10,11,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,13,14,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,14,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,15,16,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,16,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,17,0,0,0,100,0,11000,15000,18000,24000,11,52606,1,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - In Combat - Cast 52606"),
(@ENTRY,0,18,19,2,0,100,1,0,50,0,0,11,49561,1,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 0-50% Health - Cast 49561"),
(@ENTRY,0,19,20,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 0-50% Health - Allow Combat Movement"),
(@ENTRY,0,20,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 0-50% Health - Increment Event Phase"),
(@ENTRY,0,21,22,0,0,100,0,12000,15000,18000,21000,11,31975,1,0,0,0,0,5,0,0,0,0,0,0,0,"Solstice Hunter - In Combat - Cast 31975"),
(@ENTRY,0,22,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - In Combat - Set Sheath Ranged"),
(@ENTRY,0,23,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - On Evade - Set Sheath Melee");

-- Runic Lightning Gunner SAI
SET @ENTRY := 26414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,46982,0,0,0,0,0,2,0,0,0,0,0,0,0,"Runic Lightning Gunner - On Aggro - Cast 46982"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,4000,6000,11,46982,0,0,0,0,0,2,0,0,0,0,0,0,0,"Runic Lightning Gunner - Between 5-30 Range - Cast 46982 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - On Evade - Set Sheath Melee"),
(@ENTRY,0,14,0,6,0,100,1,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - On Death - Set Event Phase 3"),
(@ENTRY,0,15,16,8,0,100,1,48046,0,0,0,11,48047,0,0,0,0,0,7,0,0,0,0,0,0,0,"Runic Lightning Gunner - On Spellhit By 48046 - Quest Credit"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runic Lightning Gunner - On Spellhit By 48046 - Forced Despawn");

-- Frostpaw Shaman SAI
SET @ENTRY := 26428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Shaman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostpaw Shaman - On Aggro - Cast 12058"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Shaman - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,30,6000,7000,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostpaw Shaman - Between 0-30 Range - Cast 12058 (Phase 1)"),
(@ENTRY,0,5,6,3,2,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Shaman - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Shaman - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,2,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Shaman - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Shaman - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Shaman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Shaman - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,14,0,100,0,2000,40,15000,20000,11,25420,1,0,0,0,0,7,0,0,0,0,0,0,0,"Frostpaw Shaman - On Friendly Unit At 2000 Health Within 40 Range - Cast 25420"),
(@ENTRY,0,12,0,6,0,100,1,0,0,0,0,11,47033,39,0,0,0,0,2,0,0,0,0,0,0,0,"Frostpaw Shaman - On Death - Cast 47033");

-- Frostpaw Trapper SAI
SET @ENTRY := 26434;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,2,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostpaw Trapper - On Aggro - Cast 6660"),
(@ENTRY,0,3,4,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostpaw Trapper - Between 5-30 Range - Cast 6660"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,5,6,0,0,100,0,9000,14000,9000,14000,11,30614,1,0,0,0,0,5,0,0,0,0,0,0,0,"Frostpaw Trapper - In Combat - Cast 30614"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - In Combat - Set Sheath Ranged"),
(@ENTRY,0,7,8,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,9,10,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,14,0,9,0,100,0,0,5,11000,15000,11,32908,1,0,0,0,0,2,0,0,0,0,0,0,0,"Frostpaw Trapper - Between 0-5 Range - Cast 32908"),
(@ENTRY,0,15,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostpaw Trapper - On Evade - Set Sheath Melee"),
(@ENTRY,0,16,0,6,0,100,1,0,0,0,0,11,47033,39,0,0,0,0,2,0,0,0,0,0,0,0,"Frostpaw Trapper - On Death - Cast 47033");

-- Drakkari Shaman SAI
SET @ENTRY := 26447;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Shaman - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Shaman - Between 0-40 Range - Cast 9532 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,9000,12000,14000,17000,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Shaman - In Combat - Cast 13730");

-- Wastes Taskmaster SAI
SET @ENTRY := 26493;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Taskmaster - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastes Taskmaster - On Aggro - Cast 16583"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Taskmaster - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,20,3400,4800,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wastes Taskmaster - Between 0-20 Range - Cast 16583 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Taskmaster - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Taskmaster - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,15,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Taskmaster - Between 15-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,10,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Taskmaster - Between 5-10 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Taskmaster - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Taskmaster - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,9,0,100,0,0,8,12000,15000,11,32712,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Taskmaster - Between 0-8 Range - Cast 32712");
