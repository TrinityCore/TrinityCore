-- DB update 2021_04_06_08 -> 2021_04_06_09
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_06_08';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_06_08 2021_04_06_09 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617743115631291700'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617743115631291700');

UPDATE `smart_scripts` SET `event_chance`=100, `event_param2`=50, `event_param3`=9000, `event_param4`=15000, `comment`='Elder Timberling - Between 0-50% Health - Cast Healing Wave' WHERE `entryorguid`=2030 AND `source_type`=0 AND `id`=2 AND `link`=0;


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
