-- 
DELETE FROM `creature` WHERE `guid` IN (116021, 116022, 116023, 116024, 116025, 116026, 116027,116028, 116029, 116030, 116031, 116032) AND `id` IN (28023,28028);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(116021, 28023, 571, 0, 0, 1, 1, 0, 1, 5485.57, -2383.3, 292.419, 4.0998, 600, 10, 0, 0, 0, 1, 0, 0, 0, 0),
(116022, 28023, 571, 0, 0, 1, 1, 0, 1, 5514.3, -2438.64, 292.419, 3.8956, 600, 10, 0, 0, 0, 1, 0, 0, 0, 0),
(116023, 28023, 571, 0, 0, 1, 1, 0, 1, 5452.69, -2425.4, 292.419, 4.0840, 600, 10, 0, 0, 0, 1, 0, 0, 0, 0),
(116024, 28023, 571, 0, 0, 1, 1, 0, 1, 5468.58, -2451.58, 292.419, 4.315, 600, 10, 0, 0, 0, 1, 0, 0, 0, 0),
(116025, 28023, 571, 0, 0, 1, 1, 0, 1, 5413.92, -2455.36, 292.419, 4.241, 600, 10, 0, 0, 0, 1, 0, 0, 0, 0),
(116026, 28023, 571, 0, 0, 1, 1, 0, 1, 5382.33, -2444.97, 292.419, 4.044, 600, 10, 0, 0, 0, 1, 0, 0, 0, 0),
(116027, 28023, 571, 0, 0, 1, 1, 0, 1, 5475.9, -2488.74, 292.419, 4.0840, 600, 10, 0, 0, 0, 1, 0, 0, 0, 0),
(116028, 28028, 571, 0, 0, 1, 1, 0, 1, 5425.1, -2516.64, 292.502, 2.007130, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(116029, 28028, 571, 0, 0, 1, 1, 0, 1, 5487.93, -2409.73, 292.418, 1.59574, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(116030, 28028, 571, 0, 0, 1, 1, 0, 1, 5412.91, -2467.73, 292.502, 1.15192, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(116031, 28028, 571, 0, 0, 1, 1, 0, 1, 5431.67, -2402.98, 292.418, 1.56747, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(116032, 28028, 571, 0, 0, 1, 1, 0, 1, 5431.93, -2497.39, 292.502, 1.55334, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28023;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28023 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28023, 0, 0, 0, 0, 0, 100, 0, 2000, 4000, 3000, 5000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rotting Abomination - IC - Cast Cleave'),
(28023, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 5000, 7000, 11, 50335, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Rotting Abomination - IC - Cast Scourge Hook');
