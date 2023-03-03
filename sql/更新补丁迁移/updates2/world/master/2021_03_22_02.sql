-- DB update 2021_03_22_01 -> 2021_03_22_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_22_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_22_01 2021_03_22_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616369823354830255'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616369823354830255');

-- Update Incorrect spawn of Tin Vein in the Barrens
UPDATE `gameobject` set `position_z`=94.7714 where `guid` = 5649;

-- Delete wrong spam Silver Vein in Ashenvale
DELETE FROM `gameobject` WHERE `guid` in (5708, 5710, 5711, 5712, 5713);

-- Swamp of Sorrows fix spawn
DELETE FROM `gameobject` WHERE `guid` in (32756, 6629, 30348);

-- Western Plaguelands fix spawn
DELETE FROM `gameobject` WHERE `guid` in (45552, 45561, 45502, 5816, 7193, 63994, 9641, 5770, 5944);

-- Arathi Hinterlands fix spawn
DELETE FROM `gameobject` WHERE `guid` in (70262, 70263, 70264, 70265, 70266, 70267);
DELETE FROM `gameobject` WHERE `guid` in (63520, 65233);

-- Searing Gorge fix spawn
DELETE FROM `gameobject` WHERE `guid` in (13216, 64839, 56790, 64843, 65291);

-- Delete nonexisting pool_objects in Western Plaguelands underwater
DELETE FROM `pool_gameobject` where `guid` in (70262, 70263, 70264, 70265, 70266, 70267);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
