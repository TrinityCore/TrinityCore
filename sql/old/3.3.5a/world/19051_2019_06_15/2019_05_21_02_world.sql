-- 
DELETE FROM `creature` WHERE `guid`=105229 AND `id`=20297;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(105229, 20297, 530, 0, 0, 1, 1, 0, 0, 2383.96, 3198.54, 152.79, 5.24138, 300, 0, 0, 5589, 3155, 0, 0, 0, 0, 0);
DELETE FROM `creature_template_addon` WHERE `entry` IN (20297);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(20297, '22766');
-- Fix an undermap
UPDATE `creature` SET `position_x`=1396.201294, `position_y`=7403.615234, `position_z`=367.474823, `orientation`=4.020805 WHERE `id`=19973 AND `guid`=71201;
