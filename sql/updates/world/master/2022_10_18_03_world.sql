-- Maynard Algerson
SET @CGUID := 850659;

DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 129613, 1643, 8567, 9358, '0', 10479, 0, 0, 0, 1659.6406, -119.65972, 57.10854, 4.436957359313964843, 120, 0, 0, 1, 0, 0, 0, 0, 0, 45745);

DELETE FROM `creature_questender` WHERE `id`=129613 AND `quest`=49467;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(129613, 49467, 45745);

DELETE FROM `phase_area` WHERE `AreaId` IN (9358,9365) AND `PhaseId`=10479;
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(9358,10479, 'Cosmetic - Tiragarde Sound - Quest 49467'),
(9365,10479, 'Cosmetic - Tiragarde Sound - Quest 49467');

DELETE FROM  `phase_name` WHERE `ID`=10479;
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(10479, 'Cosmetic - Show Maynard Algerson');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=10479 AND `SourceEntry` IN (9358,9365) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 10479, 9358, 0, 0, 28, 0, 49467, 0, 0, 0, 0, 0, '', 'Show Phase 10479 for area 9358 if quest Witch of the Woods is complete'),
(26, 10479, 9365, 0, 0, 28, 0, 49467, 0, 0, 0, 0, 0, '', 'Show Phase 10479 for area 9365 if quest Witch of the Woods is complete');
