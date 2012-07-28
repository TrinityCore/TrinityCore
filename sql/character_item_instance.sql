ALTER TABLE `item_instance`
    ADD COLUMN `displayId` MEDIUMINT(8) DEFAULT 0 NOT NULL AFTER `itemEntry`;

