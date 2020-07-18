UPDATE `creature` SET `unit_flags`=33587968 WHERE  `guid`IN(53208,53209,53210,53617,53586,53229,53711,53230,53710);

DELETE FROM `creature_addon` WHERE `guid` IN(53208,53209,53210,53210,53617,53586,53229,53711,53230,53710);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(53208, 0, 0x7, 0x1, ''), -- 23232 - 41290 - 41290
(53209, 0, 0x7, 0x1, ''), -- 23232 - 41290 - 41290
(53210, 0, 0x7, 0x1, ''), -- 23232 - 41290 - 41290
(53617, 0, 0x7, 0x1, ''), -- 23236
(53586, 0, 0x7, 0x1, ''), -- 23236
(53229, 0, 0x7, 0x1, ''), -- 23235
(53711, 0, 0x7, 0x1, ''), -- 23237
(53230, 0, 0x7, 0x1, ''), -- 23235
(53710, 0, 0x7, 0x1, ''); -- 23237

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(23232);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(23232) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23232, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 41290, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mutant War Hound - On Reset - Cast Disease Cloud'),
(23232, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 41193, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mutant War Hound - On Death - Cast Cloud of Disease');
