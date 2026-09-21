ALTER TABLE `account` MODIFY `expansion` tinyint unsigned NOT NULL DEFAULT '11';

UPDATE `account` SET `expansion`=11 WHERE `expansion`=10;
