-- Flame Revenant (30873)
UPDATE `creature` SET `phaseMask` = 1 WHERE `id` = 30873;


-- Move ally vendors (don't need to delete originals, they are in differen phase)
DELETE FROM `creature` WHERE guid IN (900024, 900025);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(900024, 39172, 571, 0, 0, 1, 1, 0, 0, 5370.42, 2880.77, 409.239, 3.12728, 300, 0, 0, 12600, 0, 0, 0, 134218496, 0, 0),
(900025, 32294, 571, 0, 0, 1, 1, 0, 0, 5370.47, 2887.44, 409.24, 3.55288, 300, 0, 0, 12600, 0, 0, 0, 134218496, 0, 0);


-- Show some allies
UPDATE `creature` SET `phaseMask` = 1 WHERE `phaseMask` = 128 AND `id` IN (31051, 30489);


-- Hide some horde guards
UPDATE `creature` SET `phaseMask` = 128 WHERE `guid` IN (131260, 131259, 131264, 131269);
