SET @OGUID := 7000606;

-- Creature
UPDATE `creature` SET `StringID` = 'ChannelWitch' WHERE `guid` = 7003002;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 273050, 1643, 8721, 9134, '0', 0, 0, -1067.8177490234375, 1810.517333984375, 119.9439163208007812, 1.499202370643615722, 0, 0, 0.681346893310546875, 0.731960654258728027, 120, 255, 1, 60568), -- Minor Ancient Cairn (Area: Gol Koval - Difficulty: 0) CreateObject1
(@OGUID+1, 278735, 1643, 8721, 9134, '0', 0, 0, -1209.0260009765625, 1716.9166259765625, 120.814361572265625, 0, 0, 0, 0, 1, 120, 255, 1, 60568), -- Minor Ancient Cairn (Area: Gol Koval - Difficulty: 0) CreateObject1
(@OGUID+2, 278736, 1643, 8721, 9134, '0', 0, 0, -1174.092041015625, 1893.2586669921875, 139.9482879638671875, 0, 0, 0, 0, 1, 120, 255, 1, 60568), -- Minor Ancient Cairn (Area: Gol Koval - Difficulty: 0) CreateObject1
(@OGUID+3, 278738, 1643, 8721, 9134, '0', 0, 0, -1270.4913330078125, 1899.5538330078125, 142.1095733642578125, 3.764612674713134765, 0, 0, -0.95187187194824218, 0.306496262550354003, 120, 255, 1, 60568), -- Minor Ancient Cairn (Area: Gol Koval - Difficulty: 0) CreateObject1
(@OGUID+4, 277727, 1643, 8721, 9134, '0', 0, 0, -1333.7291259765625, 1912.546875, 161.7480316162109375, 4.09563446044921875, 0, 0, -0.88836669921875, 0.459134608507156372, 120, 255, 1, 60568); -- Major Ancient Cairn (Area: Gol Koval - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (277727 /*Major Ancient Cairn*/, 278738 /*Minor Ancient Cairn*/, 278736 /*Minor Ancient Cairn*/, 278735 /*Minor Ancient Cairn*/, 273050 /*Minor Ancient Cairn*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(277727, 0, 0x40005, 0, 0), -- Major Ancient Cairn
(278738, 0, 0x40005, 0, 0), -- Minor Ancient Cairn
(278736, 0, 0x40005, 0, 0), -- Minor Ancient Cairn
(278735, 0, 0x40005, 0, 0), -- Minor Ancient Cairn
(273050, 0, 0x40005, 0, 0); -- Minor Ancient Cairn

-- Template
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=60568 WHERE `entry`=277727; -- Major Ancient Cairn
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=60568 WHERE `entry` IN (278738, 278736, 278735, 273050); -- Minor Ancient Cairn

-- Quest
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (294156,295081,295091,295092);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(294156, NULL, 251019, NULL, 1, 0),
(295081, NULL, 251019, NULL, 1, 0),
(295091, NULL, 251019, NULL, 1, 0),
(295092, NULL, 251019, NULL, 1, 0);

-- SpawnTracking
DELETE FROM `spawn_tracking` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveId`) VALUES
(1360838, 1, @OGUID+0, 294156), -- Minor Ancient Cairn
(1359128, 1, @OGUID+1, 295081), -- Minor Ancient Cairn
(1360837, 1, @OGUID+2, 295091), -- Minor Ancient Cairn
(1360836, 1, @OGUID+3, 295092), -- Minor Ancient Cairn
(1401363, 1, @OGUID+4, 295093); -- Major Ancient Cairn

DELETE FROM `spawn_tracking_state` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4));
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(1, @OGUID+0, 0, 0, NULL, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+0, 1, 1, NULL, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+0, 2, 0, 72695, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+1, 0, 0, NULL, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+1, 1, 1, NULL, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+1, 2, 0, 72695, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+2, 0, 0, NULL, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+2, 1, 1, NULL, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+2, 2, 0, 72695, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+3, 0, 0, NULL, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+3, 1, 1, NULL, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+3, 2, 0, 72695, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+4, 0, 0, NULL, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+4, 1, 1, NULL, NULL, NULL, NULL), -- Minor Ancient Cairn
(1, @OGUID+4, 2, 0, 72695, NULL, NULL, NULL); -- Major Ancient Cairn
