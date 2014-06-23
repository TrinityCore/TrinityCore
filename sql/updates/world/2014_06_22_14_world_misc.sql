--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=2230;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2274,2275) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =227400 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2274, 0, 0, 1, 20, 0, 100, 0, 502, 0, 0, 0, 36, 2275, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stanley - On Quest Complete "Elixir of Pain"  - Update Template To "Enraged Stanley"'),
(2274, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Stanley - On Quest Complete "Elixir of Pain"  - Attack Invoker'),
(2274, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 227400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stanley - On Quest Complete "Elixir of Pain"  - Run Script'),
(2274, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stanley - On Death  - Reset All Scripts'),
(227400, 9, 0, 0, 0, 0, 100, 0, 120000, 120000, 0, 0, 36, 2274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stanley - Script - Update Entry to Stanley');
