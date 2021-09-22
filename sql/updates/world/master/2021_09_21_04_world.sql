UPDATE `quest_template` SET `RewardMoney`=1130, `RewardBonusMoney`=450, `FlagsEx`=0, `VerifiedBuild`=40000 WHERE `ID`=37442;

DELETE FROM `quest_template_addon` WHERE `ID`=37442;
INSERT INTO `quest_template_addon`(`ID`, `PrevQuestID`) VALUES 
(37442, 8326);

UPDATE `quest_offer_reward` SET `VerifiedBuild`=40120 WHERE `ID`=37442;

UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE `QuestID`=37442 AND `BlobIndex`=0 AND `Idx1` IN (0,1,2);

UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=37442 AND `Idx1` IN (0,1,2) AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=40120 WHERE `ID`=37442;

DELETE FROM `quest_request_items` WHERE `ID`=37442;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(37442, 0, 6, 0, 0, 'Have you read the plaque on the shrine then, $c?', 40120);
