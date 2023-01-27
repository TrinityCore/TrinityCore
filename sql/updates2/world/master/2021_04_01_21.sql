-- DB update 2021_04_01_20 -> 2021_04_01_21
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_20';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_20 2021_04_01_21 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617265345631987700'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617265345631987700');

DELETE FROM `creature_addon` WHERE (`guid` IN (17090));

DELETE FROM `waypoints` WHERE (`entry` IN (3984));
INSERT INTO `waypoints` VALUES
(3984, 1, 888.1400, -121.8399, 38.3880, 'Nancy Vishas'),
(3984, 2, 891.5708, -114.1264, 38.2004, 'Nancy Vishas'),
(3984, 3, 909.1765, -90.91162, 33.7845, 'Nancy Vishas'),
(3984, 4, 891.5708, -114.1264, 38.2004, 'Nancy Vishas'),
(3984, 5, 888.1400, -121.8399, 38.3880, 'Nancy Vishas');

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 398400) AND (`source_type` = 9);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE (`entry` IN (3984, 3985));

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3984);
INSERT INTO `smart_scripts` VALUES
(3984, 0, 0, 0, 21, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - On Reached Home - Set Event Phase 1'),
(3984, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - On Respawn - Set Event Phase 1'),
(3984, 0, 2, 0, 1, 1, 100, 0, 60000, 180000, 180000, 180000, 0, 1, 0, 3000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - Out of Combat - Say Line 0 (Phase 1)'),
(3984, 0, 3, 0, 52, 1, 100, 1, 0, 3984, 0, 0, 0, 1, 0, 3000, 0, 0, 0, 0, 19, 3985, 6, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - On Text 0 Over - Say Line 0 (Phase 1) (No Repeat)'),
(3984, 0, 4, 0, 52, 1, 100, 0, 0, 3985, 0, 0, 0, 1, 1, 3000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - On Text 0 Over - Say Line 1 (Phase 1)'),
(3984, 0, 5, 0, 52, 1, 100, 1, 1, 3984, 0, 0, 0, 1, 1, 3000, 0, 0, 0, 0, 19, 3985, 0, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - On Text 1 Over - Say Line 1 (Phase 1) (No Repeat)'),
(3984, 0, 6, 0, 52, 1, 100, 0, 1, 3985, 0, 0, 0, 1, 2, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - On Text 1 Over - Say Line 2 (Phase 1)'),
(3984, 0, 7, 0, 52, 1, 100, 0, 2, 0, 0, 0, 0, 53, 0, 3984, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - On Text 2 Over - Start Waypoint (Phase 1)'),
(3984, 0, 8, 0, 40, 1, 100, 0, 3, 0, 0, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - On Waypoint 3 Reached - Pause Waypoint (Phase 1)'),
(3984, 0, 9, 0, 40, 1, 100, 0, 3, 0, 0, 0, 0, 1, 3, 3000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - On Waypoint 3 Reached - Say Line 3 (Phase 1)'),
(3984, 0, 10, 0, 56, 0, 100, 0, 3, 0, 0, 0, 0, 1, 4, 2500, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - On Waypoint Resumed - Say Line 4'),
(3984, 0, 11, 0, 40, 0, 100, 0, 5, 0, 0, 0, 0, 70, 900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - On Waypoint 5 Reached - Respawn Self'),
(3984, 0, 12, 0, 40, 0, 100, 0, 5, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1.08982, 'Nancy Vishas - On Waypoint 5 Reached - Set Orientation 1.08982'),
(3984, 0, 13, 0, 2, 1, 100, 1, 1, 15, 0, 0, 0, 25, 1, 0, 0, 0, 0, 0, 19, 0, 30, 0, 0, 0, 0, 0, 0, 'Nancy Vishas - Between 1-15% Health - Flee For Assist (Phase 1) (No Repeat)');

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3985);
INSERT INTO `smart_scripts` VALUES
(3985, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Grandpa Vishas - On Respawn - Set Event Phase 1'),
(3985, 0, 1, 0, 2, 1, 100, 1, 1, 15, 0, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Grandpa Vishas - Between 1-15% Health - Flee For Assist (Phase 1) (No Repeat)');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
