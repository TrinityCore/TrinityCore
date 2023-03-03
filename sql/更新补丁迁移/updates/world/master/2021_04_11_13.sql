-- DB update 2021_04_11_12 -> 2021_04_11_13
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_11_12';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_11_12 2021_04_11_13 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617779221786870600'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617779221786870600');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 12818;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 12818);
INSERT INTO `smart_scripts` VALUES
(12818, 0, 0, 0, 19, 0, 100, 0, 6482, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 48166, 178147, 1, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Quest \'Freedom to Ruul\' Taken - Activate Gameobject'),
(12818, 0, 1, 0, 19, 0, 100, 0, 6482, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Quest \'Freedom to Ruul\' Taken - Set Reactstate Aggressive'),
(12818, 0, 2, 0, 19, 0, 100, 0, 6482, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Quest \'Freedom to Ruul\' Taken - Set Event Phase 1'),
(12818, 0, 3, 0, 19, 0, 100, 0, 6482, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Quest \'Freedom to Ruul\' Taken - Set Run Off'),
(12818, 0, 4, 0, 1, 1, 100, 1, 100, 100, 0, 0, 0, 53, 0, 12818, 0, 6482, 10000, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - Out of Combat - Start Waypoint (Phase 1) (No Repeat)'),
(12818, 0, 5, 0, 1, 1, 100, 1, 3100, 3100, 0, 0, 0, 54, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - Out of Combat - Pause Waypoint (Phase 1) (No Repeat)'),
(12818, 0, 6, 0, 1, 1, 100, 1, 3100, 3100, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 3339.1, -693.613, 162.218, 1.14192, 'Ruul Snowhoof - Out of Combat - Set Orientation 1.14192 (Phase 1) (No Repeat)'),
(12818, 0, 7, 0, 1, 1, 100, 1, 3150, 3150, 0, 0, 0, 1, 0, 1000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - Out of Combat - Say Line 0 (Phase 1) (No Repeat)'),
(12818, 0, 8, 0, 1, 1, 100, 1, 5000, 5000, 0, 0, 0, 3, 0, 29421, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - Out of Combat - Morph To Model 29421 (Phase 1) (No Repeat)'),
(12818, 0, 9, 0, 1, 1, 100, 1, 5000, 5000, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - Out of Combat - Set Run On (Phase 1) (No Repeat)'),
(12818, 0, 10, 0, 60, 1, 100, 1, 50000, 50000, 0, 0, 0, 12, 3921, 7, 60000, 1, 1, 0, 18, 10, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Update - Summon Creature \'Thistlefur Ursa\' (Phase 1) (No Repeat)'),
(12818, 0, 11, 0, 60, 1, 100, 1, 54000, 54000, 0, 0, 0, 12, 3922, 7, 60000, 1, 1, 0, 18, 10, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Update - Summon Creature \'Thistlefur Totemic\' (Phase 1) (No Repeat)'),
(12818, 0, 12, 0, 60, 1, 100, 1, 58000, 58000, 0, 0, 0, 12, 3926, 7, 60000, 1, 1, 0, 18, 10, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Update - Summon Creature \'Thistlefur Pathfinder\' (Phase 1) (No Repeat)'),
(12818, 0, 13, 0, 60, 1, 100, 1, 120000, 120000, 0, 0, 0, 12, 3921, 7, 60000, 1, 1, 0, 18, 10, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Update - Summon Creature \'Thistlefur Ursa\' (Phase 1) (No Repeat)'),
(12818, 0, 14, 0, 60, 1, 100, 1, 124000, 124000, 0, 0, 0, 12, 3922, 7, 60000, 1, 1, 0, 18, 10, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Update - Summon Creature \'Thistlefur Totemic\' (Phase 1) (No Repeat)'),
(12818, 0, 15, 0, 60, 1, 100, 1, 128000, 128000, 0, 0, 0, 12, 3926, 7, 60000, 1, 1, 0, 18, 10, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Update - Summon Creature \'Thistlefur Pathfinder\' (Phase 1) (No Repeat)'),
(12818, 0, 16, 17, 58, 1, 100, 1, 15, 0, 0, 0, 0, 1, 1, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Waypoint Finished - Say Line 1 (Phase 1) (No Repeat)'),
(12818, 0, 17, 0, 61, 0, 100, 0, 15, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Waypoint Finished - Demorph (Phase 1) (No Repeat)'),
(12818, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ruul Snowhoof - On Respawn - Set Reactstate Passive');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
