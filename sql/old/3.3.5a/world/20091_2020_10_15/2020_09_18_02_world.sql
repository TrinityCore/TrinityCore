-- Respawn time https://www.wowhead.com/object=2712/calcified-elven-gem#comments:id=363573
UPDATE `gameobject` SET `spawntimesecs` = 20 WHERE `id` = 2712;
-- They should be pooled, also more of them should be spawned
DELETE FROM `gameobject` WHERE `guid` IN (30002,30010,30011,30019,30022) AND `id` = 2712;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(30002, 2712, 0, 1, 1, -2311.438, -1775.693, -38.39598, 2.879789, 0, 0, 0, 1, 20, 255, 1, 0),
(30010, 2712, 0, 1, 1, -2346.703, -1622.398, -32.72837, 0.2967052, 0, 0, 0, 1, 20, 255, 1, 0),
(30011, 2712, 0, 1, 1, -2143.996, -1674.242, -46.47116, 3.769912, 0, 0, 0, 1, 20, 255, 1, 0),
(30019, 2712, 0, 1, 1, -2224.817, -1608.232, -54.79397, 2.33873, 0, 0, 0.920504, 0.3907318, 20, 255, 1, 12340),
(30022, 2712, 0, 1, 1, -2263.765, -1499.152, -42.05137, -0.26179, 0, 0, -0.130525, 0.991444, 20, 255, 1, 12340);
