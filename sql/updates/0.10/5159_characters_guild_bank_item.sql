ALTER TABLE `guild_bank_item` 
  ADD COLUMN `item_entry` int(11) unsigned NOT NULL default '0',
  ADD KEY `item_guid_key` (`item_guid`),
  ADD KEY `guildid_key` (`guildid`);

UPDATE `guild_bank_item` ,`item_instance`
  SET `guild_bank_item`.`item_entry` = SUBSTRING_INDEX(SUBSTRING_INDEX(`item_instance`.`data`, ' ', 4), ' ', -1)
  WHERE `guild_bank_item`.`item_guid` = `item_instance`.`guid`;

