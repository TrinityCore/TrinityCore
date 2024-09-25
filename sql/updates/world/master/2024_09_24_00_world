-- delete old chromies
DELETE FROM `creature` WHERE `guid` = 1070809;
DELETE FROM `creature` WHERE `guid` = 62000000002001338;

-- Chromie's Hourglass
DELETE FROM `gameobject` WHERE `guid` IN (990000000100049620, 990000000100049621);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(990000000100049620, 350063, 1, 1637, 5170, '0', '0', 0, 1557.09375, -4216.90478515625, 54.11083984375, 0.080494672060012817, 0, 0, 0.040236473083496093, 0.999190151691436767, 120, 255, 1, 44015), -- 350063 (Area: 5170 - Difficulty: 0)
(990000000100049621, 350063, 0, 1519, 0, '0', '0', 0, -8196.39453125, 744.904541015625, 76.43845367431640625, 0.205067232251167297, 0, 0, 0.102354049682617187, 0.994748055934906005, 120, 255, 1, 43971); -- 350063 (Area: 0 - Difficulty: 0)

-- Chromie with modified spawn for fix sitting on hourglass
DELETE FROM `creature` WHERE `guid` IN (990000000100049620, 990000000100049621);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(990000000100049620, 167032, 1, 1637, 5170, '0', '0', 0, 0, 0, 0, 1557.338257, -4216.685059, 55.900105, 1.017488956451416015, 120, 0, 0, 5895500, 0, 3, 0, 0, 0, 44015), -- 167032 (Area: 5170 - Difficulty: 0)
(990000000100049621, 167032, 0, 1519, 0, '0', '0', 0, 0, 0, 0, -8196.362305, 745.026489, 78.343849, 1.435181260108947753, 120, 0, 0, 5895500, 0, 3, 0, 0, 0, 43971); -- 167032 (Area: 0 - Difficulty: 0)

-- Chromie sit
DELETE FROM `creature_addon` WHERE `guid` IN (990000000100049620, 990000000100049621);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(990000000100049620,0,0,0,1,0,0,1,0,0,0,0,0,0,NULL),
(990000000100049621,0,0,0,1,0,0,1,0,0,0,0,0,0,NULL);
