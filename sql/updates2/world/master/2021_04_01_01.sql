-- DB update 2021_04_01_00 -> 2021_04_01_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_00 2021_04_01_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616536931445376664'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616536931445376664');

-- Stonetalon Mountains herb issue #273
UPDATE `gameobject` SET `position_x`=1600.44, `position_y`=1424.05, `position_z`=210.444 WHERE `guid`=87262;

-- Redridge Mountains herb issue #270 and #261
UPDATE `gameobject` SET `position_x`=-9738.75, `position_y`=-1773.03, `position_z`=53.9976 WHERE `guid`=2904;
UPDATE `gameobject` SET `position_x`=-9773.77, `position_y`=-1747.93, `position_z`=53.0246 WHERE `guid`=1374;
UPDATE `gameobject` SET `position_x`=-9603.99, `position_y`=-1910.21, `position_z`=61.5482 WHERE `guid`=1740;
UPDATE `gameobject` SET `position_x`=-9151.08, `position_y`=-2508.94, `position_z`=117.203 WHERE `guid`=1537;
UPDATE `gameobject` SET `position_x`=-9485.22, `position_y`=-2329.47, `position_z`=69.3981 WHERE `guid`=1497;
UPDATE `gameobject` SET `position_x`=-9160.94, `position_y`=-3029.85, `position_z`=96.2563 WHERE `guid`=1456;

DELETE FROM `gameobject` WHERE `guid` in (3433, 3801, 85463);

DELETE FROM `pool_gameobject` where `guid` in (3433, 3801, 85463);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
