-- Blackrock Sorcerer SAI
SET @ENTRY := 7026;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4500,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Sorcerer - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,8500,19300,14700,19400,11,20827,1,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Sorcerer - In Combat - Cast 'Flamestrike'");

-- Blackrock Warlock SAI
SET @ENTRY := 7028;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3300,5200,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Warlock - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,2600,7300,29100,31300,11,13338,33,0,0,0,0,5,0,0,0,0,0,0,0,"Blackrock Warlock - In Combat - Cast 'Curse of Tongues'"),
(@ENTRY,0,2,0,0,0,100,0,6200,8700,5100,11000,11,20826,33,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Warlock - In Combat - Cast 'Immolate'");

-- Thaurissan Firewalker SAI
SET @ENTRY := 7037;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,4700,11,10452,64,0,0,0,0,2,0,0,0,0,0,0,0,"Thaurissan Firewalker - In Combat CMC - Cast 'Flame Buffet'"),
(@ENTRY,0,1,0,0,0,100,0,9100,12500,12300,15700,11,10733,1,0,0,0,0,2,0,0,0,0,0,0,0,"Thaurissan Firewalker - In Combat - Cast 'Flame Spray'");

-- Thaurissan Agent SAI
SET @ENTRY := 7038;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2200,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Thaurissan Agent - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,36300,50000,11,6685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thaurissan Agent - Within 5-30 Range - Cast 'Piercing Shot'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,13300,24100,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thaurissan Agent - Within 0-5 Range - Cast 'Gouge'");

-- Black Wyrmkin SAI
SET @ENTRY := 7041;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Black Wyrmkin - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,30400,45900,11,11969,1,0,0,0,0,2,0,0,0,0,0,0,0,"Black Wyrmkin - Between 0-50% Health - Cast 'Fire Nova'");

-- Flamescale Wyrmkin SAI
SET @ENTRY := 7043;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,4700,11,9574,64,0,0,0,0,2,0,0,0,0,0,0,0,"Flamescale Wyrmkin - In Combat CMC - Cast 'Flame Buffet'"),
(@ENTRY,0,1,0,0,0,100,0,1000,5200,10800,15100,11,13341,1,0,0,0,0,2,0,0,0,0,0,0,0,"Flamescale Wyrmkin - In Combat - Cast 'Fire Blast'");

-- Black Broodling SAI
SET @ENTRY := 7047;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2800,3600,11,13375,64,0,0,0,0,2,0,0,0,0,0,0,0,"Black Broodling - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,8,0,100,1,16007,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - On Spellhit 'Draco-Incarcinatrix 900' - Set Phase 1"),
(@ENTRY,0,2,0,6,1,100,1,0,0,0,0,11,16027,7,0,0,0,0,1,0,0,0,0,0,0,0,"Black Broodling - On Just Died - Cast 'Create Broodling Essence' (Phase 1)");

-- Scalding Broodling SAI
SET @ENTRY := 7048;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2800,3600,11,13375,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scalding Broodling - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,8,0,100,1,16007,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - On Spellhit 'Draco-Incarcinatrix 900' - Set Phase 1"),
(@ENTRY,0,2,0,6,1,100,1,0,0,0,0,11,16027,7,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Broodling - On Just Died - Cast 'Create Broodling Essence' (Phase 1)");

-- Flamescale Broodling SAI
SET @ENTRY := 7049;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2800,3600,11,13375,64,0,0,0,0,2,0,0,0,0,0,0,0,"Flamescale Broodling - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,6700,12700,8200,13300,11,13342,1,0,0,0,0,2,0,0,0,0,0,0,0,"Flamescale Broodling - In Combat - Cast 'Fire Blast'"),
(@ENTRY,0,2,0,8,0,100,1,16007,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - On Spellhit 'Draco-Incarcinatrix 900' - Set Phase 1"),
(@ENTRY,0,3,0,6,1,100,1,0,0,0,0,11,16027,7,0,0,0,0,1,0,0,0,0,0,0,0,"Flamescale Broodling - On Just Died - Cast 'Create Broodling Essence' (Phase 1)");

-- Condemned Cleric SAI
SET @ENTRY := 7070;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,25054,64,0,0,0,0,2,0,0,0,0,0,0,0,"Condemned Cleric - In Combat CMC - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,74,0,100,0,0,40,18000,21000,11,15586,1,0,0,0,0,9,0,0,0,0,0,0,0,"Condemned Cleric - On Friendly Between 0-40% Health - Cast 'Heal'");

-- Writhing Mage SAI
SET @ENTRY := 7075;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,40,3400,4800,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,"Writhing Mage - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Writhing Mage - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Jaedenar Warlock SAI
SET @ENTRY := 7120;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Out of Combat - Cast 'Summon Imp' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Warlock - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8699,1,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 0-30% Health - Cast 'Unholy Frenzy' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Warlock - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Deadwood Pathfinder SAI
SET @ENTRY := 7155;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2200,3800,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Pathfinder - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,6000,12000,11,6685,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Pathfinder - Within 5-30 Range - Cast 'Piercing Shot'"),
(@ENTRY,0,2,0,0,0,100,0,5000,9000,125000,130000,11,13583,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Pathfinder - In Combat - Cast 'Curse of the Deadwood'");

-- Sandfury Shadowhunter SAI
SET @ENTRY := 7246;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Shadowhunter - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,12000,18000,25000,11,11641,1,0,0,0,0,6,0,0,0,0,0,0,0,"Sandfury Shadowhunter - In Combat - Cast 'Hex' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Shadowhunter - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Shadowforge Sharpshooter SAI
SET @ENTRY := 7290;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,30000,36000,11,6685,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - In Combat - Cast 'Piercing Shot' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Sharpshooter - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Withered Spearhide SAI
SET @ENTRY := 7332;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Spearhide - In Combat CMC - Cast 'Shoot' (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,2,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 0-30% Health - Cast 'Enrage' (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Death's Head Necromancer SAI
SET @ENTRY := 7337;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,12420,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Out of Combat - Cast 'Summon Skeletal Servant' (Normal Dungeon)"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,11,11445,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - On Aggro - Cast 'Bone Armor' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Necromancer - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,8000,15000,18000,25000,11,11443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Necromancer - In Combat - Cast 'Cripple' (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Necromancer - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Skeletal Shadowcaster SAI
SET @ENTRY := 7340;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Shadowcaster - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,6000,10000,7000,14000,11,12248,33,0,0,0,0,5,0,0,0,0,0,0,0,"Skeletal Shadowcaster - In Combat - Cast 'Amplify Damage' (Normal Dungeon)"),
(@ENTRY,0,2,0,7,0,100,3,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Shadowcaster - On Evade - Despawn Instant (No Repeat) (Normal Dungeon)");

-- Skeletal Frostweaver SAI
SET @ENTRY := 7341;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Frostweaver - In Combat CMC - Cast 'Frostbolt'");

-- Skeletal Summoner SAI
SET @ENTRY := 7342;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Summoner - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,0,100,3,6000,10000,0,0,11,11980,1,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Summoner - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,2,0,0,0,100,2,15000,20000,15000,20000,11,12258,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Summoner - In Combat - Cast 'Summon Shadowcaster'");

-- Ragglesnout SAI
SET @ENTRY := 7354;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ragglesnout - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,3000,5000,20000,25000,11,11639,1,0,0,0,0,5,0,0,0,0,0,0,0,"Ragglesnout - In Combat - Cast 'Shadow Word: Pain' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,13000,15000,20000,11,7645,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ragglesnout - In Combat - Cast 'Dominate Mind' (Normal Dungeon)"),
(@ENTRY,0,3,0,74,0,100,2,0,40,12000,16000,11,12039,0,0,0,0,0,9,0,0,0,0,0,0,0,"Ragglesnout - On Friendly Between 0-40% Health - Cast 'Heal' (Normal Dungeon)");

-- Deadwind Warlock SAI
SET @ENTRY := 7372;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Warlock - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,7000,15000,11,11980,33,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Warlock - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,2,0,0,0,100,0,9000,11000,11000,18000,11,20787,33,0,0,0,0,5,0,0,0,0,0,0,0,"Deadwind Warlock - In Combat - Cast 'Immolate'");

-- Deadwind Ogre Mage SAI
SET @ENTRY := 7379;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,600000,600000,11,12550,33,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwind Ogre Mage - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2800,4200,11,20824,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Ogre Mage - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,7000,9000,16000,20000,11,21049,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Ogre Mage - In Combat - Cast 'Bloodlust'"),
(@ENTRY,0,3,0,2,0,100,0,0,30,30000,36000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwind Ogre Mage - Between 0-30% Health - Cast 'Bloodlust'");

-- Oro Eyegouge SAI
SET @ENTRY := 7606;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,12741,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - On Aggro - Cast 'Curse of Weakness' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,80,2,5000,7000,23000,27000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - In Combat - Cast 'Immolate' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,80,2,8000,10000,15000,18250,11,11990,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - In Combat - Cast 'Rain of Fire' (Normal Dungeon)");

-- Archmage Allistarj SAI
SET @ENTRY := 7666;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,33,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Allistarj - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Allistarj - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,11000,14000,11,12737,1,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Allistarj - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,3,0,0,0,100,0,13000,16000,13000,16000,11,14145,1,0,0,0,0,5,0,0,0,0,0,0,0,"Archmage Allistarj - In Combat - Cast 'Fire Blast'"),
(@ENTRY,0,4,0,0,0,100,0,5000,7000,16000,20000,11,12738,1,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Allistarj - In Combat - Cast 'Amplify Damage'"),
(@ENTRY,0,5,0,0,0,100,0,7000,12000,20000,24000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Archmage Allistarj - In Combat - Cast 'Polymorph'");

-- Lady Sevine SAI
SET @ENTRY := 7667;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,33,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sevine - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,24000,27000,11,12742,1,0,0,0,0,5,0,0,0,0,0,0,0,"Lady Sevine - In Combat - Cast 'Immolate'"),
(@ENTRY,0,3,0,0,0,100,0,2000,5000,30000,45000,11,12741,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sevine - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,4,0,0,0,100,0,7000,9000,15000,25000,11,12740,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - In Combat - Cast 'Summon Infernal Servant'");

-- Gnomeregan Evacuee SAI
SET @ENTRY := 7843;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,7165,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gnomeregan Evacuee - Out of Combat - Cast 'Battle Stance'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gnomeregan Evacuee - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,17000,23000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gnomeregan Evacuee - Within 0-5 Range - Cast 'Hamstring'"),
(@ENTRY,0,3,0,0,0,100,0,7000,9000,13000,16000,11,25712,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gnomeregan Evacuee - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,4,0,2,0,100,0,0,30,30000,45000,11,2055,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gnomeregan Evacuee - Between 0-30% Health - Cast 'Heal'"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnomeregan Evacuee - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Southsea Freebooter SAI
SET @ENTRY := 7856;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2200,3800,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Southsea Freebooter - In Combat CMC - Cast 'Shoot' (Phase 1)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Southsea Freebooter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Death's Head Cultist SAI
SET @ENTRY := 7872;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Cultist - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,9000,12500,8000,13000,11,11433,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death's Head Cultist - In Combat - Cast 'Death & Decay'");

-- Cyclok the Mad SAI
SET @ENTRY := 8202;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20829,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cyclok the Mad - In Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,7000,11000,15000,19000,11,11975,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - In Combat - Cast 'Arcane Explosion'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclok the Mad - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");

-- Mojo the Twisted SAI
SET @ENTRY := 8296;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mojo the Twisted - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,9000,14000,11,17228,1,0,0,0,0,5,0,0,0,0,0,0,0,"Mojo the Twisted - Within 0-30 Range - Cast 'Shadow Bolt Volley'");

-- Akubar the Seer SAI
SET @ENTRY := 8298;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20824,64,0,0,0,0,2,0,0,0,0,0,0,0,"Akubar the Seer - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,13800,13800,11,20831,1,0,0,0,0,5,0,0,0,0,0,0,0,"Akubar the Seer - Within 0-30 Range - Cast 'Chain Lightning'"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,25700,31300,11,11436,1,0,0,0,0,5,0,0,0,0,0,0,0,"Akubar the Seer - In Combat - Cast 'Slow'");

-- Gibblewilt SAI
SET @ENTRY := 8503;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,80,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gibblewilt - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,0,1300,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gibblewilt - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gibblewilt - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Blighted Surge SAI
SET @ENTRY := 8519;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2800,3800,11,16554,64,0,0,0,0,2,0,0,0,0,0,0,0,"Blighted Surge - In Combat CMC - Cast 'Toxic Bolt'"),
(@ENTRY,0,1,0,8,0,100,0,21332,0,0,0,36,13279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blighted Surge - On Spellhit 'Aspect of Neptulon' - Update Template To 'Discordant Surge'");

-- Cursed Mage SAI
SET @ENTRY := 8524;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20829,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Mage - In Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,16567,7,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Mage - On Just Died - Cast 'Tainted Mind'");

-- Dark Caster SAI
SET @ENTRY := 8526;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Caster - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,11000,14000,22000,25000,11,20825,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Caster - In Combat - Cast 'Shadow Bolt'");

-- Shadowmage SAI
SET @ENTRY := 8550;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,16592,33,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - Out of Combat - Cast 'Shadowform'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmage - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dark Summoner SAI
SET @ENTRY := 8551;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20829,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Summoner - In Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,15000,20000,11,16590,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - In Combat - Cast 'Summon Zombie'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - Between 0-15% Health - Flee For Assist");

-- Mossflayer Shadowhunter SAI
SET @ENTRY := 8561;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,6000,9000,11,17171,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - Within 5-30 Range - Cast 'Shadow Shot'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - Between 0-15% Health - Flee For Assist");

-- Ranger SAI
SET @ENTRY := 8564;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,7000,9000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger - Within 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,9000,11000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger - Within 5-30 Range - Cast 'Concussive Shot'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - Between 0-15% Health - Flee For Assist");

-- Dark Iron Lookout SAI
SET @ENTRY := 8566;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,1200,2400,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Lookout - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Lookout - Between 0-15% Health - Flee For Assist");

-- Hukku's Imp SAI
SET @ENTRY := 8658;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,180000,180000,11,11770,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hukku's Imp - In Combat - Cast 'Fire Shield'"),
(@ENTRY,0,1,0,0,0,100,2,0,0,3100,4900,11,11762,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hukku's Imp - In Combat CMC - Cast 'Firebolt' (Normal Dungeon)");

-- Sandfury Acolyte SAI
SET @ENTRY := 8876;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Acolyte - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8000,10000,25000,31000,11,11639,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Acolyte - In Combat - Cast 'Shadow Word: Pain' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4000,6000,120000,135000,11,11980,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Acolyte - In Combat - Cast 'Curse of Weakness' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,5000,6000,15000,22000,11,11981,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sandfury Acolyte - In Combat - Cast 'Mana Burn' (Normal Dungeon)");

-- Anvilrage Reservist SAI
SET @ENTRY := 8901;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,9128,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - On Aggro - Cast 'Battle Shout' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2200,3800,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Reservist - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,4000,6000,12000,15000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Reservist - In Combat - Cast 'Hamstring' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,8000,11000,6000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anvilrage Reservist - In Combat - Cast 'Strike' (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anvilrage Reservist - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Thauris Balgarr SAI
SET @ENTRY := 8978;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,5,9,0,100,0,0,0,21700,35200,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Thauris Balgarr - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,7000,11000,21700,35200,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Thauris Balgarr - In Combat - Cast 'Net'"),
(@ENTRY,0,2,0,0,0,100,0,1000,3000,19200,32700,11,11802,1,0,0,0,0,2,0,0,0,0,0,0,0,"Thauris Balgarr - In Combat - Cast 'Dark Iron Land Mine'");
