-- "Inoculation" (9303) is missing Reward next quest
UPDATE `quest_template` SET `RewardNextQuest`=9309 WHERE `Id`=9303;

-- "Urgent Delivery!" (9409) is missing Reward next quest
UPDATE `quest_template` SET `RewardNextQuest`=9283 WHERE `Id`=9409;
