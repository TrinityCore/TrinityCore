ALTER TABLE `item_refund_instance`
DROP COLUMN `paidHonor`,
DROP COLUMN `paidArena`,
DROP COLUMN `paidItem_1`,
DROP COLUMN `paidItemCount_1`,
DROP COLUMN `paidItem_2`,
DROP COLUMN `paidItemCount_2`,
DROP COLUMN `paidItem_3`,
DROP COLUMN `paidItemCount_3`,
DROP COLUMN `paidItem_4`,
DROP COLUMN `paidItemCount_4`,
DROP COLUMN `paidItem_5`,
DROP COLUMN `paidItemCount_5`,
ADD COLUMN `paidExtendedCost` int(11) unsigned NOT NULL DEFAULT '0';
