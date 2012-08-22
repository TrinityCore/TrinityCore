ALTER TABLE `account_banned`
    CHANGE `bandate` `bandate` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `unbandate` `unbandate` INT(10) UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `ip_banned`
    CHANGE `ip` `ip` VARCHAR(15) CHARSET utf8 COLLATE utf8_general_ci DEFAULT '127.0.0.1' NOT NULL,
    CHANGE `bandate` `bandate` INT(10) UNSIGNED NOT NULL,
    CHANGE `unbandate` `unbandate` INT(10) UNSIGNED NOT NULL;
