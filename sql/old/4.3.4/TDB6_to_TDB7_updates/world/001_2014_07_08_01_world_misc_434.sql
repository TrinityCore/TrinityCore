-- See to the Survivors (27671) quest script
DELETE FROM `conditions` WHERE `SourceEntry` = 86264;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 86264, 0, 0, 31, 1, 3, 46268, 0, 0, 0, 0, '', 'Activate Teleport Beacon can target only Survivor');

DELETE FROM `creature_text` WHERE `entry` = 46268;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(46268, 0, 0, 'Don''t let them eat me!', 12, 0, 100, 0, 0, 0, 'Survivor', 0),
(46268, 0, 1, 'Help! I''m too weak to make it on my own.', 12, 0, 100, 0, 0, 0, 'Survivor', 0),
(46268, 0, 2, 'I don''t want to die down here!', 12, 0, 100, 0, 0, 0, 'Survivor', 0),
(46268, 0, 3, 'I''m really going to die down here, aren''t I?', 12, 0, 100, 0, 0, 0, 'Survivor', 0),
(46268, 0, 4, 'I''m too young to die!', 12, 0, 100, 0, 0, 0, 'Survivor', 0),
(46268, 0, 5, 'Please help me!', 12, 0, 100, 0, 0, 0, 'Survivor', 0),
(46268, 0, 6, 'Some help! Anyone!', 12, 0, 100, 0, 0, 0, 'Survivor', 0);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 46268;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 46268;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(46268, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 17, 431, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Survivor - on spawn - set emote state (431)'),
(46268, 0, 1, 0, 1, 0, 10, 0, 60000, 300000, 60000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Survivor - linked - say text 0 (10% chance)'),
(46268, 0, 2, 3, 8, 0, 100, 1, 86264, 0, 0, 0, 17, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Survivor - on spell hit (86264) - set emote state (26)'),
(46268, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 33, 46268, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Survivor - linked - give quest credit (46268)'),
(46268, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Survivor - linked - add not selectable flag (33554432)'),
(46268, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Survivor - linked - despawn after 5 seconds');
