-- The Public Servant (433) quest script
DELETE FROM `conditions` WHERE `SourceEntry` = 77819;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 77819, 0, 0, 31, 1, 3, 41671, 0, 0, 0, 0, '', 'Give Rune of Return can target only Trapped Miner');
DELETE FROM `creature_text` WHERE `entry` = 41671;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(41671, 0, 0, 'I can''t wait to get home to my family. Thank you, stranger.', 12, 0, 100, 0, 0, 0, 'Trapped Miner - rescued', 0),
(41671, 0, 1, 'I thought I would die down here.', 12, 0, 100, 0, 0, 0, 'Trapped Miner - rescued', 0),
(41671, 0, 2, 'I thought they were going to tear me apart!', 12, 0, 100, 0, 0, 0, 'Trapped Miner - rescued', 0),
(41671, 0, 3, 'Light bless you, stranger. You''ve saved me!', 12, 0, 100, 0, 0, 0, 'Trapped Miner - rescued', 0),
(41671, 0, 4, 'Thank you!', 12, 0, 100, 0, 0, 0, 'Trapped Miner - rescued', 0),
(41671, 0, 5, 'You''re the best thing I''ve seen since the troggs showed up!', 12, 0, 100, 0, 0, 0, 'Trapped Miner - rescued', 0);
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 41671;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (41671, 4167100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(41671, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 17, 431, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Trapped Miner - on spawn - set emote state (431)'),
(41671, 0, 1, 0, 8, 0, 100, 1, 77819, 0, 0, 0, 80, 4167100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Trapped Miner - on spell hit (77819) - run actionlist'),
(4167100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Trapped Miner - actionlist - set emote state (26)'),
(4167100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Trapped Miner - actionlist - face player'),
(4167100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 33, 41671, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Trapped Miner - actionlist - give quest credit (42224)'),
(4167100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Trapped Miner - actionlist - say text 0'),
(4167100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Trapped Miner - actionlist - play emote (2)'),
(4167100, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 6000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Trapped Miner - actionlist - despawn after 6 seconds');
