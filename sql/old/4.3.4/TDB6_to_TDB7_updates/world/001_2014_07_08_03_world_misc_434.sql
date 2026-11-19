-- Schemin' That Sabotage (25878) quest script
UPDATE `creature_template` SET `lootid` = 41437 WHERE `entry` = 41437;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (41437, 41475);

DELETE FROM `creature_loot_template` WHERE `entry` = 41437 AND `item` = 56140;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(41437, 56140, -67, 1, 0, 1, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (13, 17) AND `SourceEntry` = 77585;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 77585, 0, 0, 29, 0, 41475, 7, 0, 0, 0, 0, '', 'Spell 77585 requires creature 41475 nearby'),
(13, 1, 77585, 0, 0, 31, 0, 3, 41475, 0, 0, 0, 0, '', 'Spell 77585 targets creature 41475');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (41437, 4143700, 41475, 4147500);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(41437, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 80, 4143700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin Pump Controller - on aggro - run actionlist'),
(4143700, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 81505, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Goblin Pump Controller - actionlist - cast spell (81505)'),
(41475, 0, 0, 0, 8, 0, 100, 1, 77585, 0, 0, 0, 80, 4147500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin Pump Controller - on spell hit (77585) - run actionlist (4147500)'),
(4147500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 77586, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin Pump Controller - actionlist - cast spell (41475)'),
(4147500, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 77587, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin Pump Controller - actionlist - cast spell(41475)'),
(4147500, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 77588, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin Pump Controller - actionlist - cast spell (41475)'),
(4147500, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 41475, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Goblin Pump Controller - actionlist - give quest credit (41475)'),
(4147500, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin Pump Controller - actionlist - despawn');
