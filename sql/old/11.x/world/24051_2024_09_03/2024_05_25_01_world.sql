SET @CGUID := 7000543;

DELETE FROM `phase_name` WHERE `ID` IN(12865, 12867);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12865, 'Cosmetic: Kul Tiran Unlock Questline - Wicker Beast in front of Chelsea'),
(12867, 'Cosmetic: Kul Tiran Unlock Questline - Unused');

DELETE FROM `phase_area` WHERE `PhaseId`=12865;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9500, 12865, 'Cosmetic: Kul Tiran Unlock Questline - Wicker Beast in front of Chelsea - Bleak Hills Mine'),
(9432, 12865, 'Cosmetic: Kul Tiran Unlock Questline - Wicker Beast in front of Chelsea - Watchman''s Rise');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12865));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12865, 0, 0, 0, 47, 0, 54729, 8, 0, '', 0, 'Player have The Bleak Hills (54729) in state incomplete');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 150885, 1643, 8721, 9500, '0', 12865, 0, 0, 0, 98.34722137451171875, 3404.9609375, 208.9343109130859375, 5.546810626983642578, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762); -- Wicker Beast (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
