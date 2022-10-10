-- DB update 2021_03_20_03 -> 2021_03_20_04
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_20_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_20_03 2021_03_20_04 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615883540984618200'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615883540984618200');

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 11711);
INSERT INTO `smart_scripts` VALUES
(11711, 0, 0, 0, 19, 0, 100, 0, 5713, 0, 0, 0, 0, 80, 1171100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sentinel Aynasha - On Quest \'One Shot.  One Kill.\' Taken - Run Script'),
(11711, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sentinel Aynasha - On Reset - Set Sheath Ranged'),
(11711, 0, 2, 0, 0, 0, 100, 0, 500, 500, 3000, 3000, 0, 11, 75, 66, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Sentinel Aynasha - In Combat - Cast \'Auto Shot\'');

DELETE FROM `smart_scripts` WHERE (`source_type` = 9 AND `entryorguid` = 1171100);
INSERT INTO `smart_scripts` VALUES
(1171100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sentinel Aynasha - Actionlist - Say Line 0'),
(1171100, 9, 1, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 0, 12, 11713, 4, 30000, 0, 1, 0, 8, 0, 0, 0, 0, 4369, -51, 86.68, 5.6, 'Sentinel Aynasha - Actionlist - Summon Creature \'Blackwood Tracker\''),
(1171100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 12, 11713, 4, 30000, 0, 1, 0, 8, 0, 0, 0, 0, 4374, -48, 85.2, 5.4, 'Sentinel Aynasha - Actionlist - Summon Creature \'Blackwood Tracker\''),
(1171100, 9, 3, 0, 0, 0, 100, 0, 50000, 50000, 0, 0, 0, 12, 11713, 4, 30000, 0, 1, 0, 8, 0, 0, 0, 0, 4369, -51, 86.68, 5.6, 'Sentinel Aynasha - Actionlist - Summon Creature \'Blackwood Tracker\''),
(1171100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 12, 11713, 4, 30000, 0, 1, 0, 8, 0, 0, 0, 0, 4374, -48, 85.2, 5.4, 'Sentinel Aynasha - Actionlist - Summon Creature \'Blackwood Tracker\''),
(1171100, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 12, 11713, 4, 30000, 0, 1, 0, 8, 0, 0, 0, 0, 4361, -43, 84.86, 5.4, 'Sentinel Aynasha - Actionlist - Summon Creature \'Blackwood Tracker\''),
(1171100, 9, 6, 0, 0, 0, 100, 0, 40000, 40000, 0, 0, 0, 12, 11714, 4, 30000, 0, 1, 0, 8, 0, 0, 0, 0, 4361, -43, 84.86, 5.4, 'Sentinel Aynasha - Actionlist - Summon Creature \'Marosh the Devious\''),
(1171100, 9, 7, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sentinel Aynasha - Actionlist - Say Line 2'),
(1171100, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 26, 5713, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, 0, 'Sentinel Aynasha - Actionlist - Quest Credit \'One Shot.  One Kill.\''),
(1171100, 9, 9, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sentinel Aynasha - Actionlist - Say Line 3'),
(1171100, 9, 10, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sentinel Aynasha - Actionlist - Say Line 4');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
