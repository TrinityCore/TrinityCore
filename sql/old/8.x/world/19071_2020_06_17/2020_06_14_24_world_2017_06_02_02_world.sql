-- 
DELETE FROM `creature` WHERE `guid` IN (80342, 80351, 80364, 80378);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(80342, 26202, 571, 0, 0, '0', 0, 0, 0, 3247.804, 3688.892, 21.705, 3.158267, 300, 7, 0, 1, 0, 1, 0, 0, 0, -1), 
(80351, 26202, 571, 0, 0, '0', 0, 0, 0, 3180.858, 3820.200, 28.555, 3.158267, 300, 7, 0, 1, 0, 1, 0, 0, 0, -1), 
(80364, 26202, 571, 0, 0, '0', 0, 0, 0, 3190.193, 3852.021, 27.972, 3.158267, 300, 7, 0, 1, 0, 1, 0, 0, 0, -1), 
(80378, 26202, 571, 0, 0, '0', 0, 0, 0, 3158.872, 3841.474, 25.945, 3.158267, 300, 7, 0, 1, 0, 1, 0, 0, 0, -1);
