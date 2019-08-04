-- 
UPDATE `creature_template` SET `unit_flags`=33554432  WHERE `entry` IN (27993);
DELETE FROM `creature` WHERE `guid`=116020 AND `id`=27993;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(116020, 27993, 571, 0, 0, 1, 1, 0, 0, 925.647, -5299.53, 175.687, 1.90241, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);
