-- DB update 2021_02_07_03 -> 2021_02_08_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_07_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_07_03 2021_02_08_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612710581998002500'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612710581998002500');

UPDATE `game_event` SET `start_time` = '2016-10-29 01:00:00', `end_time` = '2030-12-31 07:00:00', `description` = 'Stranglethorn Fishing Extravaganza Announce' WHERE `evententry` = 14;
UPDATE `game_event` SET `start_time` = '2016-10-30 15:00:00', `end_time` = '2030-12-31 07:00:00', `holiday` = 301, `description` = 'Stranglethorn Fishing Extravaganza Fishing Pools' WHERE `evententry` = 15;
UPDATE `game_event` SET `start_time` = '2016-10-30 15:00:00', `end_time` = '2030-12-31 07:00:00', `holiday` = 0, `holidayStage` = 0, `description` = 'Stranglethorn Fishing Extravaganza Turn-ins' WHERE `evententry` = 62;

UPDATE `game_event_creature` SET `EventEntry` = 62 WHERE `EventEntry` = 15 AND `guid` IN (54687,54688,203521);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
