-- 
UPDATE `creature` SET `spawnMask`=5 WHERE `guid` IN (137751, 137750);
DELETE FROM `creature` WHERE `guid` IN (48306,48307);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(48306, 37868, 631, 0, 0, 10, 1, 0, 0, 4185.2851, 2464.014, 364.8696, 0.798137, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(48307, 37868, 631, 0, 0, 10, 1, 0, 0, 4183.7006, 2503.9326, 364.879, 5.508426, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 0);
