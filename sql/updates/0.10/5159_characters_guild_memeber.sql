ALTER TABLE `guild_member` 
  ADD KEY `guildid_key` (`guildid`),
  ADD KEY `guildid_rank_key` (`guildid`,`rank`),
  ADD KEY `guid_key` (`guid`);

