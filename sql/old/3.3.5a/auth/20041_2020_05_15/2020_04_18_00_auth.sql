--
ALTER TABLE `logs_ip_actions` ADD COLUMN `realm_id` INT(10) UNSIGNED NOT NULL DEFAULT 0 COMMENT 'Realm ID' AFTER `character_guid`;
