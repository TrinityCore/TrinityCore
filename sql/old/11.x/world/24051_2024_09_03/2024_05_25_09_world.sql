-- 
SET @CGUID := 7000553;

DELETE FROM `phase_name` WHERE `ID`=12626;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12626, 'Cosmetic: Kul Tiran Unlock Questline - Dorian Atwater near Haunted Lumber in Evergreen Grove');

DELETE FROM `phase_area` WHERE `PhaseId`=12626;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9358, 12626, 'Cosmetic: Kul Tiran Unlock Questline - Dorian Atwater near Haunted Lumber - Evergreen Grove');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12626));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12626, 0, 0, 0, 47, 0, 54727, 66, 0, '', 0, 'Player have Team Carry (54727) in state complete, rewarded'),
(26, 12626, 0, 0, 0, 47, 0, 54728, 64, 0, '', 1, 'Player doesn\'t have The Lumber is Haunted (54728) in state rewarded'),
(26, 12626, 0, 0, 0, 47, 0, 54729, 64, 0, '', 1, 'Player doesn\'t have The Bleak Hills (54729) in state rewarded');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 148870, 1643, 8567, 9358, '0', 12626, 0, 0, 0, 1701.2864990234375, 10.18055534362792968, 67.647979736328125, 0.581830918788909912, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762); -- Dorian Atwater (Area: Evergreen Grove - Difficulty: 0) CreateObject1
