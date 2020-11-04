-- 
-- Overlord Ramtusk SAI -- Add 'Battle Stance'
SET @ENTRY := 4420;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Ramtusk - On Reset - Cast 'Battle Stance'");

-- Irradiated Invader SAI -- Add abilities, visualspells and texts
SET @ENTRY := 6213;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,9769,0,0,0,0,0,0,0,0,0,0,0,0,0,"Irradiated Invader - On Reset - Cast 'Radiation'"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,11,21862,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Invader - On Reset - Cast 'Radiation'"),
(@ENTRY,0,2,0,0,0,100,0,3600,7200,3600,7200,11,9771,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irradiated Invader - In Combat - Cast 'Radiation Bolt'"),
(@ENTRY,0,3,4,6,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Invader - On Just Died - Say Line 0"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,11,9798,2,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Invader - On Just Died - Cast 'Radiation'");

-- Irradiated Pillager SAI -- Add visualspells and texts
SET @ENTRY := 6329;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,75,9798,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Pillager - On Reset - Add Aura 'Radiation'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,10000,11000,11,9771,64,0,0,0,0,17,0,50,0,0,0,0,0,"Irradiated Pillager - In Combat CMC - Cast 'Radiation Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,8269,2,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Pillager - Between 0-50% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,11,21862,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Pillager - On Reset - Cast 'Radiation'"),
(@ENTRY,0,4,5,6,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Pillager - On Just Died - Say Line 0"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,11,9798,2,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Pillager - On Just Died - Cast 'Radiation'");

-- Caverndeep Burrower SAI
SET @ENTRY := 6206;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,4,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caverndeep Burrower - On Spellhit 'Radiation' - Say Line 0");

-- Caverndeep Ambusher SAI
SET @ENTRY := 6207;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3700,3700,3600,12400,11,2590,0,0,0,0,0,2,0,0,0,0,0,0,0,"Caverndeep Ambusher - In Combat - Cast 'Backstab'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caverndeep Ambusher - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caverndeep Ambusher - On Spellhit 'Radiation' - Say Line 0");

-- Caverndeep Invader SAI
SET @ENTRY := 6208;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caverndeep Invader - On Spellhit 'Radiation' - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caverndeep Invader - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Caverndeep Looter SAI
SET @ENTRY := 6209;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caverndeep Looter - On Spellhit 'Radiation' - Say Line 0");

-- Caverndeep Pillager SAI
SET @ENTRY := 6210;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,8876,32,0,0,0,0,1,0,0,0,0,0,0,0,"Caverndeep Pillager - On Reset - Cast 'Thrash'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,24500,24500,11,1777,0,0,0,0,0,2,0,0,0,0,0,0,0,"Caverndeep Pillager - Within 0-5 Range - Cast 'Gouge'"),
(@ENTRY,0,2,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caverndeep Pillager - On Spellhit 'Radiation' - Say Line 0"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caverndeep Pillager - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Caverndeep Reaver SAI
SET @ENTRY := 6211;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id` >=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caverndeep Reaver - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,4,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Caverndeep Reaver - On Spellhit 'Radiation' - Say Line 0");

-- Leprous Technician SAI
SET @ENTRY := 6222;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id` >=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,0,1,0,100,0,10000,45000,30000,70000,11,10348,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Technician - Out of Combat - Cast 'Tune Up'"),
(@ENTRY,0,4,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Technician - On Spellhit 'Radiation' - Say Line 0");

-- Leprous Defender SAI
SET @ENTRY := 6223;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,4,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Defender - On Spellhit 'Radiation' - Say Line 0");

-- Leprous Machinesmith SAI
SET @ENTRY := 6224;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Machinesmith - On Spellhit 'Radiation' - Say Line 0");

-- Dark Iron Ambassador SAI
SET @ENTRY := 6228;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,6,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - On Spellhit 'Radiation' - Say Line 0");

-- Holdout Warrior SAI
SET @ENTRY := 6391;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`>=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Holdout Warrior - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,3,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Holdout Warrior - On Spellhit 'Radiation' - Say Line 0");

-- Leprous Assistant SAI
SET @ENTRY := 7603;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Assistant - On Aggro - Call For Help"),
(@ENTRY,0,1,0,8,0,100,0,9798,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Assistant - On Spellhit 'Radiation' - Say Line 0");

-- Electrocutioner 6000 SAI
SET @ENTRY := 6235;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Electrocutioner 6000 - On Aggro - Say Line 0");

-- Mobile Alert System SAI (credits to Sunwell)
SET @ENTRY := 7849;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mobile Alert System - On Reset - Disable Combat Movement"),
(@ENTRY,0,1,0,0,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mobile Alert System - In Combat - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,1,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mobile Alert System - In Combat - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,4,0,0,100,0,10000,10000,10000,10000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mobile Alert System - In Combat - Say Line 0"),
(@ENTRY,0,4,5,61,0,100,0,10000,10000,10000,10000,12,7603,4,30000,0,0,0,1,0,0,0,5,0,0,0,"Mobile Alert System - In Combat - Summon Creature 'Leprous Assistant'"),
(@ENTRY,0,5,0,61,0,100,0,10000,10000,10000,10000,12,6223,4,30000,0,0,0,1,0,0,0,-5,0,0,0,"Mobile Alert System - In Combat - Summon Creature 'Leprous Defender'");

DELETE FROM `creature_text` WHERE `CreatureID`=7849;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`, `BroadcastTextId`) VALUES 
(7849, 0, 0, 'Warning! Warning! Intruder alert! Intruder alert!', 14, 0, 100, 0, 0, 0, 'Mobile Alert System', 4142);

DELETE FROM `creature_text` WHERE `CreatureID` IN (6213, 6329, 6206, 6207, 6208, 6209, 6210, 6211, 6212, 6222, 6223, 6224, 6228, 6391, 7603, 6235);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(6213, 0, 0, '%s blood sprays into the air!', 16, 0, 100, 0, 0, 0, 3131, 'Irradiated Invader'),
(6329, 0, 0, '%s blood sprays into the air!', 16, 0, 100, 0, 0, 0, 3131, 'Irradiated Pillager'),
(6206, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Caverndeep Burrower '),
(6207, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Caverndeep Ambusher'),
(6208, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Caverndeep Invader'),
(6209, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Caverndeep Looter'),
(6210, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Caverndeep Pillager'),
(6211, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Caverndeep Reaver'),
(6212, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Dark Iron Agent'),
(6222, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Leprous Technician'),
(6223, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Leprous Defender'),
(6224, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Leprous Machinesmith'),
(6228, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Dark Iron Ambassador'),
(6391, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Holdout Warrior'),
(7603, 0, 0, '%s is splashed by the blood and becomes irradiated!', 16, 0, 100, 0, 0, 0, 3367, 'Leprous Assistant '),
(6235, 0, 0, 'Electric justice!', 14, 0, 100, 0, 0, 5811, 6177, 'Electrocutioner 6000');
