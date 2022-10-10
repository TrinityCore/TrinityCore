-- DB update 2021_04_11_21 -> 2021_04_11_22
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_11_21';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_11_21 2021_04_11_22 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617936479961800600'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617936479961800600');


UPDATE `gameobject` SET `position_x`=1234.406, `position_y`=-4135.120, `position_z`=26.184, `orientation`=0.517706 WHERE `guid`=12381;

UPDATE `gameobject` SET `position_x`=857.312, `position_y`=-4118.451, `position_z`=26.625, `orientation`=2.861797 WHERE `guid`=5361;

-- Silver Vein

UPDATE `gameobject` SET `position_x`=345.075, `position_y`=-3199.625, `position_z`=99.877, `orientation`=4.398968 WHERE `guid`=5756;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
