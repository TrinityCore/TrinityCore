-- Proto-Drake Whelp
DELETE FROM `creature_template_addon` WHERE `entry` =32592;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(32592, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, "52970");

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30080066,`StaticFlags5`=0x1000200 WHERE `Entry`=32592;
