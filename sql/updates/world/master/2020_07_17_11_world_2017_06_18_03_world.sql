-- 
DELETE FROM creature WHERE guid IN (80424,80426,80427);
INSERT INTO creature (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(80424, 28931, 571, 0, 0, '0', 0, 0, 0, 25770, 0, 6221.2, -1986.5, 461.485, 3.78736, 300, 0, 0, 200000, 0, 0, 0, 0, 0, 0),
(80426, 28932, 571, 0, 0, '0', 0, 0, 0, 19595, 0, 6218.72, -1985.63, 482.18, 4.39823, 300, 0, 0, 4979, 0, 2, 0, 0, 0, 0),
(80427, 28932, 571, 0, 0, '0', 0, 0, 0, 19595, 0, 6221.37, -1989.22, 482.167, 1.50098, 300, 0, 0, 4979, 0, 2, 0, 0, 0, 0);
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id`=28932;
