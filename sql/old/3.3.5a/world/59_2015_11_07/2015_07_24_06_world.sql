
-- Jademir Tree Warder SAI
SET @ENTRY := 5319;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,20656,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jademir Tree Warder - On Aggro - Cast 'Faerie Fire'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,20000,25000,11,20654,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jademir Tree Warder - In Combat - Cast 'Entangling Roots'");

-- Jademir Oracle SAI
SET @ENTRY := 5317;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,20664,64,0,0,0,0,1,0,0,0,0,0,0,0,"Jademir Oracle - On Aggro - Cast 'Rejuvenation'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,20665,64,0,0,0,0,1,0,0,0,0,0,0,0,"Jademir Oracle - Between 0-30% Health - Cast 'Regrowth' (No Repeat)");

-- Jademir Boughguard SAI
SET @ENTRY := 5320;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,6000,10000,11,20666,2,0,0,0,0,2,0,0,0,0,0,0,0,"Jademir Boughguard - In Combat - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,3000,8000,8000,12000,75,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jademir Boughguard - In Combat - Add Aura 'Mortal Strike'");

-- Hatecrest Wave Rider SAI
SET @ENTRY := 5332;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,8000,15000,11,10987,2,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Wave Rider - In Combat - Cast 'Geyser'");

-- Hatecrest Warrior SAI
SET @ENTRY := 5331;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,7164,2,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecrest Warrior - On Aggro - Cast 'Defensive Stance'"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,5000,10000,11,6713,2,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Warrior - In Combat - Cast 'Disarm'");

-- Hatecrest Sorceress SAI
SET @ENTRY := 5336;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,3000,4000,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Sorceress - In Combat - Cast 'Frostbolt'");

-- Hatecrest Siren SAI
SET @ENTRY := 5337;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,3000,4000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Siren - In Combat - Cast 'Lightning Bolt'");

-- Hatecrest Serpent Guard SAI
SET @ENTRY := 5333;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,8058,2,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Serpent Guard - On Aggro - Cast 'Frost Shock'");

-- Hatecrest Screamer SAI
SET @ENTRY := 5335;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,6078,2,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecrest Screamer - Between 0-30% Health - Cast 'Renew' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,4000,8000,11,8281,2,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Screamer - In Combat - Cast 'Sonic Burst'");

-- Hatecrest Myrmidon SAI
SET @ENTRY := 5334;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,6533,2,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Myrmidon - On Aggro - Cast 'Net'");

-- Groddoc Thunderer SAI
SET @ENTRY := 5262;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,10000,12000,11,8078,2,0,0,0,0,2,0,0,0,0,0,0,0,"Groddoc Thunderer - In Combat - Cast 'Thunderclap'");

-- Grimtotem Shaman SAI
SET @ENTRY := 7727;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,2000,4000,11,930,64,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Shaman - In Combat - Cast 'Chain Lightning'"),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,8499,2,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Shaman - Between 0-50% Health - Cast 'Fire Nova' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,0,0,30,0,0,11,8005,64,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Shaman - Between 0-30% Health - Cast 'Healing Wave'");

-- Grimtotem Raider SAI
SET @ENTRY := 7725;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,7366,2,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Raider - On Aggro - Cast 'Berserker Stance'"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,5000,8000,11,6533,2,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Raider - In Combat - Cast 'Net'");

-- Grimtotem Naturalist SAI
SET @ENTRY := 7726;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - On Aggro - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Naturalist - On Aggro - Cast 'Wrath' (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4700,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Naturalist - Within 0-40 Range - Cast 'Wrath' (Phase 1)"),
(@ENTRY,0,4,0,9,1,100,0,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - Within 40-100 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,9,1,100,0,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - Within 10-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - Within 0-40 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,3,1,100,0,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - Between 0-15% Mana - Set Event Phase 2 (Phase 1)"),
(@ENTRY,0,8,0,3,2,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - Between 0-15% Mana - Enable Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - Between 30-100% Mana - Set Event Phase 1 (Phase 2)"),
(@ENTRY,0,10,0,7,1,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - On Evade - Set Event Phase 0 (Phase 1) (No Repeat)"),
(@ENTRY,0,11,12,2,1,100,1,0,50,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - Between 0-50% Health - Set Event Phase 3 (Phase 1) (No Repeat)"),
(@ENTRY,0,12,13,61,1,100,1,0,50,0,0,11,19030,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - Between 0-50% Health - Cast 'Bear Form' (Phase 1) (No Repeat)"),
(@ENTRY,0,13,0,61,1,100,1,0,50,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - Between 0-50% Health - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,14,0,0,4,100,0,3000,4500,12000,13000,11,12161,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Naturalist - In Combat - Cast 'Maul' (Phase 4)"),
(@ENTRY,0,15,0,0,4,100,0,8000,9000,25000,26000,11,15727,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - In Combat - Cast 'Demoralizing Roar' (Phase 4)"),
(@ENTRY,0,16,0,7,4,100,1,0,0,0,0,28,19030,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - On Evade - Remove Aura 'Bear Form' (Phase 4) (No Repeat)"),
(@ENTRY,0,17,0,7,4,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - On Evade - Set Event Phase 0 (Phase 4) (No Repeat)");

-- Gordunni Warlord SAI
SET @ENTRY := 5241;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,15000,20000,11,10967,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Warlord - In Combat - Cast 'Echoing Roar'");

-- Gordunni Warlock SAI
SET @ENTRY := 5240;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Warlock - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Warlock - On Aggro - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,11,7289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Warlock - On Aggro - Cast 'Shrink' (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3000,4500,11,7289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Warlock - Within 0-40 Range - Cast 'Shrink' (Phase 1)"),
(@ENTRY,0,4,0,9,1,100,0,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Warlock - Within 40-100 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,9,1,100,0,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Warlock - Within 10-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Warlock - Within 0-40 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,3,1,100,0,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Warlock - Between 0-15% Mana - Set Event Phase 2 (Phase 1)"),
(@ENTRY,0,8,0,3,2,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Warlock - Between 0-15% Mana - Enable Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Warlock - Between 30-100% Mana - Set Event Phase 1 (Phase 2)"),
(@ENTRY,0,10,0,0,1,100,0,5000,6000,20000,25000,11,7289,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Warlock - In Combat - Cast 'Shrink' (Phase 1)"),
(@ENTRY,0,11,0,4,1,20,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Warlock - On Aggro - Say Line 0 (Phase 1) (No Repeat)"),
(@ENTRY,0,12,0,9,1,100,0,0,8,13600,14500,11,20298,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Warlock - Within 0-8 Range - Cast 'Shadow Bolt' (Phase 1)");

-- NPC talk text insert
SET @ENTRY := 5240;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I''ll crush you!',12,0,50,0,0,0, 'on Aggro Text', 1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text', 1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text', 1927);

-- Gordunni Shaman SAI
SET @ENTRY := 5236;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Shaman - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,1,100,0,5000,5000,19000,22000,11,26369,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Shaman - In Combat - Cast 'Lightning Shield' (Phase 1)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,8134,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Shaman - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,3,0,16,0,100,0,19514,1,15000,30000,11,8134,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Shaman - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'"),
(@ENTRY,0,4,0,14,0,100,0,450,40,15000,18000,11,8005,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Shaman - Friendly At 450 Health - Cast 'Healing Wave'"),
(@ENTRY,0,5,0,2,0,100,0,0,40,14000,21000,11,8005,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Shaman - Between 0-40% Health - Cast 'Healing Wave'");

-- NPC talk text insert
SET @ENTRY := 5236;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I''ll crush you!',12,0,50,0,0,0, 'on Aggro Text',1925),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text',1926),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text',1927);

-- Gordunni Ogre Mage SAI
SET @ENTRY := 5237;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Ogre Mage - On Aggro - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Within 0-40 Range - Cast 'Lightning Bolt' (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,0,0,15,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Between 0-15% Mana - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,1,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Between 0-15% Mana - Increment Phase (Phase 1) (No Repeat)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Within 35-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,100,100,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,100,100,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Between 30-100% Mana - Decrement Phase"),
(@ENTRY,0,10,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");

-- Gordunni Mauler SAI
SET @ENTRY := 5234;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,3000,5000,11,3391,2,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Mauler - In Combat - Cast 'Thrash'");

-- Gordunni Mage-Lord SAI
SET @ENTRY := 5239;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Mage-Lord - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,20000,26000,11,20827,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Mage-Lord - In Combat - Cast 'Flamestrike'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mage-Lord - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");

-- Gordunni Brute SAI
SET @ENTRY := 5232;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,8000,15000,11,10966,2,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Brute - In Combat - Cast 'Uppercut'");

-- Gordunni Battlemaster SAI
SET @ENTRY := 5238;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,13730,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Battlemaster - On Aggro - Cast 'Demoralizing Shout'");

-- Gordok Ogre-Mage SAI
SET @ENTRY := 11443;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Ogre-Mage - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Ogre-Mage - On Aggro - Cast 20823"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,2400,3800,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 0-40 Range - Cast 20823 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,0,0,100,0,5000,12000,35000,45000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - In Combat - Cast 6742");
-- Texts for Gordok Ogre-Mage
SET @ENTRY := 11443;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,"Gordok Ogre-Mage",1925),
(@ENTRY,0,1,"Me smash! You die!",12,0,100,0,0,0,"Gordok Ogre-Mage",1926),
(@ENTRY,0,2,"I'll crush you!",12,0,100,0,0,0,"Gordok Ogre-Mage",1927);

-- Gordok Mauler SAI
SET @ENTRY := 11442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,3,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Mauler - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,10000,8000,12000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Mauler - In Combat - Cast 3391 (Normal Dungeon)"),
(@ENTRY,0,2,3,2,0,100,3,0,30,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mauler - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mauler - Between 0-30% Health - Say Line 1 (Normal Dungeon)");
-- Texts for Gordok Mauler
SET @ENTRY := 11442;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,"Gordok Mauler",1925),
(@ENTRY,0,1,"Me smash! You die!",12,0,100,0,0,0,"Gordok Mauler",1926),
(@ENTRY,0,2,"I'll crush you!",12,0,100,0,0,0,"Gordok Mauler",1927),
(@ENTRY,1,0,"%s becomes enraged!",16,0,100,0,0,0,"Gordok Mauler", 7798);

-- Gordok Hyena SAI
SET @ENTRY := 12418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,15000,20000,11,13445,32,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Hyena - In Combat - Cast Rend");

-- Gnarl Leafbrother SAI
SET @ENTRY := 5354;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,11922,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gnarl Leafbrother - On Aggro - Cast 'Entangling Roots'");

-- Frayfeather Stagwing SAI
SET @ENTRY := 5304;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,8000,11,5708,2,0,0,0,0,2,0,0,0,0,0,0,0,"Frayfeather Stagwing - In Combat - Cast 'Swoop'");

-- Frayfeather Skystormer SAI
SET @ENTRY := 5305;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,20000,25000,11,6535,2,0,0,0,0,2,0,0,0,0,0,0,0,"Frayfeather Skystormer - In Combat - Cast 'Lightning Cloud'");

-- Enraged Feral Scar SAI
SET @ENTRY := 5295;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,11831,2,0,0,0,0,2,0,0,0,0,0,0,0,"Enraged Feral Scar - On Aggro - Cast 'Frost Nova'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,3000,4000,11,8398,64,0,0,0,0,2,0,0,0,0,0,0,0,"Enraged Feral Scar - In Combat - Cast 'Frostbolt Volley'");

-- Elder Rage Scar SAI
SET @ENTRY := 5297;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,6507,2,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Rage Scar - On Aggro - Cast 'Battle Roar'");

-- Dreamroarer SAI
SET @ENTRY := 12497;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,20000,25000,11,18435,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dreamroarer - In Combat - Cast 'Flame Breath'");

-- Diamond Head SAI
SET @ENTRY := 5345;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,15000,20000,11,5164,2,0,0,0,0,2,0,0,0,0,0,0,0,"Diamond Head - In Combat - Cast 'Knockdown'");

-- Coast Crawl Deepseer SAI
SET @ENTRY := 5328;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,10000,10000,10000,11,12544,2,0,0,0,0,1,0,0,0,0,0,0,0,"Coast Crawl Deepseer - Out of Combat - Cast 'Frost Armor'");

-- Chimaerok SAI
SET @ENTRY := 12800;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,20629,2,0,0,0,0,2,0,0,0,0,0,0,0,"Chimaerok - On Aggro - Cast 'Corrosive Venom Spit'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,3000,4000,11,20627,64,0,0,0,0,2,0,0,0,0,0,0,0,"Chimaerok - In Combat - Cast 'Lightning Breath'"),
(@ENTRY,0,2,0,0,0,100,0,10000,15000,10000,15000,11,18144,2,0,0,0,0,2,0,0,0,0,0,0,0,"Chimaerok - In Combat - Cast 'Swoop'");

-- Bloodroar the Stalker SAI
SET @ENTRY := 5346;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,17000,22000,11,3264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodroar the Stalker - In Combat - Cast 'Blood Howl'"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodroar the Stalker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodroar the Stalker - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 5346;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 7798);

-- Arcane Chimaerok SAI
SET @ENTRY := 12801;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,3000,4000,11,20630,64,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Chimaerok - In Combat - Cast 'Lightning Breath'"),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,20223,2,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Chimaerok - Between 0-50% Health - Cast 'Magic Reflection' (No Repeat)");

-- Arash-ethis SAI
SET @ENTRY := 5349;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,3000,4000,11,15117,64,0,0,0,0,2,0,0,0,0,0,0,0,"Arash-ethis - In Combat - Cast 'Chain Lightning'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,10000,12000,11,12553,2,0,0,0,0,2,0,0,0,0,0,0,0,"Arash-ethis - In Combat - Cast 'Shock'");

-- Antilus the Soarer SAI
SET @ENTRY := 5347;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,15000,20000,11,13445,2,0,0,0,0,2,0,0,0,0,0,0,0,"Antilus the Soarer - In Combat - Cast 'Rend'");
