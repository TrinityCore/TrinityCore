-- DB update 2021_02_25_05 -> 2021_02_25_06
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_25_05';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_25_05 2021_02_25_06 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614187724074625300'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614187724074625300');
-- -------------------------------------------------Viscous Fallout--------------------------------------------------
SET @ENTRY := 7079;
SET @GUID := 30137;
UPDATE `creature_template` SET `scale` = 1.3,`MovementType` = 0 WHERE `entry` = @ENTRY;
UPDATE `creature` SET `position_x` = -471.39,`position_y` = 48.4756,`position_z` = -207.954,`orientation` = 6.03304,`MovementType` = 2,`wander_distance` = 0 WHERE `guid` = @GUID;
UPDATE `creature_model_info` SET `CombatReach` = 0.3 WHERE `DisplayID` = 5497;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` >= 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7079,0,1,0,0,0,100,1,1000,2000,0,0,0,75,10341,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Viscous Fallout - In Combat - Add Aura \'Radiation Cloud\''),
(7079,0,2,0,0,0,100,0,2000,9000,11000,14000,0,11,9459,64,0,0,0,0,17,0,50,0,0,0,0,0,0,'Viscous Fallout - In Combat CMC - Cast \'Corrosive Ooze\'');

SET @ENTRY := 70790;
DELETE FROM `creature_addon` WHERE `guid` = @GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(@GUID,@ENTRY,0,0,0,0,0,NULL);

DELETE FROM `waypoint_data` WHERE `id` = @ENTRY;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES 
(@ENTRY,1,-440.007,40.4573,-208.528,0,0,0,0,100,0),
(@ENTRY,2,-403.428,48.1517,-208.92,0,0,0,0,100,0),
(@ENTRY,3,-393.459,63.5904,-209.678,0,0,0,0,100,0),
(@ENTRY,4,-406.709,75.8918,-210.99,0,0,0,0,100,0),
(@ENTRY,5,-421.506,82.5705,-210.045,0,0,0,0,100,0),
(@ENTRY,6,-428.759,100.234,-209.626,0,0,0,0,100,0),
(@ENTRY,7,-409.098,109.523,-210.525,0,0,0,0,100,0),
(@ENTRY,8,-393.271,112.121,-209.804,0,0,0,0,100,0),
(@ENTRY,9,-380.83,95.3402,-210.582,0,0,0,0,100,0),
(@ENTRY,10,-372.115,112.371,-209.234,0,0,0,0,100,0),
(@ENTRY,11,-372.697,137.794,-208.769,0,0,0,0,100,0),
(@ENTRY,12,-396.703,139.501,-210.381,0,0,0,0,100,0),
(@ENTRY,13,-372.697,137.794,-208.769,0,0,0,0,100,0),
(@ENTRY,14,-396.703,139.501,-210.381,0,0,0,0,100,0),
(@ENTRY,15,-372.697,137.794,-208.769,0,0,0,0,100,0),
(@ENTRY,16,-372.115,112.371,-209.234,0,0,0,0,100,0),
(@ENTRY,17,-380.83,95.3402,-210.582,0,0,0,0,100,0),
(@ENTRY,18,-393.271,112.121,-209.804,0,0,0,0,100,0),
(@ENTRY,19,-409.098,109.523,-210.525,0,0,0,0,100,0),
(@ENTRY,20,-428.759,100.234,-209.626,0,0,0,0,100,0),
(@ENTRY,21,-421.506,82.5705,-210.045,0,0,0,0,100,0),
(@ENTRY,22,-406.709,75.8918,-210.99,0,0,0,0,100,0),
(@ENTRY,23,-393.459,63.5904,-209.678,0,0,0,0,100,0),
(@ENTRY,24,-403.428,48.1517,-208.92,0,0,0,0,100,0),
(@ENTRY,25,-440.007,40.4573,-208.528,0,0,0,0,100,0),
(@ENTRY,26,-471.277,47.9361,-208.061,0,0,0,0,100,0);


-- -------------------------------------------Viscous Fallout Mobs Spell Updates-------------------------------------------
-- Irradiated Slime
SET @ENTRY := 6218;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,0,2000,9000,11000,14000,0,11,9459,0,0,0,0,0,17,0,50,0,0,0,0,0,0,'Irradiated Slime - In Combat - Cast \'Corrosive Ooze\'');


-- Corrosive Lurker
SET @ENTRY := 6219;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,0,2000,9000,11000,14000,0,11,9459,0,0,0,0,0,17,0,50,0,0,0,0,0,0,'Corrosive Lurker - In Combat - Cast \'Corrosive Ooze\'');


-- Irradiated Horror
SET @ENTRY := 6220;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0 AND `id` >= 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,1,1000,2000,0,0,0,75,10341,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Irradiated Horror - In Combat - Add Aura \'Radiation Cloud\' (No Repeat)'),
(@ENTRY,0,2,0,0,0,100,0,2000,9000,11000,14000,0,11,9459,0,0,0,0,0,17,0,50,0,0,0,0,0,0,'Irradiated Horror - In Combat - Cast \'Corrosive Ooze\'');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
