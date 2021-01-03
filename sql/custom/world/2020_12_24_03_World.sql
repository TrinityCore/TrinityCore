-- Missing Spawns In Stormwind Keep

-- Biship DeLavey
DELETE FROM `creature` WHERE `guid` IN (188514, 314302);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(188514, 4960, 0, 1519, 6292, '0', 0, 0, 0, -1, 2961, 0, -8395.96, 329.411, 147.014, 1.94075, 300, 0, 0, 1163, 0, 0, 0, 0, 0, 0, 0, '', 0);

-- Kirin Tor Summoner #1
DELETE FROM `creature` WHERE `guid`=20549121;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(20549121, 92553, 0, 1519, 6292, '0', 0, 0, 0, -1, 0, 0, -8398.37, 332.507, 147.014, 3.8187, 300, 0, 0, 80, 0, 0, 0, 0, 0, 0, 0, '', 0);

-- Kirin Tor Summoner #2
DELETE FROM `creature` WHERE `guid`=20549120;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(20549120, 92553, 0, 1519, 6292, '0', 0, 0, 0, -1, 0, 0, -8403, 328.907, 147.014, 0.677107, 300, 0, 0, 80, 0, 0, 0, 0, 0, 0, 0, '', 0);

-- Portal To Dalaran
DELETE FROM `gameobject` WHERE `guid`=20405933;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES 
(20405933, 216350, 0, 1519, 6292, '0', 0, 0, 0, -1, -8401.06, 330.757, 147.014, 5.15268, 0, 0, -0.535631, 0.844452, 120, 255, 1, '', 25549);


