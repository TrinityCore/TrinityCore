UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 51712;

UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `ID` IN (51712, 45859, 45905, 51674);

SET @CGUID := 252516;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 47062, 1, 5034, 5666, "0", 169, 0, 0, 0, -9757.48, -918.474, 56.99433, 0.6457718, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Vir'Naal Priest (Area: Vir'naal Dam - Difficulty: 0)
(@CGUID+1, 47062, 1, 5034, 5666, "0", 169, 0, 0, 0, -9761.31, -912.45, 57.00123, 0.6457718, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Vir'Naal Priest (Area: Vir'naal Dam - Difficulty: 0)
(@CGUID+2, 46135, 1, 5034, 5666, "0", 169, 0, 0, 0, -9758.25, -914.427, 57.09123, 0.6457718, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26654); -- High Priest Amet (Area: Vir'naal Dam - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 468, ''), -- Vir'Naal Priest
(@CGUID+1, 0, 0, 0, 1, 468, ''), -- Vir'Naal Priest
(@CGUID+2, 0, 0, 0, 1, 0, ''); -- High Priest Amet

SET @OGUID := 200965;
DELETE FROM `gameobject` WHERE `guid`= @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 205564, 1, 5034, 5599, "0", 169, 0, -10674.59, -1323.694, 15.63416, 3.647743, 0.004201889, 0.001173973, -0.9681377, 0.2503803, 120, 255, 1, 26654); -- Meeting Stone (Area: Lost City of the Tol'vir - Difficulty: 0)
