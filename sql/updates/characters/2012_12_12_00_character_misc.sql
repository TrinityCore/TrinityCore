
-- -------------------------
-- -- Primary Key updates --
-- -------------------------
ALTER TABLE `guild_finder_applicant`
	ADD PRIMARY KEY (`guildId`, `playerGuid`);
	
ALTER TABLE `guild_member`
	ADD PRIMARY KEY (`guildid`);