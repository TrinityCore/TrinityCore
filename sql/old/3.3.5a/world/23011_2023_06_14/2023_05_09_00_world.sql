-- Avenging spirits Wither aura
DELETE FROM `creature_template_addon` WHERE `entry` IN (27386, 30756);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(27386, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "48584"),
(30756, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "48584");
