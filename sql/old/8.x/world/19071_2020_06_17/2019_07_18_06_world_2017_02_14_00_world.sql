-- 
UPDATE `creature` SET `MovementType`=0, `spawndist`=0, `orientation`= 3.104503 WHERE `guid`=136610;
UPDATE `creature` SET `orientation`= 4.244902 WHERE `guid`=136603;

DELETE FROM `creature` WHERE `guid` BETWEEN 78324 AND 78329;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(78324, 34199, 603, 0, 0, '14,33', 0, 0, 1, 1544.26, -20.2985, 420.967, 3.24509, 300, 0, 0, 741455, 0, 0, 0, 0, 0, 0),
(78325, 34190, 603, 0, 0, '14,33', 0, 0, 0, 1548.88, -10.8608, 420.967, 5.55185, 300, 0, 0, 741455, 0, 0, 0, 0, 0, 0),
(78326, 34198, 603, 0, 0, '14,33', 0, 0, 1, 1551.49, -14.7856, 420.967, 2.11809, 300, 0, 0, 539240, 62535, 0, 0, 0, 0, 0),
(78327, 34190, 603, 0, 0, '14,33', 0, 0, 0, 1683.74, -10.3208, 427.5, 3.83577, 300, 0, 0, 741455, 0, 0, 0, 0, 0, 0),
(78328, 34198, 603, 0, 0, '14,33', 0, 0, 1, 1676.68, -10.5521, 427.312, 0.257448, 300, 0, 0, 539240, 62535, 0, 0, 0, 0, 0),
(78329, 34199, 603, 0, 0, '14,33', 0, 0, 1, 1681.19, -19.7237, 427.31, 3.01208, 300, 0, 0, 741455, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry`=34237;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(34237, 0, 0, 0, 1, 333, "");

DELETE FROM `creature_addon` WHERE `guid`=127005;
