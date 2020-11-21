-- Tempest-Forge Patroller SAI (ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 19166;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,6100,10400,6800,16900,11,35012,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest-Forge Patroller - In Combat - Cast 'Charged Arcane Missile' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,6100,10400,6800,16900,11,38941,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest-Forge Patroller - In Combat - Cast 'Charged Arcane Missile' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,0,9700,16400,12500,20500,11,35011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest-Forge Patroller - In Combat - Cast 'Knockdown'"),
(@ID,0,3,0,2,0,100,1,0,50,0,0,39,30,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tempest-Forge Patroller - Between 0-50% Health - Call for Help (No Repeat)");

-- Bloodwarder Slayer SAI (ACID 4.3.4 Official Data - Normal/Heroic + sniffs)
-- Pretty similar to Cabal Ritualist but equipment is changed on aggro
-- and an unique aura is linked to each equipment set
-- For some reason default aura is 35191 (Arcane Explosion Proc) and is removed each time
-- creature choses another phase. Equipment is too changed to different,
-- default equipment is not linked to any phase
SET @ID := 19167;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- I have no idea if we should not reset these events
-- Both options are not correct currently because auras are removed on evade
-- But if event can be repeated, probably we have to restore default equipment
(@ID,0,0,0,1,0,100,257,0,0,0,0,75,35191,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - Out of Combat - Add Aura 'Arcane Explosion Proc' (No Repeat) (No Reset)"),
(@ID,0,1,0,0,0,100,257,0,0,0,0,31,1,4,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - In Combat - Set Random Phase (1-4) (No Repeat) (No Reset)"),

-- Item 29407
(@ID,0,2,0,66,0,100,0,1,0,0,0,71,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Enter Phase 1 - Change Equipment"),
(@ID,0,3,0,66,0,100,0,1,0,0,0,28,35191,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Enter Phase 1 - Remove Aura 'Arcane Explosion Proc'"),
(@ID,0,4,0,66,0,100,0,1,0,0,0,75,35192,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Enter Phase 1 - Add Aura 'Melt Armor Proc'"),

-- Item 29408
(@ID,0,5,0,66,0,100,0,2,0,0,0,71,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Enter Phase 2 - Change Equipment"),
(@ID,0,6,0,66,0,100,0,2,0,0,0,28,35191,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Enter Phase 2 - Remove Aura 'Arcane Explosion Proc'"),
(@ID,0,7,0,66,0,100,0,2,0,0,0,75,35193,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Enter Phase 2 - Add Aura 'Seed of Corruption Proc'"),

-- Item 29409 (guessed https://youtu.be/NDGPQIpMJu4?t=174)
(@ID,0,8,0,66,0,100,0,4,0,0,0,71,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Enter Phase 3 - Change Equipment"),
(@ID,0,9,0,66,0,100,0,4,0,0,0,28,35191,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Enter Phase 3 - Remove Aura 'Arcane Explosion Proc'"),
(@ID,0,10,0,66,0,100,0,4,0,0,0,75,35188,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Enter Phase 3 - Add Aura 'Chilling Touch'"),

-- Item 29410
-- Nothing to add or remove here, we already have Arcane Explosion Proc
(@ID,0,11,0,66,0,100,0,8,0,0,0,71,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Enter Phase 4 - Change Equipment"),

-- Used in phase 1 and 2 only
(@ID,0,12,0,0,3,100,0,7200,10600,12100,22900,11,35189,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Slayer - In Combat - Cast 'Solar Strike' (Phase 1, 2)"),
-- Used in Phase 3 and 4 only
(@ID,0,13,0,0,12,100,0,7700,7700,10900,21700,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Slayer - In Combat - Cast 'Mortal Strike' (Phase 3, 4)"),
-- Any phase
(@ID,0,14,0,0,0,100,0,9800,22900,10900,26500,11,13736,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - In Combat - Cast 'Whirlwind'");

-- Sunseeker Astromage SAI (ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 19168;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,4800,16100,3000,5000,11,35265,32,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast 'Fire Shield' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,4800,16100,3000,5000,11,38933,32,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast 'Fire Shield' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,3100,7600,12100,21700,11,17195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast 'Scorch' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,3100,7600,12100,21700,11,36807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast 'Scorch' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,2,4800,26700,13200,27700,11,35267,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast 'Solarburn' (Normal Dungeon)"),
(@ID,0,5,0,0,0,100,4,4800,26700,13200,27700,11,38930,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast 'Solarburn' (Heroic Dungeon)");

-- Mechanar Crusher SAI (ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 19231;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,7800,13200,13300,21200,11,35055,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Crusher - In Combat - Cast 'The Claw'"),
(@ID,0,1,0,0,0,100,2,11100,19300,22900,28900,11,35056,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Crusher - In Combat - Cast 'Glob of Machine Fluid' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,11100,19300,22900,28900,11,38923,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Crusher - In Combat - Cast 'Glob of Machine Fluid' (Heroic Dungeon)");

-- Bloodwarder Centurion SAI (ACID 4.3.4 Official Data - Normal/Heroic + sniffs)
-- This time equipment and auras are just linked together
SET @ID := 19510;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- I have no idea if we should not reset this event
-- Both options are not correct currently because auras are removed on evade
-- But if event can be repeated, probably we have to restore default equipment
(@ID,0,0,0,0,0,100,257,0,0,0,0,31,1,4,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Centurion - In Combat - Set Random Phase (1-4) (No Repeat) (No Reset)"),
-- Item 29403
(@ID,0,1,0,66,0,100,0,1,0,0,0,71,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Enter Phase 1 - Change Equipment"),
(@ID,0,2,0,66,0,100,0,1,0,0,0,75,35186,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Enter Phase 1 - Add Aura 'Melt Armor Proc'"),
-- Item 29404
(@ID,0,3,0,66,0,100,0,2,0,0,0,71,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Enter Phase 2 - Change Equipment"),
(@ID,0,4,0,66,0,100,0,2,0,0,0,75,35187,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Enter Phase 2 - Add Aura 'Arcane Explosion Proc'"),
-- Item 29405
(@ID,0,5,0,66,0,100,0,4,0,0,0,71,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Enter Phase 3 - Change Equipment"),
(@ID,0,6,0,66,0,100,0,4,0,0,0,75,35188,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Enter Phase 3 - Add Aura 'Chilling Touch'"),
-- Item 29406
(@ID,0,7,0,66,0,100,0,8,0,0,0,71,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Enter Phase 4 - Change Equipment"),
(@ID,0,8,0,66,0,100,0,8,0,0,0,75,35184,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Enter Phase 4 - Add Aura 'Unstable Affliction Proc'"),
-- Only one spell, not linked to any phase
(@ID,0,9,0,0,0,100,0,6200,19300,12100,16900,11,35178,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Centurion - In Combat - Cast 'Shield Bash'");

-- Mechanar Driller SAI (ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 19712;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,4700,18100,7200,16900,11,35047,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Driller - In Combat - Cast 'Drill Armor'"),
(@ID,0,1,0,0,0,100,2,13300,37400,21700,33800,11,35056,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Driller - In Combat - Cast 'Glob of Machine Fluid' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,13300,37400,21700,33800,11,38923,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Driller - In Combat - Cast 'Glob of Machine Fluid' (Heroic Dungeon)");

-- Mechanar Wrecker SAI (ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 19713;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,15700,22500,17300,26500,11,35049,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Wrecker - In Combat - Cast 'Pound'"),
(@ID,0,1,0,0,0,100,2,15200,27700,21700,36800,11,35056,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Wrecker - In Combat - Cast 'Glob of Machine Fluid' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,15200,27700,21700,36800,11,38923,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Wrecker - In Combat - Cast 'Glob of Machine Fluid' (Heroic Dungeon)");

-- Mechanar Tinkerer SAI (ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 19716;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mechanar Tinkerer - On Respawn - Set Phase 1"),
(@ID,0,1,0,0,1,100,2,0,0,1200,1200,11,35057,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Tinkerer - In Combat CMC - Cast 'Netherbomb' (Normal Dungeon) (Phase 1)"),
(@ID,0,2,0,0,1,100,4,0,0,1200,1200,11,38925,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Tinkerer - In Combat CMC - Cast 'Netherbomb' (Heroic Dungeon) (Phase 1)"),
(@ID,0,3,4,2,0,100,1,0,50,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mechanar Tinkerer - Between 0-50% Health - Set Phase 2 (No Repeat)"),
(@ID,0,4,5,61,0,100,0,0,0,0,0,11,35062,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mechanar Tinkerer - On Link - Cast 'Maniacal Charge'"),
(@ID,0,5,0,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mechanar Tinkerer - On Link - Set Reactstate Passive"),
(@ID,0,6,0,0,2,100,1,2000,2000,0,0,11,35058,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mechanar Tinkerer - In Combat - Cast 'Nether Explosion' (No Repeat) (Phase 2)"),
(@ID,0,7,0,0,2,100,1,3000,3000,0,0,11,29878,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mechanar Tinkerer - In Combat - Cast 'Instakill Self' (No Repeat) (Phase 2)");

-- Tempest-Forge Destroyer SAI (ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 19735;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,9700,10800,10900,22900,11,35783,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest-Forge Destroyer - In Combat - Cast 'Knockdown'"),
(@ID,0,1,0,0,0,100,0,8400,16900,9600,20500,11,36582,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tempest-Forge Destroyer - In Combat - Cast 'Charged Fist'");

-- Sunseeker Netherbinder SAI (ACID 4.3.4 Official Data - Normal/Heroic)
-- TO-DO: Timers for the 'Dispel Magic' are rough
SET @ID := 20059;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,12100,19300,10800,25300,11,35261,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Netherbinder - In Combat - Cast 'Arcane Nova' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,12100,19300,10800,25300,11,38936,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Netherbinder - In Combat - Cast 'Arcane Nova' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,6100,15600,12100,22500,11,35243,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Netherbinder - In Combat - Cast 'Starfire' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,6100,15600,12100,22500,11,38935,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Netherbinder - In Combat - Cast 'Starfire' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,0,6000,12000,12000,17000,11,17201,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Netherbinder - In Combat - Cast 'Dispel Magic'"),
(@ID,0,5,6,0,0,100,0,14100,18900,63200,68100,11,35251,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Netherbinder - In Combat - Cast 'Summon Arcane Golem'"),
(@ID,0,6,0,61,0,100,0,0,0,0,0,11,35260,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Netherbinder - On Link - Cast 'Summon Arcane Golem'");

-- Arcane Servant SAI (ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 20478;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,11,35259,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Servant - On Just Summoned - Cast 'Spotlight'"),
(@ID,0,1,0,0,0,100,0,3600,10800,16900,26500,11,35255,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Servant - In Combat - Cast 'Arcane Volley'"),
(@ID,0,2,0,6,0,100,0,0,0,0,0,11,22271,2,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Servant - On Death - Cast 'Arcane Explosion'");

-- Nether Charge SAI (ACID 4.3.4 Official Data - Normal/Heroic + sniffs + old script)
SET @ID := 20405;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,11,35150,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Just Summoned - Cast 'Nether Charge Passive'"),
(@ID,0,1,2,61,0,100,0,0,0,0,0,11,37670,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Link - Cast 'Nether Charge Timer'"),
(@ID,0,2,3,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Link - Set Reactstate Passive"),
(@ID,0,3,0,61,0,100,0,0,0,0,0,89,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Link - Start Random Movement"),
(@ID,0,4,5,60,0,100,1,10500,10500,0,0,11,35148,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Update - Cast 'Nether Charge Countdown' (No Repeat)"),
(@ID,0,5,0,61,0,100,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Link - Stop Random Movement");

-- Sunseeker Engineer SAI (ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 20988;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,1300,9600,21700,30200,11,36341,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Engineer - In Combat - Cast 'Super Shrink Ray'"),
(@ID,0,1,0,0,0,100,2,5100,16400,12100,22900,11,36345,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Engineer - In Combat - Cast 'Death Ray' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,5100,16400,12100,22900,11,39196,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Engineer - In Combat - Cast 'Death Ray' (Heroic Dungeon)"),
(@ID,0,3,0,16,0,100,0,36346,15,18100,24100,11,36346,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sunseeker Engineer - On Friendly Unit Missing Buff 'Growth Ray' - Cast 'Growth Ray'");

-- Bloodwarder Physician SAI (ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 20990;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,8400,19300,7200,19300,0,11,36340,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Physician - In Combat - Cast 'Holy Shock' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,8400,19300,7200,19300,0,11,38921,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Physician - In Combat - Cast 'Holy Shock' (Heroic Dungeon)"),
(@ID,0,2,0,74,0,100,2,0,60,10000,16000,15,11,36348,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodwarder Physician - On Friendly Between 0-60% Health - Cast 'Bandage' (Normal Dungeon)"),
(@ID,0,3,0,74,0,100,4,0,60,10000,16000,15,11,38919,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodwarder Physician - On Friendly Between 0-60% Health - Cast 'Bandage' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,0,9000,14000,12000,16000,0,11,36333,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bloodwarder Physician - In Combat - Cast 'Anesthetic'");
