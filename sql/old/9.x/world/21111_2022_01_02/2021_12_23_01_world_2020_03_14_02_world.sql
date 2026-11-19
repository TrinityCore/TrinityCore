-- 
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry` IN (184969,184968,184967,184950);
UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=21861 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (184969,184968,184967,184950) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(184969, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 0, 12, 21861, 3, 6000, 0, 0, 0, 8, 0, 0, 0, 0, 3572.57, 6669.2, 128.455, 5.6229, 'Four Prophecy - On Loot State - Summon Whisper Raven God'),
(184969, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Four Prophecy - Link - Store Target'),
(184969, 1, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 21861, 20, 0, 0, 0, 0, 0, 0, 'Fourth Prophecy - Link - Send Target to Raven God'),
(184969, 1, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 4, 0, 0, 0, 0, 19, 21861, 20, 0, 0, 0, 0, 0, 0, 'Fourth Prophecy - Link - Set Data 4 to Raven God'),
(184968, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 0, 12, 21861, 3, 6000, 0, 0, 0, 8, 0, 0, 0, 0, 3736.95, 6640.75, 133.675, 3.33629, 'Third Prophecy - On Loot State - Summon Whisper Raven God'),
(184968, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Third Prophecy - Link - Store Target'),
(184968, 1, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 21861, 20, 0, 0, 0, 0, 0, 0, 'Third Prophecy - Link - Send Target to Raven God'),
(184968, 1, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 3, 0, 0, 0, 0, 19, 21861, 20, 0, 0, 0, 0, 0, 0, 'Third Prophecy - Link - Set Data 3 to Raven God'),
(184967, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 0, 12, 21861, 3, 6000, 0, 0, 0, 8, 0, 0, 0, 0, 3629.29, 6542.14, 155.005, 2.56267, 'Second Prophecy - On Loot State - Summon Whisper Raven God'),
(184967, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Second Prophecy - Link - Store Target'),
(184967, 1, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 21861, 20, 0, 0, 0, 0, 0, 0, 'Second Prophecy - Link - Send Target to Raven God'),
(184967, 1, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 19, 21861, 20, 0, 0, 0, 0, 0, 0, 'Second Prophecy - Link - Set Data 2 to Raven God'),
(184950, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 0, 12, 21861, 3, 6000, 0, 0, 0, 8, 0, 0, 0, 0, 3779.99, 6729.6, 180.498, 5.7149, 'First Prophecy - On Loot State - Summon Whisper Raven God'),
(184950, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'First Prophecy - Link - Store Target'),
(184950, 1, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 21861, 20, 0, 0, 0, 0, 0, 0, 'First Prophecy - Link - Send Target to Raven God'),
(184950, 1, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 21861, 20, 0, 0, 0, 0, 0, 0, 'First Prophecy - Link - Set Data 1 to Raven God');
