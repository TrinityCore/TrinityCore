-- Quest POIs
DELETE FROM `quest_poi` WHERE (`QuestID`=9294 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=9294 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=9294 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(9294, 0, 2, 32, 0, 0, 530, 468, 0, 0, 0, 0, 0, 136400, 0, 46924), -- Healing the Lake
(9294, 0, 1, 0, 260415, 88791, 530, 468, 0, 0, 0, 0, 0, 0, 0, 46924), -- Healing the Lake
(9294, 0, 0, -1, 0, 0, 530, 468, 0, 0, 0, 0, 0, 0, 0, 46924); -- Healing the Lake

DELETE FROM `quest_poi_points` WHERE (`QuestID`=9294 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=9294 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=9294 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(9294, 2, 0, -4057, -13722, 73, 46924), -- Healing the Lake
(9294, 1, 0, -4387, -13632, 0, 46924), -- Healing the Lake
(9294, 0, 0, -4057, -13722, 73, 46924); -- Healing the Lake
