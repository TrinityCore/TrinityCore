ALTER TABLE `character_inventory` DROP PRIMARY KEY, DROP KEY `idx_item`;

ALTER TABLE `character_inventory` ADD PRIMARY KEY (`item`);
