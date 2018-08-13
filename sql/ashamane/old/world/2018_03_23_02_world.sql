-- Table `creature_template`
UPDATE `creature_template` SET `minlevel` = 110, `maxlevel` = 110, `faction` = 35, `unit_flags` = 33587968, `unit_flags2` = 2048, `type` = 10, `type_flags` = 1048576 WHERE (entry = 120573);

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 121539;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 121539);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(121539, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ''),
(121539, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 33, 121539, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '');

-- Table `creature_template`
UPDATE `creature_template` SET `faction` = 35 WHERE (entry = 251766);

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 251766;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 251766);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(251766, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ''),
(251766, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 33, 251766, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '');

-- Table `creature_template`
UPDATE `creature_template` SET `minlevel` = 110, `maxlevel` = 110, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 64, `unit_flags2` = 2048, `type` = 7, `type_flags` = 2097260 WHERE (entry = 121546);

-- FULL `creature` of id 121546
DELETE FROM `creature` WHERE guid = 21011270;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(21011270, 121546, 1669, 8701, 8706, 1, 0, 0, 5341.473145, 10374.401367, -34.34544, 6.140757, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);

