--
DELETE FROM `creature` WHERE `guid` IN (80537,80538);
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(80537, 31152, 571, 210, 4508, '0', 0, 0, 0, 0, 1, 6799.83, 1433.43, 390.812, 6.28299, 300, 0, 0, 12600, 0, 0, 0, 0, 0, '', 0),
(80538, 31152, 571, 0, 0, '0', 0, 0, 0, 0, 1, 6799.42, 1426.43, 390.812, 0.0389925, 300, 0, 0, 12600, 0, 0, 0, 0, 0, '', 0);
