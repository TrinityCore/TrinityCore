-- DB update 2021_03_11_05 -> 2021_03_11_06
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_11_05';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_11_05 2021_03_11_06 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615362796749970694'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615362796749970694');

-- Booty Bay fishing, add description
UPDATE `pool_gameobject` SET `description`="Fishing pool - Booty Bay" WHERE `pool_entry`=268;

-- Change respawn of items in pool
UPDATE `gameobject` SET `spawntimesecs`=3600 WHERE `guid` IN (50320,64627);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
