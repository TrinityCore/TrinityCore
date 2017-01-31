-- The View from Down Here (28868) quest script
DELETE FROM `conditions` WHERE `SourceEntry` = 93773;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 93773, 0, 0, 31, 1, 3, 41251, 0, 0, 0, 0, '', 'Equalize Viewpoint can target only Frostmane Builder');
DELETE FROM `creature_text` WHERE `entry` = 41251;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(41251, 0, 0, 'Can''t... lift... tools...', 12, 0, 100, 0, 0, 0, 'Frostmane Builder', 0),
(41251, 0, 1, 'No make me small!', 12, 0, 100, 0, 0, 0, 'Frostmane Builder', 0),
(41251, 0, 2, 'What you do to me?', 12, 0, 100, 0, 0, 0, 'Frostmane Builder', 0),
(41251, 0, 3, 'Why everyone else get so big?', 12, 0, 100, 0, 0, 0, 'Frostmane Builder', 0),
(41251, 1, 0, 'Take curse away!', 12, 0, 100, 0, 0, 0, 'Frostmane Builder', 0);
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 41251;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (41251, 4125100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(41251, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 17, 173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Builder - on spawn - set emote state (173)'),
(41251, 0, 1, 0, 8, 0, 100, 1, 93773, 0, 0, 0, 80, 4125100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Builder - on spell hit (93773) - run actionlist'),
(4125100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Builder - actionlist - set emote state (26)'),
(4125100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Builder - actionlist - face player'),
(4125100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 50606, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Builder - actionlist - give quest credit (50606)'),
(4125100, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Builder - actionlist - say text 0'),
(4125100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 89, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Builder - actionlist - set random movement'),
(4125100, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Builder - actionlist - say text 1'),
(4125100, 9, 6, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Builder - actionlist - despawn');
