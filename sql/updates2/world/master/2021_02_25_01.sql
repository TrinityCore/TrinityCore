-- DB update 2021_02_25_00 -> 2021_02_25_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_25_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_25_00 2021_02_25_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613970765283918400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613970765283918400');

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 8996);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8996, 0, 0, 0, 1, 0, 100, 1, 100, 100, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Voidwalker Minion - Out of Combat - Set Reactstate Aggressive (No Repeat)'),
(8996, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 4000, 6000, 0, 11, 33914, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Voidwalker Minion - In Combat - Cast \'Shadowstrike\''),
(8996, 0, 2, 3, 74, 0, 100, 0, 1, 99, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 3198, 4, 0, 0, 0, 0, 0, 0, 'Voidwalker Minion - On Friendly Between 1-99% Health - Start Attacking'),
(8996, 0, 3, 0, 61, 0, 100, 0, 1, 99, 0, 0, 0, 49, 1, 0, 0, 0, 0, 0, 18, 32, 0, 0, 0, 0, 0, 0, 0, 'Voidwalker Minion - On Friendly Between 1-99% Health - Start Attacking');

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3198);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3198, 0, 0, 0, 1, 0, 100, 1, 100, 100, 0, 0, 0, 11, 12746, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Burning Blade Apprentice - Out of Combat - Cast \'Summon Voidwalker\' (No Repeat)'),
(3198, 0, 1, 0, 0, 0, 100, 0, 100, 100, 2400, 3800, 0, 11, 20791, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Burning Blade Apprentice - In Combat - Cast \'Shadow Bolt\''),
(3198, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Burning Blade Apprentice - Between 0-15% Health - Flee For Assist (No Repeat)');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
