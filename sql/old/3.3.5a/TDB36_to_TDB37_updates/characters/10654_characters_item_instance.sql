-- Add new column to item_instance table
ALTER TABLE `item_instance` ADD COLUMN `itemEntry` mediumint(8) unsigned NOT NULL DEFAULT '0' AFTER `guid`;

-- Set values for new column from corresponding columns in other tables
UPDATE item_instance ii, auctionhouse ah
SET ii.itemEntry = ah.item_template
WHERE ii.guid = ah.itemguid;

UPDATE item_instance ii, character_inventory ci
SET ii.itemEntry = ci.item_template
WHERE ii.guid = ci.item;

UPDATE item_instance ii, guild_bank_item gbi
SET ii.itemEntry = gbi.item_entry
WHERE ii.guid = gbi.item_guid;

UPDATE item_instance ii, mail_items mi
SET ii.itemEntry = mi.item_template
WHERE ii.guid = mi.item_guid;

-- Remove unnecessary columns
ALTER TABLE `auctionhouse` DROP COLUMN `item_template`;
ALTER TABLE `character_inventory` DROP COLUMN `item_template`;
ALTER TABLE `guild_bank_item` DROP COLUMN `item_entry`;
ALTER TABLE `mail_items` DROP COLUMN `item_template`;

-- Delete orphan records (use at your own risk)
-- DELETE FROM item_instance WHERE itemEntry = 0;
