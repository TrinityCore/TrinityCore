-- Flame Revenant (30873)
UPDATE `creature` SET `phaseMask` = 1 WHERE `id` = 30873;

-- Hackfix Sons of Hodir Vendor
DELETE FROM `creature` WHERE `guid` = 900014;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(900014, 32540, 571, 0, 0, 1, 1, 0, 1, 7294.19, -2874.07, 822.378, 1.52255, 300, 0, 0, 50400, 0, 0, 0, 0, 0, 0);
