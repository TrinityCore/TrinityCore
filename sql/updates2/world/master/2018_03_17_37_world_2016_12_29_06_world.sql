-- Ethereal Sorcerer SAI
SET @ENTRY := 18313;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat CMC - Cast 'Arcane Missiles' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,6,5100,10800,10800,15700,11,25603,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat - Cast 'Slow' (Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,14000,22700,22300,22300,11,32349,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat - Cast 'Summon Arcane Fiend' (Dungeon)"),
(@ENTRY,0,3,0,0,0,100,6,14000,22700,22300,22300,11,32353,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat - Cast 'Summon Arcane Fiend' (Dungeon)"),
(@ENTRY,0,4,0,0,0,100,4,0,0,2400,3800,11,22273,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat CMC - Cast 'Arcane Missiles' (Heroic Dungeon)");

-- Cobalt Serpent SAI
SET @ENTRY := 19428;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,17503,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,4000,5000,8000,11000,11,38193,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat - Cast 'Lightning Breath' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,4000,5000,8000,11000,11,38133,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat - Cast 'Lightning Breath' (Heroic Dungeon)"),
(@ENTRY,0,3,0,0,0,100,6,6000,7000,7000,13000,11,38110,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat - Cast 'Wing Buffet' (Dungeon)"),
(@ENTRY,0,4,0,0,0,100,4,0,0,3400,4800,11,38238,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Serpent - In Combat CMC - Cast 'Frostbolt' (Heroic Dungeon)");

-- Master Daellis Dawnstrike SAI
SET @ENTRY := 19705;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2300,3900,2300,3900,11,50092,64,0,0,0,0,2,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,12000,15000,11000,14000,11,35963,1,0,0,0,0,2,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - In Combat - Cast 'Improved Wing Clip'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Daellis Dawnstrike - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Deathforge Summoner SAI
SET @ENTRY := 20872;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Summoner - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,17000,24000,11,37628,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deathforge Summoner - In Combat - Cast 'Fel Immolate'");

-- Gordunni Soulreaper SAI
SET @ENTRY := 23022;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Soulreaper - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,18000,25000,11,20464,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Soulreaper - In Combat - Cast 'Summon Skeleton'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,20743,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Soulreaper - Between 0-30% Health - Cast 'Drain Life' (No Repeat)");

-- Dragonflayer Strategist SAI
SET @ENTRY := 23956;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,5000,11,42772,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Strategist - In Combat CMC - Cast 'Hurl Dagger' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,4500,5000,11000,16000,11,54962,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Strategist - In Combat - Cast 'Ticking Bomb' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,4500,5000,11000,16000,11,60227,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Strategist - In Combat - Cast 'Ticking Time Bomb' (Heroic Dungeon)"),
(@ENTRY,0,3,0,0,0,100,6,7500,9000,13000,15000,11,42972,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Strategist - In Combat - Cast 'Blind' (Dungeon)"),
(@ENTRY,0,4,0,0,0,100,4,0,0,2300,5000,11,59685,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Strategist - In Combat CMC - Cast 'Hurl Dagger' (Heroic Dungeon)");

-- Solstice Hunter SAI
SET @ENTRY := 26389;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Solstice Hunter - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,9000,13000,11,14443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Solstice Hunter - Within 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,0,0,100,0,7000,9000,19000,24000,11,52604,1,0,0,0,0,5,0,0,0,0,0,0,0,"Solstice Hunter - In Combat - Cast 'Scorpid Sting'"),
(@ENTRY,0,3,0,0,0,100,0,11000,15000,18000,24000,11,52606,1,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - In Combat - Cast 'Immolation Trap'"),
(@ENTRY,0,4,0,2,0,100,1,0,50,0,0,11,49561,0,0,0,0,0,1,0,0,0,0,0,0,0,"Solstice Hunter - Between 0-50% Health - Cast 'Worgen Transform' (No Repeat)"),
(@ENTRY,0,5,0,0,0,100,0,12000,15000,18000,21000,11,31975,1,0,0,0,0,5,0,0,0,0,0,0,0,"Solstice Hunter - In Combat - Cast 'Serpent Sting'");

-- Stars' Rest Sentinel SAI
SET @ENTRY := 26448;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,2300,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stars' Rest Sentinel - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,8,100,9000,13000,11,47059,1,0,0,0,0,2,0,0,0,0,0,0,0,"Stars' Rest Sentinel - Within 8-100 Range - Cast 'Frost Arrow'");

-- Wastes Taskmaster SAI
SET @ENTRY := 26493;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,16583,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wastes Taskmaster - In Combat CMC - Cast 'Shadow Shock'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,12000,15000,11,32712,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wastes Taskmaster - Within 0-8 Range - Cast 'Shadow Nova'");

-- Silverbrook Trapper SAI
SET @ENTRY := 26679;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Silverbrook Trapper - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,9000,15000,11,13608,1,0,0,0,0,2,0,0,0,0,0,0,0,"Silverbrook Trapper - Within 0-20 Range - Cast 'Hooked Net'");

-- Moa'ki Warrior SAI
SET @ENTRY := 27178;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,38556,64,0,0,0,0,2,0,0,0,0,0,0,0,"Moa'ki Warrior - In Combat CMC - Cast 'Throw'");

-- Onslaught Raven Priest SAI
SET @ENTRY := 27202;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,0,0,3400,4800,11,50740,64,0,0,0,0,2,0,0,0,0,0,0,0,"Onslaught Raven Priest - In Combat CMC - Cast 'Raven Flock' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,0,0,30,14000,18000,11,50750,1,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - Between 0-30% Health - Cast 'Raven Heal'"),
(@ENTRY,0,2,3,8,0,100,1,48679,0,0,0,85,48655,2,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit 'Banshee's Magic Mirror' - Invoker Cast 'The Perfect Dissemblance: Summon Player's Footman & Credit Credit' (No Repeat)"),
(@ENTRY,0,3,7,61,0,100,0,48679,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit 'Banshee's Magic Mirror' - Say Line 2 (No Repeat)"),
(@ENTRY,0,4,0,8,0,100,255,48268,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit 'Container of Rats' - Despawn Instant (No Repeat) (Dungeon & Raid) (Debug)"),
(@ENTRY,0,5,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,6,0,1,0,50,0,0,45000,60000,90000,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Onslaught Raven Priest - Out of Combat - Say Line 1"),
(@ENTRY,0,7,8,61,0,100,0,48679,0,0,0,11,48654,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit 'Banshee's Magic Mirror' - Cast 'The Perfect Dissemblance: Summon Priest's Footman' (No Repeat)"),
(@ENTRY,0,8,9,61,0,100,0,48679,0,0,0,85,48763,0,0,0,0,0,7,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit 'Banshee's Magic Mirror' - Invoker Cast 'Scarlet Raven Priest Image' (No Repeat)"),
(@ENTRY,0,9,10,61,0,100,0,48679,0,0,0,85,48761,0,0,0,0,0,7,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit 'Banshee's Magic Mirror' - Invoker Cast 'Scarlet Raven Priest Image' (No Repeat)"),
(@ENTRY,0,10,0,61,0,100,255,48679,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onslaught Raven Priest - On Spellhit 'Banshee's Magic Mirror' - Set Faction 14 (No Repeat)");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (27202);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,9,27202,0,0,20,1,0,0,0,0,0,0,'','Onslaught Raven Priest SAI event 17 require a male character'),
(22,10,27202,0,0,20,1,1,0,0,0,0,0,'','Onslaught Raven Priest SAI event 17 require a female character');

-- Steamwheedle Bruiser SAI
SET @ENTRY := 16096;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2200,3800,2200,3800,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Steamwheedle Bruiser - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steamwheedle Bruiser - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,500,1800,11000,18000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Steamwheedle Bruiser - In Combat - Cast 'Net'");

-- Mag'har Hunter SAI
SET @ENTRY := 16912;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2200,3800,2200,3800,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mag'har Hunter - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,500,1800,11000,18000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mag'har Hunter - In Combat - Cast 'Net'"),
(@ENTRY,0,3,0,1,0,100,1,1000,1000,0,0,11,32730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mag'har Hunter - Out of Combat - Cast 'Summon Tamed Ravager' (No Repeat)");
