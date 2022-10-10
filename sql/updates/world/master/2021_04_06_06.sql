-- DB update 2021_04_06_05 -> 2021_04_06_06
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_06_05';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_06_05 2021_04_06_06 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617686115809585900'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617686115809585900');

-- They did not have stealth in classic https://youtu.be/4Hlaez09riY?t=90
-- No changes during TBC or WOLTK, until WoD https://youtu.be/JVQzZmGWjF8?t=16
DELETE FROM `smart_scripts` WHERE `entryorguid`=3566 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=3566;


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
