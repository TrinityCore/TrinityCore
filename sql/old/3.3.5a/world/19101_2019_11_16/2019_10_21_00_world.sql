-- 
DELETE FROM `creature` WHERE `guid` IN (85978,117314,117315,117316);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(85978, 30669, 571, 210, 4501, 1, 64, 0, 0, 6309.156, 53.15728, 393.4325, 2.391101, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 30669 (Area: 4501 - Difficulty: 0)
(117314, 30669, 571, 210, 4501, 1, 64, 0, 0, 6255.246, 112.484, 387.5711, 1.745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 30669 (Area: 4501 - Difficulty: 0)
(117315, 30669, 571, 210, 4501, 1, 64, 0, 0, 6218.403, 75.91792, 378.1545, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 30669 (Area: 4501 - Difficulty: 0)
(117316, 30669, 571, 210, 4501, 1, 64, 0, 0, 6155.497, 78.52045, 370.4583, 4.18879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340); -- 30669 (Area: 4501 - Difficulty: 0)

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (30669);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30669) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3066900, 3066901, 3066902, 3066903, 3066904, 3066905, 3066906, 3066907, 3066908, 3066909, 3066910, 3066911) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30669, 0, 0, 0, 1, 0, 100, 0, 20000, 40000, 30000, 50000, 88, 3066900, 3066911, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Ooc - Random action list'),
(3066900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14560, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound'),
(3066901, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14563, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound'),
(3066902, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14562, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound'),
(3066903, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14561, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound'),
(3066904, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14556, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound'),
(3066905, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14559, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound'),
(3066906, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14558, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound'),
(3066907, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14557, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound'),
(3066908, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14564, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound'),
(3066909, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14565, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound'),
(3066910, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14566, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound'),
(3066911, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14567, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vanguard Sound Dummy - Action list - Play sound');
