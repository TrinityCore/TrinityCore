-- Replace the previously spawned chests with sniffed ones
DELETE FROM `gameobject` WHERE `id` IN (185168, 185169) AND `guid` IN (20499, 20496);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(20496, 185168, 543, 3, 1, -1429.81, 1772.916, 82.0765, 5.044002, 0, 0, 0, 1, 7200, 255, 1, 19243), -- 185168 (Area: 3562)
(20499, 185169, 543, 3, 1, -1429.81, 1772.916, 82.0765, 5.044002, 0, 0, 0, 1, 7200, 255, 1, 19243); -- 185169 (Area: 3562)
