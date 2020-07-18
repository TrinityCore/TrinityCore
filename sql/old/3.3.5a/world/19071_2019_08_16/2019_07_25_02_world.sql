-- 
DELETE FROM `creature` WHERE `id`=24977 AND `guid`=113227;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(113227, 24977, 530, 0, 0, 1, 1, 0, 0, 3045.6779, 3701.3554, 143.3911, 3.395507, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `gameobject` WHERE `guid` IN (9224, 9225, 9226, 9230);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(9224, 180037, 530, 3523, 0, 1, 1, 3048.147, 3705.473, 143.5917, 0.6806767, 0, 0, 0.333806, 0.9426418, 120, 255, 1, 15595), -- 180037 (Area: 0 - Difficulty: 0)
(9225, 179975, 530, 3523, 0, 1, 1, 3050.009, 3708.433, 143.4847, 5.201083, 0, 0, -0.5150375, 0.8571676, 120, 255, 1, 15595), -- 179975 (Area: 0 - Difficulty: 0)
(9226, 187299, 530, 3523, 3712, 1, 1, 2965.176, 3678.182, 144.1205, 4.607672, 0, 0, -0.743144, 0.6691315, 120, 255, 1, 15595), -- 187299 (Area: 3712 - Difficulty: 0)
(9230, 183306, 530, 3523, 3712, 1, 1, 2999.551, 3741.136, 144.0803, 2.111848, 0, 0, 0.8703556, 0.4924237, 120, 255, 1, 15595); -- 183306 (Area: 3712 - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid` =9230 ;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(9230, 0, 0, -0.4461977, 0.8949344); -- 183306
