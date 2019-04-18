-- 
DELETE FROM `creature` WHERE `guid` IN (61694, 61695, 61696, 61697);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `unit_flags`,`spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(61694, 13096, 0, 1, 1, 0, 1, -4958.26, -1264.67, 717.511, 5.39958, 768, 900, 0, 0, 837, 4234, 0),
(61695, 13096, 0, 1, 1, 0, 1, -4952.16, -1269.72, 716.152, 2.79599, 768, 900, 0, 0, 837, 4234, 0),
(61696, 13096, 0, 1, 1, 0, 1, -4868, -667, 624.228, 0.46338, 768, 900, 0, 0, 837, 4234, 0),
(61697, 13096, 0, 1, 1, 0, 1, -4862.35, -661.51, 624.875, 4.16261, 768, 900, 0, 0, 811, 4082, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (61694, 61695, 61696, 61697);
INSERT INTO `creature_addon` (`guid`, `bytes2`, `path_id`, `bytes1`) VALUES
(61694, 1, 0, 1),
(61695, 1, 0, 1),
(61696, 1, 0, 1),
(61697, 1, 0, 1);
