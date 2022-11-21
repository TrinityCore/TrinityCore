-- Terrence Foster
SET @CGUID := 850658;

DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 134325, 1643, 8567, 9365, '0', 10489, 0, 0, 0, 1443.484375, -424.4375, 24.3382568359375, 1.905074119567871093, 120, 0, 0, 1, 0, 0, 0, 0, 0, 45745);

DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID, 0, 0, 8, 1, 0, 0, 0, 0, 0, '');

DELETE FROM `creature_text` WHERE `CreatureID`=134325;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(134325, 0, 0, 'Alright... Looks like you cleared a path. I think I can make it out on my own.', 12, 0, 100, 1, 0, 0, 148358, 0, 'Terrence Foster to Player'),
(134325, 1, 0, 'If you can take out that spider... you\'re gonna help a lot of people.', 12, 0, 100, 6, 0, 0, 148359, 0, 'Terrence Foster to Player');

DELETE FROM `creature_queststarter` WHERE `id`=134325;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(134325, 50058, 45745);

DELETE FROM `phase_area` WHERE `AreaId` IN (9334,9365) AND `PhaseId`=10489;
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(9334,10489, 'Cosmetic - Tiragarde Sound - Quest 50058'),
(9365,10489, 'Cosmetic - Tiragarde Sound - Quest 50058');

DELETE FROM  `phase_name` WHERE `ID`=10489;
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(10489, 'Cosmetic - Show Terrence Foster');

-- Condition for source Phase condition type Quest not taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=10489 AND `SourceEntry` IN (9334,9365) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 10489, 9334, 0, 0, 14, 0, 50058, 0, 0, 0, 0, 0, '', 'Show Phase 10489 for area 9334 if quest The Witch\'s Pet has not been taken.'),
(26, 10489, 9365, 0, 0, 14, 0, 50058, 0, 0, 0, 0, 0, '', 'Show Phase 10489 for area 9365 if quest The Witch\'s Pet has not been taken.');
