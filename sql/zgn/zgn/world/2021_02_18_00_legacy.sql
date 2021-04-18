DELETE FROM `scene_template` WHERE `SceneId` IN (2236, 2334, 2418, 2338, 2341, 2422, 2380, 2379, 2421, 2423, 2420, 2499);
INSERT INTO `scene_template`(`SceneId`,`Flags`,`ScriptPackageID`,`ScriptName`) VALUES 
(2236,40,2578,''),
(2334,16,2708,''),
(2418,16,2932,''),
(2338,16,2712,''),
(2341,17,2933,''),
(2422,16,2824,''),
(2380,16,2773,''),
(2379,17,2775,''),
(2421,16,2823,''),
(2423,16,2825,''),
(2420,16,2822,''),
(2499,17,2908,'');

DELETE FROM gameobject WHERE guid = 5000000;
INSERT INTO gameobject (guid, id, map, zoneId, areaId, spawnDifficulties, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state, isActive, ScriptName, VerifiedBuild) VALUES
(5000000, 292518, 2175, 0, 0, '0', 0, 0, 0, -1, -9.46167, -4.97189, 5.45624, 3.28829, -0, -0, -0.997311, 0.073282, 300, 255, 1, 0, '', 0);
