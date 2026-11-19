-- Tainted Arcane Sliver
UPDATE `quest_offer_reward` SET `VerifiedBuild`=40120 WHERE `ID`=8338;

UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8338 AND `BlobIndex`=0 AND `Idx1` IN (0,1));

UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8338 AND `Idx1`=1 AND `Idx2` IN (0,1,2));
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8338 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=40120 WHERE `ID`=8338;

UPDATE `quest_template` SET `RewardMoney`=1130, `RewardBonusMoney`=450, `FlagsEx`=0, `VerifiedBuild`=40120 WHERE `ID`=8338;

UPDATE `quest_objectives` SET `VerifiedBuild`=40120 WHERE `ID`=257005;
