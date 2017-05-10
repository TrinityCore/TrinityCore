-- Bound Fire Elemental SAI
SET @ENTRY := 30416;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4800,11,17195,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Fire Elemental - Combat CMC - Cast Scorch (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,0,5,11000,14000,11,12470,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Fire Elemental - Combat - Cast Fire Nova (Dungeon Only)");

-- Bound Air Elemental SAI
SET @ENTRY := 30418;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,22414,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Air Elemental - Combat CMC - Cast Lightning Bolt (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4800,11,59169,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Air Elemental - Combat CMC - Cast Lightning Bolt (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10000,13000,11000,13000,11,46150,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - Combat - Cast Forked Lightning (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,10000,13000,11000,13000,11,59152,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bound Air Elemental - Combat - Cast Forked Lightning (Heroic Dungeon)");

-- Bound Water Elemental SAI
SET @ENTRY := 30419;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4800,11,56862,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bound Water Elemental - Combat CMC - Cast Water Bolt (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,2,9000,12000,12000,15000,11,39207,1,0,0,0,0,5,0,0,0,0,0,0,0,"Bound Water Elemental - Combat - Cast Water Spout (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,9000,12000,12000,15000,11,35735,1,0,0,0,0,5,0,0,0,0,0,0,0,"Bound Water Elemental - Combat - Cast Water Spout (Heroic Dungeon)");

-- Halefnir the Windborn SAI
SET @ENTRY := 30376;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,6000,6000,11,20831,64,0,0,0,0,2,0,0,0,0,0,0,0,"Halefnir the Windborn - Combat CMC - Cast Chain Lightning");

-- Twilight Darkcaster SAI
SET @ENTRY := 30319;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,4000,5000,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Darkcaster - Combat CMC - Cast Shadow Bolt (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,5000,7000,11,61562,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Darkcaster - Combat CMC - Cast Shadow Bolt (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,17000,20000,11,56898,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Darkcaster - Combat - Cast Corruption (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,4000,7000,17000,20000,11,61563,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Darkcaster - Combat - Cast Corruption (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,12000,15000,19000,23000,11,13338,1,0,0,0,0,6,0,0,0,0,0,0,0,"Twilight Darkcaster - Combat - Cast Curse of Tongues (Dungeon Only)");
