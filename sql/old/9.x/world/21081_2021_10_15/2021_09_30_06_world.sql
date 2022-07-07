-- Aggression
UPDATE `quest_offer_reward` SET `VerifiedBuild`=40120 WHERE `ID`=8334;

UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8334 AND `BlobIndex`=0 AND `Idx1` IN (0,1,2,3));

UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8334 AND `Idx1`=3 AND `Idx2`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8334 AND `Idx1`=2 AND `Idx2` IN (0,1,2,3,4,5,6,7,8,9,10,11));
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8334 AND `Idx1`=1 AND `Idx2` IN (0,1,2,3,4,5,6,7,8,9));
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8334 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `Emote1`=5, `Emote3`=1, `VerifiedBuild`=40120 WHERE `ID`=8334;

UPDATE `quest_template` SET `RewardMoney`=200, `RewardBonusMoney`=270, `FlagsEx`=0, `VerifiedBuild`=40120 WHERE `ID`=8334;
