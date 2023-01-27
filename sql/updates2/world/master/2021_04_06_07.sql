-- DB update 2021_04_06_06 -> 2021_04_06_07
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_06_06';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_06_06 2021_04_06_07 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617688058640897400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617688058640897400');

UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=9000, `event_param3`=26000, `event_param4`=30000, `action_param1`=6016, `comment`='Dabyrie Laborer - In Combat - Cast Pierce Armor' WHERE  `entryorguid`=2582 AND `source_type`=0 AND `id`=0 AND `link`=0;


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
