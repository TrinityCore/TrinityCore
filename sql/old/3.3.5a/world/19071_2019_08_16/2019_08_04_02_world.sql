-- 
DELETE FROM `creature` WHERE `guid` IN (116033,116034,116035,116064,116065,116066) AND `id` IN (28343,28344,20485);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(116033, 28343, 530, 0, 0, 1, 1, 0, 0, 2959.510, 3678.8798, 144.20399, 1.26551, 600, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(116034, 28344, 530, 0, 0, 1, 1, 0, 1, 3063.406, 3677.57, 142.7607, 4.276057, 600, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(116035, 20485, 530, 0, 0, 1, 1, 0, 1, 2967.32, 3685.43, 144.121, 3.60993, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(116064, 20485, 530, 0, 0, 1, 1, 0, 1, 2962.43, 3676.92, 144.121, 1.36762, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(116065, 20485, 530, 0, 0, 1, 1, 0, 1, 2955.12, 3687.38, 144.121, 5.60002, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(116066, 20485, 530, 0, 0, 1, 1, 0, 1, 2959.45, 3631.219, 144.412, 1.67552, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `creature` SET `position_x`=2971.42, `position_y`=3752.675, `position_z`=144.2516 WHERE `id`=29145;

UPDATE `creature_template` SET `npcflag`=131072 WHERE `entry`=28343;
UPDATE `creature_template` SET `npcflag`=4224 WHERE `entry`=28344;
