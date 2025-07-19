ALTER TABLE `item_loot_items` ADD `item_type` tinyint NOT NULL DEFAULT 0 COMMENT 'item or currency' AFTER `container_id`;
ALTER TABLE `item_loot_items` DROP PRIMARY KEY;
ALTER TABLE `item_loot_items` ADD PRIMARY KEY (`container_id`,`item_type`,`item_id`);
