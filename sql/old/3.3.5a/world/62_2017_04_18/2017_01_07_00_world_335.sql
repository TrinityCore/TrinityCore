-- Lava Reaver SAI
SET @ENTRY := 12100;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,7000,11,19644,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lava Reaver - Within 0-5 Range - Cast 'Strike' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8000,11000,12000,15000,11,19642,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lava Reaver - In Combat - Cast 'Cleave' (Normal Dungeon)");

-- Lava Elemental SAI
SET @ENTRY := 12076;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,9000,9000,14000,11,19641,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lava Elemental - In Combat - Cast 'Pyroclast Barrage' (Normal Dungeon)");

-- Flame Imp SAI
SET @ENTRY := 11669;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,10,4000,7000,11,20602,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flame Imp - Within 0-10 Range - Cast 'Fire Nova' (Normal Dungeon)");

-- Lava Annihilator SAI
SET @ENTRY := 11665;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,12000,15000,11,16168,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lava Annihilator - In Combat - Cast 'Flame Buffet' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,3400,4700,11,22088,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lava Annihilator - In Combat CMC - Cast 'Fireball' (Normal Dungeon)");
