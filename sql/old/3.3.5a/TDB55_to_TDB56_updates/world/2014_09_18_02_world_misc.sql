-- Nexus Guardian SAI
SET @ENTRY := 26276;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,47425,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Guardian - Combat CMC - Cast 'Frost Breath'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,13000,11,51857,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Guardian - Within 0-5 Range - Cast 'Frost Cleave'");

-- Saragosa SAI
SET @ENTRY := 26232;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,6200,11,51779,64,0,0,0,0,2,0,0,0,0,0,0,0,"Saragosa - In Combat CMC - Cast 'Frostfire Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,8500,17500,20100,40100,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - In Combat - Cast 'Frost Nova'");

-- Snowfall Glade Shaman SAI
SET @ENTRY := 26201;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,600000,600000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Snowfall Glade Shaman - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,12548,64,0,0,0,0,2,0,0,0,0,0,0,0,"Snowfall Glade Shaman - In Combat CMC - Cast 'Frost Shock'"),
(@ENTRY,0,2,0,14,0,100,0,4000,40,23000,30000,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Snowfall Glade Shaman - Friendly At 4000 Health - Cast 'Healing Wave'");

-- Snowfall Glade Wolvar SAI
SET @ENTRY := 26198;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,43413,64,0,0,0,0,2,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - In Combat CMC - Cast 'Throw Spear'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,9000,14000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Snowfall Glade Wolvar - Within 0-20 Range - Cast 'Net'");

-- Storm Tempest SAI
SET @ENTRY := 26045;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,11,8609,2,0,0,0,0,1,0,0,0,0,0,0,0,"Storm Tempest - On Just Created - Cast 'Cyclone Visual Spawn (DND)' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,1000,1000,12,23837,2,120000,0,0,0,8,0,0,0,3404,4133,18,6,"Storm Tempest - Out of Combat - Summon Creature 'ELM General Purpose Bunny'(No Repeat)"),
(@ENTRY,0,2,0,60,0,100,1,1000,1000,7000,8000,11,40136,2,0,0,0,0,19,23837,5,0,0,0,0,0,"Storm Tempest - On Update - Cast 'Lightning Cloud' (No Repeat)"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Storm Tempest - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,4,0,0,0,100,0,0,30,6000,7500,11,15659,64,0,0,0,0,2,0,0,0,0,0,0,0,"Storm Tempest - In Combat CMC - Cast 'Chain Lightning'"),
(@ENTRY,0,5,0,0,0,100,0,8000,11000,9000,14000,11,31272,0,0,0,0,0,2,0,0,0,0,0,0,0,"Storm Tempest - In Combat - Cast 'Wind Shock'"),
(@ENTRY,0,6,7,6,0,100,0,0,0,0,0,51,0,0,0,0,0,0,9,23837,0,10,0,0,0,0,"Storm Tempest - On Just Died - Kill Target"),
(@ENTRY,0,7,8,61,0,100,0,0,0,0,0,81,16777216,0,0,0,0,0,19,26048,10,0,0,0,0,0,"Storm Tempest - On Just Died - Set Npc Flag Spellclick"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,85,46424,2,0,0,0,0,16,0,0,0,0,0,0,0,"Storm Tempest - On Just Died - Invoker Cast 'Power of the Storm'");

-- Coldarra Spellweaver SAI
SET @ENTRY := 25722;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,600,5300,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Spellweaver - In Combat CMC - Cast 'Arcane Missiles' (No Repeat)");

-- Coldarra Spellbinder SAI
SET @ENTRY := 25719;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3900,5800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Spellbinder - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,1700,13500,172100,172100,11,50583,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - In Combat - Cast 'Summon Frozen Spheres'");

-- Inquisitor Caleras SAI
SET @ENTRY := 25720;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,6200,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,"Inquisitor Caleras - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,9800,21300,18400,18400,11,32192,1,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - In Combat - Cast 'Frost Nova'");

-- Bloodspore Firestarter SAI
SET @ENTRY := 25470;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,600000,600000,11,45985,1,1,0,0,0,1,0,0,0,0,0,0,0,"Bloodspore Firestarter - Out of Combat - Cast 'Flaming Touch'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3800,6200,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodspore Firestarter - In Combat CMC - Cast 'Fireball'");

-- Winterfin Oracle SAI
SET @ENTRY := 25216;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,50272,1,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - On Aggro - Cast 'Unstable Magic'"),
(@ENTRY,0,1,0,0,1,100,0,0,0,2700,5600,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Winterfin Oracle - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfin Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Budd's Bodyguard SAI
SET @ENTRY := 25145;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Budd's Bodyguard - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,8000,13000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Budd's Bodyguard - Within 0-20 Range - Cast 'Net'");
