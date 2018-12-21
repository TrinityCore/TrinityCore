ALTER TABLE `lfg_dungeon_rewards` ADD COLUMN `completionsPerPeriod` TINYINT(3) UNSIGNED DEFAULT 0 NULL COMMENT 'Maximum amount that the first quest may be rewarded' AFTER `otherQuestId`;
ALTER TABLE `lfg_dungeon_rewards` ADD COLUMN `dailyReset` TINYINT(1) UNSIGNED DEFAULT 0 NULL COMMENT 'Indicator for resetting rewards daily or weekly' AFTER `completionsPerPeriod`;

UPDATE `quest_template` SET `RewardCurrencyId1`= 0, `RewardCurrencyCount1`= 0 WHERE `ID` = 28908;
UPDATE `quest_template` SET `RewardCurrencyCount1`= 14000 WHERE `ID` = 28907;
UPDATE `quest_template` SET `Flags`= 0 WHERE `ID`= 30110;

UPDATE `lfg_dungeon_rewards` SET `completionsPerPeriod`= 7 WHERE `dungeonId` NOT IN (417, 416, 434, 301);
UPDATE `lfg_dungeon_rewards` SET `completionsPerPeriod`= 1 WHERE `dungeonId` IN (417, 416);
UPDATE `lfg_dungeon_rewards` SET `completionsPerPeriod`= 1, `dailyReset`= 1 WHERE `dungeonId` IN (288, 287, 286, 285);
