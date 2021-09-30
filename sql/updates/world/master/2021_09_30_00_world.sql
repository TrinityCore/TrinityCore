-- Reclaiming Sunstrider Isle
UPDATE `quest_offer_reward` SET `VerifiedBuild`=40120 WHERE `ID`=8325;

UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8325 AND `BlobIndex`=0 AND `Idx1` IN (0,1,2));

UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8325 AND `Idx1`=2 AND `Idx2`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8325 AND `Idx1`=1 AND `Idx2` IN (0,1,2,3,4,5,6,7,8,9,10));
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8325 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `Emote2`=1, `Emote3`=5, `VerifiedBuild`=40120 WHERE `ID`=8325;

UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `CompletionText`='Our work in rebuilding our society begins here, $n.  Once we are able to secure our home, we can look outward and upward.', `VerifiedBuild`=40120 WHERE `ID`=8325;

UPDATE `quest_template` SET `RewardMoney`=165, `RewardBonusMoney`=180, `FlagsEx`=512, `VerifiedBuild`=40120 WHERE `ID`=8325;
