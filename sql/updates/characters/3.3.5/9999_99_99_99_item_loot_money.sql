
ALTER TABLE `item_loot_money` CHANGE `container_id` `container_id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'guid of container (item_instance.guid)';
ALTER TABLE `item_loot_money` CHANGE `money` `money` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'money loot (in copper)';
ALTER TABLE `item_loot_money` ADD PRIMARY KEY (`container_id`);
