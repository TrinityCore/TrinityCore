ALTER TABLE `areatrigger_data` DROP `visualId`;
ALTER TABLE `areatrigger_data` ADD `customVisualId` INT(11) NOT NULL DEFAULT '0' AFTER `maxCount`;