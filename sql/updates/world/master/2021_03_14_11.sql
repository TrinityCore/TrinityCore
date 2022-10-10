-- DB update 2021_03_14_10 -> 2021_03_14_11
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_14_10';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_14_10 2021_03_14_11 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615647120285678400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615647120285678400');

UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = 177524;

DELETE FROM `smart_scripts` WHERE (`source_type` = 1 AND `entryorguid` = 177524);
INSERT INTO `smart_scripts` VALUES
(177524, 1, 0, 0, 60, 0, 100, 0, 500, 500, 3500, 3500, 0, 75, 17775, 0, 0, 0, 0, 0, 18, 10, 0, 0, 0, 0, 0, 0, 0, 'Bubbling Fissure - On Update - Add Aura \'Air Bubbles\'');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
