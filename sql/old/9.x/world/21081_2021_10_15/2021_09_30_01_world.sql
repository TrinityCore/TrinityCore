-- Unfortunate Measures
UPDATE `quest_offer_reward` SET `VerifiedBuild`=40120 WHERE `ID`=8326;

DELETE FROM `quest_poi` WHERE (`QuestID`=8326 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=8326 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=8326 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(8326, 0, 2, 32, 0, 0, 530, 467, 0, 0, 0, 0, 0, 120146, 0, 40120),
(8326, 0, 1, 0, 256445, 20797, 530, 467, 0, 1, 0, 0, 0, 0, 0, 40120),
(8326, 0, 0, -1, 0, 0, 530, 467, 0, 1, 0, 0, 0, 0, 0, 40120);

DELETE FROM `quest_poi_points` WHERE (`QuestID`=8326 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=8326 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=8326 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=8326 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=8326 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=8326 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=8326 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=8326 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=8326 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(8326, 2, 0, 10352, -6360, 34, 40120),
(8326, 1, 6, 10457, -6375, 22, 40120),
(8326, 1, 5, 10493, -6418, 40, 40120),
(8326, 1, 4, 10518, -6449, 47, 40120),
(8326, 1, 3, 10521, -6483, 20, 40120),
(8326, 1, 2, 10345, -6522, 27, 40120),
(8326, 1, 1, 10313, -6474, 65, 40120),
(8326, 1, 0, 10360, -6453, 65, 40120),
(8326, 0, 0, 10358, -6370, 34, 40120);

UPDATE `quest_details` SET `VerifiedBuild`=40120 WHERE `ID`=8326;

UPDATE `quest_request_items` SET `VerifiedBuild`=40120 WHERE `ID`=8326;

UPDATE `quest_template` SET `RewardMoney`=120, `RewardBonusMoney`=390, `FlagsEx`=0, `VerifiedBuild`=40120 WHERE `ID`=8326;
