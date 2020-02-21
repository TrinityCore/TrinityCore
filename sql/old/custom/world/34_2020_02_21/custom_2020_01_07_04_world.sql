DELETE FROM `spawn_group_template` WHERE `groupId` IN (425, 426);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(425, 'Shadowfang Keep - Commander Springvale Alliance Troups', 4),
(426, 'Shadowfang Keep - Outside Alliance Troups', 4);

SET @CGUID := 395363;
DELETE FROM `spawn_group` WHERE `groupId` IN (425, 426);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
-- Commander Springvale Alliance Troups
(425, 0, @CGUID+0),
(425, 0, @CGUID+1),
(425, 0, @CGUID+2),
-- Outside Alliance Troups
(426, 0, @CGUID+3),
(426, 0, @CGUID+4),
(426, 0, @CGUID+5),
(426, 0, @CGUID+6);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Commander Springvale Alliance Troups
(@CGUID+0, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -263.906, 2269.6, 97.62373, 5.88176, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+1, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -262.012, 2268.67, 98.67534, 5.934119, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+2, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -259.929, 2267.86, 99.79284, 5.934119, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
-- Outside Alliance Troups
(@CGUID+3, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -220.9429, 2223.227, 105.8726, 4.528842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+4, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -226.6541, 2222.231, 106.2409, 4.48631, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+5, 47006, 33, 209, 209, 3, 169, 0, 0, 0, -241.7395, 2217.392, 106.464, 4.622139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Packleader Ivar Bloodfang (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+6, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -234.9143, 2216.633, 106.979, 4.32102, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153); -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)

DELETE FROM `areatrigger_scripts` WHERE `ScriptName` IN
('at_sfk_pre_walden',
'at_sfk_outside_troups',
'at_sfk_gargoyle_event');

INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(6425, 'at_sfk_outside_troups'),
(255, 'at_sfk_gargoyle_event'),
(256, 'at_sfk_gargoyle_event');

DELETE FROM `creature_text` WHERE `CreatureID`= 43679;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `TextRange`, `BroadcastTextId`, `comment`) VALUES
(43679, 0, 0, 'A nearby Gargoyle comes to life!', 41, 0, 100, 0, 0, 0, 3, 47423, 'DEBUG Announcer');
