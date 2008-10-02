ALTER TABLE `character_social` 
  ADD COLUMN `new_flags` tinyint(1) unsigned NOT NULL default '0';

UPDATE `character_social` SET `new_flags` = 1 WHERE `flags`='IGNORE';

ALTER TABLE `character_social` 
  DROP PRIMARY KEY,
  DROP COLUMN `flags`,
  CHANGE COLUMN `new_flags` `flags` tinyint(1) unsigned NOT NULL default '0',
  ADD PRIMARY KEY  (`guid`,`friend`,`flags`),
  ADD KEY (`guid`),
  ADD KEY (`friend`),
  ADD KEY `guid_flags` (`guid`,`flags`),
  ADD KEY `friend_flags` (`friend`,`flags`);

