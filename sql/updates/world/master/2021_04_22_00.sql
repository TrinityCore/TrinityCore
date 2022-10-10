-- DB update 2021_04_21_00 -> 2021_04_22_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_21_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_21_00 2021_04_22_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1619032787077995400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1619032787077995400');

-- Despawn minions on death
DELETE FROM `smart_scripts` WHERE `entryorguid`=12203 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(12203, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 11, 11783, 100, 0, 0, 0, 0, 0, 0, 'Landslide - On death - Despawn minions');

-- Use correct spell for Knock Away
UPDATE `smart_scripts` SET `action_param1`=10101 WHERE `entryorguid`=12203 AND `source_type`=0 AND `id`=1 AND `link`=0;


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
