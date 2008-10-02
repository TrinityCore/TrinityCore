ALTER TABLE `guild_rank` 
  ADD `rid` int(11) unsigned NOT NULL AFTER `guildid`,
  ADD PRIMARY KEY (`guildid`,`rid`);