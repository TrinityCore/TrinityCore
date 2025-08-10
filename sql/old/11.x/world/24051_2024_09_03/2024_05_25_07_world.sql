SET @CGUID := 7000552;

DELETE FROM `phase_name` WHERE `ID`=12884;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12884, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea Wright petting Princess in Bleak Hills Mine');

DELETE FROM `phase_area` WHERE `PhaseId`=12884;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9500, 12884, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea Wright petting Princess - Bleak Hills Mine'),
(9432, 12884, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea Wright petting Princess - Watchman''s Rise');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12884));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12884, 0, 0, 0, 47, 0, 54733, 74, 0, '', 0, 'Player have Make it Wright (54733) in state incomplete, complete, rewarded');

-- Princess Ritual Circle
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12875)) AND `ConditionValue1`=54733;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12875, 0, 0, 0, 47, 0, 54733, 74, 0, '', 1, 'Player doesn\'t have Make it Wright (54733) in state incomplete, complete, rewarded');

-- Chelsea calm
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12866)) AND `ConditionValue1`=54733;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12866, 0, 0, 0, 47, 0, 54733, 74, 0, '', 1, 'Player doesn\'t have Make it Wright (54733) in state incomplete, complete, rewarded');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 150884, 1643, 8721, 9432, '0', 12884, 0, 0, 0, 99.08159637451171875, 3403.7197265625, 209.405242919921875, 1.96906137466430664, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- Chelsea Wright (Area: Watchman's Rise - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+0);
INSERT INTO `creature_addon` (`guid`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 1, 0, 0, 11679, 0, 0, 0, ''); -- 150884 (Chelsea Wright)
