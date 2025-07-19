SET @CGUID := 7000542;

DELETE FROM `phase_name` WHERE `ID`=12864;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12864, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea frightened');

DELETE FROM `phase_area` WHERE `PhaseId`=12864;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9500, 12864, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea frightened - Bleak Hills Mine'),
(9432, 12864, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea frightened - Watchman''s Rise');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12864));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12864, 0, 0, 0, 47, 0, 54729, 8, 0, '', 0, 'Player have The Bleak Hills (54729) in state incomplete');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 150884, 1643, 8721, 9500, '0', 12864, 0, 0, 0, 102.875, 3401.12841796875, 210.9712371826171875, 2.603888750076293945, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762); -- Chelsea Wright (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid`=@CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''); -- Chelsea Wright
