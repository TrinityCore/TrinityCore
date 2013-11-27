-- Illiyana Moonblaze SAI
SET @ENTRY := 14753;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illiyana Moonblaze - On Aggro - Cast 22907"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 5-30 Range - Cast 22907 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,20,12000,15000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-20 Range - Cast 6533"),
(@ENTRY,0,14,0,2,0,100,0,0,30,40000,40000,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-30% Health - Cast 3019"),
(@ENTRY,0,15,16,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - On Evade - Set Sheath Melee");

-- Steamwheedle Bruiser SAI
SET @ENTRY := 16096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Steamwheedle Bruiser - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2200,3800,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,0,0,0,100,0,500,1800,11000,18000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Steamwheedle Bruiser - In Combat - Cast 12024"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - On Evade - Set Sheath Melee");

-- Bleeding Hollow Dark Shaman SAI
SET @ENTRY := 16873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Out Of Combat - Cast 12550"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Aggro - Cast 20825"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-40 Range - Cast 20825 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-30% Health - Cast 6742"),
(@ENTRY,0,12,0,0,0,100,0,4000,8000,30000,45000,11,32062,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - In Combat - Cast 32062"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,5,0,100,1,0,0,0,0,11,34013,1,0,0,0,0,7,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Killed Unit - Cast 34013");

-- Unyielding Sorcerer SAI
SET @ENTRY := 16905;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Sorcerer - On Aggro - Cast 9053"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 0-40 Range - Cast 9053 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,0,1,100,0,5000,9000,12000,15000,11,11829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Sorcerer - In Combat - Cast 11829 (Phase 1)"),
(@ENTRY,0,11,0,9,0,100,1,0,5,0,0,79,10,150,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 0-5 Range - Set Ranged Movement Distance 10 Angle 150"),
(@ENTRY,0,12,0,9,0,100,1,0,5,0,0,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 0-5 Range - Cast 11831"),
(@ENTRY,0,13,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 0-15% Health - Cast 11831"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Unyielding Sorcerer - Between 0-15% Health - Flee For Assist");

-- Mag'har Hunter SAI
SET @ENTRY := 16912;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,0,1,0,100,1,1000,1000,0,0,11,32730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Out Of Combat - Cast 32730"),
(@ENTRY,0,3,4,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mag'har Hunter - On Aggro - Cast 6660"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,6,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mag'har Hunter - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,7,8,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,9,10,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,11,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,12,13,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,13,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,14,0,0,0,100,0,4000,8000,14000,18000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mag'har Hunter - In Combat - Cast 12024"),
(@ENTRY,0,15,16,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mag'har Hunter - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - On Evade - Set Sheath Melee");

-- Kil'sorrow Spellbinder SAI
SET @ENTRY := 17146;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - On Aggro - Cast 34447"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Between 0-40 Range - Cast 34447 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,3000,6000,20000,25000,11,22744,0,0,0,0,0,5,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - In Combat - Cast 22744"),
(@ENTRY,0,11,0,13,0,90,0,25000,25000,0,0,11,31999,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - On Target Casting - Cast 31999"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Between 0-15% Health - Flee For Assist");

-- Vir'aani Arcanist SAI
SET @ENTRY := 17150;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,0,0,100,0,0,0,300000,300000,11,33839,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - In Combat - Cast 33839"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,13901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vir'aani Arcanist - On Aggro - Cast 13901"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,13901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vir'aani Arcanist - Between 0-40 Range - Cast 13901 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,7,61,1,100,0,0,0,0,0,11,14514,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - Between 0-15% Mana - Cast 14514 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,0,1,100,0,13400,36100,13400,36100,11,22938,1,0,0,0,0,2,0,0,0,0,0,0,0,"Vir'aani Arcanist - In Combat - Cast 22938 (Phase 1)"),
(@ENTRY,0,12,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vir'aani Arcanist - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Vir'aani Arcanist - Between 0-15% Health - Flee For Assist");

-- Siltfin Oracle SAI
SET @ENTRY := 17191;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,0,0,0,100,0,0,0,600000,600000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - In Combat - Cast 12550"),
(@ENTRY,0,3,4,4,0,100,1,0,0,0,0,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Siltfin Oracle - On Aggro - Cast 9739"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,0,9,1,100,0,0,40,3400,4800,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Siltfin Oracle - Between 0-40 Range - Cast 9739 (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Oracle - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Siltfin Oracle - Between 0-15% Health - Flee For Assist");

-- Siltfin Hunter SAI
SET @ENTRY := 17192;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Siltfin Hunter - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Siltfin Hunter - Between 5-30 Range - Cast 10277 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Siltfin Hunter - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,16,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siltfin Hunter - On Evade - Set Sheath Melee");

-- Shattered Hand Archer SAI
SET @ENTRY := 17427;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Archer - On Aggro - Cast 16100 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,5,30,2300,5000,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 5-30 Range - Cast 16100 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Archer - On Aggro - Cast 22907 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,0,100,4,5,30,2300,5000,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 5-30 Range - Cast 22907 (Heroic Dungeon)"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,10,11,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,12,13,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,15,16,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,17,18,9,0,100,6,5,30,6000,9000,11,30990,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 5-30 Range - Cast 30990 (Dungeon Only)"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - Between 5-30 Range - Set Sheath Ranged (Dungeon Only)"),
(@ENTRY,0,21,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Archer - On Evade - Set Sheath Melee (Dungeon Only)");

-- Stillpine Hunter SAI
SET @ENTRY := 17439;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stillpine Hunter - On Aggro - Cast 6660"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stillpine Hunter - Between 5-30 Range - Cast 6660 (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Between 5-30 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Between 25-80 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Between 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Between 0-5 Range - Start Auto Attack (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Between 5-15 Range - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stillpine Hunter - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Hunter - On Evade - Set Sheath Melee");

-- Sharpshooter Guard SAI
SET @ENTRY := 17622;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sharpshooter Guard - On Aggro - Cast 15620 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,5,30,2300,5000,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-30 Range - Cast 15620 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sharpshooter Guard - On Aggro - Cast 22907 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,0,100,4,5,30,2300,5000,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-30 Range - Cast 22907 (Heroic Dungeon)"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,10,11,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,12,13,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,15,16,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,17,18,9,0,100,2,5,90,6000,9000,11,30481,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-90 Range - Cast 30481 (Normal Dungeon)"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-90 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,19,20,9,0,100,4,5,100,6000,9000,11,35945,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-100 Range - Cast 35945 (Heroic Dungeon)"),
(@ENTRY,0,20,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-100 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,21,22,9,0,100,6,5,30,10000,14000,11,37551,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-30 Range - Cast 37551 (Dungeon Only)"),
(@ENTRY,0,22,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - Between 5-30 Range - Set Sheath Ranged (Dungeon Only)"),
(@ENTRY,0,23,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpshooter Guard - On Evade - Set Sheath Melee (Dungeon Only)");

-- Coilfang Sorceress SAI
SET @ENTRY := 17722;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Sorceress - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Sorceress - On Aggro - Cast 12675 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Sorceress - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Sorceress - Between 0-40 Range - Cast 12675 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,37930,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Sorceress - On Aggro - Cast 37930 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Sorceress - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,2400,3800,11,37930,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Sorceress - Between 0-40 Range - Cast 37930 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Sorceress - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Sorceress - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Sorceress - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Sorceress - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Sorceress - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Sorceress - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,80,2,18000,20000,25000,27000,11,31581,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Sorceress - In Combat - Cast 31581 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,18000,20000,25000,27000,11,39416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Sorceress - In Combat - Cast 39416 (Heroic Dungeon)"),
(@ENTRY,0,15,0,0,0,100,2,6000,8000,15000,15000,11,15063,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Sorceress - In Combat - Cast 15063 (Normal Dungeon)"),
(@ENTRY,0,16,0,0,0,100,4,6000,8000,15000,15000,11,15531,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Sorceress - In Combat - Cast 15531 (Heroic Dungeon)");

-- Coilfang Siren SAI
SET @ENTRY := 17801;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Siren - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Siren - On Aggro - Cast 15234 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Siren - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,4400,5800,11,15234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Siren - Between 0-40 Range - Cast 15234 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,0,4,0,100,5,0,0,0,0,11,37664,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Siren - On Aggro - Cast 37664 (Heroic Dungeon)"),
(@ENTRY,0,5,0,4,0,100,5,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Siren - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,3400,4800,11,37664,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Siren - Between 0-40 Range - Cast 37664 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Siren - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Siren - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Siren - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Siren - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Siren - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Siren - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,85,2,12000,15000,15000,19000,11,35106,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Siren - In Combat - Cast 35106 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,9000,12000,15000,17000,11,37856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Siren - In Combat - Cast 37856 (Heroic Dungeon)"),
(@ENTRY,0,15,0,0,0,100,6,9000,13000,10000,14000,11,38660,1,0,0,0,0,6,0,0,0,0,0,0,0,"Coilfang Siren - In Combat - Cast 38660 (Dungeon Only)");

-- Coilfang Soothsayer SAI
SET @ENTRY := 17960;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Soothsayer - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,7,0,0,0,0,11,15791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Soothsayer - On Aggro - Cast 15791 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Soothsayer - On Aggro - Increment Event Phase (Dungeon Only)"),
(@ENTRY,0,3,0,9,1,100,6,0,30,2400,3800,11,15791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Soothsayer - Between 0-30 Range - Cast 15791 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Soothsayer - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Soothsayer - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Soothsayer - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Soothsayer - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Soothsayer - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Soothsayer - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,10,0,0,0,100,7,12200,13400,6000,9000,11,31555,33,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Soothsayer - In Combat - Cast 31555 (Dungeon Only)"),
(@ENTRY,0,11,0,0,0,100,7,9700,10900,12000,18000,11,35280,1,0,0,0,0,6,0,0,0,0,0,0,0,"Coilfang Soothsayer - In Combat - Cast 35280 (Dungeon Only)");

-- Warmaul Warlock SAI
SET @ENTRY := 18037;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Warlock - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,50,1,1000,1000,0,0,11,11939,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Warlock - Out Of Combat - Cast 11939"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Warlock - On Aggro - Cast 9613"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Warlock - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Warlock - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Warlock - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Warlock - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Warlock - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Warlock - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Warlock - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Warlock - Between 30-100% Mana - Decrement Event Phase");

-- Bloodscale Enchantress SAI
SET @ENTRY := 18088;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Enchantress - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,0,0,100,1,0,0,0,0,11,33245,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Enchantress - In Combat - Cast 33245"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscale Enchantress - On Aggro - Cast 34447"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Enchantress - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,30,2400,3800,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscale Enchantress - Between 0-30 Range - Cast 34447 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Enchantress - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Enchantress - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Enchantress - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Enchantress - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Enchantress - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Enchantress - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,0,0,100,0,6000,8000,16000,22000,11,34787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Enchantress - In Combat - Cast 34787");

-- Ango'rosh Shaman SAI
SET @ENTRY := 18118;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Shaman - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Shaman - Between 0-40 Range - Cast 9532 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,1,18000,25000,0,0,11,32062,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Shaman - In Combat - Cast 32062"),
(@ENTRY,0,11,0,2,0,100,1,0,50,0,0,11,23381,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - Between 0-50% Health - Cast 23381"),
(@ENTRY,0,12,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shaman - Between 0-30% Health - Cast 6742");

-- Mire Hydra SAI
SET @ENTRY := 18213;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mire Hydra - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,39419,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mire Hydra - On Aggro - Cast 39419"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mire Hydra - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,30,2400,3800,11,39419,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mire Hydra - Between 0-30 Range - Cast 39419 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mire Hydra - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mire Hydra - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mire Hydra - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mire Hydra - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mire Hydra - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mire Hydra - Between 30-100% Mana - Decrement Event Phase");

-- Mragesh SAI
SET @ENTRY := 18286;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mragesh - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,35316,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mragesh - On Aggro - Cast 35316"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mragesh - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,8,40,2400,3800,11,35316,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mragesh - Between 8-40 Range - Cast 35316 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mragesh - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mragesh - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mragesh - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mragesh - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,8,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mragesh - Between 0-8 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mragesh - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,9,0,100,0,0,5,20000,24000,11,35317,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mragesh - Between 0-5 Range - Cast 35317");

-- Ethereal Wraith SAI
SET @ENTRY := 18394;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Wraith - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Wraith - Out Of Combat - Set Event Phase 0 (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,7,0,0,0,0,11,34934,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Wraith - On Aggro - Cast 34934 (Dungeon Only)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Wraith - On Aggro - Increment Event Phase (Dungeon Only)"),
(@ENTRY,0,4,0,9,1,100,6,0,30,3400,7800,11,34934,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Wraith - Between 0-30 Range - Cast 34934 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Wraith - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Wraith - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Wraith - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Wraith - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Wraith - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Wraith - Between 15-100% Mana - Decrement Event Phase (Dungeon Only)");

-- Cabal Summoner SAI
SET @ENTRY := 18634;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,14034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Summoner - On Aggro - Cast 14034 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,14034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Summoner - Between 0-40 Range - Cast 14034 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Summoner - On Aggro - Cast 15228 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,2400,3800,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Summoner - Between 0-40 Range - Cast 15228 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,6,0,2000,6000,8000,11,33335,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Summoner - In Combat - Cast 33335 (Dungeon Only)"),
(@ENTRY,0,14,0,4,0,50,7,0,0,0,0,11,33507,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - On Aggro - Cast 33507 (Dungeon Only)"),
(@ENTRY,0,15,0,4,0,50,7,0,0,0,0,11,33506,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - On Aggro - Cast 33506 (Dungeon Only)");

-- Cabal Zealot SAI
SET @ENTRY := 18638;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Zealot - On Aggro - Cast 12471 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Zealot - Between 0-40 Range - Cast 12471 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,15472,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Zealot - On Aggro - Cast 15472 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,2400,3800,11,15472,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Zealot - Between 0-40 Range - Cast 15472 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,2,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,13,14,2,0,100,7,0,20,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - Between 0-20% Health - Set Event Phase 3 (Dungeon Only)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,11,33499,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - Between 0-20% Health - Cast 33499 (Dungeon Only)");

-- Cabal Spellbinder SAI
SET @ENTRY := 18639;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Spellbinder - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Spellbinder - On Aggro - Cast 12471 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Spellbinder - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Spellbinder - Between 0-40 Range - Cast 12471 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,15472,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Spellbinder - On Aggro - Cast 15472 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Spellbinder - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,2400,3800,11,15472,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Spellbinder - Between 0-40 Range - Cast 15472 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Spellbinder - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Spellbinder - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Spellbinder - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Spellbinder - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Spellbinder - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Spellbinder - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,6,5000,10000,20000,30000,11,33502,1,0,0,0,0,6,0,0,0,0,0,0,0,"Cabal Spellbinder - In Combat - Cast 33502 (Dungeon Only)"),
(@ENTRY,0,14,0,13,0,100,6,7000,9000,0,0,11,32691,1,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Spellbinder - On Target Casting - Cast 32691 (Dungeon Only)");
