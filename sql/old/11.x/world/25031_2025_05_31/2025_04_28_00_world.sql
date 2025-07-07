SET @OGUID := 7000471;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 272755, 1643, 8721, 9130, '0', 0, 0, -331.595489501953125, 1341.9427490234375, 8.073209762573242187, 4.660353660583496093, 0, 0, -0.72526264190673828, 0.688472270965576171, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+1, 277546, 1643, 8721, 9130, '0', 0, 0, -413.229156494140625, 1315.35595703125, 23.82360076904296875, 0, 0, 0, 0, 1, 120, 255, 0, 60490), -- Bug-Catching Jar (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+2, 272755, 1643, 8721, 9130, '0', 0, 0, -267.970489501953125, 1288.4947509765625, 4.185694217681884765, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+3, 272755, 1643, 8721, 9130, '0', 0, 0, -316.0625, 1362.486083984375, 5.584984779357910156, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+4, 272755, 1643, 8721, 9130, '0', 0, 0, -270.017364501953125, 1267.8802490234375, 2.300406932830810546, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+5, 272755, 1643, 8721, 9130, '0', 0, 0, -337.4288330078125, 1423.2274169921875, 13.48361396789550781, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+6, 272755, 1643, 8721, 9130, '0', 0, 0, -347.9600830078125, 1377.4132080078125, 14.02172565460205078, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+7, 272755, 1643, 8721, 9130, '0', 0, 0, -290.727447509765625, 1332.060791015625, 5.302012920379638671, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+8, 272755, 1643, 8721, 9130, '0', 0, 0, -254.5625, 1303.6771240234375, 3.30822920799255371, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+9, 272755, 1643, 8721, 9130, '0', 0, 0, -273.383697509765625, 1285.564208984375, 7.076454639434814453, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+10, 272755, 1643, 8721, 9130, '0', 0, 0, -271.14410400390625, 1344.423583984375, 2.886948108673095703, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+11, 272755, 1643, 8721, 9130, '0', 0, 0, -280.071197509765625, 1395.1492919921875, 1.765017390251159667, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+12, 272755, 1643, 8721, 9130, '0', 0, 0, -231.149307250976562, 1296.03125, 2.402006387710571289, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+13, 272755, 1643, 8721, 9130, '0', 0, 0, -311.239593505859375, 1443.217041015625, 12.68751239776611328, 0, 0, 0, 0, 1, 120, 255, 1, 60490), -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@OGUID+14, 272755, 1643, 8721, 9130, '0', 0, 0, -227.704864501953125, 1289.935791015625, 3.987019777297973632, 0, 0, 0, 0, 1, 120, 255, 1, 60490); -- Hovering Bloodflies (Area: Hangman's Point - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry`=277546;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(277546, 0, 0x40000, 0, 0); -- Bug-Catching Jar

-- Template
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=60490 WHERE `entry`=272755; -- Hovering Bloodflies
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=60490 WHERE `entry`=277546; -- Bug-Catching Jar

-- Spawntracking
DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (1354376 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354377 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354374 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354372 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354373 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354375 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354378 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354371 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354379 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354370 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354369 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1424072 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354380 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1354199 /*Map: 1643 (Kul Tiras) - Phase: 0*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(1354376, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354377, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354374, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354372, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354373, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354375, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354378, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354371, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354379, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354370, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354369, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1424072, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354380, 1643, 0, 0, 0, 60490), -- Map: 1643 (Kul Tiras) - Phase: 0
(1354199, 1643, 0, 0, 0, 60490); -- Map: 1643 (Kul Tiras) - Phase: 0

DELETE FROM `spawn_tracking_quest_objective` WHERE `QuestObjectiveId` IN (291619,294064);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(1399207,291619,60257), -- Bug-Catching Jar
(1354370,294064,60257), -- Hovering Bloodflies
(1354373,294064,60257), -- Hovering Bloodflies
(1354369,294064,60257), -- Hovering Bloodflies
(1354374,294064,60257), -- Hovering Bloodflies
(1354199,294064,60257), -- Hovering Bloodflies
(1354379,294064,60257), -- Hovering Bloodflies
(1354371,294064,60257), -- Hovering Bloodflies
(1354375,294064,60257), -- Hovering Bloodflies
(1354372,294064,60257), -- Hovering Bloodflies
(1354378,294064,60257), -- Hovering Bloodflies
(1424072,294064,60257), -- Hovering Bloodflies
(1354377,294064,60257), -- Hovering Bloodflies
(1354380,294064,60257), -- Hovering Bloodflies
(1354376,294064,60257); -- Hovering Bloodflies

DELETE FROM `spawn_tracking` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4,@OGUID+5,@OGUID+6,@OGUID+7,@OGUID+8,@OGUID+9,@OGUID+10,@OGUID+11,@OGUID+12,@OGUID+13,@OGUID+14));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveId`) VALUES
(1354370, 1, @OGUID+0, 294064), -- Hovering Bloodflies
(1399207, 1, @OGUID+1, 291619), -- Bug-Catching Jar
(1354373, 1, @OGUID+2, 294064), -- Hovering Bloodflies
(1354369, 1, @OGUID+3, 294064), -- Hovering Bloodflies
(1354374, 1, @OGUID+4, 294064), -- Hovering Bloodflies
(1354199, 1, @OGUID+5, 294064), -- Hovering Bloodflies
(1354379, 1, @OGUID+6, 294064), -- Hovering Bloodflies
(1354371, 1, @OGUID+7, 294064), -- Hovering Bloodflies
(1354375, 1, @OGUID+8, 294064), -- Hovering Bloodflies
(1354372, 1, @OGUID+9, 294064), -- Hovering Bloodflies
(1354378, 1, @OGUID+10, 294064), -- Hovering Bloodflies
(1424072, 1, @OGUID+11, 294064), -- Hovering Bloodflies
(1354377, 1, @OGUID+12, 294064), -- Hovering Bloodflies
(1354380, 1, @OGUID+13, 294064), -- Hovering Bloodflies
(1354376, 1, @OGUID+14, 294064); -- Hovering Bloodflies

DELETE FROM `spawn_tracking_state` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4,@OGUID+5,@OGUID+6,@OGUID+7,@OGUID+8,@OGUID+9,@OGUID+10,@OGUID+11,@OGUID+12,@OGUID+13,@OGUID+14));
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(1, @OGUID+1, 0, 1, NULL, NULL, NULL, NULL), -- Bug-Catching Jar
(1, @OGUID+1, 1, 1, NULL, NULL, NULL, NULL), -- Bug-Catching Jar
(1, @OGUID+1, 2, 0, NULL, NULL, NULL, NULL), -- Bug-Catching Jar
(1, @OGUID+0, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+0, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+0, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+2, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+2, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+2, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+3, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+3, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+3, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+4, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+4, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+4, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+5, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+5, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+5, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+6, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+6, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+6, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+7, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+7, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+7, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+8, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+8, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+8, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+9, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+9, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+9, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+10, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+10, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+10, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+11, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+11, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+11, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+12, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+12, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+12, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+13, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+13, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+13, 2, 0, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+14, 0, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+14, 1, 1, NULL, NULL, NULL, NULL), -- Hovering Bloodflies
(1, @OGUID+14, 2, 0, NULL, NULL, NULL, NULL); -- Hovering Bloodflies
