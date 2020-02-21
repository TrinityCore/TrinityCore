DELETE FROM `spawn_group_template` WHERE `groupId` IN (427, 428);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(427, 'Shadowfang Keep - Lord Walden Alliance Troups', 4),
(428, 'Shadowfang Keep - Lord Walden Horde Troups', 4);

SET @CGUID := 395370;
DELETE FROM `spawn_group` WHERE `groupId` IN (427, 428);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
-- Lord Walden Alliance Troups
(427, 0, @CGUID+0),
(427, 0, @CGUID+1),
(427, 0, @CGUID+2),
(427, 0, @CGUID+3),
(427, 0, @CGUID+4),
(427, 0, @CGUID+5),
(427, 0, @CGUID+6),
(427, 0, @CGUID+7),
-- Lord Walden Horde Troups
(428, 0, @CGUID+8),
(428, 0, @CGUID+9),
(428, 0, @CGUID+10),
(428, 0, @CGUID+11),
(428, 0, @CGUID+12),
(428, 0, @CGUID+13),
(428, 0, @CGUID+14);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Lord Walden Alliance Troups
(@CGUID+0, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -156.882, 2177.6, 128.7793, 5.864306, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 58506 - Stealth)
(@CGUID+1, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -148.575, 2178.92, 128.2843, 5.078908, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 58506 - Stealth)
(@CGUID+2, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -136.068, 2168.84, 128.7793, 2.722714, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 58506 - Stealth)
(@CGUID+3, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -151.531, 2162.95, 128.7793, 1.082104, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 58506 - Stealth)
(@CGUID+4, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -152.111, 2170.61, 128.2843, 0.3665192, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 58506 - Stealth)
(@CGUID+5, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -141.684, 2183.09, 128.7793, 4.29351, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 58506 - Stealth)
(@CGUID+6, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -143.906, 2167.56, 128.2843, 1.972222, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 58506 - Stealth)
(@CGUID+7, 47006, 33, 209, 209, 3, 169, 0, 0, 0, -172.833, 2178.76, 129.3383, 0.6615827, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Packleader Ivar Bloodfang (Area: Shadowfang Keep - Difficulty: 2)
-- Lord Walden Horde Troups
(@CGUID+8, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -136.833, 2161.72, 138.7803, 2.059489, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+9, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -134.288, 2164.36, 138.7803, 2.373648, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+10, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -131.498, 2170.57, 138.7803, 3.124139, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+11, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -131.438, 2174.3, 138.7803, 3.473205, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+12, 47031, 33, 209, 0, 3, 169, 0, 0, 0, -131.734, 2167.9, 138.7803, 2.80998, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Forsaken Blightspreader (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+13, 47031, 33, 209, 0, 3, 169, 0, 0, 0, -132.72, 2166.21, 138.7803, 2.80998, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Forsaken Blightspreader (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+14, 47293, 33, 209, 0, 3, 169, 0, 0, 0, -171.7906, 2180.634, 129.2917, 1.069335, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595); -- Deathstalker Commander Belmont (Area: 0 - Difficulty: 0) (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14;
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `auras`) VALUES
(@CGUID+0, 0, 1, '58506'),
(@CGUID+1, 0, 1, '58506'),
(@CGUID+2, 0, 1, '58506'),
(@CGUID+3, 0, 1, '58506'),
(@CGUID+4, 0, 1, '58506'),
(@CGUID+5, 0, 1, '58506'),
(@CGUID+6, 0, 1, '58506');
