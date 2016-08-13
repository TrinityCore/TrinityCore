-- 
-- DB/Quest: Escape Through Force
DELETE FROM `smart_scripts` WHERE `entryorguid`=3692 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3692, 0, 0, 1, 19, 0, 100, 0, 994, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Volcor - On Quest \'Escape Through Force\' Taken - Store Targetlist'),
(3692, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Volcor - On Quest \'Escape Through Force\' Taken - Set Unit Flags'),
(3692, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 369200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Volcor - On Quest \'Escape Through Force\' Taken - Run Script'),
(3692, 0, 3, 4, 19, 0, 100, 0, 995, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Volcor - On Quest \'Escape Through Stealth\' Taken - Store Targetlist'),
(3692, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Volcor - On Quest \'Escape Through Stealth\' Taken - Set Unit Flags'),
(3692, 0, 5, 0, 61, 0, 100, 0, 995, 0, 0, 0, 80, 369201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Volcor - On Quest \'Escape Through Stealth\' Taken - Run Script'),
(3692, 0, 6, 0, 40, 0, 100, 0, 15, 3692, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Volcor - On Waypoint 15 Reached - Despawn 5 Seconds');

UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid` IN(369200,369201) AND `source_type`=9 AND `id`IN(2,3);
