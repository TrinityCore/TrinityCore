-- DB update 2021_04_13_03 -> 2021_04_14_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_13_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_13_03 2021_04_14_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1618370524737999000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1618370524737999000');

UPDATE `smart_scripts` SET `action_type`=39, `action_param1`=40, `comment`='Deviate Guardian - Between 0-15% Health - Call for help' WHERE `entryorguid`=3637 AND `source_type`=0 AND `id`=0 AND `link`=1;


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
