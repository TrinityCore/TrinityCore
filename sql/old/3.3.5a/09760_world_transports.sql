ALTER TABLE `transports`
  ADD COLUMN `guid` int(10) UNSIGNED NOT NULL AUTO_INCREMENT FIRST,
  MODIFY COLUMN `entry` mediumint(8) unsigned NOT NULL DEFAULT '0' AFTER `guid`,
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`guid`),
  ADD UNIQUE INDEX `idx_entry` (`entry`);
