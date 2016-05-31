-- Hate'rel SAI
SET @ENTRY := 9034;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hate'rel - In Combat CMC - Cast 'Shadow Bolt'(Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,0,5,5000,7000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hate'rel - Within 0-5 Range - Cast 'Strike' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,14000,40000,48000,11,15232,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - In Combat - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,14000,17000,15000,20000,11,15232,1,0,0,0,0,5,0,0,0,0,0,0,0,"Hate'rel - In Combat - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,4,0,21,0,100,3,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Hate'rel - On Reached Home - Set Instance Data 4 to 2 (Phase 1) (No Repeat) (Normal Dungeon)");

-- Vile'rel SAI
SET @ENTRY := 9036;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,15587,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vile'rel - In Combat CMC - Cast 'Mind Blast' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,20000,30000,60000,120000,11,11974,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - In Combat - Cast 'Power Word: Shield' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,15000,20000,15000,20000,11,15585,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - In Combat - Cast 'Prayer of Healing' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,2,0,50,16000,20000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - Between 0-50% Health - Cast 'Heal' (Normal Dungeon)"),
(@ENTRY,0,4,0,21,0,100,3,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vile'rel - On Reached Home - Set Instance Data 4 to 2 (No Repeat) (Normal Dungeon)");

-- Seeth'rel SAI
SET @ENTRY := 9038;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,33,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - Out of Combat - Cast 'Frost Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,3400,4800,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,"Seeth'rel - In Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,14000,19000,24000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - In Combat - Cast 'Cone of Cold' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,12000,16000,20000,23000,11,12674,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - In Combat - Cast 'Frost Nova' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,3000,5000,64000,75000,11,15044,1,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - In Combat - Cast 'Frost Ward' (Normal Dungeon)"),
(@ENTRY,0,5,0,21,0,100,3,0,0,0,0,34,4,2,0,0,0,0,1,0,0,0,0,0,0,0,"Seeth'rel - On Reached Home - Set Instance Data 4 to 2 (No Repeat) (Normal Dungeon)");

-- Warder Stilgiss SAI
SET @ENTRY := 9041;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,33,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Out of Combat - Cast 'Frost Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warder Stilgiss - In Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,9000,14000,18000,11,12674,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - In Combat - Cast 'Frost Nova' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,3000,4000,65000,70000,11,15044,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - In Combat - Cast 'Frost Ward' (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warder Stilgiss - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Spirestone Ogre Magus SAI
SET @ENTRY := 9201;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15979,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spirestone Ogre Magus - In Combat CMC - Cast 'Arcane Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,2,0,40,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Ogre Magus - Between 0-40% Health - Cast 'Bloodlust'= (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,6000,9000,20000,30000,11,13747,1,0,0,0,0,2,0,0,0,0,0,0,0,"Spirestone Ogre Magus - In Combat - Cast 'Slow'= (Normal Dungeon)");

-- Spirestone Lord Magus SAI
SET @ENTRY := 9217;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15230,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spirestone Lord Magus - In Combat CMC - Cast 'Arcane Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,12000,14000,19000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Spirestone Lord Magus - In Combat - Cast 'Polymorph' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,2,0,50,25000,30000,11,8365,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - Between 0-50% Health - Cast 'Enlarge' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,2,0,30,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spirestone Lord Magus - Between 0-30% Health - Cast 'Bloodlust' (Normal Dungeon)");

-- Smolderthorn Headhunter SAI
SET @ENTRY := 9241;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15795,64,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Headhunter - In Combat CMC - Cast 'Throw' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,5,30,9000,13000,11,16001,1,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Within 5-30 Range - Cast 'Impale' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,5000,10000,22000,26000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Headhunter - In Combat - Cast 'Pierce Armor' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Headhunter - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Scarshield Warlock SAI
SET @ENTRY := 9257;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarshield Warlock - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,10000,20000,60000,75000,11,15125,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - In Combat - Cast 'Scarshield Portal' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarshield Warlock - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Firebrand Darkweaver SAI
SET @ENTRY := 9261;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Darkweaver - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,50,2,4000,6000,30000,45000,11,15128,32,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Darkweaver - In Combat - Cast 'Mark of Flames' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,14000,9000,14000,11,15090,1,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Darkweaver - In Combat - Cast 'Dispel Magic' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,1000,4000,12000,15000,11,16071,32,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Darkweaver - In Combat - Cast 'Curse of the Firebrand' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,12000,15000,12000,15000,11,14887,1,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Darkweaver - In Combat - Cast 'Shadow Bolt Volley' (Normal Dungeon)"),
(@ENTRY,0,5,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Darkweaver - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Firebrand Invoker SAI
SET @ENTRY := 9262;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,"Firebrand Invoker - In Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,50,2,4000,6000,30000,45000,11,15128,32,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Invoker - In Combat - Cast 'Mark of Flames' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,8000,10000,11000,14000,11,12470,1,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - In Combat - Cast 'Fire Nova' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,12000,16000,14000,18000,11,12468,0,0,0,0,0,5,0,0,0,0,0,0,0,"Firebrand Invoker - In Combat - Cast 'Flamestrike' (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firebrand Invoker - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Smolderthorn Axe Thrower SAI
SET @ENTRY := 9267;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15795,64,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - In Combat CMC - Cast 'Throw' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,9000,12000,11,3391,1,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - In Combat - Cast 'Thrash' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,14000,11000,15000,11,11428,1,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - In Combat - Cast 'Knockdown' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Axe Thrower - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Smolderthorn Seer SAI
SET @ENTRY := 9269;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,600000,600000,11,13585,33,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Out of Combat - Cast 'Lightning Shield' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,15801,64,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderthorn Seer - In Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,14,0,100,2,3000,40,15000,25000,11,12492,1,0,0,0,0,7,0,0,0,0,0,0,0,"Smolderthorn Seer - Friendly At 3000 Health - Cast 'Healing Wave' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,3000,6000,12000,15000,11,15802,32,0,0,0,0,5,0,0,0,0,0,0,0,"Smolderthorn Seer - In Combat - Cast 'Shrink' (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderthorn Seer - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Dark Keeper Vorfalk SAI
SET @ENTRY := 9437;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15234,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - In Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,7000,10000,11,15306,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Vorfalk - In Combat - Cast 'Shock' (Normal Dungeon)");

-- Dark Keeper Bethek SAI
SET @ENTRY := 9438;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15228,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Bethek - In Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,5000,15000,20000,11,12738,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Bethek - In Combat - Cast 'Amplify Damage' (Normal Dungeon)");

-- Dark Keeper Uggel SAI
SET @ENTRY := 9439;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Uggel - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,7000,12000,18000,11,14875,33,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Keeper Uggel - In Combat - Cast 'Curse of Agony' (Normal Dungeon)");

-- Dark Keeper Ofgut SAI
SET @ENTRY := 9442;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15230,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Ofgut - In Combat CMC - Cast 'Arcane Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,12000,18000,24000,11,7121,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Ofgut - In Combat - Cast 'Anti-Magic Shield' (Normal Dungeon)");

-- Dark Keeper Pelver SAI
SET @ENTRY := 9443;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,33,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Keeper Pelver - Out of Combat - Cast 'Frost Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Keeper Pelver - In Combat CMC - Cast 'Frostbolt' (Normal Dungeon)");

-- Scarlet Cleric SAI
SET @ENTRY := 9449;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,15587,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Cleric - In Combat CMC - Cast 'Mind Blast'"),
(@ENTRY,0,1,0,74,0,100,0,0,40,25000,35000,11,15587,1,0,0,0,0,9,0,0,0,0,0,0,0,"Scarlet Cleric - On Friendly Between 0-40% Health - Cast 'Mind Blast'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Curate SAI
SET @ENTRY := 9450;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,3400,4800,11,25054,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Curate - In Combat CMC - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,15,0,100,1,0,0,30,0,11,17201,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Curate - Friendly Crowd Controlled - Cast 'Dispel Magic'"),
(@ENTRY,0,2,0,74,0,100,0,0,40,25000,35000,11,17201,1,0,0,0,0,9,0,0,0,0,0,0,0,"Scarlet Curate - On Friendly Between 0-40% Health - Cast 'Dispel Magic'"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Archmage SAI
SET @ENTRY := 9451;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,18100,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,9,0,100,0,0,40,3400,4800,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Archmage - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,16000,21000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - In Combat - Cast 'Cone of Cold'"),
(@ENTRY,0,3,0,13,0,100,1,0,0,0,0,11,15122,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Archmage - Target Casting - Cast 'Counterspell'"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Enchanter SAI
SET @ENTRY := 9452;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,25055,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Enchanter - In Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,7000,10000,18000,22000,11,15970,1,0,0,0,0,6,0,0,0,0,0,0,0,"Scarlet Enchanter - In Combat - Cast 'Sleep'");

-- Bloodaxe Evoker SAI
SET @ENTRY := 9693;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,13748,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodaxe Evoker - In Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,0,0,75,2,12000,14000,25000,30000,11,15743,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - In Combat - Cast 'Flamecrack' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,80,2,7000,9000,15000,20000,11,15744,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - In Combat - Cast 'Blast Wave' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Evoker - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Bloodaxe Summoner SAI
SET @ENTRY := 9717;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,5800,11,15791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodaxe Summoner - In Combat CMC - Cast 'Arcane Missiles' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,90,2,6000,9000,13000,18000,11,15532,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodaxe Summoner - In Combat - Cast 'Frost Nova' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,75,2,8000,12000,25000,30000,11,15734,1,0,0,0,0,6,0,0,0,0,0,0,0,"Bloodaxe Summoner - In Combat - Cast 'Summon' (Normal Dungeon)");

-- Flamekin Spitter SAI
SET @ENTRY := 9776;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2600,5100,11,15664,64,0,0,0,0,2,0,0,0,0,0,0,0,"Flamekin Spitter - In Combat CMC - Cast 'Venom Spit'");

-- Flamekin Torcher SAI
SET @ENTRY := 9778;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4700,11,15665,64,0,0,0,0,2,0,0,0,0,0,0,0,"Flamekin Torcher - In Combat CMC - Cast 'Fireball'");

-- Wesley SAI
SET @ENTRY := 9978;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wesley - Between 0-15% Health - Flee For Assist");
