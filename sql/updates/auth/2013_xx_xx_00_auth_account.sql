ALTER TABLE `account`
    ADD COLUMN `mutereason` VARCHAR(255) NOT NULL AFTER `mutetime`,
    ADD COLUMN `muteby` VARCHAR(50) NOT NULL AFTER `mutereason`;