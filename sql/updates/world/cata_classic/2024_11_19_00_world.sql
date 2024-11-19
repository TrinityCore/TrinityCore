SET @CGUID := 3990051;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 2439, 0, 1519, 1519, '0', '0', 0, 0, 0, -8355.2099609375, 243.9739990234375, 155.430328369140625, 2.984513044357299804, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564), -- Major Samuelson (Area: Stormwind City - Difficulty: 0) CreateObject1
(@CGUID+1, 29611, 0, 1519, 1519, '0', '0', 0, 0, 1, -8363.0595703125, 232.236114501953125, 157.073333740234375, 2.234021425247192382, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564), -- King Varian Wrynn (Area: Stormwind City - Difficulty: 0) CreateObject1 (Auras: 18943 - Double Attack)
(@CGUID+2, 45253, 0, 1519, 1519, '0', '0', 0, 0, 1, -8364.9296875, 230.891998291015625, 157.073333740234375, 2.268928050994873046, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564), -- Genn Greymane (Area: Stormwind City - Difficulty: 0) CreateObject1
(@CGUID+3, 1747, 0, 1519, 1519, '0', '0', 0, 0, 1, -8361.3603515625, 233.5630035400390625, 157.073333740234375, 2.268928050994873046, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564); -- Anduin Wrynn (Area: Stormwind City - Difficulty: 0) CreateObject1 (Auras: 82804 - Anduin Wrynn Quest Invis)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Major Samuelson
(@CGUID+1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 3, '18943'), -- King Varian Wrynn - 18943 - Double Attack
(@CGUID+2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 3, ''), -- Genn Greymane
(@CGUID+3, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '82804'); -- Anduin Wrynn - 82804 - Anduin Wrynn Quest Invis

DELETE FROM `creature_template_gossip` WHERE `CreatureID`= 29611;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(29611, 9834, 57564); -- King Varian Wrynn
