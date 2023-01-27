/*
**************************
*    BfaCore Reforged    *
**************************
*/

ALTER TABLE characters
	CHANGE COLUMN `inventorySlots` `inventorySlots` TINYINT(3) UNSIGNED NOT NULL DEFAULT '20' AFTER `customDisplay3`;

-- update the inventory slots for existing characters
UPDATE characters SET inventorySlots = 20;
