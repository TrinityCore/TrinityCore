-- A Fistful of Slivers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=40120 WHERE `ID`=37440;

UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=37440 AND `BlobIndex`=0 AND `Idx1` IN (0,1,2));

UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=37440 AND `Idx1`=2 AND `Idx2`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=37440 AND `Idx1`=1 AND `Idx2` IN (0,1,2,3,4,5,6,7,8,9,10,11));
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=37440 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=40120 WHERE `ID`=37440;

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=40120 WHERE `ID`=37440;

UPDATE `quest_template` SET `RewardBonusMoney`=270, `FlagsEx`=0, `VerifiedBuild`=40120 WHERE `ID`=37440;
