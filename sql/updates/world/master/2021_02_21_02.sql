-- DB update 2021_02_21_01 -> 2021_02_21_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_21_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_21_01 2021_02_21_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613600380697311600'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613600380697311600');
UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = 180771;
DELETE FROM `smart_scripts` WHERE (`entryorguid` = 180771) AND (`source_type` = 1) AND (`id` IN (1, 2, 3, 4, 5, 6));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(180771, 1, 1, 0, 60, 0, 100, 0, 1000, 1000, 15000, 15000, 0, 11, 26351, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Firework Launcher - SE: Update + SA: Cast Spell: Rocket BLUE BIG on Self'),
(180771, 1, 2, 0, 60, 0, 100, 0, 2000, 2000, 15000, 15000, 0, 11, 26352, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Firework Launcher - SE: Update + SA: Cast Spell: Rocket GREEN BIG on Self'),
(180771, 1, 3, 0, 60, 0, 100, 0, 3000, 3000, 15000, 15000, 0, 11, 26353, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Firework Launcher - SE: Update + SA: Cast Spell: Rocket PURPLE BIG on Self'),
(180771, 1, 4, 0, 60, 0, 100, 0, 4000, 4000, 15000, 15000, 0, 11, 26354, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Firework Launcher - SE: Update + SA: Cast Spell: Rocket RED BIG on Self'),
(180771, 1, 5, 0, 60, 0, 100, 0, 5000, 5000, 15000, 15000, 0, 11, 26355, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Firework Launcher - SE: Update + SA: Cast Spell: Rocket WHITE BIG on Self'),
(180771, 1, 6, 0, 60, 0, 100, 0, 6000, 6000, 15000, 15000, 0, 11, 26356, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Firework Launcher - SE: Update + SA: Cast Spell: Rocket YELLOW BIG on Self');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
