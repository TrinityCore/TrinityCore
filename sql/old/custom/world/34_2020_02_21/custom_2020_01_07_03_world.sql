DELETE FROM `spawn_group_template` WHERE `groupId` IN (423, 424);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(423, 'Shadowfang Keep - Baron Silverlaine Alliance Troups', 4),
(424, 'Shadowfang Keep - Baron Silverlaine Horde Troups', 4);

SET @CGUID := 395349;
DELETE FROM `spawn_group` WHERE `groupId` IN (423, 424);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(423, 0, @CGUID+0),
(423, 0, @CGUID+1),
(423, 0, @CGUID+2),
(423, 0, @CGUID+3),
(423, 0, @CGUID+4),
(423, 0, @CGUID+5),
(423, 0, @CGUID+6),
(424, 0, @CGUID+7),
(424, 0, @CGUID+8),
(424, 0, @CGUID+9),
(424, 0, @CGUID+10),
(424, 0, @CGUID+11),
(424, 0, @CGUID+12),
(424, 0, @CGUID+13);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Baron Silverlaine Troups Alliance
(@CGUID+0, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -287.359, 2313.4, 92.71404, 4.39823, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 58506 - Stealth)
(@CGUID+1, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -293.95, 2316.14, 92.78304, 4.433136, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 58506 - Stealth)
(@CGUID+2, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -292.418, 2310.59, 90.83453, 4.34587, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 58506 - Stealth)
(@CGUID+3, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -216.639, 2279.1, 95.98424, 2.986222, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+4, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -231.135, 2275.78, 96.04263, 2.454399, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+5, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -242.517, 2281.8, 96.40804, 2.64016, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+6, 47006, 33, 209, 209, 3, 169, 0, 0, 0, -276.547, 2298.07, 96.82654, 5.873963, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Packleader Ivar Bloodfang (Area: Shadowfang Keep - Difficulty: 2)
-- Baron Silverlaine Troups Horde
(@CGUID+7, 47031, 33, 209, 0, 3, 169, 0, 0, 0, -223.637, 2275.91, 77.13573, 5.585053, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Forsaken Blightspreader (Area: 0 - Difficulty: 0)
(@CGUID+8, 47031, 33, 209, 0, 3, 169, 0, 0, 0, -217.88, 2285.48, 77.13573, 1.448623, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Forsaken Blightspreader (Area: 0 - Difficulty: 0)
(@CGUID+9, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -288.9552, 2300.522, 89.72758, 4.921014, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+10, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -285.8244, 2304.515, 89.64634, 0.6435287, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+11, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -287.1191, 2305.041, 89.74182, 0.5727214, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+12, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -287.7312, 2299.908, 89.64044, 4.768981, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+13, 47293, 33, 209, 0, 3, 169, 0, 0, 0, -260.385, 2290.04, 75.08263, 2.775074, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Deathstalker Commander Belmont (Area: 0 - Difficulty: 0) (Auras: 58506 - Stealth)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `auras`) VALUES
(@CGUID+0, 0, 1, '58506'),
(@CGUID+1, 0, 1, '58506'),
(@CGUID+2, 0, 1, '58506'),
(@CGUID+13, 0, 1, '58506');

DELETE FROM `creature_text` WHERE `CreatureID`= 47027 AND `GroupID`= 1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(47027, 1, 0, 'Commander Springvale is down that hall, heroes.', 12, 0, 100, 397, 0, 0, 47158, 'Bloodfang Berserker');

DELETE FROM `areatrigger_scripts` WHERE `ScriptName`= 'at_sfk_baron_silverlaine_post_floor';
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(6422, 'at_sfk_baron_silverlaine_post_floor');
