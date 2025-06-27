-- 
DELETE FROM `creature` WHERE `guid` IN (130746, 130748, 130750, 130751);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(130746, 30881, 571, 67, 4446, 1, 1, 0, 0, 7506.01, -1923.566, 1473.698, 1.256637, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 30881 (Area: 4446 - Difficulty: 0) (Auras: 29266 - 29266)
(130748, 30881, 571, 67, 4446, 1, 1, 0, 0, 7458.983, -1928.875, 1474.344, 4.468043, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 30881 (Area: 4446 - Difficulty: 0) (Auras: 29266 - 29266)
(130750, 30881, 571, 67, 4446, 1, 1, 0, 0, 7483.364, -1855.742, 1474.344, 4.363323, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 30881 (Area: 4446 - Difficulty: 0) (Auras: 29266 - 29266)
(130751, 30881, 571, 67, 4446, 1, 1, 0, 0, 7501.811, -1849.362, 1474.344, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 30881 (Area: 4446 - Difficulty: 0) (Auras: 29266 - 29266)

UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=30881;
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='29266' WHERE `entry`=30881;
