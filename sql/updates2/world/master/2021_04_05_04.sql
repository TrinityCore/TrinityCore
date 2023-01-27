-- DB update 2021_04_05_03 -> 2021_04_05_04
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_05_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_05_03 2021_04_05_04 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617596593417183200'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617596593417183200');

-- harvest watcher 36 -> 43
UPDATE `creature_loot_template` SET `Chance`=43 WHERE `Entry`=114 AND `Item`=732;
-- harvest reaper 40 -> 43
UPDATE `creature_loot_template` SET `Chance`=43 WHERE `Entry`=115 AND `Item`=732;
-- rusty harvest golem 28.0247 -> 37
UPDATE `creature_loot_template` SET `Chance`=37 WHERE `Entry`=480 AND `Item`=732;
-- harvest golem 33-> 40
UPDATE `creature_loot_template` SET `Chance`=40 WHERE `Entry`=36 AND `Item`=732;
-- foe reaper 4000 30 -> 43
UPDATE `creature_loot_template` SET `Chance`=43 WHERE `Entry`=573 AND `Item`=732;


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
