-- DB update 2021_02_21_06 -> 2021_02_25_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_21_06';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_21_06 2021_02_25_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613848536903926000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613848536903926000');
-- -------------------------------------Sparklematic Animation---------------------------------
-- The Sparklematic 5200 SAI
SET @ENTRY := 142487;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,20,0,100,0,0,0,0,0,0,93,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Sparklematic 5200 - On Quest Finished - Send Custom Animation 0");


-- The Sparklematic 5200 SAI
SET @ENTRY := 175084;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,20,0,100,0,0,0,0,0,0,93,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Sparklematic 5200 - On Quest Finished - Send Custom Animation 0");


-- The Sparklematic 5200 SAI
SET @ENTRY := 175085;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,20,0,100,0,0,0,0,0,0,93,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Sparklematic 5200 - On Quest Finished - Send Custom Animation 0");


UPDATE `creature_loot_template` SET `QuestRequired` = 0 WHERE `Item` = 9308;


-- -------------------------------------------Creature Fixes------------------------------------------
-- Caverndeep Burrower SAI
SET @ENTRY := 6206;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(6206,0,2,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Caverndeep Burrower - On Spell Hit - Say Line 0');

DELETE FROM `creature_text` WHERE `CreatureID` = @ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(@ENTRY,0,0,'%s is splashed by the blood and becomes irradiated!',16,0,100,0,0,0,3367,0,'Caverndeep Burrower ');


-- Caverndeep Ambusher SAI
SET @ENTRY := 6207;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,2,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Caverndeep Ambusher - On Spell Hit - Say Line 0');

DELETE FROM `creature_text` WHERE `CreatureID` = @ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(@ENTRY,0,0,'%s is splashed by the blood and becomes irradiated!',16,0,100,0,0,0,3367,0,'Caverndeep Ambusher');


-- Caverndeep Invader SAI
SET @ENTRY := 6208;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Caverndeep Invader - On Spellhit 'Radiation' - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Caverndeep Invader - Between 0-15% Health - Flee For Assist (No Repeat)");


-- Caverndeep Looter SAI
SET @ENTRY := 6209;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Caverndeep Looter - On Spellhit 'Radiation' - Say Line 0");


-- Caverndeep Pillager SAI
SET @ENTRY := 6210;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,0,11,8876,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Caverndeep Pillager - On Reset - Cast 'Thrash'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,24500,24500,0,11,1777,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Caverndeep Pillager - Within 0-5 Range - Cast 'Gouge'"),
(@ENTRY,0,2,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Caverndeep Pillager - On Spellhit 'Radiation' - Say Line 0"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Caverndeep Pillager - Between 0-15% Health - Flee For Assist (No Repeat)");


-- Caverndeep Reaver SAI
SET @ENTRY := 6211;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` = 3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,3,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Caverndeep Reaver - On Spell Hit - Say Line 0');


-- Dark Iron Agent SAI
SET @ENTRY := 6212;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` >= 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,4,0,40,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Agent - On Aggro - Say Line 1"),
(@ENTRY,0,2,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Agent - On Spellhit 'Radiation' - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ENTRY AND `GroupID` = 0 AND `id` = 0;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(@ENTRY,0,0,'%s is splashed by the blood and becomes irradiated!',16,0,100,0,0,0,3367,0,'Dark Iron Agent');


-- Irradiated Invader SAI -- Add abilities,visualspells and texts
SET @ENTRY := 6213;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,0,11,9769,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Irradiated Invader - On Reset - Cast 'Radiation'"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,0,11,21862,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Invader - On Reset - Cast 'Radiation'"),
(@ENTRY,0,2,0,0,0,100,0,3600,7200,3600,7200,0,11,9771,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Irradiated Invader - In Combat - Cast 'Radiation Bolt'"),
(@ENTRY,0,3,4,6,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Invader - On Just Died - Say Line 0"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,0,11,9798,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Invader - On Just Died - Cast 'Radiation'");


-- Addled Leper
SET @ENTRY := 6221;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` = 6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,6,0,4,0,40,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Addled Leper - On Aggro - Say Line 0");


-- Leprous Technician SAI
SET @ENTRY := 6222;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Leprous Technician - On Aggro - Say Line 1'),
(@ENTRY,0,1,0,0,0,100,0,5000,12000,9000,18000,0,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Leprous Technician - In Combat - Cast Net'),
(@ENTRY,0,2,0,0,0,100,0,5000,12000,9000,18000,0,11,13398,0,0,0,0,0,5,30,0,0,0,0,0,0,0,'Leprous Technician - In Combat - Cast Throw Wrench'),
(@ENTRY,0,3,0,1,0,100,0,10000,45000,30000,70000,0,11,10348,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Leprous Technician - Out of Combat - Cast 'Tune Up'"),
(@ENTRY,0,4,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Leprous Technician - On Spellhit 'Radiation' - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(@ENTRY,0,0,'%s is splashed by the blood and becomes irradiated!',16,0,100,0,0,0,3367,0,'Leprous Technician'),
(@ENTRY,1,0,'No gnome will be left behind.',12,7,100,0,0,0,2422,0,'Leprous Technician'),
(@ENTRY,1,1,'The troggs...they never stop coming.  Die trogg!  Die!',12,7,100,0,0,0,2423,0,'Leprous Technician'),
(@ENTRY,1,2,'This sickness clouds my vision,but I know you must be a trogg.  Die foul invader!',12,7,100,0,0,0,2424,0,'Leprous Technician'),
(@ENTRY,1,3,'A foul trogg if ever I saw one.  Die!',12,7,100,0,0,0,2425,0,'Leprous Technician');


-- Leprous Defender SAI
SET @ENTRY := 6223;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Leprous Defender - On Aggro - Say Line 1'),
(@ENTRY,0,1,0,0,0,100,0,500,1000,2000,2500,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'Leprous Defender - In Combat - Cast Shoot'),
(@ENTRY,0,2,0,0,0,100,0,5000,12000,9000,18000,0,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Leprous Defender - In Combat - Cast Multi-Shot'),
(@ENTRY,0,3,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Leprous Defender - On Spellhit 'Radiation' - Say Line 0");


DELETE FROM `creature_text` WHERE `CreatureID` = @ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(@ENTRY,0,0,'%s is splashed by the blood and becomes irradiated!',16,0,100,0,0,0,3367,0,'Leprous Defender'),
(@ENTRY,1,0,'No gnome will be left behind.',12,7,100,0,0,0,2422,0,'Leprous Defender'),
(@ENTRY,1,1,'The troggs...they never stop coming.  Die trogg!  Die!',12,7,100,0,0,0,2423,0,'Leprous Defender'),
(@ENTRY,1,2,'This sickness clouds my vision,but I know you must be a trogg.  Die foul invader!',12,7,100,0,0,0,2424,0,'Leprous Defender'),
(@ENTRY,1,3,'A foul trogg if ever I saw one.  Die!',12,7,100,0,0,0,2425,0,'Leprous Defender');


-- Leprous Machinesmith SAI
SET @ENTRY := 6224;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Leprous Machinesmith - On Aggro - Say Line 1'),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,20000,25000,0,11,10732,0,0,0,0,0,19,6224,50,0,0,0,0,0,0,'Leprous Machinesmith - In Combat - Cast Supercharge'),
(@ENTRY,0,2,0,0,0,100,0,2000,5000,4000,6000,0,11,13398,64,0,0,0,0,21,30,0,0,0,0,0,0,0,'Leprous Machinesmith - In Combat - Cast Throw Wrench'),
(@ENTRY,0,3,0,2,0,100,1,0,90,0,0,0,11,10348,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Leprous Machinesmith - Between 0-90% Health - Cast Tune Up'),
(@ENTRY,0,4,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Leprous Machinesmith - On Spellhit 'Radiation' - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(@ENTRY,0,0,'%s is splashed by the blood and becomes irradiated!',16,0,100,0,0,0,3367,0,'Leprous Machinesmith'),
(@ENTRY,1,0,'No gnome will be left behind.',12,7,100,0,0,0,2422,0,'Leprous Machinesmith'),
(@ENTRY,1,1,'The troggs...they never stop coming.  Die trogg!  Die!',12,7,100,0,0,0,2423,0,'Leprous Machinesmith'),
(@ENTRY,1,2,'This sickness clouds my vision,but I know you must be a trogg.  Die foul invader!',12,7,100,0,0,0,2424,0,'Leprous Machinesmith'),
(@ENTRY,1,3,'A foul trogg if ever I saw one.  Die!',12,7,100,0,0,0,2425,0,'Leprous Machinesmith');


-- Dark Iron Ambassador SAI
SET @ENTRY := 6228;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` = 6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,6,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Ambassador - On Spellhit 'Radiation' - Say Line 0");


-- Techbot - SAI Non-Elite in WOTLK
SET @ENTRY := 6231;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,15000,15000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Techbot - In Combat - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,15000,15000,20000,25000,0,11,10852,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Techbot - In Combat - Cast 'Battle Net'"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,20000,30000,0,11,10855,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Techbot - In Combat - Cast 'Lag'"),
(@ENTRY,0,3,0,0,0,100,0,0,0,6000,9000,0,11,10858,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Techbot - In Combat - Cast 'Summon Dupe Bug'"),
(@ENTRY,0,4,0,2,0,100,0,0,50,25000,25000,0,11,10860,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Techbot - Between 0-50% Health - Cast 'Patch'"),
(@ENTRY,0,5,0,6,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,11,7732,15,0,0,0,0,0,0,'Techbot - On Just Died - Set Data |Dupe Bug|');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (10860,10852);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,3,10860,0,0,31,0,3,7732,0,0,0,0,'','Patch can only hit Dupe Bug'), -- Prevent Techbot instantly killing everyone including self
(13,1,10852,0,0,31,0,4,0,0,0,0,0,'','Battle Net can only hit Players');

DELETE FROM `creature_text` WHERE `CreatureID` = @ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY,0,0,'There is no COW level!... really! I repeat: there is no COW level. Well,maby there is...',12,0,9,0,0,0,0,0,'Techbot'),
(@ENTRY,0,1,'You are welcome,have a nice day.',12,0,9,0,0,0,0,0,'Techbot'),
(@ENTRY,0,2,'Please be patient,we will call your name when it is your turn. We are helping people in the order they appear to us on the screen.',12,0,9,0,0,0,0,0,'Techbot'),
(@ENTRY,0,3,'People think I like corndogs,but actually,they give me indigestion !!!',12,0,9,0,0,0,0,0,'Techbot'),
(@ENTRY,0,4,'Techbot is sensitive and those words hurt my ears. :[ Please be nice to me. I just want to help.',12,0,9,0,0,0,0,0,'Techbot'),
(@ENTRY,0,5,'I am a BOT. I have tons of information. To find out what I know whisper me.',12,0,9,0,0,0,0,0,'Techbot'),
(@ENTRY,0,6,'When the rep is talking to you,he will start each line with your name. If you don\'t see your name,he\'s not speaking to you.',12,0,9,0,0,0,0,0,'Techbot'),
(@ENTRY,0,7,'Remember,if you harass the rep or spam the channel,your account may be kicked,banned or worse.',12,0,9,0,0,0,0,0,'Techbot'),
(@ENTRY,0,8,'If you have been muted,or have questions about the Muting/UnMuting process,please visit...zzzzttt!!',12,0,9,0,0,0,0,0,'Techbot'),
(@ENTRY,0,9,'Some topics I can help you with are: | drivers | commands | lag | bots... zzzttt!',12,0,9,0,0,0,2435,0,'Techbot Random Speech'),
(@ENTRY,0,10,'I love you too. :)',12,0,9,0,0,0,2437,0,'Techbot Random Speech'),
(@ENTRY,0,11,'Please be patient,we will call your name when it is your turn.',12,0,9,0,0,0,2437,0,'Techbot Random Speech'),
(@ENTRY,0,12,'We are helping people in the order they appear to us on our screen. $N!',12,0,9,0,0,0,2437,0,'Techbot Random Speech');


-- Irradiated Pillager SAI -- Add visualspells and texts
SET @ENTRY := 6329;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,0,75,9798,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Pillager - On Reset - Add Aura 'Radiation'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,10000,11000,0,11,9771,64,0,0,0,0,17,0,50,0,0,0,0,0,0,"Irradiated Pillager - In Combat CMC - Cast 'Radiation Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,0,11,8269,0,2,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Pillager - Between 0-50% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,0,11,21862,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Pillager - On Reset - Cast 'Radiation'"),
(@ENTRY,0,4,5,6,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Pillager - On Just Died - Say Line 0"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,0,11,9798,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Pillager - On Just Died - Cast 'Radiation'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(@ENTRY,0,0,'%s blood sprays into the air!',16,0,100,0,0,0,3131,0,'Irradiated Pillager');


-- Holdout Warrior SAI
SET @ENTRY := 6391;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id`>= 3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Holdout Warrior - On Spellhit 'Radiation' - Say Line 0");


-- Leprous Assistant SAI
SET @ENTRY := 7603;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Leprous Assistant - On Aggro - Say Line 1'),
(@ENTRY,0,1,0,0,0,100,0,5000,12000,9000,18000,0,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Leprous Assistant - In Combat - Cast Net'),
(@ENTRY,0,2,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Leprous Assistant - On Spellhit 'Radiation' - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(@ENTRY,0,0,'%s is splashed by the blood and becomes irradiated!',16,0,100,0,0,0,3367,0,'Leprous Assistant '),
(@ENTRY,1,0,'No gnome will be left behind.',12,7,100,0,0,0,2422,0,'Leprous Assistant'),
(@ENTRY,1,1,'The troggs...they never stop coming.  Die trogg!  Die!',12,7,100,0,0,0,2423,0,'Leprous Assistant'),
(@ENTRY,1,2,'This sickness clouds my vision,but I know you must be a trogg.  Die foul invader!',12,7,100,0,0,0,2424,0,'Leprous Assistant'),
(@ENTRY,1,3,'A foul trogg if ever I saw one.  Die!',12,7,100,0,0,0,2425,0,'Leprous Assistant');


-- Gnomeregan Evacuee
SET @ENTRY := 7843;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` = 6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,6,0,6,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gnomeregan Evacuee - On Just Died - Say Line 0");


-- Dupe Bugs - Remove existing world dupe bugs (these are summoned only)
DELETE FROM `creature` WHERE `guid` IN (86352,86353);


-- Dupe Bugs
SET @ENTRY := 7732;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Dupe Bug - On Data Set - Despawn');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
