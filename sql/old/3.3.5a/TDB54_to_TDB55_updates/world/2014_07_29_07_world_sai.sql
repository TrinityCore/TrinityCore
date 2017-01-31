-- Death's Head Adept SAI
SET @ENTRY := 4516;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Adept - In Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,10000,15000,11,113,1,0,0,0,0,5,0,0,0,0,0,0,0,"Death's Head Adept - In Combat - Cast 'Chains of Ice' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Adept - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Death's Head Priest SAI
SET @ENTRY := 4517;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,1245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Out of Combat - Cast 'Power Word: Fortitude' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Priest - In Combat CMC - Cast 'Shadow Bolt' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,2,0,40,14000,20000,11,6063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Between 0-40% Health - Cast 'Heal' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Priest - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Burning Blade Augur SAI
SET @ENTRY := 4663;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20807,64,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Augur - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,25000,25000,11,6909,32,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Augur - In Combat - Cast 'Curse of Thorns'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Augur - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Burning Blade Adept SAI
SET @ENTRY := 4665;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,19816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Adept - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Between 0-20% Health - Cast 'Bloodlust'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Adept - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Burning Blade Shadowmage SAI
SET @ENTRY := 4667;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Shadowmage - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,12000,18000,26000,11,9657,1,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - In Combat - Cast 'Shadow Shell'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Shadowmage - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Burning Blade Summoner SAI
SET @ENTRY := 4668;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,688,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Out of Combat - Cast 'Summon Imp'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Summoner - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Summoner - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Fallenroot Hellcaller SAI
SET @ENTRY := 4799;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Fallenroot Hellcaller - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,12000,15000,30000,45000,11,8129,1,0,0,0,0,5,0,0,0,0,0,0,0,"Fallenroot Hellcaller - In Combat - Cast 'Mana Burn' (Normal Dungeon)");

-- Blackfathom Tide Priestess SAI
SET @ENTRY := 4802;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,0,0,30,25000,35000,11,11642,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Between 0-30% Health - Cast 'Heal'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackfathom Tide Priestess - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Twilight Aquamancer SAI
SET @ENTRY := 4811;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,8372,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Out of Combat - Cast 'Summon Aqua Guardian' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,2,0,40,2400,3800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Aquamancer - In Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Twilight Shadowmage SAI
SET @ENTRY := 4813;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,12746,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - Out of Combat - Cast 'Summon Voidwalker' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Shadowmage - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,18000,26000,24000,30000,11,7645,1,0,0,0,0,6,0,0,0,0,0,0,0,"Twilight Shadowmage - In Combat - Cast 'Dominate Mind' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Blindlight Oracle SAI
SET @ENTRY := 4820;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Blindlight Oracle - In Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,14,0,100,2,1000,40,30000,40000,11,6063,1,0,0,0,0,7,0,0,0,0,0,0,0,"Blindlight Oracle - Friendly At 1000 Health - Cast 'Heal' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,2,0,49,22000,22000,11,8362,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - Between 0-50% Health - Cast 'Renew' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blindlight Oracle - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Lady Sarevess SAI
SET @ENTRY := 4831;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - On Aggro - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sarevess - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,12000,15000,11,8435,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sarevess - In Combat - Cast 'Forked Lightning' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,6000,8500,9000,13000,11,865,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - In Combat - Cast 'Frost Nova' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,7000,9000,9000,13000,11,246,33,0,0,0,0,6,0,0,0,0,0,0,0,"Lady Sarevess - In Combat - Cast 'Slow' (Normal Dungeon)"),
(@ENTRY,0,5,0,6,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - On Just Died - Say Line 1 (Normal Dungeon)");

-- Earthcaller Halmgar SAI
SET @ENTRY := 4842;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,8270,1,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Out of Combat - Cast 'Summon Earth Rumbler' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Earthcaller Halmgar - In Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,0,2000,50000,60000,11,2484,1,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - In Combat - Cast 'Earthbind Totem' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthcaller Halmgar - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Shadowforge Surveyor SAI
SET @ENTRY := 4844;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - Out of Combat - Cast 'Frost Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,5000,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Surveyor - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,10700,20100,20300,22600,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - In Combat - Cast 'Frost Nova'"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Shadowforge Darkcaster SAI
SET @ENTRY := 4848;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9081,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Darkcaster - In Combat CMC - Cast 'Shadow Bolt Volley' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,11000,15000,11,15800,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowforge Darkcaster - In Combat - Cast 'Mana Burn' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkcaster - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Stonevault Geomancer SAI
SET @ENTRY := 4853;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Geomancer - In Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,4000,8000,30000,38000,11,10452,1,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Geomancer - In Combat - Cast 'Flame Buffet' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Geomancer - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Grimlok SAI
SET @ENTRY := 4854;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Grimlok - In Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,8000,12000,21000,31000,11,8292,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimlok - In Combat - Cast 'Chain Bolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,3,5000,7000,0,0,11,8143,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - In Combat - Cast 'Tremor Totem' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,2,0,50,25000,35000,11,11892,33,0,0,0,0,5,0,0,0,0,0,0,0,"Grimlok - Between 0-50% Health - Cast 'Shrink' (Normal Dungeon)"),
(@ENTRY,0,5,0,2,0,100,2,0,30,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Between 0-30% Health - Cast 'Bloodlust' (Normal Dungeon)"),
(@ENTRY,0,6,0,5,0,100,3,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - On Killed Unit - Say Line 2 (No Repeat) (Normal Dungeon)");

-- Stonevault Cave Hunter SAI
SET @ENTRY := 4856;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2800,4700,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Cave Hunter - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,0,0,100,0,5900,13200,20300,26700,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Cave Hunter - In Combat - Cast 'Net'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - Between 0-15% Health - Flee For Assist (No Repeat)");
