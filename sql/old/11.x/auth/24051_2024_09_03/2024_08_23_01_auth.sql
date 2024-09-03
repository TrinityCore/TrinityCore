ALTER TABLE `account` MODIFY `expansion` tinyint unsigned NOT NULL DEFAULT 10;

UPDATE `account` SET `expansion`=10 WHERE `expansion`=9;
