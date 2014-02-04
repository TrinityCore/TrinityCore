--
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (179507,179508,179510,179513);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (179507,179508,179510,179513) AND `source_type` =1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(179507, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 49943, 177188, 0, 0, 0, 0, 0, 'Door Lever - On Gameobject State Changed - Activate Gameobject (No Repeat)'),
(179508, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 49945, 177189, 0, 0, 0, 0, 0, 'Door Lever - On Gameobject State Changed - Activate Gameobject (No Repeat)'),
(179510, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 49948, 177192, 0, 0, 0, 0, 0, 'Door Lever - On Gameobject State Changed - Activate Gameobject (No Repeat)'),
(179513, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 49956, 177198, 0, 0, 0, 0, 0, 'Door Lever - On Gameobject State Changed - Activate Gameobject (No Repeat)');
