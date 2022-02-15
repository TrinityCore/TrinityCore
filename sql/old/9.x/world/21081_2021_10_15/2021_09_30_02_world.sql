-- Report to Lanthan Perilon
UPDATE `quest_offer_reward` SET `VerifiedBuild`=40120 WHERE `ID`=8327;

UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8327 AND `BlobIndex`=0 AND `Idx1` IN (0,1));

UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=8327 AND `Idx1` IN (0,1) AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=40120 WHERE `ID`=8327;

UPDATE `quest_template` SET `FlagsEx`=0, `VerifiedBuild`=40120 WHERE `ID`=8327;
