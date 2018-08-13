-- Creating a new SmartAI script for [Creature] ENTRY 127271 (name: Legion Portal)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 127271;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 127271);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(127271, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ''),
(127271, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 33, 127271, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '');

-- FULL `creature` of id 120573
DELETE FROM `creature` WHERE guid = 21011267;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(21011267, 120573, 1669, 8701, 0, 1, 0, 0, 0, 0, 4880.14, 9823.22, -90.1795, 6.14956, 300, 0, 0, 87, 0, 0, 0, 0, 0, 0, 0, '', 0);

-- Table `creature_template`
UPDATE `creature_template` SET `family` = 151, `type` = 1, `MovementType` = 1, `HealthModifier` = 2 WHERE (entry = 123089);

-- Creating a new SmartAI script for [Creature] ENTRY 121676 (name: Void Harvester)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 121676;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 121676);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(121676, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ''),
(121676, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 33, 121676, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '');

-- FULL `creature` of id 126852
DELETE FROM `creature` WHERE guid = 21011268;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(21011268, 126852, 1669, 8701, 8914, 1, 0, 0, 5320.839844, 9730.352539, -94.511971, 0.85291, 32400, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0);

-- Table `creature_template`
UPDATE `creature_template` SET `faction` = 14, `rank` = 2, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 512, `unit_flags2` = 2048, `type` = 7, `MovementType` = 1 WHERE (entry = 126852);

-- FULL `creature` of id 120764
DELETE FROM `creature` WHERE guid = 21011269;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(21011269, 120764, 1669, 8701, 8914, 1, 0, 0, 5379.442871, 9829.514648, -86.313545, 3.110257, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);

-- Table `creature_template`
UPDATE `creature_template` SET `BaseAttackTime` = 2800, `RangeAttackTime` = 2000, `unit_flags` = 512, `unit_flags2` = 2048, `type` = 3 WHERE (entry = 120764);

-- Table `creature_template`
UPDATE `creature_template` SET `minlevel` = 110, `maxlevel` = 110, `HealthModifier` = 18 WHERE (entry = 120764);