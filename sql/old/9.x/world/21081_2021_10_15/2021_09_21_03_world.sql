-- 37443 Solanian's Belongings
UPDATE `quest_template` SET `RewardMoney`=200, `RewardBonusMoney`=270, `FlagsEx`=0, `VerifiedBuild`=40120 WHERE `ID`=37443;

UPDATE `quest_template_addon` SET `PrevQuestID`=8326 WHERE `ID`=37443; 

UPDATE `quest_offer_reward` SET `VerifiedBuild`=40120 WHERE `ID`=37443;

DELETE FROM `quest_poi` WHERE (`QuestID`=37443 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=37443 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=37443 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37443 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37443 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(37443, 0, 4, 32, 0, 0, 530, 467, 0, 0, 0, 0, 0, 120439, 0, 40120),
(37443, 0, 3, 2, 276222, 20472, 530, 467, 0, 0, 0, 0, 0, 120395, 0, 40120),
(37443, 0, 2, 1, 276221, 20471, 530, 467, 0, 0, 0, 0, 0, 120392, 0, 40120),
(37443, 0, 1, 0, 276220, 20470, 530, 467, 0, 0, 0, 0, 0, 120390, 0, 40120),
(37443, 0, 0, -1, 0, 0, 530, 467, 0, 0, 0, 0, 0, 120439, 0, 40120);

DELETE FROM `quest_poi_points` WHERE (`QuestID`=37443 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=37443 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=37443 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37443 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37443 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(37443, 4, 0, 10376, -6407, 50, 40120),
(37443, 3, 0, 10224, -6344, 31, 40120),
(37443, 2, 0, 10295, -6030, 28, 40120),
(37443, 1, 0, 10093, -6218, 17, 40120),
(37443, 0, 0, 10376, -6407, 50, 40120);

UPDATE `quest_details` SET `VerifiedBuild`=40120 WHERE `ID`=37443;

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=40120 WHERE `ID`=37443;
