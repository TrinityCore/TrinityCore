-- Sifreldar Runekeeper SAI
SET @ENTRY := 29331;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sifreldar Runekeeper - On Aggro - Cast 20792"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Between 0-40 Range - Cast 20792 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,2,0,100,0,0,30,15000,22000,11,52714,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Between 0-30% Health - Cast 52714");

-- Yulda the Stormspeaker SAI
SET @ENTRY := 30046;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,32018,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yulda the Stormspeaker - On Aggro - Cast 32018"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yulda the Stormspeaker - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,30,3400,4800,11,32018,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Between 0-30 Range - Cast 32018 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,9000,12000,15000,18000,11,55087,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yulda the Stormspeaker - In Combat - Cast 55087");

-- Ahn'kahar Spell Flinger SAI
SET @ENTRY := 30278;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,56698,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - On Aggro - Cast 56698 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,23000,27000,11,56698,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Between 0-40 Range - Cast 56698 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,59102,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - On Aggro - Cast 59102 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,23000,27000,11,59102,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Between 0-40 Range - Cast 59102 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Between 15-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,2,10000,14000,13000,16000,11,56702,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - In Combat - Cast 56702 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,10000,14000,13000,16000,11,59103,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - In Combat - Cast 59103 (Heroic Dungeon)");

-- Eye of Taldaram SAI
SET @ENTRY := 30285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Taldaram - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,17439,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - On Aggro - Cast 17439 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Taldaram - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,20,3400,4800,11,17439,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Between 0-20 Range - Cast 17439 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,17289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - On Aggro - Cast 17289 (Heroic Dungeon)"),
(@ENTRY,0,5,0,4,0,100,5,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Taldaram - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,20,3400,4800,11,17289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Between 0-20 Range - Cast 17289 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,0,13,0,100,3,0,0,0,0,11,56730,0,0,0,0,0,7,0,0,0,0,0,0,0,"Eye of Taldaram - On Target Casting - Cast 56730 (Normal Dungeon)"),
(@ENTRY,0,8,0,13,0,100,5,0,0,0,0,11,59111,0,0,0,0,0,7,0,0,0,0,0,0,0,"Eye of Taldaram - On Target Casting - Cast 59111 (Heroic Dungeon)"),
(@ENTRY,0,9,0,0,0,100,6,15000,19000,23000,27000,11,56728,1,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - In Combat - Cast 56728 (Dungeon Only)"),
(@ENTRY,0,10,11,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Taldaram - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Taldaram - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,9,1,100,7,15,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Taldaram - Between 15-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,9,1,100,7,5,10,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Taldaram - Between 5-10 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,14,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Taldaram - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,15,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of Taldaram - Between 15-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,16,0,6,0,100,3,0,0,0,0,11,56733,7,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - On Death - Cast 56733 (Normal Dungeon)"),
(@ENTRY,0,17,0,6,0,100,5,0,0,0,0,11,61463,7,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - On Death - Cast 61463 (Heroic Dungeon)");

-- Bound Water Elemental SAI
SET @ENTRY := 30419;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Water Elemental - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,7,0,0,0,0,11,56862,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Water Elemental - On Aggro - Cast 56862"),
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Water Elemental - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,6,0,40,3400,4800,11,56862,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Water Elemental - Between 0-40 Range - Cast 56862 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Water Elemental - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Water Elemental - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Water Elemental - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Water Elemental - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Water Elemental - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Water Elemental - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,2,9000,12000,12000,15000,11,39207,1,0,0,0,0,5,0,0,0,0,0,0,0,"Bound Water Elemental - In Combat - Cast 39207 (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,4,9000,12000,12000,15000,11,35735,1,0,0,0,0,5,0,0,0,0,0,0,0,"Bound Water Elemental - In Combat - Cast 35735 (Heroic Dungeon)");

-- Azure Binder SAI
SET @ENTRY := 31007;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,58456,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Binder - On Aggro - Cast 58456 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,30,3400,4800,11,58456,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Binder - Between 0-30 Range - Cast 58456 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,59248,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Binder - On Aggro - Cast 59248 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,30,3400,4800,11,59248,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Binder - Between 0-30 Range - Cast 59248 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,9,0,100,2,0,8,9000,15000,11,58455,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - Between 0-8 Range - Cast 58455 (Normal Dungeon)"),
(@ENTRY,0,13,0,9,0,100,4,0,8,9000,15000,11,59257,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - Between 0-8 Range - Cast 59257 (Heroic Dungeon)"),
(@ENTRY,0,14,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - Between 15-100% Mana - Decrement Event Phase (Dungeon Only)");

-- Gatekeeper Melindra SAI
SET @ENTRY := 32373;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - Out Of Combat - Cast 12544"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gatekeeper Melindra - On Aggro - Cast 17290"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,3400,4800,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gatekeeper Melindra - Between 0-40 Range - Cast 17290 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,9,0,100,0,0,15,9000,15000,11,56837,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - Between 0-15 Range - Cast 56837"),
(@ENTRY,0,12,0,0,0,100,0,8000,11000,19000,25000,11,12738,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gatekeeper Melindra - In Combat - Cast 12738");

-- Time-Lost Scryer SAI
SET @ENTRY := 18319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,6,1000,1000,1800000,1800000,11,32689,1,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - Out Of Combat - Cast 32689 (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,22273,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Scryer - On Aggro - Cast 22273 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,30,2400,3800,11,22273,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Scryer - Between 0-30 Range - Cast 22273 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,4,0,100,5,0,0,0,0,11,33989,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Scryer - On Aggro - Cast 33989 (Heroic Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,7,0,9,1,100,4,0,30,2400,3800,11,33989,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Scryer - Between 0-30 Range - Cast 33989 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Scryer - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,14,0,14,0,100,2,5000,20,7000,10000,11,17843,0,0,0,0,0,7,0,0,0,0,0,0,0,"Time-Lost Scryer - On Friendly Unit At 5000 Health Within 20 Range - Cast 17843 (Normal Dungeon)"),
(@ENTRY,0,15,0,14,0,100,4,8000,20,7000,10000,11,17138,0,0,0,0,0,7,0,0,0,0,0,0,0,"Time-Lost Scryer - On Friendly Unit At 8000 Health Within 20 Range - Cast 17138 (Heroic Dungeon)"),
(@ENTRY,0,16,0,14,0,100,2,2000,20,8000,10000,11,12160,0,0,0,0,0,7,0,0,0,0,0,0,0,"Time-Lost Scryer - On Friendly Unit At 2000 Health Within 20 Range - Cast 12160 (Normal Dungeon)"),
(@ENTRY,0,17,0,14,0,100,4,3500,20,8000,10000,11,15981,0,0,0,0,0,7,0,0,0,0,0,0,0,"Time-Lost Scryer - On Friendly Unit At 3500 Health Within 20 Range - Cast 15981 (Heroic Dungeon)");

-- Auchenai Soulpriest SAI
SET @ENTRY := 18493;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,32860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Cast 32860 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,32860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Soulpriest - Between 0-40 Range - Cast 32860 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,38378,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Cast 38378 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,2400,3800,11,38378,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Soulpriest - Between 0-40 Range - Cast 38378 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,3,8000,8000,0,0,11,32858,1,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat - Cast 32858 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,5,8000,8000,0,0,11,38377,1,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat - Cast 38377 (Heroic Dungeon)"),
(@ENTRY,0,15,0,4,0,20,7,0,0,0,0,11,32853,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Cast 32853 (Dungeon Only)"),
(@ENTRY,0,16,0,4,0,20,7,0,0,0,0,11,32854,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Cast 32854 (Dungeon Only)"),
(@ENTRY,0,17,0,4,0,20,7,0,0,0,0,11,32855,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Cast 32855 (Dungeon Only)"),
(@ENTRY,0,18,0,4,0,20,7,0,0,0,0,11,32856,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Cast 32856 (Dungeon Only)"),
(@ENTRY,0,19,0,4,0,20,7,0,0,0,0,11,32857,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Cast 32857 (Dungeon Only)");

-- Unliving Sorcerer SAI
SET @ENTRY := 18499;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Sorcerer - On Aggro - Cast 12466 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,2400,3800,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Sorcerer - Between 0-40 Range - Cast 12466 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Sorcerer - On Aggro - Cast 17290 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,2400,3800,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Sorcerer - Between 0-40 Range - Cast 17290 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,2,6000,8000,13000,15000,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Sorcerer - In Combat - Cast 15043 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,6000,8000,13000,15000,11,15530,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Sorcerer - In Combat - Cast 15530 (Heroic Dungeon)"),
(@ENTRY,0,15,0,0,0,100,2,10000,10000,10000,13000,11,15744,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - In Combat - Cast 15744 (Normal Dungeon)"),
(@ENTRY,0,16,0,0,0,100,4,10000,10000,10000,13000,11,22424,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - In Combat - Cast 22424 (Heroic Dungeon)"),
(@ENTRY,0,17,0,7,0,100,7,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - On Evade - Die (Dungeon Only)");

-- Durnholde Mage SAI
SET @ENTRY := 18934;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - Out Of Combat - Cast 12544"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Mage - On Aggro - Cast 12466 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,3400,4800,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Mage - Between 0-40 Range - Cast 12466 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,4,0,100,5,0,0,0,0,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Mage - On Aggro - Cast 17290 (Heroic Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,7,0,9,1,100,4,0,40,3400,4800,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Mage - Between 0-40 Range - Cast 17290 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,8,9,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,3,2,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,14,0,0,0,100,6,7000,11000,13000,16000,11,13341,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Mage - In Combat - Cast 13341 (Dungeon Only)"),
(@ENTRY,0,15,0,0,0,100,6,7000,11000,13000,16000,11,16144,0,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Mage - In Combat - Cast 16144 (Dungeon Only)"),
(@ENTRY,0,16,0,0,0,100,6,14000,19000,16000,19000,11,15244,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - In Combat - Cast 15244 (Dungeon Only)"),
(@ENTRY,0,17,0,0,0,100,6,14000,19000,16000,19000,11,38384,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - In Combat - Cast 38384 (Dungeon Only)"),
(@ENTRY,0,18,0,0,0,100,6,8000,13000,14000,18000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Durnholde Mage - In Combat - Cast 13323 (Dungeon Only)"),
(@ENTRY,0,19,20,2,0,100,7,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - Between 0-15% Health - Set Event Phase 3 (Dungeon Only)"),
(@ENTRY,0,20,21,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Mage - Between 0-15% Health - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,21,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Durnholde Mage - Between 0-15% Health - Flee For Assist (Dungeon Only)");

-- Sunfury Nethermancer SAI
SET @ENTRY := 20248;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,300000,300000,11,36477,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - Out Of Combat - Cast 36477"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,35778,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - On Aggro - Cast 35778"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Nethermancer - On Aggro - Cast 9613"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,0,9,1,100,0,0,40,3400,4800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,6,7,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,11,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,12,0,0,0,100,0,35000,38000,30000,35000,11,35778,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - In Combat - Cast 35778"),
(@ENTRY,0,13,0,2,0,100,0,0,75,15000,20000,11,17173,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 0-75% Health - Cast 17173"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 0-15% Health - Flee For Assist");

-- Snowplain Disciple SAI
SET @ENTRY := 26705;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowplain Disciple - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,61730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowplain Disciple - On Aggro - Cast 61730"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowplain Disciple - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,2,100,0,0,40,4000,5000,11,61730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowplain Disciple - Between 0-40 Range - Cast 61730 (Phase 1)"),
(@ENTRY,0,4,5,3,2,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowplain Disciple - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowplain Disciple - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowplain Disciple - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowplain Disciple - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowplain Disciple - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Snowplain Disciple - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,14,0,100,0,1000,20,13000,16000,11,52011,1,0,0,0,0,7,0,0,0,0,0,0,0,"Snowplain Disciple - On Friendly Unit At 1000 Health Within 20 Range - Cast 52011"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowplain Disciple - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowplain Disciple - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Snowplain Disciple - Between 0-15% Health - Flee For Assist");

-- Azure Magus SAI
SET @ENTRY := 26722;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Magus - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,15530,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Magus - On Aggro - Cast 15530 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Magus - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4800,11,15530,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Magus - Between 0-40 Range - Cast 15530 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,56775,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Magus - On Aggro - Cast 56775 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Magus - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,3400,4800,11,56775,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Magus - Between 0-40 Range - Cast 56775 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Magus - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Magus - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Magus - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Magus - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Magus - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Magus - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,13,0,0,0,100,2,9000,11000,9000,15000,11,37132,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Magus - In Combat - Cast 37132 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,9000,11000,9000,15000,11,56776,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Magus - In Combat - Cast 56776 (Heroic Dungeon)");

-- 7th Legion Cleric SAI
SET @ENTRY := 26780;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Cleric - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,25054,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Cleric - On Aggro - Cast 25054"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Cleric - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,25054,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Cleric - Between 0-40 Range - Cast 25054 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Cleric - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Cleric - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Cleric - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Cleric - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Cleric - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Cleric - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,14,0,100,0,7000,40,17000,24000,11,31739,0,0,0,0,0,7,0,0,0,0,0,0,0,"7th Legion Cleric - On Friendly Unit At 7000 Health Within 40 Range - Cast 31739"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Cleric - Between 0-15% Health - Set Event Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Cleric - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"7th Legion Cleric - Between 0-15% Health - Flee For Assist");

-- Drakkari Oracle SAI
SET @ENTRY := 26795;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Oracle - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Oracle - On Aggro - Cast 9532"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Oracle - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Oracle - Between 0-40 Range - Cast 9532 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Oracle - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Oracle - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Oracle - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Oracle - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Oracle - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Oracle - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,7000,9000,12000,17000,11,52430,1,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Oracle - In Combat - Cast 52430"),
(@ENTRY,0,11,0,0,0,100,0,9000,12000,12000,17000,11,52431,1,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari Oracle - In Combat - Cast 52431");

-- Reanimated Frost Wyrm SAI
SET @ENTRY := 26841;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,47425,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - On Aggro - Cast 47425"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,35,5000,7000,11,47425,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - Between 0-35 Range - Cast 47425 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,30,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - Between 30-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - Between 15-100% Mana - Decrement Event Phase");

-- Decrepit Necromancer SAI
SET @ENTRY := 26942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Necromancer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Decrepit Necromancer - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Necromancer - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Decrepit Necromancer - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Necromancer - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Necromancer - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Necromancer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Necromancer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Necromancer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Necromancer - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,7000,10000,16000,20000,11,50659,1,0,0,0,0,2,0,0,0,0,0,0,0,"Decrepit Necromancer - In Combat - Cast 50659");

-- Overseer Deathgaze SAI
SET @ENTRY := 27122;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Deathgaze - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overseer Deathgaze - On Aggro - Cast 12739"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Deathgaze - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overseer Deathgaze - Between 0-40 Range - Cast 12739 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Deathgaze - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Deathgaze - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Deathgaze - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Deathgaze - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Deathgaze - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Deathgaze - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,9000,14000,15000,18000,11,50659,1,0,0,0,0,2,0,0,0,0,0,0,0,"Overseer Deathgaze - In Combat - Cast 50659");

-- Iron Rune Overseer SAI
SET @ENTRY := 27177;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Overseer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,32018,0,0,0,0,0,2,0,0,0,0,0,0,0,"Iron Rune Overseer - On Aggro - Cast 32018"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Overseer - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,30,3400,4800,11,32018,0,0,0,0,0,2,0,0,0,0,0,0,0,"Iron Rune Overseer - Between 0-30 Range - Cast 32018 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Overseer - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Overseer - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Overseer - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Overseer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Overseer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Overseer - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,11,8,0,100,1,48046,0,0,0,11,48047,0,0,0,0,0,7,0,0,0,0,0,0,0,"Iron Rune Overseer - On Spellhit By 48046 - Quest Credit"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Overseer - On Spellhit By 48046 - Forced Despawn");

-- Dragonflayer Flamebinder SAI
SET @ENTRY := 27259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,52209,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - On Aggro - Cast 52209"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,3400,4800,11,52209,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - Between 0-40 Range - Cast 52209 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,1,0,7,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,0,0,100,0,8000,12000,16000,19000,11,52208,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - In Combat - Cast 52208"),
(@ENTRY,0,12,0,7,0,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - On Evade - Set Event Phase 0");

-- Risen Wintergarde Mage SAI
SET @ENTRY := 27283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Wintergarde Mage - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Wintergarde Mage - On Aggro - Cast 9672"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Wintergarde Mage - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Wintergarde Mage - Between 0-40 Range - Cast 9672 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Wintergarde Mage - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Wintergarde Mage - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Wintergarde Mage - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Wintergarde Mage - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Wintergarde Mage - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Wintergarde Mage - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,10,0,0,0,100,0,8000,12000,9000,14000,11,13339,1,0,0,0,0,5,0,0,0,0,0,0,0,"Risen Wintergarde Mage - In Combat - Cast 13339");

-- Naxxramas Necrolord SAI
SET @ENTRY := 27289;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxramas Necrolord - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,51287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naxxramas Necrolord - On Aggro - Cast 51287"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxramas Necrolord - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,51287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naxxramas Necrolord - Between 0-40 Range - Cast 51287 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxramas Necrolord - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxramas Necrolord - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxramas Necrolord - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxramas Necrolord - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxramas Necrolord - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxramas Necrolord - Between 15-100% Mana - Decrement Event Phase");

-- Onslaught Raven Priest SAI
SET @ENTRY := 27202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,50740,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Aggro - Cast 50740"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,50740,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Raven Priest - Between 0-40 Range - Cast 50740 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,1,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - Between 15-100% Mana - Decrement Event Phase (Phase 1)"),
(@ENTRY,0,10,0,2,0,100,0,0,30,14000,18000,11,50750,1,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - Between 0-30% Health - Cast 50750"),
(@ENTRY,0,11,12,8,0,100,1,48679,0,0,0,11,48655,0,0,0,0,0,7,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit By 48679 - Quest Credit"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit By 48679 - Forced Despawn");

-- Bishop Street SAI
SET @ENTRY := 27246;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bishop Street - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,20820,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bishop Street - On Aggro - Cast 20820"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bishop Street - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,20820,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bishop Street - Between 0-40 Range - Cast 20820 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bishop Street - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bishop Street - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bishop Street - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bishop Street - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bishop Street - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bishop Street - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,0,0,100,0,12000,16000,45000,55000,11,11974,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bishop Street - In Combat - Cast 11974");

-- Onslaught Raven Archon SAI
SET @ENTRY := 27357;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Archon - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,50740,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Raven Archon - On Aggro - Cast 50740"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Archon - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,6000,8500,11,50740,0,0,0,0,0,5,0,0,0,0,0,0,0,"Onslaught Raven Archon - Between 0-40 Range - Cast 50740 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Archon - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Archon - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Archon - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Archon - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Archon - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Archon - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,10,0,2,0,100,0,0,30,19000,23000,11,50743,1,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Archon - Between 0-30% Health - Cast 50743");

-- Thel'zan the Duskbringer SAI
SET @ENTRY := 27383;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,31256,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Out Of Combat - Cast 31256"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,42719,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - On Aggro - Cast 42719"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,3400,4800,11,42719,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 0-40 Range - Cast 42719 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 15-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,0,0,100,0,7000,11000,14000,18000,11,39268,1,0,0,0,0,5,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - In Combat - Cast 39268"),
(@ENTRY,0,12,0,9,0,100,0,0,10,15000,20000,11,22643,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 0-10 Range - Cast 22643"),
(@ENTRY,0,13,0,2,0,100,1,0,50,0,0,11,50497,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 0-50% Health - Cast 50497"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,11,50497,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 0-15% Health - Cast 50497");

-- Necrolord Amarion SAI
SET @ENTRY := 27508;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Amarion - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,51339,0,0,0,0,0,2,0,0,0,0,0,0,0,"Necrolord Amarion - On Aggro - Cast 51339"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Amarion - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3800,4500,11,51339,0,0,0,0,0,5,0,0,0,0,0,0,0,"Necrolord Amarion - Between 0-40 Range - Cast 51339 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Amarion - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Amarion - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Amarion - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Amarion - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Amarion - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Necrolord Amarion - Between 15-100% Mana - Decrement Event Phase");

-- Burning Depths Necromancer SAI
SET @ENTRY := 27358;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Depths Necromancer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,51431,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Depths Necromancer - On Aggro - Cast 51431"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Depths Necromancer - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,7000,10000,11,51431,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Depths Necromancer - Between 0-40 Range - Cast 51431 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Depths Necromancer - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Depths Necromancer - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Depths Necromancer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Depths Necromancer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Depths Necromancer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Depths Necromancer - Between 15-100% Mana - Decrement Event Phase (Phase 2)");

-- Frigid Necromancer SAI
SET @ENTRY := 27539;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,50324,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer - On Aggro - Cast 50324"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frigid Necromancer - On Aggro - Cast 9613"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,1,100,0,0,40,3400,4800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frigid Necromancer - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,10,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer - Between 15-100% Mana - Decrement Event Phase (Phase 2)"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,50324,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frigid Necromancer - Between 0-30% Health - Cast 50324");

-- Angrathar Necrolord SAI
SET @ENTRY := 27603;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angrathar Necrolord - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Angrathar Necrolord - On Aggro - Cast 9613"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angrathar Necrolord - On Aggro - Increment Event Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Angrathar Necrolord - Between 0-40 Range - Cast 9613 (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angrathar Necrolord - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angrathar Necrolord - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angrathar Necrolord - Between 35-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angrathar Necrolord - Between 5-15 Range - Disallow Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angrathar Necrolord - Between 0-5 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Angrathar Necrolord - Between 15-100% Mana - Decrement Event Phase (Phase 2)");
