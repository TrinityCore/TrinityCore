ALTER TABLE `account`
   ADD COLUMN `mutereason` VARCHAR(255) NOT NULL DEFAULT '' AFTER `mutetime`,
   ADD COLUMN `muteby` VARCHAR(50) NOT NULL DEFAULT '' AFTER `mutereason`;
