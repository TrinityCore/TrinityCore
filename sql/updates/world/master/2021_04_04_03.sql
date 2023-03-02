-- DB update 2021_04_04_02 -> 2021_04_04_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_04_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_04_02 2021_04_04_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617306326870988315'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617306326870988315');

-- Redridge Mountains
UPDATE `gameobject` SET `position_x`=-9200.57, `position_y`=-2441.51, `position_z`=60.5342 WHERE `guid`=5236;
UPDATE `gameobject` SET `position_x`=-8999.95, `position_y`=-3221.55, `position_z`=112.057 WHERE `guid`=4755;
UPDATE `gameobject` SET `position_x`=-9001.20, `position_y`=-3207.21, `position_z`=111.948 WHERE `guid`=5746;
UPDATE `gameobject` SET `position_x`=-9041.66, `position_y`=-3307.45, `position_z`=107.945 WHERE `guid`=5199;
UPDATE `gameobject` SET `position_x`=-8923.28, `position_y`=-2651.38, `position_z`=134.326 WHERE `guid`=5637;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
