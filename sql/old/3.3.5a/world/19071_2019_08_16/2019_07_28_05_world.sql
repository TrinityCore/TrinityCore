-- 
UPDATE `creature_template` SET `unit_flags`=131328  WHERE `entry` = 17578;
DELETE FROM `creature` WHERE `id`=17578 AND `guid` IN (86753, 113595, 113605, 113607, 113609, 113635);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(86753, 17578, 540, 3714, 0, 3, 1, 0, 0, 512.1739, 205.3514, 2.007787, 0.6981317, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 17578 (Area: 0 - Difficulty: 0) (Auras: )
(113595, 17578, 540, 3714, 0, 3, 1, 0, 0, 512.9296, 186.9605, 2.00013, 0.7679449, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 17578 (Area: 0 - Difficulty: 0) (Auras: )
(113605, 17578, 540, 3714, 0, 3, 1, 0, 0, 525.0672, 176.6558, 2.016024, 2.356194, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 17578 (Area: 0 - Difficulty: 0) (Auras: )
(113607, 17578, 540, 3714, 0, 3, 1, 0, 0, 508.1696, 131.2284, 2.018857, 1.22173, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 17578 (Area: 0 - Difficulty: 0) (Auras: )
(113609, 17578, 540, 3714, 0, 3, 1, 0, 0, 512.5972, 119.7658, 1.994586, 0.6632251, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 17578 (Area: 0 - Difficulty: 0) (Auras: )
(113635, 17578, 540, 3714, 0, 3, 1, 0, 0, 523.4672, 119.2777, 1.946144, 2.042035, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545); -- 17578 (Area: 0 - Difficulty: 0) (Auras: )
