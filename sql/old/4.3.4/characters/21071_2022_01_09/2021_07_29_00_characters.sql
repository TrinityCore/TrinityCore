ALTER TABLE `guild` 
ADD COLUMN `WeeklyBonusMoney` bigint UNSIGNED NOT NULL DEFAULT 0 AFTER `completedRatedBattlegroundChallenges`;
