-- DB update 2021_02_18_01 -> 2021_02_21_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_18_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_18_01 2021_02_21_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613517719180332000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613517719180332000');
UPDATE `creature` SET `position_x` = -1201.63, `position_y` = -3099.24, `position_z` = 94.8781 WHERE (`guid` = 20720);
-- his guards https://www.youtube.com/watch?v=pJm-Ja82IJM --
UPDATE `creature` SET `position_x` = -1198.8, `position_y` = -3096.75, `position_z` = 94.5592 WHERE (`guid` = 20588);
UPDATE `creature` SET `position_x` = -1198.92, `position_y` = -3101.53, `position_z` = 94.8262 WHERE (`guid` = 14007);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
