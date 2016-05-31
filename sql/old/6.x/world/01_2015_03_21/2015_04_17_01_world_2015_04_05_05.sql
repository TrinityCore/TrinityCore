UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` =29217;

DELETE FROM `smart_scripts` WHERE `entryorguid` =29217 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29217, 0, 0, 0, 0, 0, 100, 2, 0, 2000, 2000, 4000, 11, 53617, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Anub ar Venomancer - On Range - Cast Poison Bolt (Normal)'),
(29217, 0, 1, 0, 0, 0, 100, 4, 0, 2000, 2000, 4000, 11, 59359, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Anub ar Venomancer - On Range - Cast Poison Bolt (Heroic)');
