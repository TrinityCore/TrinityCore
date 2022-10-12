-- DB update 2021_02_12_04 -> 2021_02_12_05
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_12_04';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_12_04 2021_02_12_05 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612566366687490200'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612566366687490200');

-- Relocate Strange Lockbox and add Bubbly Fissure near it.

UPDATE `gameobject` SET `position_x` = 842.715, `position_y` = 2208.32, `position_z` = -136.765 WHERE `guid` = 27813;
DELETE FROM `gameobject` WHERE (`id` = 177524) AND (`guid` = 2134520);
INSERT INTO `gameobject` (`guid`, `id`, `position_x`, `position_y`, `position_z`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(2134520, 177524, 838.26, 2208.14, -136.906, -0.753998, -0.656877, 900, 100, 1);


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
