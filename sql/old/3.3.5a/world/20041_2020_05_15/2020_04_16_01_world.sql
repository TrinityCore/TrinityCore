-- 
DELETE FROM `creature` WHERE `guid` IN (130723, 130733, 130739, 130741, 130742, 130745);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(130723, 32317, 571, 210, 4510, 1, 1, 0, 0, 7897.79, 2066.469, 600.2611, 2.83531, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15354),
(130733, 32430, 571, 210, 4510, 1, 1, 0, 0, 7892.259, 2057.9199, 600.262, 3.33411, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15354), 
(130739, 30755, 571, 210, 4510, 1, 1, 0, 1, 7904.836, 2054.737, 600.3429, 5.864306, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15354),
(130741, 30755, 571, 210, 4510, 1, 1, 0, 1, 7884.729, 2042.477, 600.3425, 4.171337, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15354),
(130742, 30755, 571, 210, 4510, 1, 1, 0, 1, 7873.443, 2062.453, 600.3425, 2.844887, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15354),
(130745, 30755, 571, 210, 4510, 1, 1, 0, 1, 7876.198, 2052.408, 600.3428, 3.787364, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15354);
UPDATE `creature` SET  `position_x`=7883.22, `position_y`=2057.75, `position_z`=600.25, `orientation`=6.279670 WHERE `id`=31839;
UPDATE `creature` SET  `position_x`=7625.41, `position_y`=2074.51, `position_z`=600.26, `orientation`=3.68412 WHERE `id`=32274;
