ALTER TABLE `item_instance`
MODIFY COLUMN `flags`  int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `charges`;

ALTER TABLE `item_instance`
CHANGE COLUMN `playedTime` `creationTime`  int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `durability`;
UPDATE `item_instance` SET `creationTime`= 0;
