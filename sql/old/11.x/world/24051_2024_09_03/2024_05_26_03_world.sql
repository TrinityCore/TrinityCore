SET @CGUID := 7000561;

DELETE FROM `phase_name` WHERE `ID`=12859;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12859, 'Cosmetic: Kul Tiran Unlock Questline - FX Stalker in Ulfars Den');

DELETE FROM `phase_area` WHERE `PhaseId`=12859;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9965, 12859, 'Cosmetic: Kul Tiran Unlock Questline - FX Stalker - Ulfars Den');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12859));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12859, 0, 0, 0, 47, 0, 54731, 8, 0, '', 0, 'Player have Balance in All Things (54731) in state incomplete'),
(26, 12859, 0, 0, 0, 48, 0, 388256, 0, 1, '', 1, 'Player doesn\'t have quest objective 388256 == 1');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 149374, 1643, 8721, 9965, '0', 12859, 0, 0, 0, -488.498260498046875, 2723.900146484375, 279.36395263671875, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- FX Stalker (Area: Ulfar's Den - Difficulty: 0) CreateObject1

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x80 WHERE `entry`=149374;
