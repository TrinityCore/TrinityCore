-- DB update 2021_02_15_01 -> 2021_02_15_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_15_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_15_01 2021_02_15_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613342086114684300'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613342086114684300');

/* Add creature_text to Arcanist Torseldori (ID 19257) to halt worldserver spam
*/

DELETE FROM `creature_text` WHERE `CreatureID`=19257 AND `GroupID`=0 AND `ID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES (19257, 0, 0, 'INCOMING! Do not let them through! Focus fire! NOW, NOW, NOW!', 12, 0, 100, 0, 0, 0, 16395, 0, 'Arcanist Torseldori');


/* Set Dalaran Inscription Vendors to only greet PLAYERS upon entering their line of sight to halt worldserver spam
*/

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 33027;

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 33027) AND (`source_type` = 0) AND (`id` IN (0));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(33027, 0, 0, 0, 10, 0, 100, 0, 1, 20, 30000, 120000, 1, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Jessica Sellers - OOC LOS - Say Line');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28723;

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 28723) AND (`source_type` = 0) AND (`id` IN (0));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28723, 0, 0, 0, 10, 0, 100, 0, 1, 20, 30000, 120000, 1, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Larana Drome - OOC LOS - Say Line');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
