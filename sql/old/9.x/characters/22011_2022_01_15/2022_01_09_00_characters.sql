ALTER TABLE `guild_rank`
  ADD COLUMN `RankOrder` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `rid`;

UPDATE `guild_rank` SET `RankOrder`=`rid`; -- set some unique initial value
