-- DB update 2021_04_11_17 -> 2021_04_11_18
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_11_17';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_11_17 2021_04_11_18 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617902440529783360'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617902440529783360');

-- Remove Flesh Piercer from Reference Table
DELETE FROM `reference_loot_template` WHERE `Entry` = 24068 AND `Item` = 3336;

-- Adds Flesh Piercer to Daggerspine Shorestalkers and Screamers loot tables
INSERT INTO `creature_loot_template` VALUES
(2368, 3336, 0, 1.5, 0, 1, 0, 1, 1, "Daggerspine Shorestalker - Flesh Piercer"),
(2370, 3336, 0, 1.1, 0, 1, 0, 1, 1, "Daggerspine Screamer - Flesh Piercer");

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
