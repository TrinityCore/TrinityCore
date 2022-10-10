-- DB update 2021_03_25_00 -> 2021_03_27_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_25_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_25_00 2021_03_27_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616747334374476238'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616747334374476238');

-- Edwin VanCleef encounter
DELETE FROM `smart_scripts` WHERE (`entryorguid` = 639) AND (`source_type` = 0) AND (`id` IN (0, 3, 4, 5, 6, 7, 8, 9, 10));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(639, 0, 0, 0, 1, 0, 100, 257, 1000, 1000, 0, 0, 0, 11, 674, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Edwin VanCleef - Out of Combat - Cast \'Dual Wield\' (No Repeat)'),
(639, 0, 3, 0, 2, 0, 100, 1, 34, 66, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Edwin VanCleef - Between 34-66% Health - Say Line 1 (No Repeat)'),
(639, 0, 4, 5, 2, 0, 100, 1, 0, 50, 0, 0, 0, 11, 5200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Edwin VanCleef - Between 0-50% Health - Cast \'VanCleef`s Allies\' (No Repeat)'),
(639, 0, 5, 0, 61, 0, 100, 0, 0, 50, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Edwin VanCleef - Between 0-50% Health - Say Line 2 (No Repeat)'),
(639, 0, 6, 0, 2, 0, 100, 1, 0, 33, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Edwin VanCleef - Between 0-33% Health - Say Line 3 (No Repeat)'),
(639, 0, 7, 0, 5, 0, 100, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Edwin VanCleef - On Killed Unit - Say Line 4'),
(639, 0, 8, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Edwin VanCleef - On Just Died - Say Line 5');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
