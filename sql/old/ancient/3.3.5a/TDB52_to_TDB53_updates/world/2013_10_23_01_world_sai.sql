DELETE FROM `smart_scripts` WHERE `entryorguid`=29884 AND `id`=7;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29884, 0, 7, 0, 0, 0, 100, 0, 6000, 10000, 6000, 10000, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gymer - IC - Say 1');

UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35 WHERE  `entry`=29884;
