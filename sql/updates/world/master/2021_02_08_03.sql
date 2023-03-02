-- DB update 2021_02_08_02 -> 2021_02_08_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_08_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_08_02 2021_02_08_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612403335049520400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612403335049520400');

-- Fix #4402: Remove quest: "Mending Fences" from list of requirements for "A Spark of Hope" to be available
DELETE FROM conditions
WHERE
	SourceTypeOrReferenceId = 19 -- CONDITON_SOURCE_TYPE_QUEST_AVAILABLE
    AND SourceEntry = 12956 -- Quest: A Spark of Hope
    AND ConditionTypeOrReference = 8 -- REQUIRES_QUEST_REWARDED
    AND ConditionValue1 = 12915; -- Quest: Mending Fences

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
