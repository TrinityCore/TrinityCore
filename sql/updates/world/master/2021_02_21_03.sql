-- DB update 2021_02_21_02 -> 2021_02_21_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_21_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_21_02 2021_02_21_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613748522727071400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613748522727071400');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 3701;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3701);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3701, 0, 0, 1, 62, 0, 100, 0, 21210, 1, 0, 0, 0, 56, 7586, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Tharnariun Treetender - On Gossip Option 1 Selected - Add Item \'Tharnariun\'s Hope\' 1 Time'),
(3701, 0, 1, 0, 61, 0, 100, 0, 21210, 1, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Tharnariun Treetender - On Gossip Option 1 Selected - Close Gossip'),
(3701, 0, 2, 0, 20, 0, 100, 0, 2118, 0, 0, 0, 0, 80, 370100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tharnariun Treetender - On Quest \'Plagued Lands\' Finished - Run Script');

DELETE FROM `smart_scripts` WHERE (`source_type` = 9 AND `entryorguid` = 370100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(370100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tharnariun Treetender - Actionlist - Remove Npc Flags Gossip & Questgiver'),
(370100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 11836, 0, 0, 0, 0, 0, 0, 0, 'Tharnariun Treetender - Actionlist - Set Orientation Closest Creature \'Captured Rabid Thistle Bear\''),
(370100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tharnariun Treetender - Actionlist - Say Line 0'),
(370100, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 11, 9457, 2, 0, 0, 0, 0, 19, 11836, 7, 0, 0, 0, 0, 0, 0, 'Tharnariun Treetender - Actionlist - Cast \'Tharnariun`s Heal\''),
(370100, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 11836, 0, 0, 0, 0, 0, 0, 0, 'Tharnariun Treetender - Actionlist - Set Data 2 2'),
(370100, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 82, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tharnariun Treetender - Actionlist - Add Npc Flags Gossip & Questgiver');

DELETE FROM `gossip_menu_option` WHERE (`MenuID` = 21210);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(21210, 1, 0, 'Tharnariun, I have lost the trap. Could you please give me another?', 9431, 1, 3, 0, 0, 0, 0, '', 0, 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` = 21210) AND (`SourceEntry` = 1) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 47) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 2118) AND (`ConditionValue2` = 8) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 21210, 1, 0, 0, 47, 0, 2118, 8, 0, 0, 0, 0, '', 'Condition for the gossip_menu_option of the Plagued Lands quest');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceGroup` = 1) AND (`SourceEntry` = 9457) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 3701) AND (`ConditionValue3` = 0);

DELETE FROM `spell_dbc` WHERE (`ID` = 9457);
INSERT INTO `spell_dbc` VALUES
('9457','0','0','0','0','0','0','268435456','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','3','0','0','0','0','0','0','101','0','0','0','0','0','0','0','0','0','0','11','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','3','0','0','0','0','0','0','0','0','0','0','0','0','0','0','25','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','58','0','13','0','0','Tharnariun''s Heal','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','16712190','','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','16712190','','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','16712190','Tharnariun''s Heal','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','16712190','0','0','1500','0','0','0','0','0','0','1','0','0','1065353216','1065353216','1065353216','0','0','0','0','0','0','8','0','0','0','0','0','0','0','0');

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 2164);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2164, 0, 1, 0, 38, 0, 100, 1, 1, 1, 0, 0, 0, 80, 216400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - On Data Set 1 1 - Run Script (No Repeat)'),
(2164, 0, 2, 0, 8, 0, 100, 0, 9457, 0, 500, 500, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - On Spellhit \'Tharnariun`s Heal\' - Despawn In 2000 ms');

DELETE FROM `smart_scripts` WHERE (`source_type` = 9 AND `entryorguid` = 216400);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(216400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - Actionlist - Set Home Position'),
(216400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - Actionlist - Evade'),
(216400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 11836, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - Actionlist - Quest Credit \'null\''),
(216400, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 29, 0, 180, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - Actionlist - Start Follow [unsupported target type]'),
(216400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 36, 11836, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - Actionlist - Update Template To \'Captured Rabid Thistle Bear\'');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
