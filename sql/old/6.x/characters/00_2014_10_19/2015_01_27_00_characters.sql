-- latin1 to utf8
ALTER TABLE `guild_finder_applicant` CONVERT TO CHARACTER SET utf8, CHARACTER SET utf8;
ALTER TABLE `guild_finder_guild_settings` CONVERT TO CHARACTER SET utf8, CHARACTER SET utf8;
ALTER TABLE `item_loot_items` CONVERT TO CHARACTER SET utf8, CHARACTER SET utf8;
ALTER TABLE `item_loot_money` CONVERT TO CHARACTER SET utf8, CHARACTER SET utf8;
ALTER TABLE `pvpstats_battlegrounds` CONVERT TO CHARACTER SET utf8, CHARACTER SET utf8;
ALTER TABLE `pvpstats_players` CONVERT TO CHARACTER SET utf8, CHARACTER SET utf8;
ALTER TABLE `quest_tracker` CONVERT TO CHARACTER SET utf8, CHARACTER SET utf8;

-- add PKs
ALTER TABLE `guild_finder_applicant` DROP INDEX `guildId`, -- had unique instead of PK
                                     ADD PRIMARY KEY (`guildId`, `playerGuid`);

ALTER TABLE `item_loot_items` ADD PRIMARY KEY (`container_id`, `item_id`);
ALTER TABLE `item_loot_money` ADD PRIMARY KEY (`container_id`);

ALTER TABLE `quest_tracker` ADD PRIMARY KEY( `id`, `character_guid`);
