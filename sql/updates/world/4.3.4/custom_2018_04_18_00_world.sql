ALTER TABLE `lfg_dungeon_rewards` ADD COLUMN `completionsPerWeek` TINYINT(3) UNSIGNED DEFAULT 0 NULL COMMENT 'Maximum amount that the first quest may be rewarded' AFTER `otherQuestId`;

UPDATE `quest_template` SET `RewardCurrencyId1`= 0, `RewardCurrencyCount1`= 0 WHERE `ID` = 28908;
UPDATE `quest_template` SET `RewardCurrencyCount1`= 14000 WHERE `ID` = 28907;
UPDATE `quest_template` SET `Flags`= 0 WHERE `ID`= 30110;

UPDATE `lfg_dungeon_rewards` SET `completionsPerWeek`= 7 WHERE `dungeonId` NOT IN (417, 416, 434, 301);
UPDATE `lfg_dungeon_rewards` SET `completionsPerWeek`= 1 WHERE `dungeonId` IN (417, 416);
