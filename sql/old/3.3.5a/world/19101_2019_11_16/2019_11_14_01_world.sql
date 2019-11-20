-- 
DELETE FROM `creature` WHERE `guid` IN (117621) AND `id`=20114;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(117621, 20114, 530, 0, 0, 1, 1, 0, 0, 3923.06, 3873.36, 180.752, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340);

UPDATE `creature_template_addon` SET `auras`="34840 34832" WHERE `entry`=20086;
UPDATE `creature_template_addon` SET `auras`="34858 34832" WHERE `entry`=20114;
