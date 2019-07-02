ALTER TABLE `character_aura`
  DROP PRIMARY KEY,
  ADD `itemGuid` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `casterGuid`,
  ADD PRIMARY KEY(`guid`,`casterGuid`,`itemGuid`,`spell`,`effectMask`);
