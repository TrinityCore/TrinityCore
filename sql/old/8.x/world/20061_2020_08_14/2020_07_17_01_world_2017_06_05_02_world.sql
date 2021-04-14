--
DELETE FROM `creature` WHERE `guid` IN (80379,80380,80382,80407,80408);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(80379, 25585, 571, 0, 0, '0', 0, 0, 0, 0, 0, 3379.032, 6157.035, 79.831, 1.675516, 300, 10, 0, 1, 0, 1, 0, 0, 0, -1),
(80380, 25585, 571, 0, 0, '0', 0, 0, 0, 0, 0, 3442.108, 6205.982, 73.805, 1.675516, 300, 10, 0, 1, 0, 1, 0, 0, 0, -1),
(80382, 25585, 571, 0, 0, '0', 0, 0, 0, 0, 0, 3506.431, 6148.332, 66.530, 1.675516, 300, 10, 0, 1, 0, 1, 0, 0, 0, -1),
(80407, 25585, 571, 0, 0, '0', 0, 0, 0, 0, 0, 3490.342, 6110.152, 70.966, 1.675516, 300, 10, 0, 1, 0, 1, 0, 0, 0, -1),
(80408, 25585, 571, 0, 0, '0', 0, 0, 0, 0, 0, 3408.131, 6242.156, 75.513, 1.675516, 300, 10, 0, 1, 0, 1, 0, 0, 0, -1);
