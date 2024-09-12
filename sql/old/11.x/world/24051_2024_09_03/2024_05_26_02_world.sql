SET @CGUID := 7000560;

DELETE FROM `phase_name` WHERE `ID`=12644;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12644, 'Cosmetic: Kul Tiran Unlock Questline - Ulfar before Ritual');

DELETE FROM `phase_area` WHERE `PhaseId`=12644;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9965, 12644, 'Cosmetic: Kul Tiran Unlock Questline - Ulfar before Ritual - Ulfars Den');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12644));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12644, 0, 0, 0, 48, 0, 388248, 0, 1, '', 0, 'Player have quest objective 388248 == 1'),
(26, 12644, 0, 0, 0, 48, 0, 388256, 0, 1, '', 1, 'Player doesn\'t have quest objective 388256 == 1');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 149386, 1643, 8721, 9965, '0', 12644, 0, 0, 0, -497.720489501953125, 2720.13720703125, 279.41680908203125, 0.197329580783843994, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- Ulfar (Area: Ulfar's Den - Difficulty: 0) CreateObject1

UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=149386 AND `DifficultyID`=0); -- 149386 (Ulfar) - CanSwim

UPDATE `creature_template` SET `faction`=3011, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=149386; -- Ulfar
