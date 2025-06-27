-- Proto-Drake Whelp
DELETE FROM `creature_template_addon` WHERE `entry` =32592;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(32592, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, "52970");

DELETE FROM `creature_template_movement` WHERE `CreatureId`=32592;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(32592, 0, 0, 1, 0, 0, 0, NULL);
