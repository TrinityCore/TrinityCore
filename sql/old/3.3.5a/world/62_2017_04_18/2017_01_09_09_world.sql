-- 
SET @OGUID := 6570; -- 3 unused set by TC TEAM
DELETE FROM `gameobject` WHERE `id` IN (185059, 185060, 185061);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(@OGUID+0, 185059, 530, 3520, 3943, 1, 1, -2668.99, 2698.53, 102.662, 2.69388, 0, 0, 0.975048, 0.221992, 300, 0, 1, 0),
(@OGUID+1, 185060, 530, 3520, 3943, 1, 1, -2671, 2694.73, 102.581, 2.57921, 0, 0, 0.960726, 0.2775, 300, 0, 1, 0),
(@OGUID+2, 185061, 530, 3520, 3943, 1, 1, -2672.43, 2691.78, 102.398, 2.5635, 0, 0, 0.958516, 0.285037, 300, 0, 1, 0);
