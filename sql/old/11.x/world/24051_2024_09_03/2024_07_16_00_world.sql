SET @OGUID := 8000015;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 350803, 2175, 10424, 10528, '0', 15355, 0, 465.720489501953125, -2508.295166015625, 147.4104156494140625, 3.157217979431152343, 0, 0, -0.999969482421875, 0.0078125, 120, 255, 1, 55461), -- Harpy Totem (Area: Harpy Roost - Difficulty: 0) CreateObject1
(@OGUID+1, 350803, 2175, 10424, 10528, '0', 15355, 0, 481.75, -2452.32470703125, 152.03143310546875, 0.12650531530380249, 0, 0, 0.063210487365722656, 0.998000204563140869, 120, 255, 1, 55461), -- Harpy Totem (Area: Harpy Roost - Difficulty: 0) CreateObject1
(@OGUID+2, 350803, 2175, 10424, 10528, '0', 15355, 0, 430.526031494140625, -2487.46533203125, 142.301300048828125, 1.587361812591552734, 0, 0, 0.712939262390136718, 0.701225817203521728, 120, 255, 1, 55461), -- Harpy Totem (Area: Harpy Roost - Difficulty: 0) CreateObject1
(@OGUID+3, 350803, 2175, 10424, 10528, '0', 15355, 0, 552.93402099609375, -2513.6650390625, 154.2525177001953125, 3.795985698699951171, 0, 0, -0.94694709777832031, 0.321389496326446533, 120, 255, 1, 55461), -- Harpy Totem (Area: Harpy Roost - Difficulty: 0) CreateObject1
(@OGUID+4, 350803, 2175, 10424, 10528, '0', 15355, 0, 502, -2589.651123046875, 155.433013916015625, 1.940680384635925292, 0, 0, 0.825078010559082031, 0.565018832683563232, 120, 255, 1, 55461); -- Harpy Totem (Area: Harpy Roost - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry`=350803;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(350803, 35, 262176, 0, 0); -- Harpy Totem

-- Phase
DELETE FROM `phase_area` WHERE `PhaseId` IN (15356, 15355); 
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(10424, 15356, 'Cosmetic - See Harpy Totems in Harpy Roost (A)'),
(10424, 15355, 'Cosmetic - See Harpy Totems in Harpy Roost (H)');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 15356 AND `SourceEntry` = 0) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 15355 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 15356, 0, 0, 0, 6, 0, 469, 0, 0, 0, 'Apply Phase 15356 if player is Team Alliance'),
(26, 15355, 0, 0, 0, 6, 0, 67, 0, 0, 0, 'Apply Phase 15355 if player is Team Horde');

-- SpawnGroups
DELETE FROM `spawn_group` WHERE (`groupId` = 128 AND `spawnId` IN (600238, 600239, 600240, 600241, 600242));
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(128, 1, 600238),
(128, 1, 600239),
(128, 1, 600240),
(128, 1, 600241),
(128, 1, 600242);

DELETE FROM `spawn_group` WHERE (`groupId` = 129 AND `spawnId` IN (@OGUID+0, @OGUID+1, @OGUID+2, @OGUID+3, @OGUID+4));
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(129, 1, @OGUID+0),
(129, 1, @OGUID+1),
(129, 1, @OGUID+2),
(129, 1, @OGUID+3),
(129, 1, @OGUID+4);
