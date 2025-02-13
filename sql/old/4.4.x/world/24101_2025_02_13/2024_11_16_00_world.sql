SET @CGUID := 3990045;
DELETE FROM `creature` WHERE `guid`= @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID, 44247, 0, 1519, 5149, '0', '0', 0, 0, 0, -8820.8076171875, 347.74652099609375, 107.1317825317382812, 5.026548385620117187, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294); -- 44247 (Area: Old Town - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, ''); -- 44247

DELETE FROM `creature_equip_template` WHERE `ID`=1 AND `CreatureID`= 44247;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(44247, 1, 3191, 0, 0, 0, 0, 0, 36628, 0, 0, 57294); -- 44247
