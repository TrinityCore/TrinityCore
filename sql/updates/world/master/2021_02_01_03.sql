-- DB update 2021_02_01_02 -> 2021_02_01_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_01_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_01_02 2021_02_01_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1610739863539733975'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1610739863539733975');

-- "Chest of The Seven" from Blackrock Depths should spawn in a different position
UPDATE `gameobject` SET `position_x`=1265.55, `position_y`=-284.421, `position_z`=-78.2193, `orientation`=0.786698, `rotation2`=-0.383284, `rotation3`=-0.923631 WHERE `guid`=67872;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
