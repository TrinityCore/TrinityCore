-- DB update 2021_02_06_00 -> 2021_02_06_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_06_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_06_00 2021_02_06_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612101065652299500'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612101065652299500');

UPDATE `page_text` SET `Text` = "L. F. has ordered increased aggression against the fools in the Alliance.  Below is a list of materials needed for an important mission against Southshore:$B$B1 week travel rations for 20 men$B20 black night suits$B20 pairs new shoes$B25 new swords$B30 throwing knives$B20 black masks$B10 vials inflammatory oil$B50 doses paralytic poison$B5 stolen Southshore guard uniforms, if available$B100 silver coins$B$B--Baron V.$BQuartermaster" WHERE `ID` = 371;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
