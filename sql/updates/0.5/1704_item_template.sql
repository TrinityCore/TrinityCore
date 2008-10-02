ALTER TABLE `item_template` ADD COLUMN `BuyCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT 1 AFTER `Flags`;
ALTER TABLE `npc_vendor` DROP COLUMN `buycount`;

UPDATE `item_template`
    SET `BuyCount` = (`BuyPrice` DIV (`SellPrice` * 4)) WHERE `SellPrice` > 0;

UPDATE `item_template`
    SET `BuyCount` = 1 WHERE `BuyCount` = 0;

