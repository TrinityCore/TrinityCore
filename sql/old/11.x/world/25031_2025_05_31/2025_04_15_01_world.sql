SET @OGUID := 7000463;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 272801, 1643, 8721, 9130, '0', 0, 0, -397.6788330078125, 1455.5, 24.419403076171875, 0, 0, 0, 0, 1, 120, 255, 1, 60257), -- Place Trap (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+1, 272801, 1643, 8721, 9130, '0', 0, 0, -418.489593505859375, 1443.470458984375, 26.84453582763671875, 1.51916205883026123, 0, 0, 0.688617706298828125, 0.725124597549438476, 120, 255, 1, 60257), -- Place Trap (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+2, 272801, 1643, 8721, 9130, '0', 0, 0, -450.0694580078125, 1375.670166015625, 28.07542991638183593, 1.866720080375671386, 0, 0, 0.803624153137207031, 0.59513711929321289, 120, 255, 1, 60257), -- Place Trap (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+3, 272801, 1643, 8721, 9130, '0', 0, 0, -447.48785400390625, 1400.9375, 29.6322021484375, 0, 0, 0, 0, 1, 120, 255, 1, 60257), -- Place Trap (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+4, 272801, 1643, 8721, 9130, '0', 0, 0, -418.7882080078125, 1347.0694580078125, 25.70470428466796875, 0, 0, 0, 0, 1, 120, 255, 1, 60257), -- Place Trap (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+5, 272801, 1643, 8721, 9130, '0', 0, 0, -424.96875, 1388.6788330078125, 27.40679931640625, 0, 0, 0, 0, 1, 120, 255, 1, 60257), -- Place Trap (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+6, 272801, 1643, 8721, 9130, '0', 0, 0, -377.15625, 1378.0521240234375, 20.95171546936035156, 1.578446745872497558, 0, 0, 0.709806442260742187, 0.704396784305572509, 120, 255, 1, 60257), -- Place Trap (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+7, 272801, 1643, 8721, 9130, '0', 0, 0, -380.673614501953125, 1427.326416015625, 23.42271232604980468, 5.047329425811767578, 0, 0, -0.57934761047363281, 0.815080583095550537, 120, 255, 1, 60257); -- Place Trap (Area: Hangman's Point - Difficulty: 0) CreateObject1

-- Template
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=60257 WHERE `entry`=272801; -- Place Trap

-- SpawnTracking
DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (1355076,1355078,1355073,1355077,1355071,1355074,1355072,1355075);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(1355076, 1643, 0, 0, 0, 60257), -- Map: 1643 (Kul Tiras) - Phase: 0
(1355078, 1643, 0, 0, 0, 60257), -- Map: 1643 (Kul Tiras) - Phase: 0
(1355073, 1643, 0, 0, 0, 60257), -- Map: 1643 (Kul Tiras) - Phase: 0
(1355077, 1643, 0, 0, 0, 60257), -- Map: 1643 (Kul Tiras) - Phase: 0
(1355071, 1643, 0, 0, 0, 60257), -- Map: 1643 (Kul Tiras) - Phase: 0
(1355074, 1643, 0, 0, 0, 60257), -- Map: 1643 (Kul Tiras) - Phase: 0
(1355072, 1643, 0, 0, 0, 60257), -- Map: 1643 (Kul Tiras) - Phase: 0
(1355075, 1643, 0, 0, 0, 60257); -- Map: 1643 (Kul Tiras) - Phase: 0

DELETE FROM `spawn_tracking` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4,@OGUID+5,@OGUID+6,@OGUID+7));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveId`) VALUES
(1355076, 1, @OGUID+0, 291539), -- Place Trap
(1355078, 1, @OGUID+1, 291539), -- Place Trap
(1355073, 1, @OGUID+2, 291539), -- Place Trap
(1355077, 1, @OGUID+3, 291539), -- Place Trap
(1355071, 1, @OGUID+4, 291539), -- Place Trap
(1355074, 1, @OGUID+5, 291539), -- Place Trap
(1355072, 1, @OGUID+6, 291539), -- Place Trap
(1355075, 1, @OGUID+7, 291539); -- Place Trap

DELETE FROM `spawn_tracking_quest_objective` WHERE `QuestObjectiveId`=291539;
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(1355071,291539,60257),
(1355072,291539,60257),
(1355073,291539,60257),
(1355074,291539,60257),
(1355075,291539,60257),
(1355076,291539,60257),
(1355077,291539,60257),
(1355078,291539,60257);

DELETE FROM `spawn_tracking_state` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4,@OGUID+5,@OGUID+6,@OGUID+7));
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(1, @OGUID+0, 0, 0, NULL, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+0, 1, 1, 37794, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+0, 2, 1, 8743, NULL, 8021, NULL), -- Place Trap
(1, @OGUID+1, 0, 0, NULL, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+1, 1, 1, 37794, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+1, 2, 1, 8743, NULL, 8021, NULL), -- Place Trap
(1, @OGUID+2, 0, 0, NULL, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+2, 1, 1, 37794, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+2, 2, 1, 8743, NULL, 8021, NULL), -- Place Trap
(1, @OGUID+3, 0, 0, NULL, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+3, 1, 1, 37794, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+3, 2, 1, 8743, NULL, 8021, NULL), -- Place Trap
(1, @OGUID+4, 0, 0, NULL, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+4, 1, 1, 37794, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+4, 2, 1, 8743, NULL, 8021, NULL), -- Place Trap
(1, @OGUID+5, 0, 0, NULL, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+5, 1, 1, 37794, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+5, 2, 1, 8743, NULL, 8021, NULL), -- Place Trap
(1, @OGUID+6, 0, 0, NULL, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+6, 1, 1, 37794, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+6, 2, 1, 8743, NULL, 8021, NULL), -- Place Trap
(1, @OGUID+7, 0, 0, NULL, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+7, 1, 1, 37794, NULL, NULL, NULL), -- Place Trap
(1, @OGUID+7, 2, 1, 8743, NULL, 8021, NULL); -- Place Trap
