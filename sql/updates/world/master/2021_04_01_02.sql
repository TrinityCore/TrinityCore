-- DB update 2021_04_01_01 -> 2021_04_01_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_01 2021_04_01_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616620260846086881'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616620260846086881');

-- Alterac Mountains - Chromie #272
DELETE FROM `gameobject` where `guid` in (8638, 8639, 9190, 32194, 32203, 33141, 9141, 35390, 3435, 8063);
DELETE FROM `gameobject` where `guid` in (7716, 35379, 3332, 8989, 9004, 9171, 32211, 7832, 8927, 7841);
DELETE FROM `gameobject` where `guid` in (9057, 8771, 7773, 7732, 7731, 7575, 7423, 7436, 7407, 7551);
DELETE FROM `gameobject` where `guid` in (7549, 7548, 7515, 7512, 7529, 7474, 7697, 32693);

UPDATE `gameobject` SET `position_x`=606.533, `position_y`=-745.792, `position_z`=175.907 WHERE `guid`=8988;
UPDATE `gameobject` SET `position_x`=822.100, `position_y`=-723.680, `position_z`=194.222 WHERE `guid`=8990;
UPDATE `gameobject` SET `position_x`=1109.57, `position_y`=-454.509, `position_z`=68.9403 WHERE `guid`=8769;

-- Badlands - Chromie #257
UPDATE `gameobject` SET `position_x`=-6064.50, `position_y`=-3238.57, `position_z`=259.058 WHERE `guid`=11477;
DELETE FROM `gameobject` where `guid` in (8114, 9003);
DELETE FROM `pool_gameobject` where `guid` in (8114, 9003);

-- The Barrens - Chromie #249
DELETE FROM `gameobject` where `guid` in (13573, 13585, 13577, 13586, 13687, 13358, 65123, 2350, 86281, 13372);
DELETE FROM `gameobject` where `guid` in (63431, 13578, 31976, 13689, 14446, 33549, 13559, 13574, 13548, 14455);
DELETE FROM `gameobject` where `guid` in (13684, 14463, 14459, 63424, 13589, 13571, 14201, 13702);
DELETE FROM `pool_gameobject` where `guid`=2350;
UPDATE `gameobject` SET `position_x`=-1119.61, `position_y`=-2150.05, `position_z`=81.8622 WHERE `guid`=983;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
