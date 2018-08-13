    /*//////////////////////////////////////////////////////////////////////
   //  FunSocietyWoW - SAI DEV                                           //
  //  Copyright 2018 FunSocietyWoW and Ashamane Core //
 //  All Rights Reserved                                                       //
//////////////////////////////////////////////////////////////////////////

/*#############
# Mardum Part - 4   #
#############*/

-- Burning Soulstalker SAI
SET @BURNING_SOULSTALKER := 96278;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@BURNING_SOULSTALKER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@BURNING_SOULSTALKER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BURNING_SOULSTALKER,0,0,0,0,0,100,0,5000,8000,12000,15000,11,200498,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Soulstalker - In Combat - Cast 'Abyss Howl'"),
(@BURNING_SOULSTALKER,0,1,0,9,0,100,0,0,8,15000,25000,11,200503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Soulstalker - Within 0-8 Range - Cast 'Ignite'");

-- Count Nefarious SAI - RareElite
SET @COUNT_NEFARIOUS := 97058;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@COUNT_NEFARIOUS;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@COUNT_NEFARIOUS AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@COUNT_NEFARIOUS,0,0,0,0,0,100,0,5000,8000,18000,22000,11,198947,0,0,0,0,0,2,0,0,0,0,0,0,0,"Count Nefarious - In Combat - Cast 'Carrion Storm'"),
(@COUNT_NEFARIOUS,0,1,0,2,0,100,0,0,30,22000,25000,11,199103,2,0,0,0,0,1,0,0,0,0,0,0,0,"Count Nefarious - Between 0-30% Health - Cast 'Fel Shield'"),
(@COUNT_NEFARIOUS,0,2,0,0,0,100,0,2000,5000,12000,15000,11,198894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Count Nefarious - In Combat - Cast 'Vampiric Cleave'");

-- Eredar Sorcerer SAI
SET @EREDAR_SORCERER := 96473;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@EREDAR_SORCERER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@EREDAR_SORCERER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@EREDAR_SORCERER,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Eredar Sorcerer - In Combat - Say Line 0 (No Repeat)"),
(@EREDAR_SORCERER,0,1,0,0,0,100,0,5000,8000,17000,20000,11,200615,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eredar Sorcerer - In Combat - Cast 'Fel Resonance'"),
(@EREDAR_SORCERER,0,2,0,0,0,100,0,0,0,3000,3000,11,200582,64,0,0,0,0,2,0,0,0,0,0,0,0,"Eredar Sorcerer - In Combat - Cast 'Fel Blast'");

DELETE FROM `creature_text` WHERE `CreatureID` = 96473;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96473, 0, 0, 'They have the spectral sight!', 12, 0, 100, 0, 0, 56999, 0, 0, 'Eredar Sorcerer to Jace Darkweaver');

-- Eredar Sorcerer SAI
SET @EREDAR_SORCERER_1 := 102726;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@EREDAR_SORCERER_1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@EREDAR_SORCERER_1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@EREDAR_SORCERER_1,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Eredar Sorcerer - In Combat - Say Line 0 (No Repeat)"),
(@EREDAR_SORCERER_1,0,1,0,0,0,100,0,5000,8000,17000,20000,11,200615,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eredar Sorcerer - In Combat - Cast 'Fel Resonance'"),
(@EREDAR_SORCERER_1,0,2,0,0,0,100,0,0,0,3000,3000,11,200582,64,0,0,0,0,2,0,0,0,0,0,0,0,"Eredar Sorcerer - In Combat - Cast 'Fel Blast'");

DELETE FROM `creature_text` WHERE `CreatureID` = 102726;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(102726, 0, 0, 'They have the spectral sight!', 12, 0, 100, 0, 0, 56999, 0, 0, 'Eredar Sorcerer to Jace Darkweaver');

-- Felguard Butcher SAI
SET @FELGUARD_BUTCHER := 96494;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@FELGUARD_BUTCHER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@FELGUARD_BUTCHER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FELGUARD_BUTCHER,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Felguard Butcher - In Combat - Say Line 0 (No Repeat)"),
(@FELGUARD_BUTCHER,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200647,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felguard Butcher - In Combat - Cast 'Shadow Blade''"),
(@FELGUARD_BUTCHER,0,2,0,2,0,100,1,0,30,0,0,11,200632,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felguard Butcher - Between 0-30% Health - Cast 'Dark Rage' (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = 96494;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96494, 0, 0, 'Die, Illidari fool.', 12, 0, 100, 0, 0, 55189, 0, 0, 'Felguard Butcher to Jace Darkweaver');

-- Fiendish Creeper SAI
SET @FIENDISH_CREEPER := 99759;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@FIENDISH_CREEPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@FIENDISH_CREEPER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FIENDISH_CREEPER,0,0,0,0,0,100,0,5000,8000,12000,15000,11,200570,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fiendish Creeper - In Combat - Cast 'Demon Spit'");

-- Fel Weaver SAI
SET @FEL_WEAVER := 97706;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@FEL_WEAVER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@FEL_WEAVER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FEL_WEAVER,0,0,0,0,0,100,0,5000,8000,12000,15000,11,200748,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Weaver - In Combat - Cast 'Fel Weaving'"),
(@FEL_WEAVER,0,1,0,0,0,100,0,0,0,2000,2500,11,200751,64,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Weaver - In Combat - Cast 'Lob Poison'");

-- General Volroth SAI
SET @GENERAL_VOLROTH := 97370;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@GENERAL_VOLROTH;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GENERAL_VOLROTH AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GENERAL_VOLROTH,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"General Volroth - In Combat - Say Line 0 (No Repeat)"),
(@GENERAL_VOLROTH,0,1,0,0,0,100,0,5000,8000,12000,15000,11,197750,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Volroth - In Combat - Cast 'Fel Breath'"),
(@GENERAL_VOLROTH,0,2,0,0,0,100,0,10000,10000,18000,25000,11,197749,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Volroth - In Combat - Cast 'Burn'"),
(@GENERAL_VOLROTH,0,3,0,2,0,100,1,40,50,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"General Volroth - Between 40-50% Health - Say Line 1 (No Repeat)"),
(@GENERAL_VOLROTH,0,4,0,6,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"General Volroth - On Just Died - Say Line 2");

DELETE FROM `creature_text` WHERE `CreatureID` = 97370;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97370, 0, 0, 'You cannot have them. They are mine!', 14, 0, 100, 0, 0, 55199, 0, 0, 'General Volroth to Player'),
(97370, 1, 0, 'My fire will leave only your bones behind.', 14, 0, 100, 0, 0, 55201, 0, 0, 'General Volroth'),
(97370, 2, 0, 'Impossible!', 14, 0, 100, 0, 0, 55200, 0, 0, 'General Volroth to Coilskar Sea-Caller');

-- Hulking Forgefiend SAI
SET @HULKING_FORGEFIEND := 96402;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@HULKING_FORGEFIEND;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@HULKING_FORGEFIEND AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@HULKING_FORGEFIEND,0,0,0,0,0,100,1,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Hulking Forgefiend - In Combat - Say Line 1 (No Repeat)"),
(@HULKING_FORGEFIEND,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hulking Forgefiend - In Combat - Cast 'Bad Breath'"),
(@HULKING_FORGEFIEND,0,2,0,2,0,100,1,40,50,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"General Volroth - Between 40-50% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = 96402;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96402, 0, 0, 'Pitiful.', 12, 0, 100, 0, 0, 55324, 0, 0, 'Hulking Forgefiend to Player'),
(96402, 1, 0, 'Die in glorious battle!', 12, 0, 100, 0, 0, 55330, 0, 0, 'Hulking Forgefiend to Player');

-- King Voras SAI - Rare
SET @KING_VORAS := 97059;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@KING_VORAS;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@KING_VORAS AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KING_VORAS,0,0,0,0,0,100,0,0,0,3400,4700,11,198163,64,0,0,0,0,2,0,0,0,0,0,0,0,"King Voras - In Combat - Cast 'Acid Spit'");

-- Leeching Spider SAI
SET @LEECHING_SPIDER := 100703;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@LEECHING_SPIDER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@LEECHING_SPIDER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@LEECHING_SPIDER,0,0,0,2,0,100,1,0,40,0,0,11,198204,2,0,0,0,0,1,0,0,0,0,0,0,0,"Leeching Spider - Between 0-40% Health - Cast 'Leeching Spider' (No Repeat)");

-- Mardum Executioner SAI
SET @MARDUM_EXECUTIONER := 96279;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@MARDUM_EXECUTIONER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MARDUM_EXECUTIONER AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@MARDUM_EXECUTIONER*100+01,@MARDUM_EXECUTIONER*100+02,@MARDUM_EXECUTIONER*100+03) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MARDUM_EXECUTIONER,0,0,0,26,0,100,0,1,10,0,0,87,@MARDUM_EXECUTIONER*100+01,@MARDUM_EXECUTIONER*100+02,@MARDUM_EXECUTIONER*100+03,0,0,0,1,0,0,0,0,0,0,0,"Mardum Executioner - In Combat LoS - Run Random Script"),
(@MARDUM_EXECUTIONER,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200827,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mardum Executioner - In Combat - Cast 'Tortured Souls'"),
(@MARDUM_EXECUTIONER*100+01,9,0,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mardum Executioner - On Script - Say Line 0"),
(@MARDUM_EXECUTIONER*100+02,9,0,0,0,0,100,0,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mardum Executioner - On Script - Say Line 1"),
(@MARDUM_EXECUTIONER*100+03,9,0,0,0,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mardum Executioner - On Script - Say Line 2");

DELETE FROM `creature_text` WHERE `CreatureID` = 96279;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96279, 0, 0, 'Your soul will be mine.', 12, 0, 100, 0, 0, 55013, 0, 0, 'Mardum Executioner to Player'),
(96279, 1, 0, 'Into my cage you go.', 12, 0, 100, 0, 0, 55200, 0, 0, 'Mardum Executioner to Player'),
(96279, 2, 0, 'So eager to be enslaved.', 12, 0, 100, 0, 0, 55018, 0, 0, 'Mardum Executioner to Player');

-- Overseer Brutarg SAI
SET @OVERSEER_BRUTARG := 97057;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@OVERSEER_BRUTARG;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@OVERSEER_BRUTARG AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@OVERSEER_BRUTARG,0,0,0,4,0,100,1,0,0,0,0,11,198497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overseer Brutarg - On Aggro - Cast 'Charge' (No Repeat)"),
(@OVERSEER_BRUTARG,0,1,0,0,0,100,1,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Brutarg - In Combat - Say Line 1 (No Repeat)"),
(@OVERSEER_BRUTARG,0,2,0,0,0,100,0,5000,8000,12000,15000,11,198518,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Brutarg - In Combat - Cast 'Meat Grinder'"),
(@OVERSEER_BRUTARG,0,3,0,0,0,100,1,10000,10000,20000,25000,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Brutarg - In Combat - Say Line 0 (No Repeat)"),
(@OVERSEER_BRUTARG,0,4,0,0,0,100,0,10000,10000,20000,25000,11,198573,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Brutarg - In Combat - Cast 'Equip Sword'");

DELETE FROM `creature_text` WHERE `CreatureID` = 97057;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97057, 0, 0, 'Like my new sword? Take a closer look.', 14, 0, 100, 0, 0, 55335, 0, 0, 'Overseer Brutarg to Overseer Brutarg'),
(97057, 1, 0, 'Stupid, tiny things...', 14, 0, 100, 0, 0, 55337, 0, 0, 'Overseer Brutarg to Player');

-- Prolifica SAI
SET @PROLIFICA := 98986;
UPDATE `creature_template` SET `InhabitType`=4, `AIName`="SmartAI" WHERE `entry`=@PROLIFICA;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PROLIFICA AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@PROLIFICA,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Prolifica - In Combat - Say Line 0 (No Repeat)"),
(@PROLIFICA,0,1,0,9,0,100,0,0,8,15000,25000,11,197240,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prolifica - Within 0-8 Range - Cast 'Gaseous Breath'"),
(@PROLIFICA,0,2,0,0,0,100,0,5000,8000,12000,15000,11,197217,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prolifica - In Combat - Cast 'Fel Geyser'"),
(@PROLIFICA,0,3,0,2,0,100,1,40,50,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Prolifica - Between 40-50% Health - Say Line 1 (No Repeat)"),
(@PROLIFICA,0,4,0,6,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Prolifica - On Just Died - Say Line 2");

DELETE FROM `creature_text` WHERE `CreatureID` = 98986;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(98986, 0, 0, 'Get away. You cannot have my tome!', 14, 0, 100, 35, 0, 55338, 0, 0, 'Prolifica to Player'),
(98986, 1, 0, 'My fel secrets will consume you!', 14, 0, 100, 0, 0, 55340, 0, 0, 'Prolifica'),
(98986, 2, 0, 'They''re stealing our secrets, my queen...', 14, 0, 100, 0, 0, 55339, 0, 0, 'Prolifica to Player');

-- Queen's Centurion SAI
SET @QUEEN_CENTURION := 96277;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@QUEEN_CENTURION;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@QUEEN_CENTURION AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@QUEEN_CENTURION*100+01,@QUEEN_CENTURION*100+02) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@QUEEN_CENTURION,0,0,0,26,0,100,1,1,10,0,0,87,@QUEEN_CENTURION*100+01,@QUEEN_CENTURION*100+02,0,0,0,0,1,0,0,0,0,0,0,0,"Queen's Centurion - In Combat LoS - Run Random Script (No Repeat)"),
(@QUEEN_CENTURION,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200805,0,0,0,0,0,1,0,0,0,0,0,0,0,"Queen's Centurion - In Combat - Cast 'Dark Communion'"),
(@QUEEN_CENTURION*100+01,9,0,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Queen's Centurion - On Script - Say Line 0"),
(@QUEEN_CENTURION*100+02,9,0,0,0,0,100,0,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Queen's Centurion - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 96277;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96277, 0, 0, 'I''ll rend you limb from limb.', 12, 0, 100, 0, 0, 55188, 0, 0, 'Queen''s Centurion to Player'),
(96277, 1, 0, 'For the Legion!', 12, 0, 100, 0, 0, 55192, 0, 0, 'Queen''s Centurion to Player');

-- Queen's Centurion SAI
SET @QUEEN_CENTURION_1 := 103432;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@QUEEN_CENTURION_1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@QUEEN_CENTURION_1 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@QUEEN_CENTURION_1*100+01,@QUEEN_CENTURION_1*100+02) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@QUEEN_CENTURION_1,0,0,0,26,0,100,1,1,10,0,0,87,@QUEEN_CENTURION_1*100+01,@QUEEN_CENTURION_1*100+02,0,0,0,0,1,0,0,0,0,0,0,0,"Queen's Centurion - In Combat LoS - Run Random Script (No Repeat)"),
(@QUEEN_CENTURION_1,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200805,0,0,0,0,0,1,0,0,0,0,0,0,0,"Queen's Centurion - In Combat - Cast 'Dark Communion'"),
(@QUEEN_CENTURION_1*100+01,9,0,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Queen's Centurion - On Script - Say Line 0"),
(@QUEEN_CENTURION_1*100+02,9,0,0,0,0,100,0,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Queen's Centurion - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 103432;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(103432, 0, 0, 'I''ll rend you limb from limb.', 12, 0, 100, 0, 0, 55188, 0, 0, 'Queen''s Centurion to Player'),
(103432, 1, 0, 'For the Legion!', 12, 0, 100, 0, 0, 55192, 0, 0, 'Queen''s Centurion to Player');

-- Soul Fragment SAI
SET @SOUL_FRAGMENT := 101753;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@SOUL_FRAGMENT;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SOUL_FRAGMENT AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SOUL_FRAGMENT,0,0,0,0,0,100,0,5000,8000,12000,15000,11,200720,0,0,0,0,0,2,0,0,0,0,0,0,0,"Soul Fragment - In Combat - Cast 'Soul Blast'");

-- Vile Soulmaster SAI
SET @VILE_SOULMASTER := 97014;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@VILE_SOULMASTER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@VILE_SOULMASTER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@VILE_SOULMASTER,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - In Combat - Say Line 0 (No Repeat)"),
(@VILE_SOULMASTER,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200674,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Soulmaster - In Combat - Cast 'Corrupt Soul'"),
(@VILE_SOULMASTER,0,2,0,2,0,100,1,45,50,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - Between 45-50% Health - Say Line 1 (No Repeat)"),
(@VILE_SOULMASTER,0,3,0,2,0,100,0,0,40,22000,25000,11,200689,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - Between 0-40% Health - Cast 'Shattered Visage'"),
(@VILE_SOULMASTER,0,4,0,6,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - On Just Died - Say Line 2");

DELETE FROM `creature_text` WHERE `CreatureID` = 97014;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97014, 0, 0, 'Kill the Illidari.', 12, 0, 100, 0, 0, 56992, 0, 0, 'Vile Soulmaster to Player'),
(97014, 1, 0, 'Your soul will be ours.', 12, 0, 100, 0, 0, 57001, 0, 0, 'Vile Soulmaster to Player'),
(97014, 2, 0, 'The Legion''s will be done.', 12, 0, 100, 0, 0, 56991, 0, 0, 'Vile Soulmaster to Player');

-- Vile Soulmaster SAI
SET @VILE_SOULMASTER_1 := 102724;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@VILE_SOULMASTER_1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@VILE_SOULMASTER_1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@VILE_SOULMASTER_1,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - In Combat - Say Line 0 (No Repeat)"),
(@VILE_SOULMASTER_1,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200674,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Soulmaster - In Combat - Cast 'Corrupt Soul'"),
(@VILE_SOULMASTER_1,0,2,0,2,0,100,1,45,50,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - Between 45-50% Health - Say Line 1 (No Repeat)"),
(@VILE_SOULMASTER_1,0,3,0,2,0,100,0,0,40,22000,25000,11,200689,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - Between 0-40% Health - Cast 'Shattered Visage'"),
(@VILE_SOULMASTER_1,0,4,0,6,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - On Just Died - Say Line 2");

DELETE FROM `creature_text` WHERE `CreatureID` = 102724;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(102724, 0, 0, 'Kill the Illidari.', 12, 0, 100, 0, 0, 56992, 0, 0, 'Vile Soulmaster to Player'),
(102724, 1, 0, 'Your soul will be ours.', 12, 0, 100, 0, 0, 57001, 0, 0, 'Vile Soulmaster to Player'),
(102724, 2, 0, 'The Legion''s will be done.', 12, 0, 100, 0, 0, 56991, 0, 0, 'Vile Soulmaster to Player');

-- Volatile Minion SAI
SET @VOLATILE_MINION := 96280;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@VOLATILE_MINION;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@VOLATILE_MINION AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@VOLATILE_MINION,0,0,0,6,0,100,1,0,0,0,0,11,200757,3,0,0,0,0,0,1,0,0,0,0,0,0,"Volatile Minion - On Just Died - Cast 'Explosive Minion on Death' (No Repeat)"),
(@VOLATILE_MINION,0,1,0,11,0,100,1,0,0,0,0,11,200756,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volatile Minion - On Respawn - Cast 'Volatile Minion' (No Repeat)");

-- Wicked Crawler SAI
SET @WICKED_CRAWLER := 100243;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@WICKED_CRAWLER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@WICKED_CRAWLER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@WICKED_CRAWLER,0,0,0,0,0,100,0,5000,8000,12000,15000,11,200782,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wicked Crawler - In Combat - Cast 'Demon Spit'");

-- Aranasi Maiden SAI
SET @ARANASI_MAIDEN := 100244;
UPDATE `creature_template` SET `unit_flags`=33280, `AIName`="SmartAI" WHERE `entry`=@ARANASI_MAIDEN;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ARANASI_MAIDEN AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ARANASI_MAIDEN,0,0,0,1,0,100,1,1000,1000,1000,1000,11,195898,2,0,0,0,0,1,0,0,0,0,0,0,0,"Aranasi Maiden - Out of Combat - Cast 'Fel Channelling' (No Repeat)"),
(@ARANASI_MAIDEN,0,1,0,7,0,100,1,0,0,0,0,11,195898,2,0,0,0,0,1,0,0,0,0,0,0,0,"Aranasi Maiden - On Evade - Cast 'Fel Channelling' (No Repeat)"),
(@ARANASI_MAIDEN,0,2,0,0,0,100,0,0,0,3400,4700,11,183345,64,0,0,0,0,2,0,0,0,0,0,0,0,"Aranasi Maiden - In Combat - Cast 'Shadow Bolt'");