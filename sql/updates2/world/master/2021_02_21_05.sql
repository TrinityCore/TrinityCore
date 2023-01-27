-- DB update 2021_02_21_04 -> 2021_02_21_05
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_21_04';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_21_04 2021_02_21_05 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613843733957350900'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613843733957350900');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 10216;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 10216);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10216, 0, 0, 0, 62, 0, 100, 0, 2562, 1, 0, 0, 0, 85, 7733, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Gubber Blump - On Gossip Option 1 Selected - Invoker Cast \'Apprentice Fishing\''),
(10216, 0, 1, 0, 62, 0, 100, 0, 2562, 1, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Gubber Blump - On Gossip Option 1 Selected - Close Gossip');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` = 2562) AND (`SourceEntry` = 1) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 47) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 1141) AND (`ConditionValue2` = 8) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 2562, 1, 0, 0, 47, 0, 1141, 8, 0, 0, 0, 0, '', 'Gubber Blump - Quest: The Family and the Fishing Pole - Gossip Condition');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` = 2562) AND (`SourceEntry` = 1) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 7) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 356) AND (`ConditionValue2` = 1) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 2562, 1, 0, 0, 7, 0, 356, 1, 0, 1, 0, 0, '', 'Gubber Blump - Quest: The Family and the Fishing Pole - Gossip Condition Hide Gossip');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
