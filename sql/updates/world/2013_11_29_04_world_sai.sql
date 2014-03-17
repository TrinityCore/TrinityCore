-- Twilight Apostle SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=30179 AND `source_type`=0 AND `id`=4;

-- Frostbringer SAI
SET @ENTRY := 30286;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,57825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostbringer - On Aggro - Cast 57825 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4800,11,57825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostbringer - Between 0-40 Range - Cast 57825 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,61461,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostbringer - On Aggro - Cast 61461 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,3400,4800,11,61461,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostbringer - Between 0-40 Range - Cast 61461 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,13,0,0,2,100,2,9000,12000,15000,18000,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - In Combat - Cast 15063 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,14,0,0,2,100,4,9000,12000,15000,18000,11,61462,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - In Combat - Cast 61462 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,15,0,2,0,100,6,0,30,120000,130000,11,56716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Between 0-30% Health - Cast 56716 (Dungeon Only)");

-- Twilight Darkcaster SAI
SET @ENTRY := 30319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Darkcaster - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Darkcaster - On Aggro - Cast 12739 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Darkcaster - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,4000,5000,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Darkcaster - Between 0-40 Range - Cast 12739 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,61562,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Darkcaster - On Aggro - Cast 61562 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Darkcaster - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,5000,7000,11,61562,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Darkcaster - Between 0-40 Range - Cast 61562 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Darkcaster - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Darkcaster - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Darkcaster - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Darkcaster - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Darkcaster - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Darkcaster - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,2,4000,7000,17000,20000,11,56898,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Darkcaster - In Combat - Cast 56898 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,4000,7000,17000,20000,11,61563,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Darkcaster - In Combat - Cast 61563 (Heroic Dungeon)"),
(@ENTRY,0,15,0,0,0,100,6,12000,15000,19000,23000,11,13338,1,0,0,0,0,6,0,0,0,0,0,0,0,"Twilight Darkcaster - In Combat - Cast 13338 (Dungeon Only)"),
(@ENTRY,0,16,0,2,0,100,7,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Darkcaster - Between 0-15% Health - Set Event Phase 3 (Dungeon Only)");

-- Twilight Worshipper SAI
SET @ENTRY := 30111;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Worshipper - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Worshipper - On Aggro - Cast 17290 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Worshipper - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,1,100,2,0,40,3400,4800,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Worshipper - Between 0-40 Range - Cast 17290 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,5,6,4,0,100,5,0,0,0,0,11,61567,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Worshipper - On Aggro - Cast 61567 (Heroic Dungeon)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Worshipper - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,7,0,9,1,100,4,0,40,5000,8000,11,61567,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Worshipper - Between 0-40 Range - Cast 61567 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,8,0,0,0,100,2,9000,12000,14000,17000,11,56858,1,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Worshipper - In Combat - Cast 56858 (Normal Dungeon)"),
(@ENTRY,0,9,0,0,0,100,4,9000,12000,14000,17000,11,61568,1,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Worshipper - In Combat - Cast 61568 (Heroic Dungeon)"),
(@ENTRY,0,10,11,3,1,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Worshipper - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Worshipper - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Worshipper - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,13,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Worshipper - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,14,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Worshipper - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,15,0,3,2,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Worshipper - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)");

-- Bound Fire Elemental SAI
SET @ENTRY := 30416;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Fire Elemental - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,7,0,0,0,0,11,17195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Fire Elemental - On Aggro - Cast 17195 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Fire Elemental - On Aggro - Increment Event Phase (Dungeon Only)"),
(@ENTRY,0,3,0,9,1,100,6,0,40,3400,4800,11,17195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Fire Elemental - Between 0-40 Range - Cast 17195 (Dungeon Only) (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Fire Elemental - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Fire Elemental - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Fire Elemental - Between 25-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Fire Elemental - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Fire Elemental - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,3,2,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Fire Elemental - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,10,0,9,0,100,6,0,5,11000,14000,11,12470,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Fire Elemental - Between 0-5 Range - Cast 12470 (Dungeon Only)");

-- Bound Air Elemental SAI
SET @ENTRY := 30418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,11,22414,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Air Elemental - On Aggro - Cast 22414 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4800,11,22414,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Air Elemental - Between 0-40 Range - Cast 22414 (Normal Dungeon) (Phase 1)"),
(@ENTRY,0,4,5,4,0,100,5,0,0,0,0,11,59169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Air Elemental - On Aggro - Cast 59169 (Heroic Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,1,100,4,0,40,3400,4800,11,38378,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Air Elemental - Between 0-40 Range - Cast 38378 (Heroic Dungeon) (Phase 1)"),
(@ENTRY,0,7,8,3,1,100,7,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - Between 0-7% Mana - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,8,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - Between 0-7% Mana - Increment Event Phase (Dungeon Only) (Phase 1)"),
(@ENTRY,0,9,0,9,1,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,10,0,9,1,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,11,0,9,1,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 1)"),
(@ENTRY,0,12,0,3,4,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - Between 15-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 4)"),
(@ENTRY,0,13,0,0,0,100,2,10000,13000,11000,13000,11,46150,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - In Combat - Cast 46150 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,4,10000,13000,11000,13000,11,59169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - In Combat - Cast 59169 (Heroic Dungeon)");
