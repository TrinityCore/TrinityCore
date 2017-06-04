ALTER TABLE `characters`
    ADD COLUMN `honor` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `deleteDate`,
    ADD COLUMN `honorLevel` INT(10) UNSIGNED NOT NULL DEFAULT '1' AFTER `honor`,
    ADD COLUMN `prestigeLevel` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `honorLevel`,
    ADD COLUMN `honor_rest_state` TINYINT UNSIGNED NOT NULL DEFAULT '2' AFTER `prestigeLevel`,
    ADD COLUMN `honor_rest_bonus` FLOAT NOT NULL DEFAULT '0' AFTER `honor_rest_state`;
