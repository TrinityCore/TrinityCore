ALTER TABLE `item_instance` ADD COLUMN `transmog` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `text`;
UPDATE `item_instance` AS `ii` INNER JOIN `custom_transmogrification` AS `ct` ON  `ii`.`guid` = `ct`.`GUID` SET `transmog` = `FakeEntry`;
DROP TABLE IF EXISTS `custom_transmogrification`;
