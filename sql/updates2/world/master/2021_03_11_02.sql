-- DB update 2021_03_11_01 -> 2021_03_11_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_11_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_11_01 2021_03_11_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615210246361880600'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615210246361880600');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 7235;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 7235);
INSERT INTO `smart_scripts` VALUES
(7235, 0, 0, 0, 0, 0, 100, 0, 2000, 2000, 5000, 5000, 0, 11, 5177, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Gnarlpine Mystic - In Combat - Cast \'Wrath\'');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
