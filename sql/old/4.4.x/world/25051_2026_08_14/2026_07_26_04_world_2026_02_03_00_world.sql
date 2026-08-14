-- Add creature addons for Id: 11260 Northshire Peasant
DELETE FROM `creature_addon` WHERE `guid` IN (279815,279818,279826,275049,275050,275051,275083);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(279815, 0, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, ''), -- 11260
(279818, 0, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, ''), -- 11260
(279826, 0, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, ''), -- 11260
-- Westfall Lumberjacks
(275049, 0, 0, 0, 0, 0, 0, 1, 1, 234, 0, 0, 0, 0, ''), -- 842
(275050, 0, 0, 0, 0, 0, 0, 1, 1, 234, 0, 0, 0, 0, ''), -- 842
(275051, 0, 0, 0, 0, 0, 0, 1, 1, 234, 0, 0, 0, 0, ''), -- 842
(275083, 0, 0, 0, 0, 0, 0, 1, 1, 234, 0, 0, 0, 0, ''); -- 842

-- Update Northshire Peasant coordinates
UPDATE `creature` SET `position_x` = -8891.61, `position_y` = -275.477, `position_z` = 80.0051, `orientation` = 4.85806 WHERE GUID = 279826;
UPDATE `creature` SET `position_x` = -8838.62, `position_y` = -225.329, `position_z` = 82.4124, `orientation` = 0.539037 WHERE GUID = 279815;
UPDATE `creature` SET `position_x` = -8855.04, `position_y` = -253.269, `position_z` = 81.1676, `orientation` = 5.91667 WHERE GUID = 279818;
