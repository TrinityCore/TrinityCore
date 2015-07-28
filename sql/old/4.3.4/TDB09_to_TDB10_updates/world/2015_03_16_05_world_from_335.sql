-- Wastes Scavenger SAI
SET @ENTRY := 28005;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,5000,11,50403,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wastes Scavenger - Combat CMC - Cast 'Bone Toss'"),
(@ENTRY,0,1,0,8,0,100,0,50430,0,0,0,80,2800500,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Scavenger - On spellhit Devour Ghoul - Run script");

-- Emperor Cobra SAI
SET @ENTRY := 28011;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,32093,32,0,0,0,0,2,0,0,0,0,0,0,0,"Emperor Cobra - Combat CMC - Cast 'Poison Spit'");

-- Rainspeaker Oracle SAI
SET @ENTRY := 28025;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,6000,8000,11,15305,64,0,0,0,0,2,0,0,0,0,0,0,0,"Rainspeaker Oracle - Combat CMC - Cast 'Chain Lightning'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,12000,15000,11,54919,1,0,0,0,0,5,0,0,0,0,0,0,0,"Rainspeaker Oracle - Combat - Cast 'Warped Armor'");

-- Frenzyheart Tracker SAI
SET @ENTRY := 28077;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,66,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Frenzyheart Tracker - On Just Summoned  - Set Orientation"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - On Just Summoned  - Say Line 1"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,41,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - On Just Summoned  - Despawn After 8 seconds"),
(@ENTRY,0,3,0,0,0,100,0,0,0,3000,5000,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Tracker - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,4,0,0,0,100,0,10000,14000,60000,65000,11,53432,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzyheart Tracker - Combat - Cast 'Bear Trap'");

-- Frenzyheart Hunter SAI
SET @ENTRY := 28079;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Hunter - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,12000,15000,11,52270,1,0,0,0,0,5,0,0,0,0,0,0,0,"Frenzyheart Hunter - Combat - Cast 'Multi-Shot'");

-- Frenzyheart Scavenger SAI
SET @ENTRY := 28081;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,54617,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Scavenger - Combat CMC - Cast 'Throw Spear'");

-- Sparktouched Oracle SAI
SET @ENTRY := 28112;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,54916,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sparktouched Oracle - Combat CMC - Cast 'Lightning Burst'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,9000,12000,11,12549,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sparktouched Oracle - Within 0-30 Range - Cast 'Forked Lightning'");

-- Don Carlos SAI
SET @ENTRY := 28132;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,50736,1,0,0,0,0,1,0,0,0,0,0,0,0,"Don Carlos - Out of Combat - Cast 'Summon Guerrero' (No Repeat) (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2300,5000,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Don Carlos - Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,0,0,2300,5000,11,16496,64,0,0,0,0,2,0,0,0,0,0,0,0,"Don Carlos - Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,9000,14000,22000,26000,11,12024,1,0,0,0,0,5,0,0,0,0,0,0,0,"Don Carlos - In Combat - Cast 'Net' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,4,9000,14000,22000,26000,11,50762,1,0,0,0,0,5,0,0,0,0,0,0,0,"Don Carlos - In Combat - Cast 'Net' (Heroic Dungeon)");

-- Snowflake SAI
SET @ENTRY := 28153;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,50721,64,0,0,0,0,2,0,0,0,0,0,0,0,"Snowflake - Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4800,11,59280,64,0,0,0,0,2,0,0,0,0,0,0,0,"Snowflake - Combat CMC - Cast 'Frostbolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,7,5000,9000,0,0,11,44604,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowflake - In Combat - Cast 'Enchantment of Spell Haste' (No Repeat) (Dungeon)");

-- Dark Necromancer SAI
SET @ENTRY := 28200;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,5000,7000,11,15537,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,5000,7000,11,61558,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,21000,25000,11,20812,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - Combat - Cast 'Cripple' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,7000,11000,21000,25000,11,52498,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Necromancer - Combat - Cast 'Cripple' (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,14000,18000,15000,21000,11,58772,1,0,0,0,0,6,0,0,0,0,0,0,0,"Dark Necromancer - Combat - Cast 'Drain Mana' (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,4,14000,18000,15000,21000,11,58770,1,0,0,0,0,6,0,0,0,0,0,0,0,"Dark Necromancer - Combat - Cast 'Drain Mana' (Heroic Dungeon)");

-- Drakkari Water Binder SAI
SET @ENTRY := 28303;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Water Binder - Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,8000,16000,25000,30000,11,54399,1,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Water Binder - Combat - Cast 'Water Bubble'");

-- Ymirjar Necromancer SAI
SET @ENTRY := 28368;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,5000,7000,11,51432,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,5000,7000,11,59254,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer - Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,14000,18000,22000,11,49205,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Necromancer - Combat - Cast 'Shadow Bolt Volley' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,9000,14000,18000,22000,11,59255,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Necromancer - Combat - Cast 'Shadow Bolt Volley' (Heroic Dungeon)");

-- Har'koan Subduer SAI
SET @ENTRY := 28403;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,20000,40000,60000,80,2840300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Har'koan Subduer - Out of Combat - Run Script"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2800,3500,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,"Har'koan Subduer - Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Har'koan Subduer - 0-15% Health - Flee For Assist (No Repeat)");

-- Dragonflayer Spiritualist SAI
SET @ENTRY := 28410;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,2400,3800,11,51587,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Combat CMC - Cast 'Lightning Bolt' (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,6,1500,4000,8000,10000,11,51588,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Combat - Cast 'Flame Shock' (Dungeon)"),
(@ENTRY,0,2,0,14,0,100,6,7000,100,7000,7000,11,51586,1,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonflayer Spiritualist - Friendly At 7000 Health - Cast 'Healing Wave' (Dungeon)");

-- Hath'ar Broodmaster SAI
SET @ENTRY := 28412;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hath'ar Broodmaster - Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,25000,11,54453,1,0,0,0,0,2,0,0,0,0,0,0,0,"Hath'ar Broodmaster - Combat - Cast 'Web Wrap'");

-- Hemet Nesingwary SAI
SET @ENTRY := 28451;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,51742,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hemet Nesingwary - Combat CMC - Cast 'Arcane Shot'");

-- Storming Vortex SAI
SET @ENTRY := 28547;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,53044,64,0,0,0,0,2,0,0,0,0,0,0,0,"Storming Vortex - Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4800,11,59169,64,0,0,0,0,2,0,0,0,0,0,0,0,"Storming Vortex - Combat CMC - Cast 'Lightning Bolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,6,0,5,9000,18000,11,60236,0,0,0,0,0,6,0,0,0,0,0,0,0,"Storming Vortex - Within 0-5 Range - Cast 'Cyclone' (Dungeon)");

-- Hardened Steel Skycaller SAI
SET @ENTRY := 28580;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,5000,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,5000,11,61515,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,15000,20000,11,52754,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat - Cast 'Impact Shot' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,7000,12000,12000,18000,11,52775,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat - Cast 'Impact Multi-Shot' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,4,9000,12000,15000,20000,11,59148,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat - Cast 'Impact Shot' (Heroic Dungeon)"),
(@ENTRY,0,5,0,0,0,100,4,7000,12000,12000,18000,11,59147,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Skycaller - Combat - Cast 'Impact Multi-Shot' (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,0,100,6,0,5,6000,9000,11,61507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Skycaller - 0-5 Range - Cast 'Disengage' (Dungeon)");

-- Titanium Vanguard SAI
SET @ENTRY := 28838;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,0,0,11,53059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - On Aggro - Cast 'Poison Tipped Spear' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,5,30,14000,21000,11,53059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - Within 5-30 Range - Cast 'Poison Tipped Spear' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,5,0,0,0,0,11,59178,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - On Aggro - Cast 'Poison Tipped Spear' (No Repeat) (Heroic Dungeon)"),
(@ENTRY,0,3,0,9,0,100,4,5,30,14000,21000,11,59178,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - Within 5-30 Range - Cast 'Poison Tipped Spear' (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,7,4000,6000,0,0,11,58619,0,0,0,0,0,2,0,0,0,0,0,0,0,"Titanium Vanguard - In Combat - Cast 'Charge' (No Repeat) (Dungeon)"),
(@ENTRY,0,5,0,0,0,100,6,12000,15000,12000,15000,11,58619,0,0,0,0,0,6,0,0,0,0,0,0,0,"Titanium Vanguard - In Combat - Cast 'Charge' (Dungeon)");
