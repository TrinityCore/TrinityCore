-- 
DELETE FROM `creature` WHERE `guid` IN (106326)  AND `id` IN (21365);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(106326, 21365, 530, 0, 0, 1, 1, 0, 0, 38.3723, 2121.23, 128.975, 2.80337, 600, 0, 0, 42, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (21365);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(21365, '36725 36727');
