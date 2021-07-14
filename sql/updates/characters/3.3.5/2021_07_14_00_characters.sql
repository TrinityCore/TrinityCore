ALTER TABLE `item_loot_items` 
ADD COLUMN `item_index` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `item_count`;
