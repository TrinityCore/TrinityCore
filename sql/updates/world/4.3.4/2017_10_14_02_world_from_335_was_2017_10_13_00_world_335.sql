/*
-- Searing Blade Cultist SAI
SET @ENTRY := 11322;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,16000,18000,11,18266,0,0,0,0,0,5,0,0,0,0,0,0,0,"Searing Blade Cultist - In Combat - Cast 'Curse of Agony' (Normal Dungeon)");

-- Ragefire Trogg SAI
SET @ENTRY := 11318;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4000,3000,5000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragefire Trogg - In Combat - Cast 'Strike' (Normal Dungeon)");

-- Ragefire Shaman SAI
SET @ENTRY := 11319;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ragefire Shaman - In Combat CMC- Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,14,0,100,2,400,40,18000,22000,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Ragefire Shaman - Friendly At 400 Health - Cast 'Healing Wave' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Earthborer SAI
SET @ENTRY := 11320;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4000,6000,9000,11,18070,0,0,0,0,0,2,0,0,0,0,0,0,0,"Earthborer - In Combat - Cast 'Earthborer Acid' (Normal Dungeon)");

-- Searing Blade Enforcer SAI
SET @ENTRY := 11323;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,10000,15000,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Blade Enforcer - In Combat - Cast 'Shield Slam' (Normal Dungeon)");

-- Searing Blade Warlock SAI
SET @ENTRY := 11324;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,2,0,0,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - On Reset - Cast 'Summon Voidwalker' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,3000,5000,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Blade Warlock - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Voidwalker Minion SAI
SET @ENTRY := 8996;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,4000,6000,11,33914,0,0,0,0,0,2,0,0,0,0,0,0,0,"Voidwalker Minion - In Combat - Cast 'Shadowstrike'"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 10000, 15000, 25000, 30000, 11, 33916, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Voidwalker Minion - IC - Void Drain");

-- Bazzalan SAI
SET @ENTRY := 11519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,6000,9000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bazzalan - In Combat - Cast 'Sinister Strike' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,4000,8000,12000,16000,11,2818,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bazzalan - In Combat - Cast 'Deadly Poison' (Normal Dungeon)");

-- Jergosh the Invoker SAI
SET @ENTRY := 11518;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,120000,150000,11,11980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jergosh the Invoker - In Combat - Cast 'Curse of Weakness' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,20000,25000,11,20800,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jergosh the Invoker - In Combat - Cast 'Immolate' (Normal Dungeon)");

-- Oggleflint SAI
SET @ENTRY := 11517;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,8000,8000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oggleflint - In Combat - Cast 'Cleave' (Normal Dungeon)");

-- Taragaman the Hungerer SAI
SET @ENTRY := 11520;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,9000,12000,11,18072,0,0,0,0,0,2,0,0,0,0,0,0,0,"Taragaman the Hungerer - In Combat - Cast 'Uppercut' (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,0,8,9000,12000,11,11970,0,0,0,0,0,2,0,0,0,0,0,0,0,"Taragaman the Hungerer - Within 0-8 Range - Cast 'Fire Nova' (Normal Dungeon)");

-- RFC bosses have no CC immunity
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry` IN (11517,11518,11519,11520);
*/
