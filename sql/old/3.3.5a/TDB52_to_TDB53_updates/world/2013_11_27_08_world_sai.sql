-- Saragosa SAI
SET @ENTRY := 26232;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saragosa - On Aggro - Cast 51779"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,6200,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saragosa - Between 0-40 Range - Cast 51779 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,9,0,0,0,100,0,8500,17500,20100,40100,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - In Combat - Cast 15063");

-- Coldarra Spellweaver SAI
SET @ENTRY := 25722;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellweaver - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Spellweaver - On Aggro - Cast 34447"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellweaver - On Aggro - Set Event Phase 6"),
(@ENTRY,0,3,0,0,1,100,0,0,0,600,5300,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Spellweaver - In Combat - Cast 34447 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellweaver - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellweaver - Between 0-15% Mana - Set Event Phase 5 (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellweaver - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellweaver - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,3,0,100,0,30,100,100,100,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellweaver - Between 30-100% Mana - Set Event Phase 6");

-- Inquisitor Caleras SAI
SET @ENTRY := 25720;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Inquisitor Caleras - On Aggro - Cast 15043"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,6200,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Inquisitor Caleras - Between 0-40 Range - Cast 15043 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,9,0,0,0,100,0,9800,21300,18400,18400,11,32192,1,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - In Combat - Cast 32192");

-- Coldarra Spellbinder SAI
SET @ENTRY := 25719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Spellbinder - On Aggro - Cast 9672"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3900,5800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Spellbinder - Between 0-40 Range - Cast 9672 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,9,0,0,0,100,0,1700,13500,172100,172100,11,50583,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - In Combat - Cast 50583");

-- Bloodspore Firestarter SAI
SET @ENTRY := 25470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodspore Firestarter - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,600000,600000,11,45985,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodspore Firestarter - Out Of Combat - Cast 45985"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodspore Firestarter - On Aggro - Cast 20793"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodspore Firestarter - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,3800,6200,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodspore Firestarter - Between 0-40 Range - Cast 20793 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodspore Firestarter - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodspore Firestarter - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodspore Firestarter - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodspore Firestarter - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodspore Firestarter - Between 30-100% Mana - Decrement Event Phase");

-- Winterfin Oracle SAI
SET @ENTRY := 25216;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,0,0,100,1,0,0,0,0,11,50272,1,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - In Combat - Cast 50272"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Winterfin Oracle - On Aggro - Cast 9532"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - On Aggro - Set Event Phase 1"),
(@ENTRY,0,4,0,0,1,100,0,0,0,2700,5600,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Winterfin Oracle - In Combat - Cast 9532 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - Between 0-15% Mana - Set Event Phase 3 (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - Between 30-100% Mana - Set Event Phase 1 (Phase 2)"),
(@ENTRY,0,10,11,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Winterfin Oracle - Between 0-15% Health - Flee For Assist");

-- Bash'ir Subprimal SAI
SET @ENTRY := 23247;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Subprimal - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,17321,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir Subprimal - On Aggro - Cast 17321"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Subprimal - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir Subprimal - Between 0-40 Range - Cast 15232 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Subprimal - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Subprimal - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Subprimal - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Subprimal - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Subprimal - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Subprimal - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,9000,14000,11000,18000,11,36097,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Subprimal - In Combat - Cast 36097");

-- Gordunni Soulreaper SAI
SET @ENTRY := 23022;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Soulreaper - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Soulreaper - On Aggro - Cast 15232"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Soulreaper - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Soulreaper - Between 0-40 Range - Cast 15232 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Soulreaper - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Soulreaper - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Soulreaper - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Soulreaper - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Soulreaper - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Soulreaper - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,4000,6000,18000,25000,11,20464,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Soulreaper - In Combat - Cast 20464"),
(@ENTRY,0,11,0,2,0,100,0,0,30,30000,35000,11,20743,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Soulreaper - Between 0-30% Health - Cast 20743"),
(@ENTRY,0,12,0,6,0,100,1,0,0,0,0,33,23450,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Soulreaper - On Death - Quest Credit");

-- Deathshadow Overlord SAI
SET @ENTRY := 22393;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Overlord - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Overlord - On Aggro - Cast 15228"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Overlord - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Overlord - Between 0-40 Range - Cast 15228 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Overlord - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Overlord - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Overlord - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Overlord - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Overlord - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Overlord - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,3000,4000,6000,8000,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Overlord - In Combat - Cast 15232"),
(@ENTRY,0,11,0,0,0,100,0,8000,15000,20000,35000,11,37579,32,0,0,0,0,6,0,0,0,0,0,0,0,"Deathshadow Overlord - In Combat - Cast 37579"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Overlord - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Overlord - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Deathshadow Overlord - Between 0-15% Health - Flee For Assist");

-- Deathshadow Imp SAI
SET @ENTRY := 22362;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Imp - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Imp - On Aggro - Cast 20801"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Imp - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,20801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Imp - Between 0-40 Range - Cast 20801 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Imp - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Imp - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Imp - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Imp - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Imp - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Imp - Between 30-100% Mana - Decrement Event Phase");

-- Bash'ir Arcanist SAI
SET @ENTRY := 22243;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Arcanist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir Arcanist - On Aggro - Cast 34447"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Arcanist - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir Arcanist - Between 0-40 Range - Cast 34447 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Arcanist - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Arcanist - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Arcanist - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Arcanist - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Arcanist - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Arcanist - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,9000,14000,14000,20000,11,36508,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir Arcanist - In Combat - Cast 36508");

-- Wrath Corruptor SAI
SET @ENTRY := 22254;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Corruptor - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrath Corruptor - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Corruptor - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrath Corruptor - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Corruptor - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Corruptor - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Corruptor - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Corruptor - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Corruptor - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Corruptor - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,2700,4200,26000,30000,11,32063,1,0,0,0,0,5,0,0,0,0,0,0,0,"Wrath Corruptor - In Combat - Cast 32063"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Corruptor - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Corruptor - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Wrath Corruptor - Between 0-15% Health - Flee For Assist");

-- Eclipsion Spellbinder SAI
SET @ENTRY := 22017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eclipsion Spellbinder - On Aggro - Cast 34447"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Spellbinder - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,30,2400,3800,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Between 0-30 Range - Cast 34447 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,1,8000,12000,18000,24000,11,18972,0,0,0,0,0,5,0,0,0,0,0,0,0,"Eclipsion Spellbinder - In Combat - Cast 18972"),
(@ENTRY,0,11,0,2,0,100,1,0,40,0,0,11,38171,1,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Between 0-40% Health - Cast 38171"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Eclipsion Spellbinder - Between 0-15% Health - Flee For Assist");

-- Skettis Soulcaller SAI
SET @ENTRY := 21911;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Soulcaller - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Soulcaller - On Aggro - Cast 20298"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Soulcaller - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,20298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Soulcaller - Between 0-40 Range - Cast 20298 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Soulcaller - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Soulcaller - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Soulcaller - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Soulcaller - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Soulcaller - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Soulcaller - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,2,0,100,1,0,30,0,0,11,5137,1,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Soulcaller - Between 0-30% Health - Cast 5137"),
(@ENTRY,0,11,0,0,0,100,0,6000,10000,13000,18000,11,38663,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Soulcaller - In Combat - Cast 38663");

-- Alluvion SAI
SET @ENTRY := 21730;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvion - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,38669,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alluvion - On Aggro - Cast 38669"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvion - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,45,2400,3800,11,38669,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alluvion - Between 0-45 Range - Cast 38669 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvion - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvion - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvion - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvion - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvion - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Alluvion - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,4000,8000,14000,18000,11,15063,1,0,0,0,0,2,0,0,0,0,0,0,0,"Alluvion - In Combat - Cast 15063");

-- Skettis Surger SAI
SET @ENTRY := 21728;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Surger - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,32011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Surger - On Aggro - Cast 32011"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Surger - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,45,2400,3800,11,32011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Surger - Between 0-45 Range - Cast 32011 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Surger - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Surger - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Surger - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Surger - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Surger - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Surger - Between 30-100% Mana - Decrement Event Phase");

-- Cabal Abjurist SAI
SET @ENTRY := 21660;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Abjurist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Abjurist - On Aggro - Cast 34447"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Abjurist - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Abjurist - Between 0-40 Range - Cast 34447 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Abjurist - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Abjurist - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Abjurist - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Abjurist - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Abjurist - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Abjurist - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,5000,9000,13000,18000,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Abjurist - In Combat - Cast 11831");

-- Skettis Windwalker SAI
SET @ENTRY := 21649;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Windwalker - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,13901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Windwalker - On Aggro - Cast 13901"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Windwalker - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,13901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Windwalker - Between 0-40 Range - Cast 13901 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Windwalker - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Windwalker - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Windwalker - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Windwalker - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Windwalker - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skettis Windwalker - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,4000,6500,14000,18000,11,40578,1,0,0,0,0,2,0,0,0,0,0,0,0,"Skettis Windwalker - In Combat - Cast 40578"),
(@ENTRY,0,11,0,14,0,100,0,3000,40,20000,30000,11,34110,1,0,0,0,0,7,0,0,0,0,0,0,0,"Skettis Windwalker - On Friendly Unit At 3000 Health Within 40 Range - Cast 34110");

-- Dark Conclave Scorncrow SAI
SET @ENTRY := 21385;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - On Aggro - Cast 9672"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - Between 0-40 Range - Cast 9672 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,0,0,100,0,7000,12000,14000,18000,11,15531,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Conclave Scorncrow - In Combat - Cast 15531");

-- Ethereal Nethermancer SAI
SET @ENTRY := 21370;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Nethermancer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Nethermancer - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Nethermancer - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Nethermancer - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Nethermancer - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Nethermancer - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Nethermancer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Nethermancer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Nethermancer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Nethermancer - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,2,0,100,1,0,50,0,0,11,17173,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Nethermancer - Between 0-50% Health - Cast 17173");





-- Ango'rosh Shadowmage SAI
SET @ENTRY := 20444;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,3000,5000,15000,19000,11,9657,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - In Combat - Cast 9657");

-- Deathforge Summoner SAI
SET @ENTRY := 20872;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Summoner - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Summoner - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Summoner - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Summoner - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Summoner - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Summoner - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Summoner - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Summoner - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Summoner - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Summoner - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,7000,9000,17000,24000,11,37628,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Summoner - In Combat - Cast 37628");

-- Deathforge Imp SAI
SET @ENTRY := 20887;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Imp - In Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,36227,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Imp - On Aggro - Cast 36227"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Imp - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,30,2400,3800,11,36227,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Imp - Between 0-30 Range - Cast 36227 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Imp - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Imp - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Imp - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Imp - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Imp - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforge Imp - Between 30-100% Mana - Decrement Event Phase");

-- Screeching Spirit SAI
SET @ENTRY := 21200;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,17327,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screeching Spirit - On Respawn - Cast 17327"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screeching Spirit - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Screeching Spirit - On Aggro - Cast 9613"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screeching Spirit - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Screeching Spirit - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screeching Spirit - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screeching Spirit - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screeching Spirit - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screeching Spirit - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screeching Spirit - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Screeching Spirit - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,0,0,100,0,17000,25000,17000,25000,11,22678,1,0,0,0,0,6,0,0,0,0,0,0,0,"Screeching Spirit - In Combat - Cast 22678"),
(@ENTRY,0,12,0,2,0,100,0,0,30,22000,32000,11,16588,1,0,0,0,0,1,0,0,0,0,0,0,0,"Screeching Spirit - Between 0-30% Health - Cast 16588");

-- Auchenai Death-Speaker SAI
SET @ENTRY := 21242;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Out Of Combat - Cast 13787"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Death-Speaker - On Aggro - Cast 9613"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Death-Speaker - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,0,3000,5000,35000,40000,11,18267,1,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Death-Speaker - In Combat - Cast 18267"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Auchenai Death-Speaker - Between 0-15% Health - Flee For Assist");

-- Ambassador Solannas SAI
SET @ENTRY := 20163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Solannas - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ambassador Solannas - On Aggro - Cast 9053"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Solannas - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ambassador Solannas - Between 0-40 Range - Cast 9053 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Solannas - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Solannas - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Solannas - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Solannas - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Solannas - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Solannas - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,9,1,100,0,0,8,9000,15000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Solannas - Between 0-8 Range - Cast 11831 (Phase 1)");

-- Culuthas SAI
SET @ENTRY := 20138;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Culuthas - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,37089,0,0,0,0,0,2,0,0,0,0,0,0,0,"Culuthas - On Aggro - Cast 37089"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Culuthas - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,4500,6000,11,37089,0,0,0,0,0,2,0,0,0,0,0,0,0,"Culuthas - Between 0-40 Range - Cast 37089 (Phase 1)"),
(@ENTRY,0,4,0,9,1,100,0,0,30,11000,16000,11,35373,1,0,0,0,0,5,0,0,0,0,0,0,0,"Culuthas - Between 0-30 Range - Cast 35373 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Culuthas - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Culuthas - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Culuthas - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Culuthas - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Culuthas - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Culuthas - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,9,0,100,0,0,30,9000,13000,11,36402,1,0,0,0,0,6,0,0,0,0,0,0,0,"Culuthas - Between 0-30 Range - Cast 36402");

-- Sunfury Arch Mage SAI
SET @ENTRY := 20135;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arch Mage - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,600000,600000,11,35917,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arch Mage - Out Of Combat - Cast 35917"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Arch Mage - On Aggro - Cast 20823"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arch Mage - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,4500,6000,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Arch Mage - Between 0-40 Range - Cast 20823 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arch Mage - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arch Mage - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arch Mage - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arch Mage - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arch Mage - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arch Mage - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,9,0,100,0,0,8,11000,15000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arch Mage - Between 0-8 Range - Cast 11831");

-- Bloodscale Wavecaller SAI
SET @ENTRY := 20089;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Wavecaller - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,600000,600000,11,34827,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Wavecaller - Out Of Combat - Cast 34827"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,32011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscale Wavecaller - On Aggro - Cast 32011"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Wavecaller - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,45,2400,3800,11,32011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscale Wavecaller - Between 0-45 Range - Cast 32011 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Wavecaller - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Wavecaller - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Wavecaller - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Wavecaller - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Wavecaller - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Wavecaller - Between 30-100% Mana - Decrement Event Phase");

-- Bloodmaul Geomancer SAI
SET @ENTRY := 19952;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Geomancer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Geomancer - Out Of Combat - Cast 12544"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Geomancer - On Aggro - Cast 9053"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Geomancer - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Geomancer - Between 0-40 Range - Cast 9053 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Geomancer - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Geomancer - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Geomancer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Geomancer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Geomancer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Geomancer - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,34932,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Geomancer - Between 0-30% Health - Cast 34932");

-- Bloodmaul Warlock SAI
SET @ENTRY := 19994;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Out Of Combat - Cast 13787"),
(@ENTRY,0,2,0,1,0,100,1,3000,3000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Out Of Combat - Cast 11939"),
(@ENTRY,0,3,4,4,0,100,1,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Warlock - On Aggro - Cast 20825"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,0,9,1,100,0,0,40,2400,3800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Warlock - Between 0-40 Range - Cast 20825 (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,12,0,2,0,100,1,0,30,0,0,11,34932,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Between 0-30% Health - Cast 34932");

-- Severed Spirit SAI
SET @ENTRY := 19881;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - On Respawn - Cast 33900"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,2,0,1,0,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Severed Spirit - On Aggro - Cast 20822"),
(@ENTRY,0,4,0,4,0,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,0,9,1,100,0,0,40,3400,4800,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Severed Spirit - Between 0-40 Range - Cast 20822 (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,1,0,7,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,12,0,9,0,100,0,0,8,12000,15000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - Between 0-8 Range - Cast 11831"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Spirit - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,15,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Severed Spirit - Between 0-15% Health - Flee For Assist");

-- Darkcrest Sorceress SAI
SET @ENTRY := 19947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Out Of Combat - Cast 12544"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,13901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkcrest Sorceress - On Aggro - Cast 13901"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,13901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkcrest Sorceress - Between 0-40 Range - Cast 13901 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,0,0,100,0,10000,15000,20000,25000,11,34787,1,0,0,0,0,2,0,0,0,0,0,0,0,"Darkcrest Sorceress - In Combat - Cast 34787"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Darkcrest Sorceress - Between 0-15% Health - Flee For Assist");

-- Sunfury Arcanist SAI
SET @ENTRY := 20134;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arcanist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Arcanist - On Aggro - Cast 34447"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arcanist - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,30,3400,4800,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Arcanist - Between 0-30 Range - Cast 34447 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arcanist - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arcanist - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arcanist - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arcanist - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arcanist - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arcanist - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,6000,11000,35000,42000,11,35778,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arcanist - In Combat - Cast 35778"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arcanist - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Arcanist - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunfury Arcanist - Between 0-15% Health - Flee For Assist");

-- Sunfury Conjurer SAI
SET @ENTRY := 20139;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Conjurer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Conjurer - On Aggro - Cast 9672"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Conjurer - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Conjurer - Between 0-40 Range - Cast 9672 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Conjurer - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Conjurer - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Conjurer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Conjurer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Conjurer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Conjurer - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,9000,14000,12000,16000,11,11829,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sunfury Conjurer - In Combat - Cast 11829"),
(@ENTRY,0,11,0,0,0,100,0,7000,9000,30000,45000,11,35778,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Conjurer - In Combat - Cast 35778"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Conjurer - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Conjurer - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunfury Conjurer - Between 0-15% Health - Flee For Assist");

-- Arcanist Ardonis SAI
SET @ENTRY := 19830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Ardonis - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,35853,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcanist Ardonis - On Aggro - Cast 35853"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Ardonis - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,35853,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcanist Ardonis - Between 0-40 Range - Cast 35853 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Ardonis - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Ardonis - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Ardonis - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Ardonis - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Ardonis - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Ardonis - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,9,0,100,0,0,8,12000,15000,11,33860,1,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Ardonis - Between 0-8 Range - Cast 33860");

-- Summoner Kanthin SAI
SET @ENTRY := 19657;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoner Kanthin - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,19816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoner Kanthin - On Aggro - Cast 19816"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoner Kanthin - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,19816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoner Kanthin - Between 0-40 Range - Cast 19816 (Phase 1)"),
(@ENTRY,0,4,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoner Kanthin - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoner Kanthin - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoner Kanthin - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoner Kanthin - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoner Kanthin - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Summoner Kanthin - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,9,0,100,0,0,8,12000,16000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Summoner Kanthin - Between 0-8 Range - Cast 11831"),
(@ENTRY,0,11,0,0,0,100,0,10000,14000,18000,21000,11,17273,1,0,0,0,0,5,0,0,0,0,0,0,0,"Summoner Kanthin - In Combat - Cast 17273");

-- Bonechewer Evoker SAI
SET @ENTRY := 19701;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Evoker - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Evoker - On Aggro - Cast 9053"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Evoker - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Evoker - Between 0-40 Range - Cast 9053 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Evoker - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Evoker - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Evoker - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Evoker - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Evoker - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Evoker - Between 30-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,11,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Evoker - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Evoker - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bonechewer Evoker - Between 0-15% Health - Flee For Assist");



-- Dreadcaller SAI
SET @ENTRY := 19434;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,32666,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadcaller - On Aggro - Cast 32666"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,32666,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadcaller - Between 0-40 Range - Cast 32666 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 0-15% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 0-15% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,4000,9000,18100,24000,11,11443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadcaller - In Combat - Cast 11443");

-- Spellbinder Maryana SAI
SET @ENTRY := 19593;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spellbinder Maryana - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,600000,600000,11,35917,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spellbinder Maryana - Out Of Combat - Cast 35917"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,35927,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spellbinder Maryana - On Aggro - Cast 35927"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spellbinder Maryana - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,30,4500,6000,11,35927,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spellbinder Maryana - Between 0-30 Range - Cast 35927 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spellbinder Maryana - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spellbinder Maryana - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spellbinder Maryana - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spellbinder Maryana - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spellbinder Maryana - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spellbinder Maryana - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,9,0,100,0,0,8,15000,18000,11,15091,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spellbinder Maryana - Between 0-8 Range - Cast 15091");

-- Sunfury Astromancer SAI
SET @ENTRY := 19643;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Astromancer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,600000,600000,11,35917,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Astromancer - Out Of Combat - Cast 35917"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,38391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Astromancer - On Aggro - Cast 38391"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Astromancer - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,30,4500,6000,11,38391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Astromancer - Between 0-30 Range - Cast 38391 (Phase 1)"),
(@ENTRY,0,5,7,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Astromancer - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Astromancer - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Astromancer - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Astromancer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Astromancer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Astromancer - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,9,0,100,0,0,30,12000,16000,11,35914,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sunfury Astromancer - Between 0-30 Range - Cast 35914");
