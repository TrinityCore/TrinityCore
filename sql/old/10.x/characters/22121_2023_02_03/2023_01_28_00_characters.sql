ALTER TABLE `mail` MODIFY `id` bigint unsigned NOT NULL DEFAULT '0' COMMENT 'Identifier';
ALTER TABLE `mail_items` MODIFY `mail_id` bigint unsigned NOT NULL DEFAULT '0';
