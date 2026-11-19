-- Paint It Black (26342) quest script
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 79781; 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 79781, 0, 0, 31, 1, 3, 42291, 0, 0, 0, 0, '', 'Blind Sentry can target only Crushcog Sentry-Bot');
DELETE FROM `creature_text` WHERE `entry` = 42291;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(42291, 0, 0, 'Optical sensor malfunction detected! Shutting down...',  12, 0, 100, 0, 0, 0, 'Crushcog Sentry-Bot - hit by Blind Sentry', 0);
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 42291;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (42291, 4229100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42291, 0, 0, 0, 8, 0, 100, 1, 79781, 0, 0, 0, 80, 4229100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Crushcog Sentry-Bot - on spell hit (79781) - run actionlist'),
(4229100, 9, 0, 0, 0, 0, 100, 0, 500, 500, 0, 0, 33, 42796, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Crushcog Sentry-Bot - actionlist - give quest credit (42796)'),
(4229100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Crushcog Sentry-Bot - actionlist - set react state to passive'),
(4229100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Crushcog Sentry-Bot - actionlist - say text 0'),
(4229100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Crushcog Sentry-Bot - actionlist - move random'),
(4229100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Crushcog Sentry-Bot - actionlist - die');
