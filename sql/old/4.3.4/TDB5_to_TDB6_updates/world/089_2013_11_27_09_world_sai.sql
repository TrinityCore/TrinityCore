-- Flamewaker Imp SAI
SET @ENTRY := 19136;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamewaker Imp - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamewaker Imp - On Aggro - Cast 9053"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamewaker Imp - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamewaker Imp - Between 0-40 Range - Cast 9053 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamewaker Imp - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamewaker Imp - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamewaker Imp - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamewaker Imp - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamewaker Imp - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Flamewaker Imp - Between 30-100% Mana - Decrement Event Phase");

-- Shattered Hand Warlock SAI
SET @ENTRY := 19411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Out Of Combat - Cast 13787"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Warlock - On Aggro - Cast 9613"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Warlock - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,0,0,85,0,5800,11800,16000,22000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Warlock - In Combat - Cast 11962"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shattered Hand Warlock - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,15,0,6,0,10,1,0,0,0,0,11,38879,7,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Warlock - On Death - Cast 38879");

-- Shattered Hand Mage SAI
SET @ENTRY := 19413;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Mage - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,14034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Mage - On Aggro - Cast 14034"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Mage - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,14034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Mage - Between 0-40 Range - Cast 14034 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Mage - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Mage - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Mage - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Mage - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Mage - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Mage - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,6000,9000,12000,16000,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Mage - In Combat - Cast 11831"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Mage - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Mage - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shattered Hand Mage - Between 0-15% Health - Flee For Assist");

-- Bleeding Hollow Necrolyte SAI
SET @ENTRY := 19422;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - On Aggro - Cast 9053"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Between 0-40 Range - Cast 9053 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,8000,12000,30000,45000,11,34073,33,0,0,0,0,5,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - In Combat - Cast 34073"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,14,0,5,0,100,1,0,0,0,0,11,34019,1,0,0,0,0,7,0,0,0,0,0,0,0,"Bleeding Hollow Necrolyte - On Killed Unit - Cast 34019");

-- Sunfury Magister SAI
SET @ENTRY := 18855;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Magister - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,1,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Magister - On Aggro - Cast 9053"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Magister - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Magister - Between 0-40 Range - Cast 9053 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Magister - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Magister - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Magister - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Magister - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Magister - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Magister - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,8000,12000,26000,31000,11,35778,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Magister - In Combat - Cast 35778"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Magister - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Magister - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunfury Magister - Between 0-15% Health - Flee For Assist");

-- Dark Vortex SAI
SET @ENTRY := 18701;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Vortex - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,7,0,0,0,0,11,12471,0,0,0,0,0,6,0,0,0,0,0,0,0,"Dark Vortex - On Aggro - Cast 12471 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Vortex - On Aggro - Increment Event Phase (Dungeon Only)"),
(@ENTRY,0,3,0,9,1,100,6,0,40,2400,3800,11,12471,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Vortex - Between 0-40 Range - Cast 12471 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Vortex - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Vortex - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Vortex - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Vortex - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Vortex - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Vortex - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,10,0,7,0,100,7,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Vortex - On Evade - Forced Despawn (Dungeon Only)");

-- Okrek SAI
SET @ENTRY := 18685;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okrek - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Okrek - Out Of Combat - Cast 13787"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,14034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okrek - On Aggro - Cast 14034"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okrek - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,14034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okrek - Between 0-40 Range - Cast 14034 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okrek - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okrek - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okrek - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okrek - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okrek - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Okrek - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,0,0,100,0,8500,12000,12000,18000,11,32711,1,0,0,0,0,1,0,0,0,0,0,0,0,"Okrek - In Combat - Cast 32711"),
(@ENTRY,0,12,0,0,0,100,0,6000,8000,6000,10000,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Okrek - In Combat - Cast 12471");

-- Kil'sorrow Ritualist SAI
SET @ENTRY := 18658;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,5000,8000,35000,45000,11,32063,0,0,0,0,0,5,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - In Combat - Cast 32063"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kil'sorrow Ritualist - Between 0-15% Health - Flee For Assist");

-- Chief Engineer Lorthander SAI
SET @ENTRY := 18697;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,38204,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Engineer Lorthander - On Aggro - Cast 38204"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Lorthander - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,38204,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Between 0-40 Range - Cast 38204 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,9,0,100,0,0,30,15000,21000,11,36843,1,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Between 0-30 Range - Cast 36843"),
(@ENTRY,0,11,0,0,0,100,0,8000,14000,12000,15000,11,38898,1,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Lorthander - In Combat - Cast 38898"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Chief Engineer Lorthander - Between 0-15% Health - Flee For Assist");

-- Cabal Familiar SAI
SET @ENTRY := 18641;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Familiar - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,20801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Familiar - On Aggro - Cast 20801 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Familiar - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,2,100,2,0,30,2400,3800,11,20801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Familiar - Between 0-30 Range - Cast 20801 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,4,0,4,0,100,5,0,0,0,0,11,38239,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Familiar - On Aggro - Cast 38239 (Heroic Dungeon)"),
(@ENTRY,0,5,0,4,0,100,5,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Familiar - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,2,100,4,0,30,2400,3800,11,38239,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Familiar - Between 0-30 Range - Cast 38239 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,7,8,3,2,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Familiar - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Familiar - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Familiar - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,10,0,9,2,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Familiar - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,11,0,9,2,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Familiar - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Familiar - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)");

-- Cabal Warlock SAI
SET @ENTRY := 18640;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,6,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - Out Of Combat - Cast 13787 (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Warlock - On Aggro - Cast 12471 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,2400,3800,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Warlock - Between 0-40 Range - Cast 12471 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,4,0,100,5,0,0,0,0,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Warlock - On Aggro - Cast 15232 (Heroic Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,7,0,9,1,100,4,0,40,2400,3800,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Warlock - Between 0-40 Range - Cast 15232 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)");

-- Lisaile Fireweaver SAI
SET @ENTRY := 18583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lisaile Fireweaver - On Aggro - Cast 9053"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 0-40 Range - Cast 9053 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,2,0,100,1,0,30,0,0,11,32932,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 0-30% Health - Cast 32932"),
(@ENTRY,0,11,0,0,0,100,0,6000,10000,10000,16000,11,12470,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - In Combat - Cast 12470"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 0-15% Health - Flee For Assist");

-- Urdak SAI
SET @ENTRY := 18541;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,0,0,100,1,0,0,0,0,11,32924,1,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - In Combat - Cast 32924"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,38465,0,0,0,0,0,2,0,0,0,0,0,0,0,"Urdak - On Aggro - Cast 38465"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,38465,0,0,0,0,0,2,0,0,0,0,0,0,0,"Urdak - Between 0-40 Range - Cast 38465 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,0,6000,10000,12000,16000,11,32907,1,0,0,0,0,2,0,0,0,0,0,0,0,"Urdak - In Combat - Cast 32907"),
(@ENTRY,0,12,0,0,0,100,0,10000,14000,18000,25000,11,6728,1,0,0,0,0,6,0,0,0,0,0,0,0,"Urdak - In Combat - Cast 6728"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Urdak - Between 0-15% Health - Flee For Assist");

-- Ashkaz SAI
SET @ENTRY := 18539;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashkaz - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,0,0,100,1,0,0,0,0,11,32924,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ashkaz - In Combat - Cast 32924"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,26098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashkaz - On Aggro - Cast 26098"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashkaz - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,26098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashkaz - Between 0-40 Range - Cast 26098 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashkaz - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashkaz - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashkaz - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashkaz - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashkaz - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ashkaz - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,0,6000,10000,12000,16000,11,32907,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ashkaz - In Combat - Cast 32907"),
(@ENTRY,0,12,0,0,0,100,0,10000,14000,18000,25000,11,6728,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ashkaz - In Combat - Cast 6728"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashkaz - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashkaz - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ashkaz - Between 0-15% Health - Flee For Assist");

-- Phasing Sorcerer SAI
SET @ENTRY := 18558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Sorcerer - On Aggro - Cast 12466 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Sorcerer - Between 0-40 Range - Cast 12466 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Sorcerer - On Aggro - Cast 17290 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,2400,3800,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Sorcerer - Between 0-40 Range - Cast 17290 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,2,5000,7000,9000,14000,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Sorcerer - In Combat - Cast 15043 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,5000,7000,9000,14000,11,15530,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Sorcerer - In Combat - Cast 15530 (Heroic Dungeon)"),
(@ENTRY,0,15,0,0,0,100,2,10000,10000,10000,13000,11,15744,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - In Combat - Cast 15744 (Normal Dungeon)"),
(@ENTRY,0,16,0,0,0,100,4,10000,10000,10000,13000,11,22424,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - In Combat - Cast 22424 (Heroic Dungeon)");

-- Infinite Defiler SAI
SET @ENTRY := 18171;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Defiler - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Defiler - On Aggro - Cast 15232 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Defiler - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4800,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Defiler - Between 0-40 Range - Cast 15232 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,38386,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Defiler - On Aggro - Cast 38386 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Defiler - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,3400,4800,11,38386,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Defiler - Between 0-40 Range - Cast 38386 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,9,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Defiler - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Defiler - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Defiler - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Defiler - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Defiler - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Defiler - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,6,9000,14000,16000,19000,11,21068,33,0,0,0,0,5,0,0,0,0,0,0,0,"Infinite Defiler - In Combat - Cast 21068 (Dungeon Only)");

-- Ethereal Sorcerer SAI
SET @ENTRY := 18313;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Sorcerer - On Aggro - Cast 15791 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,30,2400,3800,11,15791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Sorcerer - Between 0-30 Range - Cast 15791 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,22273,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Sorcerer - On Aggro - Cast 22273 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,30,2400,3800,11,22273,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Sorcerer - Between 0-30 Range - Cast 22273 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,6,14000,22700,22300,22300,11,32349,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat - Cast 32349 (Dungeon Only)"),
(@ENTRY,0,14,0,0,0,100,6,14000,22700,22300,22300,11,32353,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat - Cast 32353 (Dungeon Only)"),
(@ENTRY,0,15,0,0,0,100,6,5100,10800,10800,15700,11,25603,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat - Cast 25603 (Dungeon Only)");

-- Ango'rosh Souleater SAI
SET @ENTRY := 18121;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Souleater - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,0,0,11,35194,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Souleater - Out Of Combat - Cast 35194"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Souleater - On Aggro - Cast 9613"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Souleater - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Souleater - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Souleater - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Souleater - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Souleater - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Souleater - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Souleater - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Souleater - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,35195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Souleater - Between 0-30% Health - Cast 35195");

-- Feralfen Mystic SAI
SET @ENTRY := 18114;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Mystic - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Mystic - On Aggro - Cast 12550"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Feralfen Mystic - On Aggro - Cast 9532"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Mystic - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Feralfen Mystic - Between 0-40 Range - Cast 9532 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Mystic - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Mystic - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Mystic - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Mystic - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Mystic - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Mystic - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Mystic - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feralfen Mystic - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Feralfen Mystic - Between 0-15% Health - Flee For Assist");

-- Rajis Fyashe SAI
SET @ENTRY := 18044;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rajis Fyashe - On Aggro - Cast 15043"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rajis Fyashe - Between 0-40 Range - Cast 15043 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,1,6000,9000,0,0,11,35594,1,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - In Combat - Cast 35594"),
(@ENTRY,0,11,0,0,0,100,0,8000,9000,8000,12000,11,35499,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rajis Fyashe - In Combat - Cast 35499"),
(@ENTRY,0,12,0,0,0,100,0,18000,24000,18000,24000,11,34787,1,0,0,0,0,2,0,0,0,0,0,0,0,"Rajis Fyashe - In Combat - Cast 34787"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Rajis Fyashe - Between 0-15% Health - Flee For Assist");

-- Darkcrest Siren SAI
SET @ENTRY := 18087;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkcrest Siren - On Aggro - Cast 9672"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkcrest Siren - Between 0-40 Range - Cast 9672 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,7000,10000,14000,18000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - In Combat - Cast 11831"),
(@ENTRY,0,11,0,0,0,100,0,5000,7000,12000,17000,11,6726,1,0,0,0,0,5,0,0,0,0,0,0,0,"Darkcrest Siren - In Combat - Cast 6726"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Darkcrest Siren - Between 0-15% Health - Flee For Assist");

-- Coilfang Enchantress SAI
SET @ENTRY := 17961;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Enchantress - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Enchantress - On Aggro - Cast 15234 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Enchantress - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3200,6900,11,15234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Enchantress - Between 0-40 Range - Cast 15234 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,37664,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Enchantress - On Aggro - Cast 37664 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Enchantress - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,3200,6900,11,37664,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Enchantress - Between 0-40 Range - Cast 37664 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Enchantress - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Enchantress - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Enchantress - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Enchantress - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Enchantress - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Enchantress - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,2,18900,22500,11000,16000,11,32193,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Enchantress - In Combat - Cast 32193 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,18900,22500,11000,16000,11,37665,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Enchantress - In Combat - Cast 37665 (Heroic Dungeon)"),
(@ENTRY,0,15,0,0,0,100,6,5600,11800,20300,20300,11,32173,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Enchantress - In Combat - Cast 32173 (Dungeon Only)");

-- Azure Spellweaver SAI
SET @ENTRY := 31403;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellweaver - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Spellweaver - On Aggro - Cast 34447"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellweaver - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,30,2400,3800,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Spellweaver - Between 0-30 Range - Cast 34447 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellweaver - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellweaver - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellweaver - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellweaver - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellweaver - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellweaver - Between 30-100% Mana - Decrement Event Phase");

-- Unbound Corrupter SAI
SET @ENTRY := 30868;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Corrupter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,38204,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Corrupter - On Aggro - Cast 38204"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Corrupter - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,5400,11,38204,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Corrupter - Between 0-40 Range - Cast 38204 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Corrupter - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Corrupter - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Corrupter - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Corrupter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Corrupter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Corrupter - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,20000,30000,45000,60000,11,58667,1,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Corrupter - In Combat - Cast 58667"),
(@ENTRY,0,11,0,2,0,100,0,0,30,30000,35000,11,58270,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Corrupter - Between 0-30% Health - Cast 58270");

-- Savage Hill Mystic SAI
SET @ENTRY := 29622;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,50273,0,0,0,0,0,2,0,0,0,0,0,0,0,"Savage Hill Mystic - On Aggro - Cast 50273"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,4400,5800,11,50273,0,0,0,0,0,2,0,0,0,0,0,0,0,"Savage Hill Mystic - Between 0-40 Range - Cast 50273 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Savage Hill Mystic - Between 0-15% Health - Flee For Assist");

-- Valduran the Stormborn SAI
SET @ENTRY := 29368;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,56326,0,0,0,0,0,2,0,0,0,0,0,0,0,"Valduran the Stormborn - On Aggro - Cast 56326"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,56326,0,0,0,0,0,2,0,0,0,0,0,0,0,"Valduran the Stormborn - Between 0-40 Range - Cast 56326 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,15000,18000,29000,33000,11,56322,1,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - In Combat - Cast 56322"),
(@ENTRY,0,11,0,0,0,100,0,3000,8000,23000,26000,11,56319,0,0,0,0,0,5,0,0,0,0,0,0,0,"Valduran the Stormborn - In Combat - Cast 56319"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Valduran the Stormborn - Between 0-15% Health - Flee For Assist");

-- Scarlet Commander SAI
SET @ENTRY := 28936;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,52818,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Commander - On Aggro - Cast 52818"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,52818,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Commander - Between 5-30 Range - Cast 52818"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - Between 5-30 Range - Set Sheath Ranged"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - Between 25-80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - Between 25-80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - Between 0-5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - Between 0-5 Range - Set Sheath Melee"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - Between 0-5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - Between 5-15 Range - Disallow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - Between 5-15 Range - Stop Auto Attack"),
(@ENTRY,0,13,0,9,0,100,0,0,5,6000,9000,11,52221,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Commander - Between 0-5 Range - Cast 52221"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander - On Evade - Set Sheath Melee");
