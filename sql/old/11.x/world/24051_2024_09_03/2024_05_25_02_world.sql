SET @CGUID := 7000544;

DELETE FROM `phase_name` WHERE `ID`=12866;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12866, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea calm');

DELETE FROM `phase_area` WHERE `PhaseId`=12866;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9500, 12866, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea calm - Bleak Hills Mine'),
(9432, 12866, 'Cosmetic: Kul Tiran Unlock Questline - Chelsea calm - Watchman''s Rise');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12866));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12866, 0, 0, 0, 47, 0, 54729, 66, 0, '', 0, 'Player have The Bleak Hills (54729) in state complete, rewarded');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 150884, 1643, 8721, 9500, '0', 12866, 0, 0, 0, 102.875, 3401.12841796875, 210.9712371826171875, 2.603888750076293945, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762); -- Chelsea Wright (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1

UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=150884 AND `DifficultyID`=0); -- 150884 (Chelsea Wright) - CanSwim

UPDATE `creature_template` SET `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=150884; -- Chelsea Wright
