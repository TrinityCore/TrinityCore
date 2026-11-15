-- Sunstrider Guardian
DELETE FROM `creature_addon` WHERE `guid` IN (55172, 55173, 55170, 55171, 55169, 55168);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(55172, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55173, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55170, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55171, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55169, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55168, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''); -- Sunstrider Guardian
