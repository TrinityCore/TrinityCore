-- talent reward for group and dungeon quest without daily
UPDATE `quest_template`
SET `RewardTalents` = 1
WHERE `QuestInfoID` IN (1, 81) AND `RewardTalents` = 0 AND `QuestType` != 1 AND `Flags` != 4096
AND ID NOT IN (4606,4605,4604, 4603, 4602, 4601, 2952, 2951, 7737, 13662);

-- talent reward for raid quest without daily / weekly
UPDATE `quest_template`
SET `RewardTalents` = 2
WHERE `QuestInfoID` = 62 AND `RewardTalents` = 0 AND `QuestType` != 1 AND `Flags` NOT IN (4096, 32768)
AND ID NOT IN (4606,4605,4604, 4603, 4602, 4601, 2952, 2951, 7737, 13662);


-- talent reward for class quest without daily
UPDATE `quest_template`
SET `RewardTalents` = 1
WHERE `QuestSortID` IN (-61, -81, -82, -141, -161, -162, -261, -262, -263, -372)
AND `RewardTalents` = 0 AND `MinLevel` > 9 AND `Flags` != 4096;