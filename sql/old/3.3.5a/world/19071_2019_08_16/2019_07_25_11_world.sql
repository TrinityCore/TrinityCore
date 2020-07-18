-- 
DELETE FROM `creature` WHERE `id`=26403 AND `guid` IN (113553);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(113553, 26403, 571, 0, 0, 1, 3, 0, 0, 2772.34, 4691.93, 41.0832, 3.24631, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 26403;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`) VALUES
(26403, 0, 0, 1, 0);
