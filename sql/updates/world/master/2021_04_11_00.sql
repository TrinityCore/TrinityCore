-- DB update 2021_04_09_00 -> 2021_04_11_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_09_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_09_00 2021_04_11_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617170212396609300'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617170212396609300');
/* Slim is walking just barely too far to target and send data back to Mikhail on a failed quest*/

-- -------------------------------- Missing Diplomat Part 11 Failed Quest Recovery Fix -----------------------------------------------

-- Tapoke "Slim" Jahn
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4962 AND `source_type` = 0 AND `id` IN (6,11,12);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 496200 AND `source_type` = 9 AND `id` = 8;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(4962,0,6,0,40,0,100,0,7,4962,0,0,0,45,1,1,0,0,0,0,10,9432,4963,1,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Waypoint 7 Reached - Set Data to Mikhail"),
(4962,0,11,0,38,0,100,0,1,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Data Set - Set Active On"),
(4962,0,12,0,11,0,100,0,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Respawn - Set Active Off"),

(496200,9,8,0,0,0,100,0,1000,1000,0,0,0,45,1,1,0,0,0,0,10,9432,4963,1,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Set Data to Mikhail");

-- Mikhail
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4963 AND `source_type` = 0 AND `id` = 6;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 496300 AND `source_type` = 9 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4963,0,6,0,19,0,100,0,1249,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mikhail - On Quest 'The Missing Diplomat (Part 11)' Taken - Set Active On"),
(496300,9,2,0,0,0,100,0,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mikhail - On Script - Set Active Off");

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
