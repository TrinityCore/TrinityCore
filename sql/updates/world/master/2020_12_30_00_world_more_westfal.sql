-- More westfall quest poi fixes

DELETE FROM `quest_poi` WHERE `QuestID` = '26322';
DELETE FROM `quest_poi_points` WHERE `QuestID` = '26322';
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26322, 0, 0, -1, 0, 0, 0, 84, 0, 0, 0, 0, 0, 0, 24330);
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26322, 0, 1, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 24330);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26322, 0, 0, -8363, 232, 24330);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26322, 1, 0, -10533, 1021, 24330);
--

DELETE FROM `quest_poi` WHERE `QuestID` = '26289';
DELETE FROM `quest_poi_points` WHERE `QuestID` = '26289';
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26289, 0, 0, -1, 0, 0, 0, 39, 0, 1, 0, 0, 0, 0, 24330);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26289, 0, 0, -11042, 625, 24330);
