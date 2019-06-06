-- 
DELETE FROM `creature` WHERE `guid` IN (106799, 106801, 106802)  AND `id` IN (21933,21934);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(106799, 21933, 548, 3607, 0, 1, 1, 0, 0, -215.7533, -375.3428, 38.40299, 5.009095, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 21933 (Area: 0 - Difficulty: 0)
(106801, 21933, 548, 3607, 0, 1, 1, 0, 0, -264.1653, -357.1713, 38.80691, 2.844887, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 21933 (Area: 0 - Difficulty: 0)
(106802, 21934, 548, 3607, 0, 1, 1, 0, 0, -239.7149, -366.4398, -0.7445137, 1.239184, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 21934 (Area: 0 - Difficulty: 0) (Auras: 37935 - 37935)
UPDATE `creature` SET `position_x`=-239.8427, `position_y`=-366.4942, `position_z`=-0.7445897, `orientation`=1.22173 WHERE `id`=21216; 

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (21933);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(21933,0,0,1,0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (21934);
INSERT INTO `creature_template_addon` (`entry`, `auras`, `bytes1`,`bytes2`) VALUES
(21934, "37935", 0, 1);
