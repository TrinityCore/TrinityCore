DELETE FROM `gameobject` WHERE `guid`= 220601;
DELETE FROM `gameobject_addon` WHERE `guid`= 220601;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(220601, 206111, 0, 1519, 5148, '0', 169, 0, -8823.8505859375, 630.57293701171875, 94.1360015869140625, 3.874634265899658203, -0.00149488449096679, 0.004098892211914062, -0.93357086181640625, 0.358366340398788452, 120, 255, 1, 57564); -- Hero's Call Board (Area: Trade District - Difficulty: 0) CreateObject1
