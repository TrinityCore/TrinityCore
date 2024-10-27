SET @CGUID := 3990012;

UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=46647; -- Training Dummy
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=31146; -- Raider's Training Dummy

UPDATE `creature_template_addon` SET `auras`='98892' WHERE `entry`=31146; -- 31146 (Raider's Training Dummy) - Training Dummy Marker
UPDATE `creature_template_addon` SET `auras`='98892' WHERE `entry`=46647; -- 46647 (Training Dummy) - Training Dummy Marker
UPDATE `creature_template_addon` SET `auras`='98892' WHERE `entry`=32667; -- 32667 (Training Dummy) - Training Dummy Marker
UPDATE `creature_template_addon` SET `auras`='98892' WHERE `entry`=32666; -- 32666 (Training Dummy) - Training Dummy Marker
UPDATE `creature_template_addon` SET `auras`='98892' WHERE `entry`=31144; -- 31144 (Training Dummy) - Training Dummy Marker

UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56713 WHERE (`Entry`=46647 AND `DifficultyID`=0); -- 46647 (Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56713 WHERE (`Entry`=32667 AND `DifficultyID`=0); -- 32667 (Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56713 WHERE (`Entry`=32666 AND `DifficultyID`=0); -- 32666 (Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56713 WHERE (`Entry`=31146 AND `DifficultyID`=0); -- 31146 (Raider's Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56713 WHERE (`Entry`=31144 AND `DifficultyID`=0); -- 31144 (Training Dummy) - Sessile, Floating

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 31144, 0, 1519, 5149, '0', 0, 0, 0, 0, -8755.16015625, 318.140625, 101.10247802734375, 0.366519153118133544, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Training Dummy (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 61574 - Banner of the Horde, 98892 - Training Dummy Marker)
(@CGUID+1, 31146, 0, 1519, 5149, '0', 0, 0, 0, 0, -8746.263671875, 361.171875, 101.4435272216796875, 5.480333805084228515, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Raider's Training Dummy (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+2, 31146, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.03125, 368.875, 100.912322998046875, 3.926990747451782226, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Raider's Training Dummy (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+3, 31146, 0, 1519, 5149, '0', 0, 0, 0, 0, -8716.3037109375, 361.6944580078125, 101.0802154541015625, 4.415682792663574218, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Raider's Training Dummy (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+4, 31146, 0, 1519, 5149, '0', 0, 0, 0, 0, -8746.201171875, 333.34027099609375, 101.10247802734375, 0.453785598278045654, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Raider's Training Dummy (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+5, 32666, 0, 1519, 5149, '0', 0, 0, 0, 0, -8746.1806640625, 309.838531494140625, 100.5484771728515625, 1.431169986724853515, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Training Dummy (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 61574 - Banner of the Horde, 98892 - Training Dummy Marker)
(@CGUID+6, 32667, 0, 1519, 5149, '0', 0, 0, 0, 0, -8751.330078125, 312.484375, 101.10247802734375, 0.959931075572967529, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Training Dummy (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 61574 - Banner of the Horde, 98892 - Training Dummy Marker)
(@CGUID+7, 46647, 0, 1519, 5149, '0', 0, 0, 0, 0, -8724.3212890625, 362.942718505859375, 100.9847564697265625, 4.433136463165283203, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Training Dummy (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+8, 46647, 0, 1519, 5149, '0', 0, 0, 0, 0, -8716.0380859375, 340.060760498046875, 100.7029266357421875, 3.019419670104980468, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Training Dummy (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+9, 46647, 0, 1519, 5149, '0', 0, 0, 0, 0, -8730.5908203125, 324.94097900390625, 99.63372802734375, 1.797689080238342285, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Training Dummy (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+10, 46647, 0, 1519, 5149, '0', 0, 0, 0, 0, -8737.3544921875, 323.482635498046875, 99.962127685546875, 1.867502331733703613, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713); -- Training Dummy (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '61574 98892'), -- Training Dummy - 61574 - Banner of the Horde, 98892 - Training Dummy Marker
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 61574'), -- Raider's Training Dummy - 98892 - Training Dummy Marker, 61574 - Banner of the Horde
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 61574'), -- Raider's Training Dummy - 98892 - Training Dummy Marker, 61574 - Banner of the Horde
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 61574'), -- Raider's Training Dummy - 98892 - Training Dummy Marker, 61574 - Banner of the Horde
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 61574'), -- Raider's Training Dummy - 98892 - Training Dummy Marker, 61574 - Banner of the Horde
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '61574 98892'), -- Training Dummy - 61574 - Banner of the Horde, 98892 - Training Dummy Marker
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '61574 98892'), -- Training Dummy - 61574 - Banner of the Horde, 98892 - Training Dummy Marker
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 61574'), -- Training Dummy - 98892 - Training Dummy Marker, 61574 - Banner of the Horde
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 61574'), -- Training Dummy - 98892 - Training Dummy Marker, 61574 - Banner of the Horde
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 61574'), -- Training Dummy - 98892 - Training Dummy Marker, 61574 - Banner of the Horde
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 61574'); -- Training Dummy - 98892 - Training Dummy Marker, 61574 - Banner of the Horde
