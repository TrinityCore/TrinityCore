--
/*
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 9376;

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=9376;

DELETE FROM `smart_scripts` WHERE `entryorguid`=9376 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9376, 0, 0, 0,11, 0, 100, 0, 0, 0, 0, 0, 11, 13913, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blazerunner - On Spawn - Cast Blazerunner Aura'),
(9376, 0, 1, 0, 9, 0, 100, 0, 0, 10, 10000, 20000, 11, 17277, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blazerunner - On Range - Cast Blast Wave'),
(9376, 0, 2, 0, 8, 0, 100, 0, 14247, 0, 0, 0, 28, 13913, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blazerunner - On Spellhit (Blazerunner Dispel) - Remove Blazerunner Aura');
*/
