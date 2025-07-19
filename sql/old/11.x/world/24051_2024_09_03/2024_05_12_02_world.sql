UPDATE `creature_template_difficulty` SET `StaticFlags1`=`StaticFlags1` & ~0x20000000 WHERE `entry` IN(61788, 61680);

DELETE FROM `creature_static_flags_override` WHERE `SpawnId` IN(4000126, 4000122, 4000098, 4000042);
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(4000126, 0, 805306624, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(4000122, 0, 805306624, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(4000042, 0, 805306624, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(4000098, 0, 805306624, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `creature_addon` WHERE `guid`=4000126;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(4000126, 0, 0, 0, 0, 3, 0, 1, 0, 0, 2297, 0, 0, 0, '');
