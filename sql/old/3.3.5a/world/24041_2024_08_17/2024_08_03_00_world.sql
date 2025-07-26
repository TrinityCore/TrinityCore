-- Iron Rune Construct Movement Flags: 0 (None)
UPDATE `creature_template_movement` SET `Ground` = 0, `Swim` = 0, `Flight` = 0 WHERE `CreatureId` = 24825;
-- Iron Rune Construct - Iron Rune Aura
DELETE FROM `creature_template_addon` WHERE `entry`=24825;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(24825, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, '44652');
