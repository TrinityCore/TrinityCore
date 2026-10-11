-- Harpy Totems (Alliance) - Quest 55881
UPDATE `gameobject` SET `PhaseId`=15356 WHERE id=327146;

DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` BETWEEN 1825277 AND 1825281;
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(1825281, 2175, 15356, 0, 0, 55461), -- Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) - Phase: 15356 (Cosmetic - See Harpy Totems in Harpy Roost (A))
(1825280, 2175, 15356, 0, 0, 55461), -- Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) - Phase: 15356 (Cosmetic - See Harpy Totems in Harpy Roost (A))
(1825279, 2175, 15356, 0, 0, 55461), -- Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) - Phase: 15356 (Cosmetic - See Harpy Totems in Harpy Roost (A))
(1825278, 2175, 15356, 0, 0, 55461), -- Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) - Phase: 15356 (Cosmetic - See Harpy Totems in Harpy Roost (A))
(1825277, 2175, 15356, 0, 0, 55461); -- Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) - Phase: 15356 (Cosmetic - See Harpy Totems in Harpy Roost (A))

DELETE FROM `spawn_tracking_quest_objective` WHERE `QuestObjectiveId`=389809;
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(1825277,389809,55461),
(1825278,389809,55461),
(1825279,389809,55461),
(1825280,389809,55461),
(1825281,389809,55461);

DELETE FROM `spawn_tracking` WHERE `SpawnTrackingId` BETWEEN 1825277 AND 1825281;
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveId`) VALUES
(1825277,1,600238,389809),
(1825278,1,600240,389809),
(1825279,1,600242,389809),
(1825280,1,600241,389809),
(1825281,1,600239,389809);

DELETE FROM `spawn_tracking_state` WHERE `SpawnType`=1 AND `SpawnId` BETWEEN 600238 AND 600242;
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(1,600238,1,1,NULL,NULL,NULL,'2099'),
(1,600238,2,1,95449,NULL,NULL,NULL),
(1,600239,1,1,NULL,NULL,NULL,'2099'),
(1,600239,2,1,95449,NULL,NULL,NULL),
(1,600240,1,1,NULL,NULL,NULL,'2099'),
(1,600240,2,1,95449,NULL,NULL,NULL),
(1,600241,1,1,NULL,NULL,NULL,'2099'),
(1,600241,2,1,95449,NULL,NULL,NULL),
(1,600242,1,1,NULL,NULL,NULL,'2099'),
(1,600242,2,1,95449,NULL,NULL,NULL);
