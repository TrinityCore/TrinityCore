ALTER TABLE `character_donate`
ADD `type` INT(11) DEFAULT '0' NOT NULL AFTER `itemguid`,
ADD `deletedate` TIMESTAMP DEFAULT '0000-00-00 00:00:00' NOT NULL AFTER `date`,
ADD `account` INT(11) DEFAULT '0' NOT NULL AFTER `deletedate`;
