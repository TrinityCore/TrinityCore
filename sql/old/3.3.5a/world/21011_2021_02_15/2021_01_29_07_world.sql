--
DELETE FROM `areatrigger_scripts` WHERE `entry`IN(4946,4947,4948);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(4946, 'SmartTrigger'),
(4947, 'SmartTrigger'),
(4948, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(4946,4947,4948) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4946, 2, 0, 0, 46, 0, 100, 0, 4946, 0, 0, 0, 0, 33, 26468, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Quest Credit 'Uncovering the Tunnels' (North Building)"),
(4948, 2, 0, 0, 46, 0, 100, 0, 4948, 0, 0, 0, 0, 33, 26469, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Quest Credit 'Uncovering the Tunnels' (South Building)"),
(4947, 2, 0, 0, 46, 0, 100, 0, 4947, 0, 0, 0, 0, 33, 26470, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Quest Credit 'Uncovering the Tunnels' (East Building)");

UPDATE `creature_template` SET `AIName`='' WHERE  `entry` IN(26468,26469,26470);

DELETE FROM `smart_scripts` WHERE  `entryorguid` IN(26468,26469,26470) AND `source_type`=0;
