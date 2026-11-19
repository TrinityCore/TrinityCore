ALTER TABLE `account` CHANGE `expansion` `expansion` tinyint(3) unsigned NOT NULL DEFAULT '6' AFTER `online`;

UPDATE `account` SET `expansion`=6;
