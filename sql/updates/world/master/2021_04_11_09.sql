-- DB update 2021_04_11_08 -> 2021_04_11_09
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_11_08';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_11_08 2021_04_11_09 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617732568440189700'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617732568440189700');

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 8996);
INSERT INTO `smart_scripts` VALUES
(8996, 0, 0, 0, 1, 0, 100, 1, 100, 100, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Voidwalker Minion - Out of Combat - Set Reactstate Aggressive (No Repeat)'),
(8996, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 4000, 6000, 0, 11, 33914, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Voidwalker Minion - In Combat - Cast \'Shadowstrike\''),
(8996, 0, 2, 3, 74, 0, 100, 0, 1, 99, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 3198, 5, 0, 0, 0, 0, 0, 0, 'Voidwalker Minion - On Friendly Between 1-99% Health - Start Attacking'),
(8996, 0, 3, 0, 61, 0, 100, 0, 1, 99, 0, 0, 0, 49, 1, 0, 0, 0, 0, 0, 18, 32, 0, 0, 0, 0, 0, 0, 0, 'Voidwalker Minion - On Friendly Between 1-99% Health - Start Attacking'),
(8996, 0, 4, 3, 74, 0, 100, 0, 1, 99, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 3728, 5, 0, 0, 0, 0, 0, 0, 'Voidwalker Minion - On Friendly Between 1-99% Health - Start Attacking');

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 12922);
INSERT INTO `smart_scripts` VALUES
(12922, 0, 0, 0, 0, 0, 100, 0, 1000, 2000, 2300, 2800, 0, 11, 20801, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Imp Minion - In Combat - Cast \'Firebolt\''),
(12922, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Imp Minion - On Just Summoned - Set Reactstate Aggressive'),
(12922, 0, 2, 3, 74, 0, 100, 0, 1, 99, 100, 20000, 0, 49, 0, 0, 0, 0, 0, 0, 19, 3725, 5, 0, 0, 0, 0, 0, 0, 'Imp Minion - On Friendly Between 1-99% Health - Start Attacking'),
(12922, 0, 3, 0, 61, 0, 100, 0, 1, 99, 100, 20000, 0, 49, 0, 0, 0, 0, 0, 0, 18, 33, 0, 0, 0, 0, 0, 0, 0, 'Imp Minion - On Friendly Between 1-99% Health - Start Attacking');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
