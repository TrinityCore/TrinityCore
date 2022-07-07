-- Felendren the Banished
UPDATE `quest_offer_reward` SET `Emote1`=0, `Emote2`=0, `VerifiedBuild`=40120 WHERE `ID`=8335;

UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8335 AND `BlobIndex`=0 AND `Idx1` IN (0,1,2,3,4));

UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8335 AND `Idx1` IN (3,4) AND `Idx2`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8335 AND `Idx1`=2 AND `Idx2` IN (0,1,2));
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8335 AND `Idx1`=1 AND `Idx2` IN (0,1,2,3,4,5,6,7,8,9));
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8335 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=40120 WHERE `ID`=8335;

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=40120 WHERE `ID`=8335;

UPDATE `quest_template` SET `RewardMoney`=720, `RewardBonusMoney`=450, `VerifiedBuild`=40120 WHERE `ID`=8335;

UPDATE `quest_objectives` SET `VerifiedBuild`=40120 WHERE `ID` IN (256930,256931,256932);
