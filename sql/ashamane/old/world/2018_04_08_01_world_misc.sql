-- Table `creature`
DELETE FROM `creature` WHERE guid = '210112048';
DELETE FROM `creature` WHERE guid = '210112049';
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(210112048, 87501, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -8685.39, 454.683, 100.619, 5.82418, 300, 0, 0, 3117801, 0, 0, 0, 0, 0, 0, 0, '', 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(210112049, 87503, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, -8681.83, 455.775, 100.067, 4.37308, 300, 0, 0, 87, 0, 0, 0, 0, 0, 0, 0, '', 0);
